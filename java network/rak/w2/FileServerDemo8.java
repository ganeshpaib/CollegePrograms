import java.io.*;
import java.net.*;

class FileServer extends Thread
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_socket;
	DataOutputStream dos_socket;
	DataInputStream dis;
	FileInputStream fis;
		
	public void startServer() throws Exception
	{
		System.out.println("\n\n\t Server is waiting for port: (2100)");
		ServerSocket s = new ServerSocket(2100);
		socket = s.accept();
		is = socket.getInputStream();
		dis_socket = new DataInputStream(is);
		os = socket.getOutputStream();
		dos_socket = new DataOutputStream(os);
		readFile();
	}

	public void readFile() throws Exception
	{
		String fname = dis_socket.readLine();
		System.out.print("\n\n\t Requested file from the client: "+fname);
		fis = new FileInputStream(fname);
		dis = new DataInputStream(fis);
		File f = new File(fname);
		int c,flag;
		String msg = new String();
		flag=0;
		int alpha[]=new int[26];
		if(f.exists())
		{
		flag=1;
		while((c=dis.read())!=-1)
		{
			
			dos_socket.writeByte((byte)c);
			if(c>=65 && c<=90)
				alpha[c-65]++;
			if(c>=97 && c<=122)
				alpha[c-97]++;

			
		}
		  dos_socket.writeByte((byte)c);
		  for(int i=0;i<26;i++)
			  dos_socket.writeInt(alpha[i]);
		 
		}
		if(flag==0)
			dos_socket.writeBytes("no\n");
		else
			dos_socket.writeBytes("yes\n");
		
		
	}
	public void reply()
	{
		try{
		dos_socket.writeInt(1000);	
			}catch(Exception e){}
	}
}
		
	class FileServerDemo8
	{
		public static void main(String args[])
		{
			try
			{
				FileServer s = new FileServer();
				s.startServer();
			}
			catch(Exception e)
			{
				System.out.println("File not found exception ..");
						
			}
		}
	}
		
	