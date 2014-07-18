import java.io.*;
import java.net.*;

class ReverseClient
{
  Socket socket;
  OutputStream os;
  InputStream is;
  DataOutputStream dos_socket;
  DataInputStream dis_socket;
  DataInputStream dis;
  InputStreamReader isr;
  BufferedReader br;

  ReverseClient() throws Exception
  {
    InetAddress addr = InetAddress.getByName("localhost");
    socket = new Socket(addr,2000);
    os = socket.getOutputStream();
    is = socket.getInputStream();
    dos_socket = new DataOutputStream(os);
    dis_socket = new DataInputStream(is);
    dis = new DataInputStream(System.in);
 
    while( true )
      {
        
	System.out.print("\n\tEnter a String: ");
                   String str = dis.readLine();        
	dos_socket.writeBytes(str);
	dos_socket.writeChar('\n');
	if(str.equals("stop"))
                   break;
	
	str=dis_socket.readLine();
                   System.out.println("\n\tReversed String from Server :"+ str);
      }	
}
}

class CReverseString
{
  public static void main(String str[])
  {
    try
    {
      ReverseClient c = new ReverseClient();
    }
    catch(Exception e)
    {}
  }
}