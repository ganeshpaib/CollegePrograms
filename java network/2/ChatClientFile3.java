import java.io.*;
import java.net.*;

class Client
{
	OutputStream os;
	DataOutputStream dos;
	InputStream is;	
	DataInputStream dis_socket,dis_keyboard;
	String temp1;
	char ch;
		
	Client() throws Exception
	{
		InetAddress add=InetAddress.getLocalHost();
		Socket socket=new Socket(add,2000);
		
		is=socket.getInputStream();
		dis_socket=new DataInputStream(is);
		dis_keyboard=new DataInputStream(System.in);
			
		os=socket.getOutputStream();
		dos=new DataOutputStream(os);
			
		while(true)
		{
			try
			{
				boolean flag1=sendMessage();
				boolean flag2=readMessage();
					
				if(flag1||flag2)
					break;
			}catch(Exception e){}
		}
	}
		
	public boolean sendMessage() throws Exception
	{
		System.out.print("\n Enter File Name : ");	
		temp1=dis_keyboard.readLine();
		dos.writeBytes(temp1);
		dos.writeChar('\n');
		
		if(temp1.equals("stop"))
			return true;
		else
			return false;
	}

	public boolean readMessage() throws Exception
	{
		ch=dis_socket.readChar();
		int c;
		
		if(ch=='N')
		{
			System.out.println("File Not Found.....");
		}
		else
		{
			for(int i=0;i<26;i++)
			{
				System.out.println(dis_socket.readChar()+"\t"+dis_socket.readInt());
			}
			
		}
		return false;
	}
}

public class ChatClientFile3
{
	public static void main(String arg[])
	{
		try
		{
			Client c=new Client();
		}catch(Exception e){}
	}
}	
		
		



		

