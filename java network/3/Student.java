import java.sql.*;
import java.io.*;
import java.net.*;

public class Student
{
	static int ch;
	static Connection con;
	
	
	public static void main(String arg[])
	{
		String name,branch;
		int roll,yoj,per;
		PreparedStatement pst;
		Statement st;
		ResultSet rs;
		
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		
		do
		{
			try
			{
			
			System.out.println("1. Insert");
			System.out.println("2. Display");
			System.out.println("3. Delete");
			System.out.println("4. Update");
			System.out.println("99.Exit");
			System.out.print("\n Enter Your Choice : ");
			ch=Integer.parseInt(bf.readLine());
					
			
			switch(ch)
			{
				case 1:
						try
						{
							System.out.print("\n Enter Student Name : ");
							name=bf.readLine();
							System.out.print("\n Enter Student Roll Number :");
							roll=Integer.parseInt(bf.readLine());
							System.out.print("\n Enter Student Branch : ");
							branch=bf.readLine();
							System.out.print("\n Enter Student Yoj :");
							yoj=Integer.parseInt(bf.readLine());
							System.out.print("\n Enter Student Percentage :");
							per=Integer.parseInt(bf.readLine());
									
							Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
							con=DriverManager.getConnection("jdbc:odbc:pp","","");
							pst=con.prepareStatement("insert into Student(Student_Name,Student_Roll,Student_Branch,Student_Yoj,Student_Per) values(?,?,?,?,?)");
							
							pst.setString(1,name);
							pst.setInt(2,roll);
							pst.setString(3,branch);
							pst.setInt(4,yoj);
							pst.setInt(5,per);
			
							int ctr=pst.executeUpdate();
			
			
							System.out.println("\n One Record Added"+ctr);
				
						}catch(Exception e){}
						break;
				
				case 2:
					try
					{
						System.out.println("\n\n");
		
						st=con.createStatement();
						rs=st.executeQuery("Select * from Student");
						
		
						while(rs.next())
						{	
							System.out.println(rs.getString(1)+"\t"+rs.getInt(2)+"\t"+rs.getString(3)+"\t"+rs.getInt(4)+"\t"+rs.getInt(5));
						}
		
					}catch(Exception e){System.out.println(e.getMessage()); }
					break;
				
			 	case 3:
			 			try
			 			{
			 				System.out.print("\n Enter Roll Number : ");
			 				int r=Integer.parseInt(bf.readLine());
			 				st=con.createStatement();
			 				//pst=con.prepareStatement("delete Student where Student_Roll=?");
			 				//pst.setInt(2,r);
			 				st.executeUpdate("delete student where Student_Roll=r");
			 				
			 				System.out.println("One Record Deleted.....");
			 				
			 			}catch(Exception e){System.out.println(e.getMessage());}
			 			break;
				
				}
				}catch(Exception e){}
			}while(ch!=99);
		}
	}