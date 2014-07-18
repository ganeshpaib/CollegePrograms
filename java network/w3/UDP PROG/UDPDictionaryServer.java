import java.io.*;
import java.net.*;

class UDPServer
{
  DatagramPacket r_packet, s_packet;
  DatagramSocket udp_socket;
  byte rbuff[],sbuff[];
  String dictionary[][];

  public void startServer() throws Exception
  {
    udp_socket = new DatagramSocket(4444);
    System.out.println("\n\tServer is waiting on port: 4444\n\n");
    createDictionary();
    while( true )
    {
      rbuff = new byte[80];
      r_packet = new DatagramPacket(rbuff,rbuff.length);
      udp_socket.receive(r_packet);
      rbuff = r_packet.getData();
      String word = new String(rbuff);
      word = word.trim();
      System.out.print("\n\tWord from the client: " + word);
      String result = search(word);
      System.out.print("\n\tSearch result: " + result);
      InetAddress addr = r_packet.getAddress();
      int port = r_packet.getPort();
      sbuff = result.getBytes();
      s_packet = new DatagramPacket(sbuff,sbuff.length,addr,port);
      udp_socket.send(s_packet);
    }
  }

  public void createDictionary()
  {
    dictionary = new String[2][2];
    for(int i=0; i<2; i++)
      for(int j=0; j<2; j++)
        dictionary[i][j] = new String();

    dictionary[0][0] = "Server"; dictionary[0][1] = "services";
    dictionary[1][0] = "client"; dictionary[1][1] = "requests";
  }

  public String search(String temp)
  {    
    String res = "Not found in the Dictionary...";
    for(int i=0; i<2; i++)
    {
      if( dictionary[i][0].equals(temp) )
      {
        res = dictionary[i][1];
        break;
      }
    }    
    return( res );
  }
}      


class UDPDictionaryServer
{
  public static void main(String str[])
  {
    try
    {
      UDPServer s = new UDPServer();
      s.startServer();
    }
    catch(Exception e)
    {
      System.out.println("\n\n\t" + e);
    }
  }
}