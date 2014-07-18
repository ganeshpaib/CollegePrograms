import java.io.*;
import java.net.*;
class UDPClient
{
	DatagramSocket socket;
	DatagramPacket packet;
	
	UDPClient() throws Exception
	{
		
		socket=new DatagramSocket(5100);
		System.out.println("Client prog wait at port 5100");			
		
		while(true)
		{
			byte buff[]=new byte[80];
			packet=new DatagramPacket(buff,buff.length);
			
			socket.receive(packet);
			InetAddress add=packet.getAddress();

			int port=packet.getPort();
			
			System.out.println("IP add of server is "+add+" Port no "+port);
			buff=packet.getData();
			
			if(buff.length==0)
			{
				break;
			}

			String msg=new String(buff);
			System.out.println(msg);
						
			
		}
		
	}
	
}
class SimpleUDPClient
{
	public static void main(String s[])
	{
		try{
			UDPClient c=new UDPClient();
		  }catch(Exception e)
		   {} 
	
	}
}