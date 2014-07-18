import java.io.*;
import java.net.*;

class SortClient
{
  Socket socket;
  OutputStream os;
  InputStream is;
  DataOutputStream dos_socket;
  DataInputStream dis_socket;
  DataInputStream dis_key;

  SortClient() throws Exception
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
    int arr[]=new int[size];   
    System.out.println("\n\n\tEnter the array elements...");
    for(int i=0; i<size; i++)
    {
      array[i] = Integer.parseInt(dis_key.readLine());
      dos_socket.writeInt(array[i]);
    }

    System.out.println(" the Sorted Array Is " );
    for(int i=0; i<size; i++)
    {
	arr[i]=dis_socket.readInt();	
	System.out.println(arr[i]);	
    }	
}
}

class SortIntegerClient
{
  public static void main(String str[])
  {
    try
    {
      SortClient c = new SortClient();
    }
    catch(Exception e)
    {}
  }
}