import java.io.*;
import java.net.*;

class Client
{
	Client() 
	{
		try
		{
			InetAddress add=InetAddress.getLocalHost();
			Socket sclient=new Socket(add,2000);
		}
		catch(Exception e) { }
	}
}

class Client1
{
	public static void main(String arg[])
	{
		Client c=new Client();
	}
}