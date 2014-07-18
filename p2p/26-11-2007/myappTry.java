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
import javax.swing.table.*;


public class myappTry extends JMenuBar implements Runnable
{
	
	Font f, f1;
	
	JMenuBar menubar;
	JLabel status;
	JPanel searchPanel, buttonPanel;
	String ipserver,usernm, ipclient;
	
	Socket s;
	DataInputStream keyboard;
	DataInputStream dis, dis_port;
	DataOutputStream dos;
	JTextField t1;
	String titles[] = new String[] {"CLIENT NAME", "CLIENT IPADDR", "FILE NAME", "FILE SIZE","PORT NUMBER"};
	String libtitles[] = new String[] {"FILE NAME", "FILE SIZE"};
	Object[][] searchResults, libResults;
	JPanel tbPanel;
	int in=0, out=0, sin=0, searchIn=0;
	DefaultTableModel model, libmodel;
	JButton searchBtn;
	JTable jt, libjt;
	JTabbedPane tab;
	Thread tUpload, tDownload;
	int thread=1;
	Socket sclient;
	String fc;
	int wait, portno, prt,row;
	myappTry mt;
	TableColumn column;
	
	
 Object data1,data2,data3, data4, data5;
 String nameClient, ipClient, fileClient, portClient, fileLengthClient;
	
	myappTry()
	{
		fileClient="gan";
		}
	
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
			
			tbPanel=new JPanel();
			tbPanel.setLayout(new BorderLayout());
			tbPanel.setPreferredSize(new Dimension(790,490));
			
			
			/*JTable jt = new JTable(new String[][] { {"", "","",""}, {"", "","",""} },
                           new String[] {"FILE NAME" , "HOST", "FILE SIZE", "FILE TYPE" });
			JScrollPane jsp = new JScrollPane(jt);
			jsp.setPreferredSize(new Dimension(790,290));
			tbPanel.add(jsp);*/
			
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
			
			dloadBtn.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{	
					 row=(int)jt.getSelectedRow();
						System.out.println("SELECTED ROW ... :" +row);
					if(row>=0)
					{
						
						 data1 = jt.getValueAt(row, 0); 
						 data2=jt.getValueAt(row,1);
						 data3=jt.getValueAt(row,2);	
						 data4=jt.getValueAt(row,3);
						 data5=jt.getValueAt(row,4);
						 	
						 nameClient=data1.toString();
						System.out.println("CLIENT NAME :"+ nameClient);
						
						 ipClient=data2.toString();
						System.out.println("CLIENT IP :"+ipClient);
						
						  fileClient=data3.toString();
						System.out.println("CLIENT FILE :"+fileClient);
						
						fileLengthClient=data4.toString();
						System.out.println("FILE SIZE:"+fileLengthClient);
						
						portClient=data5.toString();
						System.out.println("CLIENT PORT :"+portClient);
						
						fc=fileClient;
						prt=Integer.parseInt(portClient);
						System.out.println( "download thread calling....\n\n" );
						
						//tDownload.start();
						new Thread(mt,"download").start();
					}
					
					else
						JOptionPane.showMessageDialog(null, "SELECT A FILE FROM THE TABLE...", "SELECT",
  							JOptionPane.INFORMATION_MESSAGE);
					
				}
			});
			
			 
			 
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

			JRadioButton audioRBtn=new JRadioButton("AUDIO",false);
			JRadioButton videoRBtn=new JRadioButton("VIDEO",false);
			JRadioButton docRBtn=new JRadioButton("DOCUMENTS",false);
			JRadioButton allRBtn=new JRadioButton("ALL FILES",true);
			
			
			Box boxMain = Box.createVerticalBox( );
			Box box1 = Box.createHorizontalBox( );
			Box box2 = Box.createHorizontalBox( );
    			
    			box1.add(Box.createHorizontalGlue( ));
				
    			box2.add(Box.createHorizontalGlue( ));

			box1.add(audioRBtn);
			box1.add(videoRBtn);

			box2.add(docRBtn);
			box2.add(allRBtn);

			

			

			allRBtn.addActionListener(new ActionListener()
			{
			public void actionPerformed(ActionEvent e)
			{	
			}
			});
			
			docRBtn.addActionListener(new ActionListener()
			{
			public void actionPerformed(ActionEvent e)
			{	
			}
			});
			
			videoRBtn.addActionListener(new ActionListener()
			{
			public void actionPerformed(ActionEvent e)
			{	
			}
			});
			
			audioRBtn.addActionListener(new ActionListener()
			{
			public void actionPerformed(ActionEvent e)
			{	
			}
			});
   			 

			box1.add(Box.createHorizontalGlue( ));
			box2.add(Box.createHorizontalGlue( ));

			
			boxMain.add(Box.createVerticalGlue( ));
			boxMain.add(box1);
			boxMain.add(box2);

			JLabel tl1=new JLabel( " File Name : " );
			JLabel tl2=new JLabel( " File Type : " );
			JLabel tl3=new JLabel( " File Size : " );
			
			
			t1=new JTextField(10);
			t1.setHorizontalAlignment(JTextField.RIGHT);


			JTextField t2=new JTextField(10);
			t2.setHorizontalAlignment(JTextField.RIGHT);
			t2.setEditable(false);

			JTextField t3=new JTextField(10);
			t3.setHorizontalAlignment(JTextField.RIGHT);
			t3.setEditable(false);

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
			
						
			searchBtn=new JButton("    SEARCH   " );
			Box boxbtnBox = Box.createHorizontalBox();
			boxbtnBox.add(Box.createHorizontalGlue( ));
			 
			
			searchBtn.setBackground(Color.black);
			searchBtn.setForeground(Color.white);
			
			
			
			JButton resetBtn=new JButton("    RESET    " );
			resetBtn.setBackground(Color.black);
			resetBtn.setForeground(Color.white);
			
			
			
			boxbtnBox.add(searchBtn);
			boxbtnBox.add(resetBtn);
			bottomPanel.add(boxbtnBox,BorderLayout.NORTH);
			
			

			searchPanel.add(topPanel,BorderLayout.NORTH);  
			searchPanel.add(bottomPanel,BorderLayout.SOUTH);
			
	

			
			JSplitPane a = new JSplitPane(JSplitPane.VERTICAL_SPLIT,searchPanel,tablePanel);
			a.setBorder(BorderFactory.createLineBorder(Color.red, 2) );
			
			
					
		
			
			tabOne.add(searchPanel,BorderLayout.WEST);					
			tabOne.add(tablePanel);
			
			JPanel tabTwo=new JPanel();
			tabTwo.setLayout(new BorderLayout());	    	
							
			jtp.addTab("SEARCH",null, tabOne, "Searches for files");
			jtp.addTab("MONITOR",null, tabTwo, "Monitors the uploading");
			jtp.addTab("LIBRARY", null, new JLabel("This is Tab Three"), "Files in library");
			
	
			three.add(jtp,BorderLayout.SOUTH);
			
			
			tab=new JTabbedPane();                     // To create each tab for every search
			
			
			// ADDING THE PANELS TO MAIN FRAME
			main.add(top, BorderLayout.NORTH);
			main.add(two,BorderLayout.CENTER);
			main.add(three,BorderLayout.SOUTH);
			add(main);
			
			searchBtn.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{	
					try
					{
				
						/*if(searchIn==0)
						{
							searchIn=1;
						}
						else
						{
							System.out.println( "Search in... removing");
							
							model.removeRow(0);
							
						} */
						
						String[] nm=new String[100];
						String[] ipcl=new String[100];
						String[] fl=new String[100];
						String[] flLen=new String[100];
						String[] port=new String[100];
						
						String ftitle=t1.getText();
					//	String finputtype=t2.getText();
						
						ftitle=ftitle.toLowerCase();
						System.out.println("SEARCH CLICKED");
						System.out.println(ftitle);
					
						ftitle=ftitle.trim();
						DataOutputStream dos_search=new DataOutputStream(s.getOutputStream());
						dos_search.writeInt(1);  				                                                   //SEARCH OPTION IN CLIENT APPLICATION
						
						dos_search.writeBytes("FILE REQUEST FROM :"+ipclient+"\n");
						dos_search.writeBytes(ftitle);
						//dos_search.writeBytes(fsearchtype+"\n");
						
						dos_search.writeBytes("\n");
						
						DataInputStream dis_search=new DataInputStream(s.getInputStream());
						int count=dis_search.readInt();
							
						System.out.println("Count= "+count);
						
						
						searchResults = new Object[count][titles.length];
		
		
						for(int i=0;i<count;i++)
						{
							nm[i]=dis_search.readLine();
							ipcl[i]=dis_search.readLine();
							fl[i]=dis_search.readLine();
							flLen[i]=dis_search.readLine();
							port[i]=dis_search.readLine();
							
							System.out.println("Name = "+nm[i] + "\tIPCLIENT = "+ipcl[i]+ "\tFile : "+fl[i]);
							searchResults[i][0]=nm[i];
							searchResults[i][1]=ipcl[i];
							searchResults[i][2]=fl[i];
							searchResults[i][3]=flLen[i];
							searchResults[i][4]=port[i];
						}
						
						if(count==0)
						{
							JLabel searchStatus=new JLabel("<HTML> <I>NO FILES FOUND...</I></HTML> ", JLabel.CENTER);
							tab.add(ftitle,searchStatus);
						}
						
						else
						{
						
							model = new DefaultTableModel(searchResults,titles);
			    			jt = new JTable(model){
	      											public Dimension getPreferredScrollableViewportSize() 
	      											{
	        											return getPreferredSize();
	      											}
	    										  };  
	    					Dimension dim = new Dimension(60,1);
	    					jt.setIntercellSpacing(new Dimension(dim));
	    
														
							column = jt.getColumnModel().getColumn(0);
	    					column.setPreferredWidth(120);
							
							column = jt.getColumnModel().getColumn(1);
	    					column.setPreferredWidth(120);
	    						
	    					column = jt.getColumnModel().getColumn(2);
	    					column.setPreferredWidth(150);
	    						
	    					column = jt.getColumnModel().getColumn(3);
	    					column.setPreferredWidth(120);
	    						
	    					column = jt.getColumnModel().getColumn(4);
	    					column.setPreferredWidth(120);
	
	
			    			jt.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
			    			jt.setRowSelectionAllowed(true);
			
			
							JScrollPane jsp = new JScrollPane(jt);
							jsp.setPreferredSize(new Dimension(790,290));
							
							tab.add(ftitle,jsp);
							tbPanel.add(tab);	
						
						
						}
						
						
						
					}
					catch(Exception me){System.out.println(me);}
				}
			});
			

			
		
	}
	
	
	public JMenuBar createMenus() 
	{
				
		// ***** create the menubar ****
		 
		menubar = new JMenuBar();
		JMenu fileMenu = new JMenu( "File" );
		JMenu navigateMenu = new JMenu ( "Navigation" );
		JMenu helpMenu = new JMenu ( "Help" );
		JLabel status;
		
		JMenuItem connectItem = new JMenuItem("Connect");
    	JMenuItem disconnectItem = new JMenuItem("Disconnect");
    	JMenuItem exitItem = new JMenuItem("Exit");

		fileMenu.add(connectItem);
		fileMenu.add(disconnectItem);
		fileMenu.add(exitItem);
		
		
		
		connectItem.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
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
									dis_port=new DataInputStream(s.getInputStream());
									keyboard=new DataInputStream(System.in);
									dos=new DataOutputStream(s.getOutputStream());
									
									
									dos.writeBytes(usernm+"\n");
									dos.writeBytes(ipclient+"\n");
									
									
									portno=dis_port.readInt();
									
									f.setVisible(false);
									
									System.out.println("----------------------------------------------------------------------------");
									
									System.out.println( "Client "+usernm+ " connected to the server at port 7777");
									System.out.println( "Client port.... : "+portno);
																/* CALL OF dirDisplay() */
									
									
									dirDisplay();
									
								//	myappTry mt=new myappTry();
									 
									tUpload=new Thread(mt,"upload");
									tUpload.start();
									
									tDownload=new Thread(mt,"download");
									
									
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
		});
		
		
			
		disconnectItem.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
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
				
					
						JOptionPane.showMessageDialog(null, "LIMEWIRE IS DISCONNECTING....", "DISCONNECT",
  							JOptionPane.INFORMATION_MESSAGE);
  					
  						in=0;
  					
  						try
  						{
  							exiting();
  							out=1;
  						}
  						catch(Exception me){}
  					}
  					else
  						JOptionPane.showMessageDialog(null, "LIMEWIRE ALREADY DISCONNECTED.....", "DISCONNECTED",
  							JOptionPane.INFORMATION_MESSAGE);
  				}
  			}
		
			
		});	
			
		
		JMenuItem item1=new JMenuItem("About",'A');
		helpMenu.add(item1);
		
		
		
		menubar.add(fileMenu);
	
		menubar.add(helpMenu);
		
		return menubar;
	}
	
public void run()
		{
			try
			{
				
				if(thread==1)
				{
					int ex=0;
					thread++;
					System.out.println("UPLOADING STARTED...\n\n"+thread);
					ServerSocket ssocket=new ServerSocket(portno);
					
					while(true)
					{
						sclient=ssocket.accept();
						
						System.out.println("Client connected to the server..\n");
						
						dis=new DataInputStream(sclient.getInputStream());
						dos=new DataOutputStream(sclient.getOutputStream());
						
						String fname1=dis.readLine().trim();
						
						FileInputStream file= new FileInputStream(fname1);
						int size=file.available();
						dos.writeInt(size);
						//System.out.println("SIZE OF THE FILE [ "+fname+" ] : "+size);
						
						byte b[]=new byte[size];
						
						file.read(b);
						dos.write(b,0,size);
						
						
						
						dos.writeInt(3);					
						
						    					
						//System.out.println("SIZE OF THE FILE [ "+fname+" ] : "+size);
						
						
						
						
						dos.writeInt(3);
						//System.out.println("TRANSFER COMPLETE");
						
					}
				}
				else
				{
						
					
						System.out.println("DOWNLOADING STARTED...in port number\n\n"+prt);
						
						Socket sc=new Socket(InetAddress.getByName(ipClient),prt);
					
					
						DataInputStream keyboard;
						DataOutputStream dos, dos_server;
					
					
					//System.out.println("FILE REQUESTED..."+fc);
					
						dos=new DataOutputStream(sc.getOutputStream());
						dos_server=new DataOutputStream(s.getOutputStream());
						DataInputStream dis=new DataInputStream(sc.getInputStream());
						
						
						//String fname="hi.txt";
						String fname=fc;
						System.out.println(ipClient);
						System.out.println("FILE REQUESTED..."+fname);
						dos.writeBytes(fname+"\n");
						
						FileOutputStream dest=new FileOutputStream("c:\\limewire\\"+fname);
						int size=dis.readInt();
						System.out.println("SIZE OF THE FILE [ "+fname+" ] : "+size);
						
						byte b[]=new byte[size];
						dis.readFully(b);
						
									
						dest.write(b);
						int c=dis.readInt();
						
						if(c==3)
						{
							
							dos_server.writeInt(3);
							dos_server.writeBytes(fname+"\n");
							dos_server.writeBytes(size+"\n");
							
							System.out.println("TRANSFER COMPLETE");
							model.addColumn("DOWNLOAD STATUS");
							model.removeRow(row);
							model.insertRow(row,new Object[]{nameClient,ipClient,fc,fileLengthClient,prt,"FILE DOWNLOADED"});
							
							 column = jt.getColumnModel().getColumn(0);
    						column.setPreferredWidth(120);
						
							column = jt.getColumnModel().getColumn(1);
    						column.setPreferredWidth(120);
    						
    						column = jt.getColumnModel().getColumn(2);
    						column.setPreferredWidth(150);
    						
    						column = jt.getColumnModel().getColumn(3);
    						column.setPreferredWidth(120);
    						
    						column = jt.getColumnModel().getColumn(4);
    						column.setPreferredWidth(120);
    						
    						column = jt.getColumnModel().getColumn(5);
    						column.setPreferredWidth(150);
						}
						
						
				}	
					
					
			}
			catch(Exception e)
			{
				System.out.println(e);
				JOptionPane.showMessageDialog(null,"ERROR WHILE TRANSFERRING FILE.....", "FILE ERROR",
  							JOptionPane.INFORMATION_MESSAGE);
  			}
		}
		
		
	
	void exiting() throws Exception 
	{
		
		
			DataOutputStream dos;
			dos=new DataOutputStream(s.getOutputStream());
		
			dos.writeInt(2);									// DISCONNECT OPTION IN CLIENT APPLICATION
  			dos.writeBytes("exiting\n");
  			System.out.println( "DISCONNECTED FROM THE SERVER");
  			System.out.println("----------------------------------------------------------------------------");
  		
	}
	
	
	/* GET THE FILE NAMES OF THE DIRECTORY (C:\LIMEWIRE) AND SEND IT TO SERVER */
	
	void dirDisplay() throws Exception
	{
		DataOutputStream dos_sock;
		File dir = new File("c:\\limewire");
        String[] s1=dir.list();
        		 
       			 	 //FilenameFilter only = new OnlyExt("txt");
				     //String s1[] = dir.list(only);
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
         		File f1=new File("c:/limewire/"+s1[i]);
               			
         		System.out.print(s1[i]);
         		System.out.println("\t"+f1.length()+"bytes");
         		dos_sock.writeBytes(s1[i]+"\n");
         		dos_sock.writeBytes(f1.length()+"\n");
                 			
         	}
         }
             	
	}
	
	void add()
	{
	mt=this;
	}
}




class p2p extends JFrame
{
	public static void main(String args[])
	{
		try
		{
			
			JFrame frame = new JFrame( "L I M E W I R E" );
			
			frame.setResizable(false);
			frame.addWindowListener(new WindowAdapter( ) 
			{
      			public void windowClosing(WindowEvent ev) 
      			{
      				
      				JOptionPane.showMessageDialog(null, "LIMEWIRE IS EXITING....", "EXIT",
  							JOptionPane.INFORMATION_MESSAGE); 					
					
				}
		
  			}); 
  			myappTry m=new myappTry(frame);	
  			m.add();	
			frame.setJMenuBar(m);
			
			frame.addWindowListener(new WindowAdapter( ) 
			{
      				public void windowClosing(WindowEvent ev) 
      				{
      					try
      					{
      					
      						myappTry mm=new myappTry();
      						mm.exiting();
        					System.exit(0);
        				}
        				catch(Exception e){}
      				}
    		});

			frame.pack();
			frame.setVisible(true);
			
			
			
			
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		
		
	}
	
	
				
}
