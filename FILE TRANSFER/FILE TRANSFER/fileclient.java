import java.net.*;
import java.io.*;

class client
{
	DataInputStream keyboard;
	DataOutputStream dos;
	
	client()throws Exception
	{
		Socket s=new Socket(InetAddress.getByName("59.92.241.103"),2000);
		
		keyboard=new DataInputStream(System.in);
		dos=new DataOutputStream(s.getOutputStream());
		DataInputStream dis=new DataInputStream(s.getInputStream());
		System.out.print("ENTER THE FILE NAME WHICH YOU WANT TO TRANSFER : ");
		String fname=keyboard.readLine().trim();
		dos.writeBytes(fname+"\n");
		
		FileInputStream file= new FileInputStream(fname);
		int size=file.available();
		dos.writeInt(size);
		System.out.println("SIZE OF THE FILE [ "+fname+" ] : "+size);
		
		byte b[]=new byte[size];
		file.read(b);
		dos.write(b,0,size);
		int c=dis.readInt();
		if(c==3)
			System.out.println("TRANSFER COMPLETE");
		
	//	System.out.println("TRANSFER COMPLETE");
	}
}

class runclient
{
	public static void main(String arg[])
	{
		try
		{
			new client();
		}
		catch(Exception e){System.out.println(e);}
	}
}
		