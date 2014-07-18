import java.io.*;
import java.net.*;

class Server
{
	DataInputStream dis;
	InputStream is;
	OutputStream os;
	DataOutputStream dos;
	ServerSocket s;
	Socket socket;
	int number,i,j,t;
	
	public void startserver() throws Exception
	{
		s=new ServerSocket(2000);
		socket=s.accept();
		
		is=socket.getInputStream();
		dis=new DataInputStream(is);
		
		os=socket.getOutputStream();
		dos=new DataOutputStream(os);
		
		int number=dis.readInt();
		int a[]=new int[number];
		for(int i=0;i<number;i++)
		{
			a[i]=dis.readInt();
		}
		
		for(i=0;i<number;i++)
		{
			System.out.println(a[i]);
		}
		
		for(i=0;i<number-1;i++)
		{
			for(j=i+1;j<number;j++)
			{
				if(a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		
		for(i=0;i<number;i++)
		{
			dos.writeInt(a[i]);
		}
	}
		
}

public class ArrangeServer
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
	
	
	
		
			
		

