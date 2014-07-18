import java.io.*;
import java.net.*;

class SortServer
{
  Socket socket;
  InputStream is;
  OutputStream os;
  DataInputStream dis_socket;
  DataOutputStream dos_socket;

  public void startServer() throws Exception
  {
    ServerSocket s = new ServerSocket(2000);
    System.out.println("\n\tSort Server is waiting on port 2000...");
    socket = s.accept();
    is = socket.getInputStream();
    os = socket.getOutputStream();
    dis_socket = new DataInputStream(is);
    dos_socket = new DataOutputStream(os);
    sortElements();
  }

  public void sortElements()
  {
    int temp;
    try
    {
      int size = dis_socket.readInt();
      System.out.println("\n\tSize of the array: " + size);
      int array[] = new int[size];
      System.out.println("\n\n\tThe values are: ");
     for(int i=0;i<size;i++)
     {
       array[i] = dis_socket.readInt();
	System.out.println(""+array[i]);
     }
      for(int i=0; i<size; i++)
      {
        for(int j=i+1;j<=size-1;j++)
        {
	if(array[i]>array[j])
	{
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
	}
        }
      }
for(int i=0;i<size;i++)
{
      dos_socket.writeInt(array[i]);
}
    }
    catch(Exception e)
    {}
  }
}

class SortIntegerServer
{
  public static void main(String str[])
  {
    try
    {
      SortServer s = new SortServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}
  