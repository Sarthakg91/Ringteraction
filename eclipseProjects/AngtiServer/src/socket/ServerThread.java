	package socket;
	
	import java.io.BufferedReader;
	import java.io.IOException;
	import java.io.InputStream;
	import java.io.InputStreamReader;
	import java.net.Socket;
	
	public class ServerThread extends Thread {
	
		private BufferedReader br = null;
		private AngtiServer mServer;
		private boolean stopThread = false;
		private int id;
	
		public ServerThread(Socket s, AngtiServer as, int i)
		{
			this.mServer = as;
			this.id = i;
			try {
				this.br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	
		@Override
		public void run() {
			while (!this.stopThread)
			{
				try {
					String msg = br.readLine();
					if (msg == null)
					{
						this.mServer.terminate(this.id);
					}
					else
					{
					this.mServer.broadcastMessage(msg);
					}
				} catch (IOException e) {
					System.out.println("*** Error termination on thread #" + this.id);
					this.mServer.terminate(this.id);
				}
			}
			this.mServer.terminate(this.id);
		}
	
		public void terminate()
		{
			System.out.println("*** Terminating properly thread #" + this.id);
			this.stopThread = true;
			try {
				this.br.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	
	}
