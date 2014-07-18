import java.net.*;
import java.io.*;
import java.util.*;
import java.sql.*;

class Server implements Runnable
{
	
	DataInputStream keyboard;
	DataInputStream dis;
	DataOutputStream dos;
	static Vector<Socket>client;
	static Hashtable<Socket,String>playerset1,playerset2,clientset;
	int thread,hello,status,flag,index,set;
	String name, ipclient;
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
		System.out.println("\t\t\tLIMEWIRE SERVER ");
		System.out.println("----------------------------------------------------------------------------");

		while(true)
		{
			s=server.accept();
			client.addElement(s);
			System.out.println("\n\n----------------------------------------------------------------------------");
			System.out.println("Client connected ..\nIndex : "+client.indexOf(s));
			Server newclient = new Server(s);
			
			
				new Thread(newclient).start();
		}
	}
	
	public void run()
	{
		try
		{
				dis=new DataInputStream(s.getInputStream());
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection conn;
				String url="jdbc:odbc:proj";
				conn=DriverManager.getConnection(url,"","");
				Statement smnt=conn.createStatement();
				System.out.println( "Connected to the database");
				
							
			
				name=dis.readLine();
				ipclient=dis.readLine();
				
				System.out.println("Client Name :"+name);
				
				System.out.println("Client Address :"+ipclient);
				clientset.put(s,name);
				
				int n=dis.readInt();
				String[] sql=new String[n];
				System.out.println("Number of files present in the directory : "+ n);
				String file;
				
				
				System.out.println("File Names : " ); 
				int i;
				for( i=0;i<n;i++)
				{
					file=dis.readLine();
					System.out.println(file);
					
					 sql[i]="insert into client values('" + name + "','" + ipclient + "','" +file+"');";
					smnt.executeUpdate(sql[i]);
					//smnt.executeQuery("commit");
					System.out.println("insert into client values('" + name + "','" + ipclient + "','" +file+"')");
				}
				//conn.close();
				
				String search=dis.readLine();
				//if(!(search.equals("exiting")))
					System.out.println(search);
				
				
				System.out.println("----------------------------------------------------------------------------");
				String msg=dis.readLine();
				String sq;
				sq="delete from client where name='"+name+"';";
				smnt.executeUpdate(sq);
				System.out.println("delete from client where name='"+name+"';");
				
				System.out.println("\n\n\n----------------------------------------------------------------------------");
				System.out.println(name +" "+ msg);
				System.out.println("----------------------------------------------------------------------------");
				conn.close();
				
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