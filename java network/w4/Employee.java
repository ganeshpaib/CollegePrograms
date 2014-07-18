import java.net.*;
import java.sql.*;
import java.io.*;

public class Employee
{
	public static void main(String str[])
	{
		try
		{
		
		DataInputStream dis;
		ResultSet rs;
		String sql,url;
		Connection conn;
		Statement st;
		int  num,count,oldid,newid,eid,ebasic;
		String ename,edeptname,egrade;

		url="jdbc:odbc:employeedb";
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		conn=DriverManager.getConnection(url);
		st=conn.createStatement();			
		while(true)
		{	
			
			System.out.println("Enter 1 for insert a employee info: ");
			System.out.println("Enter 2 for delete the employee info: ");
			System.out.println("Enter 3 for update the employee ino: ");
			System.out.println("Enter 4 for display the employee infO: ");

			System.out.println("Enter 5 for exit: ");
			
			System.out.println("Enter the number :: ");
			dis=new DataInputStream(System.in);
			num=Integer.parseInt(dis.readLine());

			switch(num)
			{
				case 1:	System.out.println("one");
			
					System.out.println("Enter the emp id");
					eid=Integer.parseInt(dis.readLine());	
						
					System.out.println("Enter the empname...");
					ename=dis.readLine();
		
					System.out.println("Enter the  deptname");
					edeptname=dis.readLine();

					System.out.println("Enter the  employee grade");
					egrade=dis.readLine();
					
					System.out.println("Enter the emloyee basic");
					ebasic=Integer.parseInt(dis.readLine());	

					sql="insert into employee(empid,empname,deptname,grade,basicpay) values("+eid+",'"+ename+"','"+edeptname+"','"+egrade+"',"+ebasic+")";
				
					count=st.executeUpdate(sql);
					System.out.println("No of record affected..."+count);
					break;

				
				case 2:System.out.println("Enter the roll of employee u want to delete...");
					eid=Integer.parseInt(dis.readLine());
					
					sql="delete * from employee where empid="+eid;
					count=st.executeUpdate(sql); 	
					System.out.println("No of record affected..."+count);
					break;

				case 3:System.out.println("Enter the employee id..");
					oldid=Integer.parseInt(dis.readLine());
					System.out.println("Enter the  grade.......");
					egrade=dis.readLine();
					
				        sql="update employee set grade='"+egrade+"' where empid="+oldid;
					count=st.executeUpdate(sql);
					System.out.println("No of record affected..."+count);
					break;	
				case 4:System.out.println("four");
						
					sql="select * from Employee";
					rs=st.executeQuery(sql);
				
				
					while(rs.next())
					{
						 eid=rs.getInt(1);
						 ename=rs.getString(2);
						 edeptname=rs.getString(3);
						 egrade=rs.getString(4);
						 ebasic=rs.getInt(5);
							
						System.out.println("employee id : "+eid);
						System.out.println("employee name: "+ename);
						System.out.println("employee depertment: "+edeptname);
						System.out.println("employee grade: "+egrade);
						System.out.println("employee basicpay: "+ebasic );

					}	
					break;
				case 5:System.out.println("Exited...");
					System.exit(0);
					
			}
		}	
		}catch(Exception e)
		{
			System.out.println("error");
		}
	}
}