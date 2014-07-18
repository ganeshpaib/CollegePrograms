import java.io.*;
import java.net.*;

class ChatServer 
{
  Socket socket;
  OutputStream os;
  InputStream is;
  DataOutputStream dos;
  DataInputStream dis_socket;
  DataInputStream dis_keyboard;

  public void startServer() throws Exception
  {
    ServerSocket s = new ServerSocket(2100);
    System.out.println("\n\tServer is waiting on port: 2100");
    socket = s.accept();
    
    is = socket.getInputStream();
    dis_socket = new DataInputStream(is);
    
    os = socket.getOutputStream();
    dos = new DataOutputStream(os);
    
    dis_keyboard = new DataInputStream(System.in);
    
    while( true )
    {
      try
      {
        boolean flag1 = readMessage();
        boolean flag2 = sendMessage();
        if( flag1 || flag2 )
          break;
      }
      catch(Exception e)
      {
        System.out.println(e);
      }
    }
  }

  boolean readMessage() throws Exception
  {
    String temp = dis_socket.readLine();
    System.out.print("\n\tMessage from the client: " + temp);
    if( temp.equals("stop") )
      return true;
    else
      return false;
  }

  boolean sendMessage() throws Exception
  {
    System.out.print("\n\tEnter the message for the client: ");
    String temp = dis_keyboard.readLine();
    dos.writeBytes(temp);
    dos.writeChar('\n');
    if( temp.equals("stop") )
      return true;
    else
      return false;
  }
}

class SimpleChatServer
{
  public static void main(String str[])
  {
    try
    {
      ChatServer s = new ChatServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}