import java.io.*;
import java.sql.*;
import java.net.*;

class Server
{
	InputStream is;
	DataInputStream dis;
	Connection con;
	PreparedStatement pst;
	ResultSet rs;
	ServerSocket s;
	Socket socket;
	String dg;
	
	public void startserver() throws Exception
	{
		s=new ServerSocket(2000);
		socket=s.accept();
		
		is=socket.getInputStream();
		dis=new DataInputStream(is);
		
		dg=dis.readLine();
		
		try
		{

		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		con=DriverManager.getConnection("jdbc:odbc:staffdb");
		pst=con.prepareStatement("select * from staff where degn=?");
		pst.setString(1,dg);
		rs=pst.executeQuery();
		
		while(rs.next())
		{
			System.out.println(rs.getString(1)+"\t"+rs.getInt(2)+"\t"+rs.getString(3)+"\t"+rs.getString(4));
		}
		}catch(Exception e){System.out.println(e.getMessage());}
		

	}
}

public class StaffServer
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



		
		
	