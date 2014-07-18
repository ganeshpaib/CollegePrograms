import java.io.*;
import java.net.*;

class Server implements Runnable
{
	Socket socket;
	int ID;
	Thread t;

	Server() { }
	
	Server(Socket socket,int ID)
	{
		this.socket=socket;
		this.ID=ID;
	}
	
	public void StartServer() throws Exception
	{
		System.out.println("\n\n Server Running and Waiting for Client");
		ServerSocket s=new ServerSocket(2000);
		int count=0;
		
		while(true)
		{
			socket=s.accept();
			ID=count++;
			Server server=new Server(socket,ID);
			t=new Thread(server);
			t.start();
		}
	}

	public void run()
	{
		System.out.println("Client Connected with ID : "+ID);
	}
}

class Server1
{
	public static void main(String arg[])
	{
		try
		{
			Server server=new Server();
			server.StartServer();
		}
		catch(Exception e){ }
	}
}



