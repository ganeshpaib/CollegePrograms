import java.io.*;
import java.net.*;

class Server implements Runnable
{
	Socket socket;
	int ID,c;
	Thread t;
	FileInputStream fi;

	Server() { }
	
	Server(Socket socket)
	{
		this.socket=socket;
	}
	
	public void StartServer() throws Exception
	{
		System.out.println("\n\n Server Running and Waiting for Client");
		ServerSocket s=new ServerSocket(2000);
				
		socket=s.accept();
		Server server=new Server(socket);
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
				//System.out.println(temp);
				fi=new FileInputStream(temp);
				
				while((c=fi.read())!=-1)
				{
					System.out.print((char)c);
				}
				
				if(temp.equals("stop")) break;
			}
		}catch(Exception e){ System.out.println("\n Error");}
		
		finally
		{
			System.out.println("\n Disconnecting Client ");
			
			try
			{
				socket.close();
			}
			catch(Exception e){ }
		}
	}
}


class FileServer1
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