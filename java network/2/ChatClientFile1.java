import java.io.*;
import java.net.*;

class ChatClient
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_keyboard;
	DataInputStream dis_socket;
	DataOutputStream dos;
	String temp;
	int c;
	FileInputStream fi;
	
	ChatClient() throws Exception
	{
		InetAddress add=InetAddress.getLocalHost();
		socket=new Socket(add,2000);
		
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
			}
			catch(Exception e){ }
		}
	}

		
	public boolean sendMessage() throws Exception
	{
		System.out.print("\n Enter File Name : ");
		temp=dis_keyboard.readLine();
		dos.writeBytes(temp);
		dos.writeChar('\n');
		
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
	
	public boolean readMessage() throws Exception
	{
		char temp1=dis_socket.readChar();
		//System.out.println(temp1);
		
		if(temp1=='N')
			System.out.println("File Not Found...");
		else
		{
			fi=new FileInputStream(temp);
			
			while((c=fi.read())!=-1)
			{
				System.out.print((char)c);
			}
		}

			//System.out.println("File Found....");
		
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
}

public class ChatClientFile1
{
	public static void main(String arg[])
	{
		try
		{
			ChatClient cc=new ChatClient();
		}
		catch(Exception e){ }
	}
}
		