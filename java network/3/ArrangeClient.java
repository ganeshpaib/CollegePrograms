import java.io.*;
import java.net.*;

class Client
{
	InputStream is;
	DataInputStream dis_socket,dis_keyboard;
	OutputStream os;
	DataOutputStream dos;
	int number,i;
	
	Client() throws Exception
	{
		InetAddress add=InetAddress.getLocalHost();
		Socket socket=new Socket(add,2000);
		
		is=socket.getInputStream();
		dis_socket=new DataInputStream(is);
		dis_keyboard=new DataInputStream(System.in);
		os=socket.getOutputStream();
		dos=new DataOutputStream(os);
		
		System.out.print("\n Enter Number Of Integer : ");
		number=Integer.parseInt(dis_keyboard.readLine());
		dos.writeInt(number);
		int a[]=new int[number];
		for(i=0;i<number;i++)
		{
			System.out.print(i+1+":");
			a[i]=Integer.parseInt(dis_keyboard.readLine());
			dos.writeInt(a[i]);
		}
		
		for(i=0;i<number;i++)
		{
			System.out.println(dis_socket.readInt());
		}
	}
}


public class ArrangeClient
{
	public static void main(String arg[])
	{
		try
		{
			Client c=new Client();
		}catch(Exception e){}
	}
}
		
		