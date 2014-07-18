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
		//	int c,line=0,alpha=0,dig=0,space=0,special=0,flag;
	
		String msg = new String();
		flag=0;
		if(f.exists())
		{
		flag=1;
		while((c=dis.read())!=-1)
		{
			
			dos_socket.writeByte((byte)c);
			/*
			if(((char)c)=='\n')
			line++;
			else if(((char)c)>='a' && ((char)c)<='z' || ((char)c)>='A' && ((char)c)<='Z')
			alpha++;
			else if(((char)c)>='0' && ((char)c)<='9')
			dig++;
			else if(((char)c)==' ')
			space++;
			else 
			special++;*/
		}
		    dos_socket.writeByte((byte)c);
		   /* dos_socket.writeInt(line);
		    dos_socket.writeInt(alpha);
		    dos_socket.writeInt(dig);
		    dos_socket.writeInt(space);
		    dos_socket.writeInt(special);
		*/
		}
		if(flag==0)
			dos_socket.writeBytes("no\n");
		else
			dos_socket.writeBytes("yes\n");
		
		
	}
	
}
		
	class FileServerDemo6
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
		
	