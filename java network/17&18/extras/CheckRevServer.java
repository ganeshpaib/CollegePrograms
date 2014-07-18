import java.io.*;
import java.net.*;

class PalinServer
{
  Socket socket;
  InputStream is;
  OutputStream os;
  DataInputStream dis_socket;
  DataOutputStream dos_socket;
  

  public void startServer() throws Exception
  {
    ServerSocket s = new ServerSocket(2000);
    System.out.println("\n\tPalindrome Server is waiting on port 2000...");
    socket = s.accept();
    is = socket.getInputStream();
    os = socket.getOutputStream();
    dis_socket = new DataInputStream(is);
    dos_socket = new DataOutputStream(os);
    checkPalin();
  }

  public void checkPalin() throws Exception
  {
    int flag=1,len,i;
     while(true)
      {
        flag=1;
        String str = dis_socket.readLine();
        System.out.print("\n\tString from client Side : " + " --> " + str);
        str=str.trim();
        if(str.equals("stop"))
          break;
       String temp="";
      len=str.length();
      for(i=len-1;i>=0;i--)
      {
	temp=temp+str.charAt(i);
     }
    /*len=str.length();
    for(i=0;i<len;i++,len--)
    {
	if(str.charAt(i)!=str.charAt(len-1))
	flag=0;
    }*/

/*if(str.equals(temp))
 flag=1;
else
 flag=0;  
       if(flag==1)
         str=" String is a Palindrome";
         else 
          str=" String is not  a Palindrome";*/
dos_socket.writeBytes(temp);
dos_socket.writeChar('\n');

      }
  }
}

class CheckRevServer
{
  public static void main(String str[])
  {
    try
    {
      PalinServer s = new PalinServer();
      s.startServer();
    }
    catch(Exception e)
    {}
  }
}
  