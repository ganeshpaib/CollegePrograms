import java.io.*;
import java.net.*;
class UDPServer
{
	DatagramSocket socket;
	DatagramPacket packet;
	public void startServer() throws Exception
	{
		socket=new DatagramSocket(5000);		
		System.out.println("Server waiting at port 5000");
		
		DataInputStream dis=new DataInputStream(System.in);
		int clientport=5100;
		
		while(true)
		{
			System.out.println("Enter the string : ");
			String temp=dis.readLine();
			byte buff[]=temp.getBytes();
		
			System.out.println("Sending data to client...");
			InetAddress add=InetAddress.getByName("localhost");
			
			packet=new DatagramPacket(buff,buff.length,add,clientport);
			
			socket.send(packet);
			
			if(buff.length==0)
				break;
		}
	}
}
class SimpleUDPServer 
{
	public static void main(String str[])
	{
		try
		{
			UDPServer s=new UDPServer();
			s.startServer();
		}catch(Exception e)
		{}
	}
}