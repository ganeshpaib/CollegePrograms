import java.io.*;
import java.sql.*;
import java.net.*;

class StudClient
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_socket;
	DataOutputStream dos_socket;
	DataInputStream dis;

	StudClient() throws Exception
	{
		InetAddress addr = InetAddress.getByName("localhost");
		socket = new Socket(addr,2000);
		os = socket.getOutputStream();
		is = socket.getInputStream();
		dos_socket = new DataOutputStream(os);
		dis_socket = new DataInputStream(is);
		dis = new DataInputStream(System.in);
		System.out.println("Enter the RollNo to Get the Information: ");
		int roll = Integer.parseInt(dis.readLine());
		dos_socket.writeInt(roll);
	}

}
	class StudentClient
	{
		public static void main(String args[])
		{
			try
			{
				StudClient c = new StudClient();
			}
			catch(Exception e)
			{}
		}
	}
		
			