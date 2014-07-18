import java.net.*;
import java.sql.*;
import java.io.*;

public class Student
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
		int  num,count,roll,mark,syoj;
		String sname,sbranch;
		url="jdbc:odbc:studentdb";
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		conn=DriverManager.getConnection(url);
		st=conn.createStatement();			
		while(true)
		{	
			
			System.out.println("Enter 1 for insert a student info: ");
			System.out.println("Enter 2 for display the student infO: ");
			System.out.println("Enter 3 for delete the student info: ");
			System.out.println("Enter 4 for update the student ino: ");
			System.out.println("Enter 5 for exit: ");
			
			System.out.println("Enter the number :: ");
			dis=new DataInputStream(System.in);
			num=Integer.parseInt(dis.readLine());

			switch(num)
			{
				case 1:	System.out.println("one");
			
					System.out.println("Enter the student id");
					roll=Integer.parseInt(dis.readLine());	
				
					System.out.println("Enter the name...");
					sname=dis.readLine();
		
					System.out.println("Enter the student branch");
					sbranch=dis.readLine();
					
					System.out.println("Enter the student year of joining..");
					syoj=Integer.parseInt(dis.readLine());
				
					System.out.println("Enter the markpercentage..");	
					mark=Integer.parseInt(dis.readLine());

					sql="insert into student(sid,name,branch,yoj,markper) values("+roll+",'"+sname+"','"+sbranch+"',"+syoj+","+mark+")";
				
					count=st.executeUpdate(sql);
					System.out.println("No of record affected..."+count);
					break;

				case 2:System.out.println("two");
						
					sql="select * from student";
					rs=st.executeQuery(sql);
				
					System.out.println("The student info are displayed...");				
					while(rs.next())
					{
						roll=rs.getInt(1);
						sname=rs.getString(2);
						sbranch=rs.getString(3);
						syoj=rs.getInt(4);
						mark=rs.getInt(5);

						System.out.println("student id: "+roll);
						System.out.println("student name: "+sname);
						System.out.println("student branch: "+sbranch);
						System.out.println("student year of joining: "+syoj);
						System.out.println("student mark percentage: "+mark);
						System.out.println();
					}	
					break;
				case 3:System.out.println("Enter the roll of student u want to delete...");
					roll=Integer.parseInt(dis.readLine());
					
					sql="delete * from student  where sid="+roll;
					count=st.executeUpdate(sql); 	
					System.out.println("No of record affected..."+count);
					break;

				case 4:System.out.println("three");	
					
					System.out.println("Enter the roll.");
					roll=Integer.parseInt(dis.readLine());
					System.out.println("Enter the mark percentage...");
					mark=Integer.parseInt(dis.readLine());
					
				        sql="update student set markper="+mark+" where sid="+roll;
					count=st.executeUpdate(sql);
					System.out.println("No of record affected..."+count);
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