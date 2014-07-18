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
	int roll;
	
	public void startserver() throws Exception
	{
		s=new ServerSocket(2000);
		socket=s.accept();
		
		is=socket.getInputStream();
		dis=new DataInputStream(is);
		
		roll=dis.readInt();
		
		try
		{

		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		con=DriverManager.getConnection("jdbc:odbc:sa");
		pst=con.prepareStatement("select * from Student where Student_Roll=?");
		pst.setInt(1,roll);
		rs=pst.executeQuery();
		
		while(rs.next())
		{
			System.out.println(rs.getString(1)+"\t"+rs.getInt(2)+"\t"+rs.getString(3)+"\t"+rs.getInt(4)+"\t"+rs.getInt(5));
		}
		}catch(Exception e){System.out.println(e.getMessage());}
		

	}
}

public class StudentServer
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



		
		
	