import java.io.*;
import java.net.*;

class UDPClient
{
  DatagramSocket socket;
  DatagramPacket cs_packet, cr_packet;
  DataInputStream dis;
  //byte csbuff[],crbuff[]; 

  UDPClient() throws Exception
  {
    dis = new DataInputStream(System.in);
    socket = new DatagramSocket(5555);
    System.out.println("\n\tClient port is: 5555\n");
    while( true )
    {
      System.out.print("\n\tEnter the word: ");
      String temp = dis.readLine();
      byte csbuff[] = temp.getBytes();
      InetAddress addr = InetAddress.getByName("172.16.3.175");
      cs_packet = new DatagramPacket(csbuff,csbuff.length,addr,4444);
      socket.send(cs_packet);
      System.out.print("\n\tWaiting the result from the server...");
      byte crbuff[] = new byte[80];
      cr_packet = new DatagramPacket(crbuff,crbuff.length);
      socket.receive(cr_packet);
      String result = new String(crbuff);
      System.out.print("\n\tMeaning: " + result);
      System.out.print("\n\tDo u want to continue? ");
      String ch = dis.readLine();
      if( ch.charAt(0) == 'n' )
        break;
    }
  }
}

class UDPDictionaryClient
{
  public static void main(String str[])
  {
    try
    {
      UDPClient c = new UDPClient();
    }
    catch(Exception e)
    {
      System.out.println("\n\n\t" + e);
    }
  }
}
      