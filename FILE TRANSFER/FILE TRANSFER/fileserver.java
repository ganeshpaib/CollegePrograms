import java.io.*;
import java.net.*;

class server
{
	DataInputStream dis;
	DataOutputStream dos;
	Socket s;
	public server()throws Exception
	{
		ServerSocket ss=new ServerSocket(2000);
		s=ss.accept();
		dis=new DataInputStream(s.getInputStream());
		dos=new DataOutputStream(s.getOutputStream());
		
		String fname=dis.readLine().trim();
		FileOutputStream dest=new FileOutputStream("c:\\data\\"+fname);
		
		int size=dis.readInt();
		System.out.println("SIZE OF THE FILE [ "+fname+" ] : "+size);
		
		byte b[]=new byte[size];
		dis.readFully(b);
		
		dest.write(b);
		dos.writeInt(3);
		System.out.println("TRANSFER COMPLETE");
		
		
	}
}

class runserver
{
	public static void main(String arg[])
	{
		try
		{
		new server();
		}catch(Exception e){System.out.println(e);}
	}
}
		
		
		