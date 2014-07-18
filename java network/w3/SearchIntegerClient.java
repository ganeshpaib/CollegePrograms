import java.io.*;
import java.net.*;

class SearchClient
{
  Socket socket;
  OutputStream os;
  InputStream is;
  DataOutputStream dos_socket;
  DataInputStream dis_socket;
  DataInputStream dis_key;

  SearchClient() throws Exception
  {
    InetAddress addr = InetAddress.getByName("localhost");
    socket = new Socket(addr,2000);
    os = socket.getOutputStream();
    is = socket.getInputStream();
    dos_socket = new DataOutputStream(os);
    dis_socket = new DataInputStream(is);
    dis_key = new DataInputStream(System.in);
    
    System.out.print("\n\tEnter the size of the array: " );
    int size = Integer.parseInt(dis_key.readLine());
    dos_socket.writeInt(size);
    
    int array[] = new int[size]; 
    int f;   
    System.out.println("\n\n\tEnter the array elements...");
    for(int i=0; i<size; i++)
    {
      array[i] = Integer.parseInt(dis_key.readLine());
      dos_socket.writeInt(array[i]);
    }
	
    System.out.println("Enter the searching elment...");
    int ser=Integer.parseInt(dis_key.readLine());	
	dos_socket.writeInt(ser);

    System.out.println("The search element is send to server..");
	ser=dis_socket.readInt();	
	if(ser==0)
		System.out.println("The search element is not found...");
	else
		System.out.println("The serch element is found..");		
    	
   }

}

class SearchIntegerClient
{
  public static void main(String str[])
  {
    try
    {
      SearchClient c = new SearchClient();
    }
    catch(Exception e)
    {}
  }
}