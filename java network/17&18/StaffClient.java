import java.io.*;
import java.net.*;

class Client
{
	DataInputStream dis;
	OutputStream os;
	DataOutputStream dos;
	String dg;
		
	Client() throws Exception
	{
		InetAddress add=InetAddress.getLocalHost();
		Socket socket=new Socket(add,2000);
		
		dis=new DataInputStream(System.in);
		
		os=socket.getOutputStream();
		dos=new DataOutputStream(os);
		
		System.out.print("\n Enter staff designation : ");
		dg=dis.readLine();
		
		dos.writeBytes(dg);
		dos.writeByte('\n');
	}
}
public class StaffClient
{
	public static void main(String arg[])
	{
		try
		{
			Client c=new Client();
		}catch(Exception e){}
	}
}
	
	