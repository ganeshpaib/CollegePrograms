import java.io.*;
import java.sql.*;
import java.net.*;

class EmpClient
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_socket;
	DataOutputStream dos_socket;
	DataInputStream dis;

	EmpClient() throws Exception
	{
		InetAddress addr = InetAddress.getByName("localhost");
		socket = new Socket(addr,2000);
		os = socket.getOutputStream();
		is = socket.getInputStream();
		dos_socket = new DataOutputStream(os);
		dis_socket = new DataInputStream(is);
		dis = new DataInputStream(System.in);
		System.out.println("Enter the Department Name to Get the Information: ");
		String dept = dis.readLine();
		dos_socket.writeBytes(dept+"\n");
		String msg = new String();
		msg = dis_socket.readLine().trim();
		if(msg.equals("no"))
		System.out.println("Record Not Found....!!!");
		
	}

}
	class EmployeeClient
	{
		public static void main(String args[])
		{
			try
			{
				EmpClient e = new EmpClient();
			}
			catch(Exception e)
			{}
		}
	}
		
			