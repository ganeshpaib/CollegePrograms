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
	char c;
		
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
		System.out.print("\n Enter String : ");
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
		 c=dis_socket.readChar();
		System.out.println("The Reversed String Is :  "+c);
		
		if(c=='Y')
		{
			System.out.println("\n The String Is Palindrome");
		}
		else
		{
			System.out.println("\n The String Is Not Palindrome");
		}
		
		
		if(temp.equals("stop"))
			return true;
		else
			return false;
	}
}

public class ChatClientString2
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
		