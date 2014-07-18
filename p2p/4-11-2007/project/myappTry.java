import java.net.*;
import java.io.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.lang.*;
import javax.swing.border.*;
//import javax.media.*;
import java.applet.*;
import java.awt.event.WindowEvent;


public class myappTry extends JMenuBar implements ActionListener
{
	String[] fileItems = new String[] { "Connect" , "Disconnect", "Exit" };
	String[] navigateItems = new String[] { "Search", "Monitor", "Library" };
	String[] Help = new String[] { "About" };
	Font f, f1;
	char[] fileShortcuts =  {'C', 'D', 'X' };
	char[] navigateShortcuts =  { 'S', 'M', 'L' };
	JMenuBar menubar;
	JLabel status;
	JPanel searchPanel, buttonPanel;
	String ipserver,usernm, ipclient;
	
	Socket s;
	DataInputStream keyboard;
	DataInputStream dis;
	DataOutputStream dos;
	
	int in=0, out=0;;
	
	JButton setFavoriteAction, downAction, gotoFavoriteAction, upAction;
	myappTry()
	{}
	
	public myappTry(Frame frame) throws Exception
	{
			System.out.println("----------------------------------------------------------------------------");

			System.out.println("\t\t\tLIMEWIRE CLIENT ");
			
			System.out.println("----------------------------------------------------------------------------\n\n");

			
			f=new Font("Comic Sans MS",1,25);
			f1=new Font("Comic Sans MS",1,14);
			
			//MAIN PANEL
			
			JPanel main=new JPanel();
			main.setLayout(new BorderLayout());
			
			// PANEL FOR MENU
			
			JPanel top = new JPanel();
			top.setLayout(new BorderLayout());
			
		
			JMenuBar menubar = createMenus();
			
			top.add(menubar, BorderLayout.NORTH);
	
		
			// PANEL FOR LABEL
			JPanel two = new JPanel();
			two.setLayout(new BorderLayout());
				
			two.setBackground(Color.black);
			two.setForeground(Color.white);
			two.setPreferredSize(new Dimension(1000, 40 ));
		
			status=new JLabel("<HTML> <I>LIMEWIRE</I></HTML> ", JLabel.RIGHT);
			status.setFont(f);
			status.setForeground(Color.white);
			two.add(status,BorderLayout.SOUTH);
		
			JPanel three = new JPanel();
			three.setLayout(new BorderLayout());
			JTabbedPane jtp;
			setSize(400,400);
			
			jtp = new JTabbedPane( );
			
			
			JPanel tabOne = new JPanel();
			tabOne.setLayout(new BorderLayout());

			
			JPanel searchPanel = new JPanel();
			searchPanel.setLayout(new BorderLayout());	    	
			searchPanel.setPreferredSize(new Dimension(200, 600));
			
			JPanel tablePanel=new JPanel();
			tablePanel.setPreferredSize(new Dimension(800,600));
			tablePanel.setBackground(Color.black);
			
			JPanel tbPanel=new JPanel();
			tbPanel.setLayout(new BorderLayout());
			tbPanel.setPreferredSize(new Dimension(790,490));
			
			JTable jt = new JTable(new String[][] { {"", "","",""}, {"", "","",""} },
                           new String[] {"FILE NAME" , "HOST", "FILE SIZE", "FILE TYPE" });
			JScrollPane jsp = new JScrollPane(jt);
			jsp.setPreferredSize(new Dimension(790,290));
			tbPanel.add(jsp);
			
			JPanel dloadPanel=new JPanel();
			dloadPanel.setLayout(new BorderLayout());
			dloadPanel.setPreferredSize(new Dimension(790,90));
			//dloadPanel.setBackground(Color.black);
			
			JButton dloadBtn=new JButton("DOWNLOAD");
			
			Box boxbtnBox1 = Box.createHorizontalBox();
			boxbtnBox1.add(Box.createHorizontalGlue( ));
			boxbtnBox1.setPreferredSize(new Dimension(100,100));
			 
			
			dloadBtn.setBackground(Color.black);
			dloadBtn.setForeground(Color.white);
			
			
			
			JButton cancelBtn=new JButton("    CANCEL    " );
			cancelBtn.setBackground(Color.black);
			cancelBtn.setForeground(Color.white);
			
			
			JLabel empty1=new JLabel("                                                                                       ");
			JLabel empty2=new JLabel("                       ");
			boxbtnBox1.add(empty1);
			boxbtnBox1.add(dloadBtn);
			boxbtnBox1.add(empty2);
			boxbtnBox1.add(cancelBtn);
			boxbtnBox1.add(empty1);
			dloadPanel.add(boxbtnBox1,BorderLayout.NORTH);
			
			
			
			
			tablePanel.add(tbPanel,BorderLayout.NORTH);
			tablePanel.add(dloadPanel,BorderLayout.SOUTH);
			
			/*JSplitPane tb = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,tbPanel,dloadPanel);
			tb.setBorder(BorderFactory.createLineBorder(Color.red, 2) );*/
			
			JPanel topPanel = new JPanel();
			topPanel.setLayout(new BorderLayout());
			topPanel.setPreferredSize(new Dimension(200, 250));
			
			
						 

			//topPanel.setBackground(Color.yellow);

			JLabel searchtype = new JLabel( "Select Search type :" );
			JPanel labelPanel=new JPanel(new BorderLayout());
			labelPanel.setBackground(Color.white);						
			labelPanel.setPreferredSize(new Dimension(200,20));

			labelPanel.add(searchtype,BorderLayout.CENTER);

			JPanel buttonPanel = new JPanel();
			buttonPanel.setLayout(new BorderLayout());
	    	
			buttonPanel.setPreferredSize(new Dimension(200, 180));
			//buttonPanel.setBackground(Color.yellow);

			JRadioButton audioRBtn=new JRadioButton("AUDIO",true);
			JRadioButton videoRBtn=new JRadioButton("VIDEO",false);
			JRadioButton docRBtn=new JRadioButton("DOCUMENTS",false);
			JRadioButton allRBtn=new JRadioButton("ALL FILES",false);

			Box boxMain = Box.createVerticalBox( );
			Box box1 = Box.createHorizontalBox( );
			Box box2 = Box.createHorizontalBox( );
    			
    			box1.add(Box.createHorizontalGlue( ));
				
    			box2.add(Box.createHorizontalGlue( ));

			box1.add(audioRBtn);
			box1.add(videoRBtn);

			box2.add(docRBtn);
			box2.add(allRBtn);

			

			audioRBtn.addActionListener(this);
			videoRBtn.addActionListener(this);
			docRBtn.addActionListener(this);
			allRBtn.addActionListener(this);

			
   			 

			box1.add(Box.createHorizontalGlue( ));
			box2.add(Box.createHorizontalGlue( ));

			
			boxMain.add(Box.createVerticalGlue( ));
			boxMain.add(box1);
			boxMain.add(box2);

			JLabel tl1=new JLabel( " File Name : " );
			JLabel tl2=new JLabel( " File Type : " );
			JLabel tl3=new JLabel( " File Size : " );
			
			
			JTextField t1=new JTextField(10);
			t1.setHorizontalAlignment(JTextField.RIGHT);


			JTextField t2=new JTextField(10);
			t2.setHorizontalAlignment(JTextField.RIGHT);


			JTextField t3=new JTextField(10);
			t3.setHorizontalAlignment(JTextField.RIGHT);


			Box boxTBox = Box.createVerticalBox( );
			//boxTBox.setPreferredSize(new Dimension(200,200));
			boxTBox.add(Box.createVerticalGlue( ));
			
			boxTBox.add(tl1);
			boxTBox.add(t1);
			
			boxTBox.add(tl2);
			boxTBox.add(t2);
			
			boxTBox.add(tl3);
			boxTBox.add(t3);
			
			
			
			
			
			buttonPanel.add(boxMain,BorderLayout.NORTH);
			buttonPanel.add(boxTBox,BorderLayout.CENTER);
			//buttonPanel.add(searchBtn,BorderLayout.SOUTH);
			

						
			topPanel.add(labelPanel,BorderLayout.NORTH);
			topPanel.add(buttonPanel,BorderLayout.SOUTH);
			
			JPanel bottomPanel = new JPanel();
			bottomPanel.setLayout(new BorderLayout());	    	
			bottomPanel.setPreferredSize(new Dimension(200,350));
			//bottomPanel.setBackground(Color.black);
			
			JSplitPane b = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,topPanel,bottomPanel);
			b.setBorder(BorderFactory.createLineBorder(Color.red, 2) );
			
			JButton searchBtn=new JButton("    SEARCH   " );
			
			Box boxbtnBox = Box.createHorizontalBox();
			boxbtnBox.add(Box.createHorizontalGlue( ));
			 
			
			searchBtn.setBackground(Color.black);
			searchBtn.setForeground(Color.white);
			
			
			
			JButton resetBtn=new JButton("    RESET    " );
			resetBtn.setBackground(Color.black);
			resetBtn.setForeground(Color.white);
			
			
			
			boxbtnBox.add(searchBtn);
			searchBtn.addActionListener(this);
			boxbtnBox.add(resetBtn);
			bottomPanel.add(boxbtnBox,BorderLayout.NORTH);
			
			

			searchPanel.add(topPanel,BorderLayout.NORTH);  
			searchPanel.add(bottomPanel,BorderLayout.SOUTH);
			
	

			
			JSplitPane a = new JSplitPane(JSplitPane.VERTICAL_SPLIT,searchPanel,tablePanel);
			a.setBorder(BorderFactory.createLineBorder(Color.red, 2) );
			
			
					
		
			
			tabOne.add(searchPanel,BorderLayout.WEST);					
			tabOne.add(tablePanel);
			
			
			jtp.addTab("SEARCH",null, tabOne, "Searches for files");
			jtp.addTab("MONITOR",null, new JLabel("This is Tab Two"), "Monitors the uploading");
			jtp.addTab("LIBRARY", null, new JLabel("This is Tab Three"), "Files in library");
			
	
			three.add(jtp,BorderLayout.SOUTH);
			

			
			// ADDING THE PANELS TO MAIN FRAME
			main.add(top, BorderLayout.NORTH);
			main.add(two,BorderLayout.CENTER);
			main.add(three,BorderLayout.SOUTH);
			add(main);
			
			

			
		
	}
	
	
	public JMenuBar createMenus() 
	{
		/*ActionListener printListener = new ActionListener( ) 
		{
                public void actionPerformed(ActionEvent event) 
				{
                    System.out.println("Menu item [" + event.getActionCommand( ) +"] was pressed.");
                }
		}; */
		
		
		// ***** create the menubar ****
		 
			menubar = new JMenuBar();
		JMenu fileMenu = new JMenu( "File" );
		JMenu navigateMenu = new JMenu ( "Navigation" );
		JMenu helpMenu = new JMenu ( "Help" );
		JLabel status;
		
		
		
		for( int i=0; i < fileItems.length; i++ )
		{
			JMenuItem item=new JMenuItem(fileItems[i], fileShortcuts[i]);
			item.addActionListener(this);
			fileMenu.add(item);			
		}
		
		JMenuItem item1=new JMenuItem("About",'A');
		helpMenu.add(item1);
		
		for( int i=0; i < navigateItems.length; i++ )
		{
			JMenuItem item=new JMenuItem(navigateItems[i], navigateShortcuts[i]);
			item.addActionListener(this);
			navigateMenu.add(item);
			
		}
		
		menubar.add(fileMenu);
		menubar.add(navigateMenu);
		menubar.add(helpMenu);
		
		return menubar;
	}
	
	
	
	
	public void actionPerformed(ActionEvent event) 
	{
		String str=(event.getActionCommand()).trim();
		
		if(str.equals("SEARCH"))
		{
			try
			{
			
				System.out.println("SEARCH CLICKED");
				DataOutputStream dos_search=new DataOutputStream(s.getOutputStream());
				dos_search.writeBytes("request\n");
			}
			catch(Exception e){System.out.println(e);}
		}
		
		if(str.equals( "AUDIO" ))
		{
			System.out.println( "audioBtn clicked" );
			
		}
		
		/* CREATION OF LOGIN BOX (USERNAME, SERVER IP ADDRESS, PORT NUMBER) */
		
		if(str.equals("Connect"))
		{
				if(in==1)
				{
					JOptionPane.showMessageDialog(null, "ALREADY CONNECTED TO THE SERVER", "CONNECTED",
  						JOptionPane.INFORMATION_MESSAGE);
				}
				else
				{
					out=0;
				
				//	System.out.println( "Connect clicked" );
			
				
					final JFrame f=new JFrame("Connect");
					Container c=f.getContentPane( );
			
					final JTextField box1 = new JTextField(10);
					box1.setHorizontalAlignment(JTextField.CENTER);
			
					final JTextField box2 = new JTextField(10);
					box2.setHorizontalAlignment(JTextField.CENTER);
					
					final JTextField box3 = new JTextField(10);
					box3.setHorizontalAlignment(JTextField.CENTER);
			
					JTextField box4 = new JTextField("7777",10);
					box4.setHorizontalAlignment(JTextField.CENTER);
					box4.setEditable(false);
			
					JLabel user=new JLabel("USER NAME   ");
					JLabel server=new JLabel("SERVER IP   ");
					JLabel client=new JLabel("CLIENT IP    ");
					JLabel port=new JLabel("PORT   ");
				
					JButton con=new JButton("CONNECT");
					JButton exit=new JButton("CANCEL");
			
					JPanel labelPane = new JPanel();
					labelPane.setLayout(new GridLayout(0, 1));
					labelPane.add(user);
					labelPane.add(server);
					labelPane.add(client);
					labelPane.add(port);
	
					JPanel fieldPane = new JPanel();
					fieldPane.setLayout(new GridLayout(0, 1));
					fieldPane.add(box1);
					fieldPane.add(box2);
					fieldPane.add(box3);
					fieldPane.add(box4);
			
					JPanel contentPane = new JPanel();
					JPanel p = new JPanel();
					p.add(con);
					p.add(exit);
					contentPane.setBorder(BorderFactory.createEmptyBorder(20, 20,20, 20));
					contentPane.setLayout(new BorderLayout());
					contentPane.add(labelPane, BorderLayout.CENTER);
					contentPane.add(fieldPane, BorderLayout.EAST);
					contentPane.add(p,BorderLayout.SOUTH);
					c.add(contentPane);
					
			
					con.addActionListener(new ActionListener()
					{
						public void actionPerformed(ActionEvent e)
						{	
							String opt=(e.getActionCommand()).trim();
							if(opt.equals("CONNECT"))
							{
							
								try
								{
									in=1;
									ipserver=box2.getText();
									usernm=box1.getText();
									ipclient=box3.getText();
									
									InetAddress address=InetAddress.getByName(ipserver);
									s=new Socket(address,7777);					
									dis=new DataInputStream(s.getInputStream());
									keyboard=new DataInputStream(System.in);
									dos=new DataOutputStream(s.getOutputStream());
									dos.writeBytes(usernm+"\n");
									dos.writeBytes(ipclient+"\n");
									f.setVisible(false);
								
									System.out.println("----------------------------------------------------------------------------");
									
									System.out.println( "Client "+usernm+ " connected to the server at port 7777");
																/* CALL OF dirDisplay() */
									dirDisplay();
								}
								catch(Exception me)
								{
									JOptionPane.showMessageDialog(f, "Sorry not able to connect to the server","Connection Error", JOptionPane.INFORMATION_MESSAGE);
									System.out.println(me);
								}
							}
							else if(opt.equals("CANCEL"))
								f.setVisible(false);
						}
					});
				
				f.pack( );
    			f.setVisible(true);
			}
		
		}
		
		if(str.equals("Disconnect"))
		{
			if(in==0)
			{
				JOptionPane.showMessageDialog(null, "LIMEWIRE NOT CONNECTED....", "NOT CONNECTED",
  						JOptionPane.INFORMATION_MESSAGE);
			}
			else
			{
				if(out==0) 						/* WHEN DISCONNECTED SET OUT=1 BCOZ DONT ALLOW TO DISCONNECT AGAIN MESSAGE BOX */
				{
				
					out=1;
					JOptionPane.showMessageDialog(null, "LIMEWIRE IS DISCONNECTING....", "DISCONNECT",
  							JOptionPane.INFORMATION_MESSAGE);
  					
  					in=0;
  					
  					try
  					{
  						exiting();
  					}
  					catch(Exception e){}
  				}
  				else
  					JOptionPane.showMessageDialog(null, "LIMEWIRE ALREADY DISCONNECTED.....", "DISCONNECTED",
  							JOptionPane.INFORMATION_MESSAGE);
  			}
  		}
		else if(str.equals("Exit"))
			System.exit(0);
	}
	
	/* SEND THE NAME OF THE USER WHO IS DISCONNECTING */
	
	void exiting() throws Exception 
	{
		DataOutputStream dos;
		dos=new DataOutputStream(s.getOutputStream());
  		dos.writeBytes("exiting\n");
  		System.out.println( "DISCONNECTED FROM THE SERVER");
  		System.out.println("----------------------------------------------------------------------------");
	}
	
	
	/* GET THE FILE NAMES OF THE DIRECTORY (C:\LIMEWIRE) AND SEND IT TO SERVER */
	
	void dirDisplay() throws Exception
		{
					DataOutputStream dos_sock;
        			 File dir = new File("c:\\limewire");
       			 	 FilenameFilter only = new OnlyExt("txt");
				     String s1[] = dir.list(only);
         			 dos_sock=new DataOutputStream(s.getOutputStream());
         			
         			
             		if (s1 == null) 
             		{
             			System.out.println("Directory does not exist or is not a Directory");
             		}
             		else 
             		{
             			dos_sock.writeInt((int)s1.length);
             			System.out.println("Number of files in the directory : " + s1.length);
                 		System.out.println("File Names : " );
                 		for (int i=0; i<s1.length;i++)                 
                 		{
                 			System.out.println(s1[i]);
                 			dos_sock.writeBytes(s1[i]+"\n");
                 			
                 		}
                 	}
             	
		}
}




class p2p extends JFrame
{
	public static void main(String args[])
	{
		try
		{
			myappTry m=new myappTry();
			JFrame frame = new JFrame( "L I M E W I R E" );
			
			
			frame.addWindowListener(new WindowAdapter( ) 
			{
      			public void windowClosing(WindowEvent ev) 
      			{
      				JOptionPane.showMessageDialog(null, "LIMEWIRE IS EXITING....", "EXIT",
  						JOptionPane.INFORMATION_MESSAGE);
					
				}
		
  			}); 
  						
			frame.setJMenuBar(new myappTry(frame));
			frame.pack();
			frame.setVisible(true);
			
			
			
			
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		
		
	}
	
	
				
}
