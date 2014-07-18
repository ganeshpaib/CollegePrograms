import java.io.*;
import java.net.*;

class ChatClient
{
  Socket socket;
  OutputStream os;
  InputStream is;
  DataOutputStream dos_socket;
  DataInputStream dis_socket;
  DataInputStream dis_keyboard;

  ChatClient() throws Exception
  {
    try
    {
      InetAddress addr = InetAddress.getByName("localhost");
      socket = new Socket(addr,2100);
      
      System.out.println("the address is : "+addr);
      
      os = socket.getOutputStream();
      dos_socket = new DataOutputStream(os);
      
      is = socket.getInputStream();
      dis_socket = new DataInputStream(is);
      
      dis_keyboard = new DataInputStream(System.in);
      
      while( true )
      {
        boolean flag1 = sendMessage();
        boolean flag2 = readMessage();
        if( flag1 || flag2 )
          break;
      }
    }
    catch(Exception e)
    {}
  }

  boolean sendMessage() throws Exception
  {
    System.out.print("\n\tEnter message to the server: ");
    String temp = dis_keyboard.readLine();
    dos_socket.writeBytes(temp);
    dos_socket.writeChar('\n');
    if( temp.equals("stop") )
      return true;
    else
      return false;
  }

  boolean readMessage() throws Exception
  {
    String temp = dis_socket.readLine();
    System.out.print("\n\tMessage from the server: " + temp);
    if( temp.equals("stop") )
      return true;
    else
      return false;
  }
}

class SimpleChatClient
{
  public static void main(String str[])
  {
    try
    {
      ChatClient c = new ChatClient();
    }
    catch(Exception e)
    {}
  }
}