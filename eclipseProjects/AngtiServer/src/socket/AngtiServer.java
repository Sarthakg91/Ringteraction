package socket;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

import arduino.ArduinoHandler;

public class AngtiServer {

	public static final int SERVER_PORT = 5000;
	public static int id_token = 0;
	private ServerSocket servSock;
	private boolean endServer = false;
	private ArrayList<OutputHandler> socketWriters = new ArrayList<OutputHandler>();
	private ArduinoHandler arduinoPort;
	
	public AngtiServer(String _com)
	{
		try {
			System.out.println("*** Opening Arduino serial port on port " + _com);
			this.arduinoPort = new ArduinoHandler(_com, this);
			this.arduinoPort.start();
			System.out.println("*** Starting server...");
			this.servSock = new ServerSocket(SERVER_PORT);
			while (!endServer)
			{
				Socket client = this.servSock.accept();
				System.out.println("*** Accepting new client...");
				this.id_token++;
				int tmpId = this.id_token;
				ServerThread readingThread = new ServerThread(client, this, tmpId);
				PrintWriter pw = new PrintWriter(new OutputStreamWriter(client.getOutputStream()));
				OutputHandler outHandle = new OutputHandler(pw, tmpId);
				this.socketWriters.add(outHandle);
				readingThread.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	public synchronized void terminate(int id) {
		int removeMe = -1;
		for (int i=0; i<this.socketWriters.size(); i++)
		{
			if (this.socketWriters.get(i).getId() == id)
			{
				removeMe = i;
			}
		}
		if (removeMe > -1)
		{
			System.out.println("*** Terminating socket id #" + id + " at index #" + removeMe);
			this.socketWriters.remove(removeMe);
		}
	}

	/**
	 * Broadcasts the message to every socket and Arduino port
	 * @param msg The String to be broadcasted
	 * @param arduino true value broadcasts to the arduino, false will not.
	 */
	public synchronized void broadcastMessage(String msg, boolean arduino) {

		for (OutputHandler o: this.socketWriters)
		{
			System.out.println("*** Broadcasting " +msg + " on thread#" + o.getId());
			o.sendMessage(msg);
		}
	      if(msg.length()<=2)
	      {
			System.out.println("writing in arduino port");
			this.arduinoPort.sendMessage(msg);
	      }
			
		if (arduino)
		{
			this.arduinoPort.sendMessage(msg);
		}
		
	}
	
	/**
	 * Broadcasts the message to every socket and Arduino port. This method sets the arduino param to "true"
	 * @param msg The String to be broadcasted
	 */
	public synchronized void broadcastMessage(String msg) {
		this.broadcastMessage(msg, true);
	}
	
	
	public void terminateArduino() {
		System.out.println("*** Terminating arduino port");
		this.arduinoPort.closePort();
	}
}
