import java.io.*;
import java.net.*;
import java.sql.*;

class stserver 
{
	Socket s;
	DataInputStream dis;
	
	stserver()throws Exception
	{
		ServerSocket ss=new ServerSocket(2007);
		System.out.println("server is running");
		s=ss.accept();
		dis=new DataInputStream(s.getInputStream());
		Class.forName ("sun.jdbc.odbc.JdbcOdbcDriver");
		String url = "jdbc:odbc:bksource";
		String username = "";
		String password = "";
		Connection conn = DriverManager.getConnection (url,username,password);
		Statement st = conn.createStatement ();
		System.out.println("connected to database");
		String name=dis.readLine();
		name=name.trim();
		String stmt="Select * from book";
		ResultSet rs=st.executeQuery(stmt);
		
		while(rs.next())
		{
			String author=rs.getString(2);
			if(author.equals(name))
			{
				System.out.println("AUTHOR = "+author+"   TITLE = "+rs.getString(1)+"   PUBLISHER = "+rs.getString(5)+"   PAGES = "+rs.getInt(4)+"   ACCESS = "+rs.getInt(3));
			}
		}
	}
}
class runst
{
	public static void main(String arg[])
	{
		try
		{
			new stserver();
		}
		catch(Exception e){System.out.println("connection error "+e);}
	}
}