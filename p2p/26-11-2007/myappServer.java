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
	int thread,hello,status,flag,index,set, count;
	String name, ipclient,SearchName, SearchIpclient, SearchFile, SearchPort,fileLength, SearchFileLength;
	Socket s;
	//String[] nm, ipcl, fl;
	DataOutputStream dos_sock, dos_port;
	int tmpportno=3000;
	int portno;
	
	Server()
	{
		client=new Vector<Socket>(5,2);
		clientset=new Hashtable<Socket,String>();
		
	}
	Server(Socket s1,int tmpportno)
	{
		s=s1;
		portno=tmpportno;
		
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
			tmpportno+=client.indexOf(s);
			
			Server newclient = new Server(s,tmpportno);
			
			
			new Thread(newclient).start();
		}
	}
	
	public void run()
	{
		try
		{
				int opt;
				
				dis=new DataInputStream(s.getInputStream());
				dos_port=new DataOutputStream(s.getOutputStream());
				
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection conn;
				String url="jdbc:odbc:project";
				conn=DriverManager.getConnection(url,"","");
				Statement smnt=conn.createStatement();
				System.out.println( "Connected to the database");
				
							
				
				name=dis.readLine();
				ipclient=dis.readLine();
				System.out.println("Client port... : "+portno);
				dos_port.writeInt(portno);
				
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
					fileLength=dis.readLine();
					
					file=file.trim();
					file=file.toLowerCase();
					System.out.println(file);
					System.out.println("FILE LENGTH = "+fileLength+ " bytes");
					 sql[i]="insert into client1 values('" + name + "','" + ipclient + "','" +file+ "','" + fileLength + "','" +portno+ "');";
					smnt.executeUpdate(sql[i]);
					//smnt.executeQuery("commit");
					System.out.println("insert into client1 values('" + name + "','" + ipclient + "','" +file+ "','" +fileLength+"','"+ +portno+ "');");
				}
				
				
				
				do
				{
					opt=dis.readInt();
					
					switch(opt)
					{
						case 1:		
								int flg=0;
								count=0;	
								String[] nm=new String[100];
								String[] ipcl=new String[100];
								String[] fl=new String[100];
								String[] flLen=new String[100];
								String[] port=new String[100];
									
								String msgClient=dis.readLine();
								String search=dis.readLine();
								//String fsearchtype=dis.readLine();
								
								search=search.trim();
								System.out.println("\n"+msgClient);
								System.out.println(search);
								String sqlSearch="select * from client1 where file='"+search+"';";
								ResultSet rs=smnt.executeQuery(sqlSearch);
								
								while(rs.next())
								{
									flg=1;
									SearchName=rs.getString(1);
								
									SearchIpclient=rs.getString(2);
									
									SearchFile=rs.getString(3);
									SearchFileLength=rs.getString(4);
									SearchPort=rs.getString(5);
									
									
									System.out.println("\n\nFILE FOUND.....");
									System.out.println("CLIENT NAME : "+SearchName);
									System.out.println("CLIENT  IP ADDRESS: "+SearchIpclient);
									System.out.println("FILE NAME : "+SearchFile);
									nm[count]=SearchName;
									ipcl[count]=SearchIpclient;
									fl[count]=SearchFile;
									flLen[count]=SearchFileLength;
									port[count]=SearchPort;
									
									count++;
									
									
								}
								
								
								dos_sock=new DataOutputStream(s.getOutputStream());
								rs.close();
								
								//dos_sock.writeInt()
								
															
									flg=2;
									char c=search.charAt(0);
									//System.out.println("CHAR ...: "+c);
									
									String sqlSearchAgain="select * from client1 where file LIKE'"+c+"%';";
									System.out.println("\n\nFILE NOT FOUND!!!!!!!!!!");
									System.out.println("\n RANGE SEARCHING......" );
									
											ResultSet rs1=smnt.executeQuery(sqlSearchAgain);
								
											while(rs1.next())
											{
												flg=3;
												SearchName=rs1.getString(1);
								
												SearchIpclient=rs1.getString(2);
												
												SearchFile=rs1.getString(3);
												SearchFileLength=rs1.getString(4);
												SearchPort=rs1.getString(5);
												
												
												System.out.println("\n\nFILE FOUND.....");
												System.out.println("CLIENT NAME : "+SearchName);
												System.out.println("CLIENT  IP ADDRESS: "+SearchIpclient);
												System.out.println("FILE NAME : "+SearchFile);
												nm[count]=SearchName;
												ipcl[count]=SearchIpclient;
												fl[count]=SearchFile;
												flLen[count]=SearchFileLength;
												port[count]=SearchPort;
												
												count++;
											}
											rs1.close();
								
								if(count>0)
									dos_sock.writeInt(count);
								else
									dos_sock.writeInt(0);
								
								for( i=0;i<count;i++)
								{
									dos_sock.writeBytes(nm[i]+"\n");
									dos_sock.writeBytes(ipcl[i]+"\n");
									dos_sock.writeBytes(fl[i]+"\n");
									dos_sock.writeBytes(flLen[i]+"\n");
									dos_sock.writeBytes(port[i]+"\n");
								}
									
								//String filetransfermsg=dis.readLine();
								//System.out.println(filetransfermsg);
								break;
								
						case 2:					
								System.out.println("----------------------------------------------------------------------------");
							String msg=dis.readLine();
							String sq;
							sq="delete from client1 where ipclient='"+ipclient+"';";
							smnt.executeUpdate(sq);
							System.out.println("delete from client1 where name='"+ipclient+"';");
						
							System.out.println("\n\n\n----------------------------------------------------------------------------");
							System.out.println(name + "   "+ipclient +" "+ msg);
							System.out.println("----------------------------------------------------------------------------");
							
							break;
							
						case 3: System.out.println("FILE TRANSFERRED\n");
								String flnm=dis.readLine();
								String flsize=(dis.readLine());
							
								
								String sqll="insert into client1 values('" + name + "','" + ipclient + "','" +flnm+ "','" + flsize + "','" +portno+ "');";
								System.out.println("insert into client1 values('" + name + "','" + ipclient + "','" +flnm+ "','" + flsize + "','" +portno+ "');");
								smnt.executeUpdate(sqll);
								
								break;
					}
					
					
				}while(opt!=2);
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