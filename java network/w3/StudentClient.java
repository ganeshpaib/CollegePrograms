import java.io.*;
import java.net.*;

class Client
{
	//InputStream is;
	DataInputStream dis;
	OutputStream os;
	DataOutputStream dos;
	int roll;
		
	Client() throws Exception
	{
		InetAddress add=InetAddress.getLocalHost();
		Socket socket=new Socket(add,2000);
		
		dis=new DataInputStream(System.in);
		
		os=socket.getOutputStream();
		dos=new DataOutputStream(os);
		
		System.out.print("\n Enter Roll Number : ");
		roll=Integer.parseInt(dis.readLine());
		
		dos.writeInt(roll);
	}
}

public class StudentClient
{
	public static void main(String arg[])
	{
		try
		{
			Client c=new Client();
		}catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}
	
	