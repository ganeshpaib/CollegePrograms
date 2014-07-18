import java.io.*;
import java.net.*;
import java.sql.*;

class StudServer
{
  Socket socket;
  InputStream is;
  OutputStream os;
  DataInputStream dis_socket;
  DataOutputStream dos_socket;
  DataInputStream dis;
 
 public void startServer() throws Exception
  {
    ServerSocket s = new ServerSocket(2000);
    System.out.println("\n\tSort Server is waiting on port 2000...");
    socket = s.accept();
    is = socket.getInputStream();
    os = socket.getOutputStream();
    dis_socket = new DataInputStream(is);
    dos_socket = new DataOutputStream(os);
    dispRecord();
  }

  public void dispRecord() throws Exception
 {

		Class.forName ("sun.jdbc.odbc.JdbcOdbcDriver");
		Connection conn;
		String url = "jdbc:odbc:nitin";
		String username = "";
		String password = "";
		conn = DriverManager.getConnection (url,username,password);
		Statement smnt = conn.createStatement ();
		dis = new DataInputStream(System.in);
		System.out.println();
		System.out.println ("*** Connected to the Database ***"); 
		int rollno,yoj,per;
		String name,branch;
		
		int roll = dis_socket.readInt();
		
		String sql1 = "select * from student where rollno="+roll;
 		ResultSet rs = smnt.executeQuery(sql1);
      		System.out.println("\n\n\tInformation of the Student is :\n");
      		while( rs.next() )
      		{
        			 
        			 name = rs.getString(1);
        			 rollno = rs.getInt(2);
			 branch = rs.getString(3);
			 yoj = rs.getInt(4);
			 per = rs.getInt(5);
		 	 System.out.println("\n\t*************************\n");
        		 	 
       			 System.out.print("\n\tName: " + name);
        		 	 System.out.print("\n\t:RollNo: "  + rollno);
        		 	 System.out.print("\n\tBranch: "  + branch);
			 System.out.print("\n\tYear Of Join: "  + yoj);
			 System.out.print("\n\tPercentage: "  + per);
      		}
		
	}
}

class StudentServer
{
  public static void main(String str[])
  {
    try
    {
      StudServer s = new StudServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}
  