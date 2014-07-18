import java.io.*;
import java.net.*;

class Server
{
	DataInputStream dis_socket;
	InputStream is;
	OutputStream os;
	DataOutputStream dos;
	String temp1;
	Socket socket;
	int ctr,alpha,line,di,ot,c;
	
	public void startserver() throws Exception
	{
		ServerSocket s=new ServerSocket(2000);
		socket=s.accept();
		
		is=socket.getInputStream();
		dis_socket=new DataInputStream(is);
		
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
		temp1=dis_socket.readLine();
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
		alpha=0;
		di=0;
		line=0;
		ot=0;
		
		if(ctr==1)
			dos.writeChar('N');
		else
		{
			dos.writeChar('Y');
			FileInputStream fis=new FileInputStream(temp1);
			while((c=fis.read())!=-1)
			{
				if(c>=65 && c<=90 || c>=97 && c<=122)
					alpha++;
				else if(c=='\n')
					line++;
				else if(c>='0' && c<='9')
					di++;
				else
					ot++;
			}

			dos.writeInt(alpha);
			dos.writeInt(line);
			dos.writeInt(di);
			dos.writeInt(ot);
		}
		
		return false;
	}
}

public class ChatServerFile2
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
	
			

		
		
		
	
	
	