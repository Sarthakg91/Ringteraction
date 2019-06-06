import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import socket.AngtiServer;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter COM port name (e.g. /dev/cu.usbserial-AM01XXVC or /dev/cu.usbserial-09AC2261):");
		String comPort = "";
		try {
			comPort = br.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		AngtiServer server = new AngtiServer(comPort);
	}

}
