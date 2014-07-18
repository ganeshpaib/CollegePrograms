import java.io.*;
import java.net.*;

class Server
{
	InputStream is;
	DataInputStream dis;
	OutputStream os;
	DataOutputStream dos;
	String temp1;
	Socket socket;
	int ctr;
		
	public void startserver() throws Exception
	{
		ServerSocket s=new ServerSocket(2000);
		 socket=s.accept();
		
		is=socket.getInputStream();
		dis=new DataInputStream(is);
		
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
			}catch(Exception e){}
		}
	}
		
		public boolean readMessage() throws Exception
		{
			ctr=0;
			temp1=dis.readLine();
			
			try
			{
				FileReader fr=new FileReader(temp1);
			}catch(Exception e){ctr=1;}
			
			if(temp1.equals("stop"))
				return true;
			else
				return false;
		}
		
		public boolean sendMessage() throws Exception
		{
			int alpha[]=new int[26];
			int c;
			
			if(ctr==1)
				dos.writeChar('N');
			else
			{
				dos.writeChar('Y');
				FileInputStream fis=new FileInputStream(temp1);
				while((c=fis.read())!=-1)
				{
					if(c>=65 && c<=90)
						alpha[c-65]++;
					if(c>=97 && c<=122)
						alpha[c-97]++;
				}
				
				for(int i=0;i<26;i++)
				{
					if(alpha[i]!=0)
					{
						dos.writeChar((char)(i+65));
						dos.writeInt(alpha[i]);
					}
						
				}
			}
			return false;
		}
}

public class ChatServerFile3
{
	public static void main(String arg[])
	{
		try
		{
			Server s=new Server();
			s.startserver();
		}catch(Exception e){}
	}
}
			
			
				
				
			
				