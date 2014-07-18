import java.io.*;
import java.net.*;
import java.sql.*;

class EmpServer
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
		String url = "jdbc:odbc:ganesh";
		String username = "";
		String password = "";
		conn = DriverManager.getConnection (url,username,password);
		Statement smnt = conn.createStatement ();
		dis = new DataInputStream(System.in);
		System.out.println();
		System.out.println ("*** Connected to the Database ***"); 
		int empno,basic,flag;
		String empname,dept,grade;
		
		String dname = dis_socket.readLine().trim();
		System.out.println("Department Name: "+dname);
		
		String sql1 = "select * from emp where dept='"+dname+"';";
 		ResultSet rs = smnt.executeQuery(sql1);
		String msg = new String();
		flag=0;
      		//System.out.println("\n\n\t Information of the Student is :\n");
		while( rs.next() )
      		{
			 flag=1;
        		 empname = rs.getString(1);
        		 empno = rs.getInt(2);
			 dept = rs.getString(3);
			 grade = rs.getString(4);
			 basic = rs.getInt(5);
		 	 System.out.println("\n\t*************************\n");
        		 	 
       			 System.out.print("\n\tName: " + empname);
        		 System.out.print("\n\t:Employee No: "  + empno);
        		 System.out.print("\n\tDepartment: "  + dept);
			 System.out.print("\n\tGrade: "  + grade);
			 System.out.print("\n\tBasic Pay: "  + basic);
      		}
		if(flag==0)
		dos_socket.writeBytes("no\n");
		else
		dos_socket.writeBytes("yes\n");
		
	}
}

class EmployeeServer
{
  public static void main(String str[])
  {
    try
    {
      EmpServer e = new EmpServer();
      e.startServer();
    }
    catch(Exception e)
    {}
  }
}
  