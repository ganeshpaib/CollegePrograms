import java.net.*;
import java.io.*;

class MesgClient
{
	Socket socket;
	OutputStream os;
	InputStream in;
	DataInputStream dis_socket;
	DataOutputStream dos_socket;
	DataInputStream dis;
	String clientmsg;
	
	MesgClient() throws Exception
	{
			InetAddress address = InetAddress.getByName("59.92.249.33");
			Socket s = new Socket(address,3000);
			os = s.getOutputStream();
			dos_socket = new DataOutputStream(os);
			in = s.getInputStream();
			dis_socket = new DataInputStream(in);
			dis = new DataInputStream(System.in);
			sendHello();
			readMessage();
			
	}
	
	void sendMessage() throws Exception
	{
		System.out.print("Enter Messg :  ");
		String temp = dis.readLine();
		//System.out.println(temp);
		dos_socket.writeBytes(temp);
		dos_socket.writeChar('\n');
		readMessage();
		
	}
	void sendHello()throws Exception
	{
		System.out.print("Enter Name:  ");
		String temp = dis.readLine();
		System.out.println("----------------------------------------------------------------------------");
		System.out.println("\n\nFrom Server : Hello "+temp+"  ..!!");
		dos_socket.writeBytes(temp);
		dos_socket.writeChar('\n');
	}	
	boolean readMessage() throws Exception
	{
		System.out.println("----------------------------------------------------------------------------");
		String from = dis_socket.readLine();
		String temp = dis_socket.readLine();
		from=from.trim();
		clientmsg=temp.trim();
		
		if(!clientmsg.equals("send"))
			System.out.println(from +" sayz : " + temp);
			
		if(clientmsg.equals("send"))
			sendMessage();
		else
			readMessage();
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
}

class runclient
{
	public static void main(String args[])
	{
		try
		{
			MesgClient c = new MesgClient();
		}
		catch(Exception e)
		{System.out.println(e);}
	}
}
		
		
		
	 