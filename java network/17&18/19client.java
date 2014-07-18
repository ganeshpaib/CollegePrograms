import java.io.*;
import java.net.*;
import java.sql.*;

class stclient
{
	Socket s;
	DataInputStream keyboard;
	DataOutputStream dos;
	
	stclient()throws Exception
	{
		s=new Socket(InetAddress.getLocalHost(),2007);
		keyboard=new DataInputStream(System.in);
		dos=new DataOutputStream(s.getOutputStream());
		System.out.print("Enter the Auther name : ");
		dos.writeBytes(keyboard.readLine()+"\n");
	}
}
class runstc
{
	public static void main(String arg[])
	{
		try
		{
			new stclient();
		}
		catch(Exception e){System.out.println(e);}
	}
}
	