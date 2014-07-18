import java.net.*;

class InetAddressDemo
{
	public static void main(String arg[]) throws Exception
	{
		System.out.println();
		InetAddress add = InetAddress.getLocalHost();
		System.out.println("The IP Address is : "+add);
		add=InetAddress.getByName("user-8026a4");
		System.out.println("The IP Address is : "+add);

	}
}



