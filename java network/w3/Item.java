import java.net.*;
import java.sql.*;
import java.io.*;

public class Item
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
		int  num,count,sid,sstock,sunitprice,newstock;
		String sname;
		url="jdbc:odbc:Itemdb";
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		conn=DriverManager.getConnection(url);
		st=conn.createStatement();			
		while(true)
		{	
			
			System.out.println("Enter 1 for insert a item info: ");
			
			System.out.println("Enter 2 for update the item ino: ");
			System.out.println("Enter 3 for delete the item info: ");	
			System.out.println("Enter 2 for display the item infO: ");
			System.out.println("Enter 5 for exit: ");
			
			System.out.println("Enter the number :: ");
			dis=new DataInputStream(System.in);
			num=Integer.parseInt(dis.readLine());

			switch(num)
			{
				case 1:	System.out.println("one");
			
					System.out.println("Enter the item id");
					sid=Integer.parseInt(dis.readLine());	
				
					System.out.println("Enter the name...");
					sname=dis.readLine();
		
					System.out.println("Enter the item stock amount..");
					sstock=Integer.parseInt(dis.readLine());

					System.out.println("Enter the items unit price...");
					sunitprice=Integer.parseInt(dis.readLine());	

					sql="insert into Item(itemid,itemname,stock,unitprice) values("+sid+",'"+sname+"',"+sstock+","+sunitprice+")";
				
					count=st.executeUpdate(sql);
					System.out.println("No of record affected..."+count);
					break;				

				case 2:System.out.println("three");	
					
					System.out.println("Enter the item id..");
					sid=Integer.parseInt(dis.readLine());
					System.out.println("Enter the  new stock...");
					sstock=Integer.parseInt(dis.readLine());
					
				        sql="update Item set stock="+sstock+" where itemid="+sid;
					count=st.executeUpdate(sql);
					System.out.println("No of record affected..."+count);
					break;	
				case 3:System.out.println("Enter the item no u want to delete...");
					sid=Integer.parseInt(dis.readLine());
					
					sql="delete * from Item  where itemid="+sid;
					count=st.executeUpdate(sql); 	
					System.out.println("No of record affected..."+count);
					break;
				case 4:System.out.println("four");
						
					sql="select * from Item";
					rs=st.executeQuery(sql);
				
					System.out.println("The record of item are...");			
					while(rs.next())
					{
						sid=rs.getInt(1);
						sname=rs.getString(2);
						sstock=rs.getInt(3);
						sunitprice=rs.getInt(4);
	
						System.out.println("Item id : "+sid);
						System.out.println("Item name : "+sname);
						System.out.println("Item stock: "+sstock);	
						System.out.println("Item unitprice: "+sunitprice);
						System.out.println();
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