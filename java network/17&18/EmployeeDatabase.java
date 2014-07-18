import java.io.*;
import java.net.*;
import java.sql.*;

class EmployeeDatabase
{
	public static void main(String args[]) throws Exception
	{
		DataInputStream dis = new DataInputStream(System.in);
		
		Class.forName ("sun.jdbc.odbc.JdbcOdbcDriver");

		Connection conn;
		String url = "jdbc:odbc:sunil";
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
		int empno,bpay;
		String grade,name,dept;
			switch(c)
			{
				case 1: System.out.println();
					System.out.print("Enter the Employee Name: ");
					name = dis.readLine();
					System.out.println("Enter the Employee No: ");
					empno = Integer.parseInt(dis.readLine());
					System.out.println("Enter the Department: ");
					dept = dis.readLine();
					System.out.println("Enter the Grade: ");
					grade = dis.readLine();
					System.out.println("Enter the Basic Pay: ");
					bpay = Integer.parseInt(dis.readLine());
					System.out.println("insert into emp values ('" + name + "'," + empno + ", '" + dept + "','" + grade + "'," + bpay + ")");

					String sql = "insert into emp values ('" + name + "'," + empno + ", '" + dept + "','" + grade + "'," + bpay + ")";
					smnt.executeUpdate(sql);	
					try
					{
						smnt.executeQuery("commit");
					}
					catch(Exception e)
					{}
					break;
				case 4: String sql1 = "select * from emp";
 					ResultSet rs = smnt.executeQuery(sql1);
      					System.out.println("\n\n\tContents of the Employee table:\n");
      					while( rs.next() )
      					{
        	
        						name = rs.getString(1);
        						empno = rs.getInt(2);
						dept = rs.getString(3);
						grade = rs.getString(4);
						bpay = rs.getInt(5);
						System.out.println("\n\t*************************\n");
           					System.out.print("\n\tName: " + name);
        					System.out.print("\n\t:Eployee No: "  + empno);
        					System.out.print("\n\tDept: "  + dept);
						System.out.print("\n\tGrade: "  + grade);
						System.out.print("\n\tPercentage: "  + bpay);
      					}
					break;
				case 2: System.out.print("Enter the Employee No to Delete: ");
		    			empno=Integer.parseInt(dis.readLine());
		    			String sql2="delete from emp where empno="+empno;
		    			smnt.executeUpdate(sql2);
					try
					{
		     				smnt.executeQuery("commit");
					}
					catch(Exception e)
					{}
    					System.out.println("\n\n\tSuccessfully executed the SQL query...");
					break;
				case 3: System.out.print("Enter the Employee No to Update: ");
		     			empno=Integer.parseInt(dis.readLine());
		    	 		System.out.println("Enter the Name: ");
		    			name=dis.readLine();
		     			System.out.println("Enter the Dept: ");
		     			dept=dis.readLine();
		     			System.out.println("Enter the Grade: ");
		     			grade=(dis.readLine());
		     			System.out.println("Enter the bpay: ");
		     			bpay=Integer.parseInt(dis.readLine());
		     			String sql3="update emp set name='"+name+"',dept='"+dept+"',grade="+grade+",bpay="+bpay+" where empno="+empno+";";
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