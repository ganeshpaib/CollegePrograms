import java.io.*;
import java.net.*;

class ChatServer
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_socket;
	DataInputStream dis_keyboard;
	DataOutputStream dos;
	FileReader fr;
	char temp1;
	String temp;
	
	public void startserver() throws Exception
	{
		ServerSocket s=new ServerSocket(2000);
		System.out.println("\n Server Ready....");
		socket=s.accept();
		
		is=socket.getInputStream();
		dis_socket=new DataInputStream(is);
		dis_keyboard=new DataInputStream(System.in);
		
		os=socket.getOutputStream();
		dos=new DataOutputStream(os);
		
		while(true)
		{
			try
			{
				boolean flag1=readMessage();
				boolean flag2=sendMessage();
					
				if(flag1||flag2)
					break;
			}
			catch(Exception e){ }
		}
	}

	public boolean readMessage() throws Exception
	{
		int ctr=0;

		String temp=dis_socket.readLine();
		System.out.println(temp);
			
		try
		{
			fr=new FileReader(temp);
		}catch(Exception e){ctr=1;}
		
		if(ctr==1)
		{
			temp1='N';
		}
		else
		{
			temp1='Y';
		}
		
		
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
		
	public boolean sendMessage() throws Exception
	{
		dos.writeChar(temp1);
				
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
}

public class ChatServerFile1
{
	public static void main(String arg[])
	{
		try
		{
			ChatServer cs=new ChatServer();
			cs.startserver();
		}
		catch(Exception e){ }
	}
}