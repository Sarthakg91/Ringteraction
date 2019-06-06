package socket;

import java.io.PrintWriter;

public class OutputHandler {

	private int id;
	private PrintWriter pw;

	public OutputHandler(PrintWriter p, int i)
	{
		this.id = i;
		this.pw = p;
	}

	public synchronized void sendMessage(String msg)
	{
		this.pw.println(msg);
		this.pw.flush();
	}

	public synchronized void terminate()
	{
		this.pw.close();
	}

	public int getId() {
		return this.id;
	}

}
