import java.io.*;
import java.net.*;

class SearchServer
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
    searchElements();
  }

  public void searchElements()
  {
    int temp,f=0;
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
	temp=dis_socket.readInt();
	System.out.println("The serach element is ..."+temp);
	
      for(int i=0; i<size; i++)
      {
        if(array[i]==temp)
	{
		f=1;break;
	}
	
      }

     	dos_socket.writeInt(f);

    }
    catch(Exception e)
    {}
  }
}

class SearchIntegerServer
{
  public static void main(String str[])
  {
    try
    {
      SearchServer s = new SearchServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}
  