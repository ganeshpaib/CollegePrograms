import java.net.*;
import java.io.*;

class Server implements Runnable
{
	
	DataInputStream keyboard;
	DataInputStream clientmsg;
	DataOutputStream dos;
	Socket s;
	static Socket user[];
	static int id,inc;
	Thread t;
	OutputStream os;
	InputStream is;
	static String name[];
	Server(){user=new Socket[8];name=new String[8];inc=1;}
	Server(Socket s1,int id1){id=id1;s=s1;user[id]=s1;}
	
	public void StartServer()throws Exception
	{
		ServerSocket ss = new ServerSocket(3000);
		System.out.println("----------------------------------------------------------------------------");
		System.out.println("\n\nServer started......");
		int count=1;
		
		while(true)
		{
			try
			{
			s=ss.accept();
			id=count++;
			
			is = s.getInputStream();
			clientmsg = new DataInputStream(is);
    
			os = s.getOutputStream();
			dos = new DataOutputStream(os);
						
			Server server=new Server(s,id);
			t=new Thread(server);		 		
			t.start();
			}catch(Exception e){System.out.println(e);}
		}
			
	}
	public void run()
	{
	
		System.out.println("client connected..."+user[id]);
		try
			{
				is = s.getInputStream();
				clientmsg = new DataInputStream(is);
				name[id]= clientmsg.readLine();
				if(id==1)
					SendMsg(id);
				ReadMsg(id);
			}
			catch(Exception e){}
		
		
	}

	public void SendMsg(int id1)throws Exception
	{
		if(inc==id)
			inc=0;
		dos=new DataOutputStream(user[++inc].getOutputStream());
		dos.writeBytes("Server");
		dos.writeChar('\n');
		if(id==1)
		{
			dos.writeBytes("Plz Wait there is no one else connected...");
			dos.writeChar('\n');
			while(id==1){}
			dos.writeBytes("Server");
			dos.writeChar('\n');
			dos.writeBytes("send");
			dos.writeChar('\n');
		}
		else
		{	
			dos.writeBytes("send");
			dos.writeChar('\n');
		}
		boolean end=ReadMsg(id1);
		if(end)
		{
			System.out.println("game over....");
			WriteMsg("GAME OVER "+name[id1]+" WON ",id1);
		}
		
	}
	
	public boolean ReadMsg(int me)throws Exception
	{
		//System.out.println("\nReading ...."+me);
		is = s.getInputStream();
		clientmsg = new DataInputStream(is);
		String temp = clientmsg.readLine();
		temp=temp.trim();
		//System.out.println(temp);
		//WriteMsg(temp,me);
		if( temp.equals("BINGO") )
			return true;
		else
		{
			WriteMsg(temp,me);
			return false;			
		}//return true;
	}
	
	public void WriteMsg(String msg,int me)throws Exception
	{
		int f=0;
		System.out.println("----------------------------------------------------------------------------");
		System.out.println("Message From : "+name[me]+"\n\n");
			for(int j=1;j<=id;j++)
			{
				if(j!=me)
				{
					System.out.println("\t\t\tSent To : "+name[j]+" id = "+id);
					os = user[j].getOutputStream();
					dos = new DataOutputStream(os);
					if(msg.equals("GAME OVER "+name[me]+" WON "))
					{
						dos.writeBytes("Server");
						f=1;
					}
					else
						dos.writeBytes(name[me]);
					dos.writeChar('\n');
					dos.writeBytes(msg);
					dos.writeChar('\n');
				}
							
			}
		if(f==1)
			System.exit(0);
		SendMsg(me);			
	}
}
class runserver
{
	public static void main(String arg[])
	{
		try
		{
			new Server().StartServer();
		}
		catch(Exception e){}
	}
}