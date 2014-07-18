import java.io.*;
import java.sql.*;
import java.net.*;

class ItmClient
{
	Socket socket;
	InputStream is;
	OutputStream os;
	DataInputStream dis_socket;
	DataOutputStream dos_socket;
	DataInputStream dis;
	int itemno,qty;

	ItmClient() throws Exception
	{
		InetAddress addr = InetAddress.getByName("localhost");
		socket = new Socket(addr,2000);
		os = socket.getOutputStream();
		is = socket.getInputStream();
		dos_socket = new DataOutputStream(os);
		dis_socket = new DataInputStream(is);
		dis = new DataInputStream(System.in);
		System.out.println("Enter the Item No & Quantity to Get the Bill Information: ");
		itemno = Integer.parseInt(dis.readLine());
		dos_socket.writeInt(itemno);
		qty = Integer.parseInt(dis.readLine());
		dos_socket.writeInt(qty);
		String msg = new String();
		msg = dis_socket.readLine().trim();
		if(msg.equals("no"))
		System.out.println("Record Not Found....!!!");
		
	}

}
	class ItemClient
	{
		public static void main(String args[])
		{
			try
			{
				ItmClient c = new ItmClient();
			}
			catch(Exception e)
			{}
		}
	}
		
			