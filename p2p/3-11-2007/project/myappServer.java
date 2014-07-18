import java.net.*;
import java.io.*;
import java.util.*;

class Server implements Runnable
{
	
	DataInputStream keyboard;
	DataInputStream dis;
	DataOutputStream dos;
	static Vector<Socket>client;
	static Hashtable<Socket,String>playerset1,playerset2,clientset;
	int thread,hello,status,flag,index,set;
	String name;
	Socket s;
	
	Server()
	{
		client=new Vector<Socket>(5,2);
		clientset=new Hashtable<Socket,String>();
	}
	Server(Socket s1)
	{
		s=s1;
		
	}
	
	public void StartServer()throws Exception
	{
		ServerSocket server=new ServerSocket(7777);
		System.out.println("----------------------------------------------------------------------------");
		System.out.println("\n\nServer started......");
		while(true)
		{
			s=server.accept();
			client.addElement(s);
			System.out.println("\n\n\n----------------------------------------------------------------------------");
			System.out.println("Client connected .. index : "+client.indexOf(s));
			Server newclient = new Server(s);
			new Thread(newclient).start();
		}
	}
	
	public void run()
	{
		try
		{
			dis=new DataInputStream(s.getInputStream());
			
			//System.out.println("Thread 1 executing");
				name=dis.readLine();
				//System.out.println("\n\n\n----------------------------------------------------------------------------");
				System.out.println("Client Name :"+name);
				
				clientset.put(s,name);
				
				int n=dis.readInt();
				System.out.println("Number of files present in the directory : "+ n);
				String file;
				for(int i=0;i<n;i++)
				{
					 file=dis.readLine();
					System.out.println(file);
				}
				
				System.out.println("----------------------------------------------------------------------------");
				String msg=dis.readLine();
				System.out.println("\n\n\n----------------------------------------------------------------------------");
				System.out.println(name +" "+ msg);
				System.out.println("----------------------------------------------------------------------------");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}

class myappServer
{
	public static void main(String arg[])
	{
		try
		{
			new Server().StartServer();
		}
		catch(Exception e){System.out.println(e);}
	}
}