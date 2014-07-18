import java.io.*;
import java.sql.*;
import java.net.*;
class DisplayDatabaseData
{
	public static void main(String str[])
	{
		try{
			String url="jdbc:odbc:sambitdb";
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection conn=DriverManager.getConnection(url);
			
			String sql="select * from employee";
			Statement st=conn.createStatement();
			ResultSet rs=st.executeQuery(sql);

				
			System.out.println("Content of table...");

			while(rs.next())
			{
				int empid=rs.getInt(1);
				String name=rs.getString(2);
				String add=rs.getString(3);
				
				System.out.println("EMP ID : "+empid);
				System.out.println("EMP NAME : "+name);
				System.out.println("EMP CITY : "+add);
			}			

		}catch(Exception e){
			System.out.println("Unable to establish connection...");}
		
		System.out.println("Connection established successfully..");
	}
}