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


public class myapp1 extends JMenuBar
{
	String[] fileItems = new String[] { "Connect" , "Disconnect", "Exit" };
	String[] navigateItems = new String[] { "Search", "Monitor", "Library" };
	String[] Help = new String[] { "About" };
	Font f, f1;
	char[] fileShortcuts =  {'C', 'D', 'X' };
	char[] navigateShortcuts =  { 'S', 'M', 'L' };
	JMenuBar menubar;
	JLabel status;
	
	JButton setFavoriteAction, downAction, gotoFavoriteAction, upAction;
	public myapp1() throws Exception
	{
		
			f=new Font("Comic Sans MS",1,25);
			f1=new Font("Comic Sans MS",1,14);
			
			//MAIN PANEL
			
			JPanel main=new JPanel();
			main.setLayout(new BorderLayout());
			
			// PANEL FOR MENU
			
			JPanel top = new JPanel();
			top.setLayout(new BorderLayout());
	
			menubar = new JMenuBar();
			menubar = createMenus();
			
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
			
			
			
			JButton audioBtn = new JButton ( "      AUDIO      " );
			JButton videoBtn = new JButton ( "     VIDEO    " );
			JButton docBtn = new JButton ( "DOCUMENTS" );
			JButton allBtn = new JButton ( "ALL FILES  " );

			Box boxMain = Box.createVerticalBox( );
			Box box1 = Box.createHorizontalBox( );
			Box box2 = Box.createHorizontalBox( );
    			
    			box1.add(Box.createHorizontalGlue( ));
				
    			box2.add(Box.createHorizontalGlue( ));

			box1.add(audioBtn);
			box1.add(videoBtn);

			box2.add(docBtn);
			box2.add(allBtn);

			box1.add(Box.createHorizontalGlue( ));
			box2.add(Box.createHorizontalGlue( ));

			
			boxMain.add(Box.createVerticalGlue( ));
			boxMain.add(box1);
			boxMain.add(box2);

			

			JPanel buttonPanel = new JPanel();
			buttonPanel.setLayout(new BorderLayout());
	    	
			buttonPanel.setPreferredSize(new Dimension(200, 600));
			buttonPanel.setBackground(Color.yellow);
			
    			
			buttonPanel.add(boxMain,BorderLayout.NORTH);
			

			JPanel tablePanel=new JPanel();
			tablePanel.setPreferredSize(new Dimension(800,600));
			tablePanel.setBackground(Color.black);

			
			JSplitPane a = new JSplitPane(JSplitPane.VERTICAL_SPLIT,buttonPanel,tablePanel);
			a.setBorder(BorderFactory.createLineBorder(Color.red, 2) );	
					
			tabOne.add(buttonPanel);			
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
		ActionListener printListener = new ActionListener( ) 
		{
                public void actionPerformed(ActionEvent event) 
				{
                    System.out.println("Menu item [" + event.getActionCommand( ) +"] was pressed.");
                }
		};
		// ***** create the menubar ****
		 
		
		JMenu fileMenu = new JMenu( "File" );
		JMenu navigateMenu = new JMenu ( "Navigation" );
		JMenu helpMenu = new JMenu ( "Help" );
		JLabel status;
		
		
		
		for( int i=0; i < fileItems.length; i++ )
		{
			JMenuItem item=new JMenuItem(fileItems[i], fileShortcuts[i]);
			item.addActionListener(printListener);
			fileMenu.add(item);			
		}
		
		JMenuItem item1=new JMenuItem("About",'A');
		helpMenu.add(item1);
		
		for( int i=0; i < navigateItems.length; i++ )
		{
			JMenuItem item=new JMenuItem(navigateItems[i], navigateShortcuts[i]);
			item.addActionListener(printListener);
			navigateMenu.add(item);
			
		}
		
		menubar.add(fileMenu);
		menubar.add(navigateMenu);
		menubar.add(helpMenu);
		
		return menubar;
	}
	
	
	
	
	public void actionPerformed(ActionEvent event){}
	public static void main(String args[])
	{
		try
		{
			JFrame frame = new JFrame( "P2P FILE SHARING" );
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setJMenuBar(new myapp1());
			
			frame.pack();
			frame.setVisible(true);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}	
}