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
	
	JButton setFavoriteAction, downAction, gotoFavoriteAction, upAction;
	public myappTry(Frame frame) throws Exception
	{
			
			
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
			boxbtnBox.add(resetBtn);
			bottomPanel.add(boxbtnBox,BorderLayout.NORTH);
			
			

			searchPanel.add(topPanel,BorderLayout.NORTH);  
			searchPanel.add(bottomPanel,BorderLayout.SOUTH);
			
	

			
			JSplitPane a = new JSplitPane(JSplitPane.VERTICAL_SPLIT,searchPanel,tablePanel);
			a.setBorder(BorderFactory.createLineBorder(Color.red, 2) );
			
			
					
		/*	JSplitPane b = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,topPanel,bottomPanel);
			b.setBorder(BorderFactory.createLineBorder(Color.red, 2) );	
			
			
			JSplitPane C = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,labelPanel,buttonPanel);
			C.setBorder(BorderFactory.createLineBorder(Color.red, 2) );	*/




			
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
	
	public void doaudio()
	{
		JPanel tboxPanel=new JPanel();
		JTextField s=new JTextField();
		tboxPanel.add(s);
		searchPanel.add(tboxPanel);
	}
	
	
	public void actionPerformed(ActionEvent event)
	{
		String str=(event.getActionCommand()).trim();
		
		if(str.equals( "AUDIO" ))
		{
			System.out.println( "audioBtn clicked" );
			//doaudio();
		}
		if(str.equals("Connect"))
			System.out.println( "Connect clicked" );
		else if(str.equals("Exit"))
			System.exit(0);
	}
}
class p2p
{
	public static void main(String args[])
	{
		try
		{
			JFrame frame = new JFrame( "L I M E W I R E" );
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
