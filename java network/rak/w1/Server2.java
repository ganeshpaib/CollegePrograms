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
		
		socket=s.accept();
		Server server=new Server(socket,ID);
		t=new Thread(server);
		t.start();
		
	}

	public void run()
	{
		try
		{
			InputStream is=socket.getInputStream();
			InputStreamReader irs=new InputStreamReader(is);
			BufferedReader br=new BufferedReader(irs);
			
			while(true)
			{
				String temp=br.readLine();
				System.out.println(temp);
				
				if(temp.equals("stop")) break;
			}
		}catch(Exception e){ System.out.println("\n Error");}
		
		finally
		{
			System.out.println("\n Disconnecting Client  "+ID);
			
			try
			{
				socket.close();
			}
			catch(Exception e){ }
		}
	}
}


class Server2
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