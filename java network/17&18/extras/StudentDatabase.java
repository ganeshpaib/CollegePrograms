import java.io.*;
import java.net.*;
import java.sql.*;

class StudentDatabase
{
	public static void main(String args[]) throws Exception
	{
		DataInputStream dis = new DataInputStream(System.in);
		
		Class.forName ("sun.jdbc.odbc.JdbcOdbcDriver");

		Connection conn;
		String url = "jdbc:odbc:nitin";
		String username = "";
		String password = "";
		conn = DriverManager.getConnection (url,username,password);
		Statement smnt = conn.createStatement ();
	
		
		System.out.println ("*** Connected to the database ***"); 
		int c;
		do
		{
		System.out.println();
		System.out.println("\nEnter the Choice You Want to Perform: ");
		System.out.println("\t 1. Insert Record");
		System.out.println("\t 2. Delete Record");
		System.out.println("\t 3. Update Record");
		System.out.println("\t 4. Display Record");
		System.out.println("\t 5. Exit");
		System.out.print("-->");
		c = Integer.parseInt(dis.readLine());
		int roll,rollno,yoj,per;
		String name,branch;
			switch(c)
			{
				case 1: System.out.println();
					System.out.print("Enter the Student Name: ");
					name = dis.readLine();
					System.out.println("Enter the RollNo: ");
					rollno = Integer.parseInt(dis.readLine());
					System.out.println("Enter the Branch: ");
					branch = dis.readLine();
					System.out.println("Enter the Year Of Join: ");
					yoj = Integer.parseInt(dis.readLine());
					System.out.println("Enter the Percentage: ");
					per = Integer.parseInt(dis.readLine());
					String sql = "insert into student values ('" + name + "'," + rollno + ", '" + branch + "'," + yoj + "," + per + ")";
					smnt.executeUpdate(sql);	
					try
					{
						smnt.executeQuery("commit");
					}
					catch(Exception e)
					{}
					break;
				case 4: String sql1 = "select * from student";
 					ResultSet rs = smnt.executeQuery(sql1);
      					System.out.println("\n\n\tContents of the Student table:\n");
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
					break;
				case 2: System.out.print("Enter the RollNo to Delete: ");
		    			roll=Integer.parseInt(dis.readLine());
		    			String sql2="delete from student where rollno="+roll;
		    			smnt.executeUpdate(sql2);
					try
					{
		     				smnt.executeQuery("commit");
					}
					catch(Exception e)
					{}
    					System.out.println("\n\n\tSuccessfully executed the SQL query...");
					break;
				case 3: System.out.print("Enter the RollNo to Update: ");
		     			roll=Integer.parseInt(dis.readLine());
		    	 		System.out.println("Enter the Name: ");
		    			name=dis.readLine();
		     			System.out.println("Enter the Branch: ");
		     			branch=dis.readLine();
		     			System.out.println("Enter the Year of joining: ");
		     			yoj=Integer.parseInt(dis.readLine());
		     			System.out.println("Enter the Percentage: ");
		     			per=Integer.parseInt(dis.readLine());
		     			String sql3="update student set name='"+name+"',branch='"+branch+"',yoj="+yoj+",per="+per+" where rollno="+roll+";";
		     			System.out.println(sql3);
		     			smnt.executeUpdate(sql3);
					try
					{
		     				smnt.executeQuery("commit");
					}
					catch(Exception e)
					{}
					break;
				case 5: conn.close();
					//exit(1);
					break;
		    }
	}while(c!=5);
     }	
}