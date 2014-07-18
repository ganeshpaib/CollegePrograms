import java.io.*;
import java.net.*;
import java.sql.*;

class ItmServer
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
		int itemno,stk,flag,utp;
		String itemname;
		
		int itno = dis_socket.readInt();
		System.out.println("Item No from client side is: "+ itno);
		int qty = dis_socket.readInt();
		System.out.println("Quantity from client side is: "+ qty);

		String sql1 = "select * from item where itemno="+itno;
 		ResultSet rs = smnt.executeQuery(sql1);
		String msg = new String();
		flag=0;
      		
		if( rs.next() )
      		{
			 flag=1;
		
        		 itemname = rs.getString(1);
        		 itemno = rs.getInt(2);
			 stk = rs.getInt(3);
			 utp = rs.getInt(4);
			 if(stk>=qty)
			 {
			    int tot = qty*utp;
			    String sql="UPDATE item SET stock="+(stk-qty)+" WHERE itemno="+itno+";";
			try{
				smnt.executeUpdate(sql);
			   } 
			   catch(Exception e){ System.out.println();}
			try{
				smnt.executeUpdate("commit;");
                           } 
			   catch(Exception e){ System.out.println();}
		 	 
			 System.out.println("\n\t***********BILL**************\n");
        		 	 
       			 System.out.print("\n\tItem Name: " + itemname);
        		 System.out.print("\n\t:Item No: "  + itemno);
        		 System.out.print("\n\tQuantity: "  + qty);
			 System.out.print("\n\tUnit Price: "  + utp);
			 System.out.print("\n\tTotal Price: " +tot);
			 }
			 else
				System.out.println();
				System.out.println("Stock In hand is: " + stk);
				System.out.println("Quantity is not Enough...!!!");
      		}
		if(flag==0)
		dos_socket.writeBytes("no\n");
		else
		dos_socket.writeBytes("yes\n");
		
	}
}

class ItemServer
{
  public static void main(String str[])
  {
    try
    {
      ItmServer s = new ItmServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}
  