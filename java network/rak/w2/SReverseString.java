import java.io.*;
import java.net.*;

class ReverseServer
{
  Socket socket;
  InputStream is;
  OutputStream os;
  DataInputStream dis_socket;
  DataOutputStream dos_socket;
  

  public void startServer() throws Exception
  {
    ServerSocket s = new ServerSocket(2000);
    System.out.println("\n\tReverse Server is waiting on port 2000...");
    socket = s.accept();
    is = socket.getInputStream();
    os = socket.getOutputStream();
    dis_socket = new DataInputStream(is);
    dos_socket = new DataOutputStream(os);
    checkRev();
  }

  public void checkRev() throws Exception
  {
    String temp=new String("");	
    int flag=1,len,i;
     while(true)
      {
        flag=1;
        String str = dis_socket.readLine();
        System.out.print("\n\tString from client Side : " + " --> " + str);
        str=str.trim();
        if(str.equals("stop"))
          break;
      
	
    len=str.length();
    for(i=len-1;i>=0;i--)
    {	
	temp=temp+str.charAt(i);	
    }


       	dos_socket.writeBytes(temp);
	dos_socket.writeChar('\n');
	temp="";

      }
  }
}

class SReverseString
{
  public static void main(String str[])
  {
    try
    {
      ReverseServer s = new ReverseServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}
  