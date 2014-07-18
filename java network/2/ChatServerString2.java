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
	String temp,temp1=" ";
	char c;
	
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
		temp1=" ";

		String temp=dis_socket.readLine();
		System.out.println(temp);

		for(int i=temp.length()-1;i>=0;i--)
		{
			c=temp.charAt(i);
			temp1=temp1+c;
		}
		temp=temp.trim();
		temp1=temp1.trim();
		
		if(temp.equals(temp1))
		{
			c='Y';
		}
		else
		{
			c='N';
		}
		
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
		
	public boolean sendMessage() throws Exception
	{
		dos.writeChar(c);
		//dos.writeChar('\n');
				
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
}

public class ChatServerString2
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