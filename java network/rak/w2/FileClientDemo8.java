import java.io.*;
import java.net.*;

class FileClient
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_socket;
	DataOutputStream dos_socket;
	DataInputStream dis;
	// FileInputStream fis;
		
	FileClient() throws Exception
	{
		InetAddress addr = InetAddress.getByName("localhost");
		socket = new Socket(addr,2100);
		os = socket.getOutputStream();
		is = socket.getInputStream();
		dos_socket = new DataOutputStream(os);
		dis_socket = new DataInputStream(is);
		dis = new DataInputStream(System.in);
		System.out.println("\n\n\t Enter the file name: ");
		String fname = dis.readLine();
		dos_socket.writeBytes(fname);
		dos_socket.writeChar('\n');
		int line=0,alpha=0,dig=0,space=0,special=0;
		byte c;
		String msg = new String();
		msg = dis_socket.readLine().trim();
		if(msg.equals("no"))
		 System.out.println("File is Not present....!!!");
		else
		System.out.println("\n\n File contents from the server..\n\n");
		
		while((c=dis_socket.readByte())!=(byte)-1)
		System.out.print((char)c);	
		
		for(int i=0;i<26;i++)
			System.out.println("\nNo of Alphabets: "+(char)(i+97) +" : "+ dis_socket.readInt());
		
	}
}
		
		
	class FileClientDemo8
	{
		public static void main(String args[])
		{
			try
			{
				FileClient c = new FileClient();
			}
			catch(Exception e)
			{}
		}
	}
		
	