import java.io.*;
import java.net.*;

class Server implements Runnable
{
	Socket socket;
	int ID,c,line=0,ch=0,di=0,sp=0,oc=0;
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
				fi=new FileInputStream(temp);
				System.out.println(" ");
				
				while((c=fi.read())!=-1)
				{
					if((c>=65 && c<=90) || (c>=97 && c<=122))
					{
						ch++;
					}
					else if(c>=48 && c<=56)
					{
						di++;
					}
					else if(c==' ')
					{
						sp++;
					}	
					else if(c=='\n')
					{
						line++;
					}
					else
					{
						oc++;
					}
					
					System.out.print((char)c);
				}
				
				System.out.println("\n Number Of Lines : "+line);
				System.out.println("\n Number Of Alphabets : "+ch);
				System.out.println("\n Number Of Digits : "+di);
				System.out.println("\n Number Of Spaces  : "+sp);
				System.out.println("\n Number Of Other Characters : "+oc);
				
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


class FileServer2
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