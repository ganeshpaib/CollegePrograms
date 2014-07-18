import java.io.*;
import java.sql.*;
import java.net.*;
class ConnectionTest
{
	public static void main(String str[])
	{
		try{
			String url="jdbc:odbc:sambitdb";
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection conn=DriverManager.getConnection(url);

		}catch(Exception e){
			System.out.println("Unable to establish connection...");}
		
		System.out.println("Connection established successfully..");
	}
}