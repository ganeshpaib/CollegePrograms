import java.io.*;
import java.net.*;

class Client
{
	Client() 
	{
		try
		{
			InetAddress add=InetAddress.getLocalHost();
			Socket socket=new Socket(add,2000);
			DataInputStream dis=new DataInputStream(System.in);

			while(true)
			{
				OutputStream os=socket.getOutputStream();
				OutputStreamWriter osw=new OutputStreamWriter(os);
				PrintWriter pw=new PrintWriter(osw);
				
				String temp=new String();
				System.out.println("Enter FileName : ");
				temp=dis.readLine();
				pw.println(temp);
				pw.flush();
				
				if(temp.equals("stop")) break;
			}
		}
		catch(Exception e) { }
	}
}

class FileClient2
{
	public static void main(String arg[])
	{
		Client c=new Client();
	}
}