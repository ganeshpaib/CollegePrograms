import java.io.*;
import java.net.*;

class server
{
	
	public server()throws Exception
	{
		String fname="image.jpg";
		FileOutputStream dest=new FileOutputStream("c:\\data\\"+fname);
		FileInputStream file= new FileInputStream(fname);
		
		int size=file.available();
		System.out.println("SIZE OF THE FILE [ "+fname+" ] : "+size);
		
		byte b[]=new byte[size];
		System.out.println("READ SIZE : "+file.read(b));
		dest.write(b);
		
		System.out.println("TRANSFER COMPLETED");
		
	}
}

class runme
{
	public static void main(String arg[])
	{
		try
		{
		new server();
		}catch(Exception e){System.out.println(e);}
	}
}
		
		
		