package arduino;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

import socket.AngtiServer;
import jssc.SerialPort;
import jssc.SerialPortException;


public class ArduinoHandler extends Thread {

	private String portName;
	private SerialPort serialPort;
	private boolean stop = false;
	private AngtiServer mServer;
	private String portMessage = "";
	private BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));


	public ArduinoHandler(String _c, AngtiServer _as)
	{
		this.portName = _c;
		this.mServer = _as;
		this.serialPort = new SerialPort(portName);
		try {
			System.out.println("Port opened: " + serialPort.openPort());
			System.out.println("Params setted: " + serialPort.setParams(SerialPort.BAUDRATE_9600,
					SerialPort.DATABITS_8,
					SerialPort.STOPBITS_1,
					SerialPort.PARITY_NONE));
			Thread.sleep(1500);
		}
		catch (SerialPortException ex){
			ex.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public SerialPort getSerialPort()
	{
		return this.serialPort;
	}

	public void closePort() {
		try {
			this.serialPort.closePort();
		} catch (SerialPortException ex) {
			ex.printStackTrace();
		}
	}

	// delay-pin-frequency-time-intensity-(l/-)

	public void sendMessage(String msg)
	{
		try {
			this.serialPort.writeByte((byte)msg.charAt(0));
			//this.serialPort.writeString(msg);
		} catch (SerialPortException ex) {
			ex.printStackTrace();
			this.mServer.terminateArduino();
		}
	}


	public boolean isAvailable()
	{
		try {
			return this.serialPort.getInputBufferBytesCount() > 0;
		} catch (SerialPortException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}

	public void flushInput()
	{
		try {
			int totalRead = this.serialPort.getInputBufferBytesCount();
			if (totalRead > 0)
			{
				/*System.err.println(*/new String(this.serialPort.readBytes(totalRead));
			}
			//this.serialPort.purgePort(SerialPort.PURGE_RXCLEAR);
		} catch (SerialPortException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}    


	public String readMessage()
	{
		/*String resul = "";

		try {
			int totalRead = this.serialPort.getInputBufferBytesCount();
			if (totalRead > 0)
			{
				resul = new String(this.serialPort.readBytes(totalRead));
			}
		} catch (SerialPortException e) {
			e.printStackTrace();
		}
		return resul;*/
		String resul = "";
		try {
			while (this.serialPort.getInputBufferBytesCount() > 0)
			{
				byte charRead = this.serialPort.readBytes(1)[0];
				char c = (char) charRead;
				if (c == '#')
				{
					// end of command and stop that shit right now
					
					resul = this.portMessage;
					this.portMessage = "";
					return resul;
				}
				if (Character.isDigit(c) || Character.isLetter(c) || (c == ' '))
				{
					this.portMessage += c;
				}
			}
		}
		catch (SerialPortException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "";
	}    

	@Override
	public void run()
	{
		while (!this.stop)
		{
			if (this.isAvailable())
			{
				String msg = this.readMessage();
				if (!msg.isEmpty())
				{
					this.mServer.broadcastMessage(msg, false);
				}
			}
			// Added to read on STDIN
			try {
				if (System.in.available() >= 3)
				{String st;
					// Means we have a character available AND also \r\n
					String stdInMessage = this.stdIn.readLine();
					if(stdInMessage.contains("blue"))
					st="color blue";
					else
					st="color red";
					
					this.mServer.broadcastMessage(st, true);
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		this.closePort();
	}
}