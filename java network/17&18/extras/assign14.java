/* Program to simulate paint brush.... on a frame
Combining 3 assignments
Nitin Kumar Agarwal*/

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*<APPLET CODE="assign14" HEIGHT=700 WIDTH=700></APPLET>*/

public class assign14 extends Applet implements ActionListener
{


	Button btnshow,btnhide;
	myframe frmobj;
	public void init()
	{

		
		btnshow = new Button("Show the frame");
		btnshow.addActionListener(this);
		add(btnshow);
		
		btnhide = new Button("Hide the frame");
		btnhide.addActionListener(this);
		add(btnhide);
		
		//Creating the object of subclass of Frame
		frmobj = new myframe("My Paint Box");
		frmobj.setSize(1000,700);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==btnshow)
		{
			frmobj.setVisible(true);	
			showStatus("Frame is visivle");
		}
		else
		{
			frmobj.setVisible(false);
			showStatus("Frame is not visible");
		}
	
	}

}

class myframe extends Frame implements ItemListener,ActionListener
{

	//Necessities for the Menu Bar and Menuitems
	MenuBar mbar = new MenuBar();
	Menu m1 = new Menu("File");
	MenuItem i1 = new MenuItem("New");
	MenuItem i2 = new MenuItem("Exit");



	Checkbox cbline,cbrect,cbcircle,cbclear,cbcolor,cbfillrect,cbfilloval,cbfreehand;
	CheckboxGroup cbg;
	Label lbl,lbl2,lbl3;
	boolean flag=false;
	int x1,y1,x2,y2;
	
	//Following six arrays are for storing what ever is been drawn and in which color with corresponding coordinates
	int arrx1[] = new int[10000];
	int arrx2[] = new int[10000];
	int arry1[] = new int[10000];
	int arry2[] = new int[10000];
	String type[]=new String[10000],selected_checkbox;
	Color color_type[] = new Color[10000];

	//Keepng account of number of figures
	int old_count=2;

	// Variables keeping the values associated with the color generated from the palette
	int red_value=0,green_value=0,blue_value=0;
	Color generated_color  =new Color(red_value,red_value,red_value);

	// If value is 0 then palette will not be repainted everytime paint is called, but if it is 1 then it will be
	int repaint_generated_color=0;

	myframe(String title)
	{
		super(title);
		mbar.add(m1);
		
		i1.addActionListener(this);
		i2.addActionListener(this);

		
		m1.add(i1);
		m1.add(i2);
		setMenuBar(mbar);
		

		//setLayout(new FlowLayout());
		setLayout(null);
		lbl =new Label("");
		lbl2 =new Label("");
		lbl3 =new Label("");
	
		lbl.setBounds(60,125,550,20);
		lbl2.setBounds(60,150,550,20);
		lbl3.setBounds(60,175,550,20);
		add(lbl);
		add(lbl2);
		add(lbl3);
		cbg = new CheckboxGroup();
		cbline = new Checkbox("Draw Line",cbg,false);
		cbrect = new Checkbox("Draw Rectangle",cbg,false);
		cbcircle = new Checkbox("Draw Circle",cbg,false);
		cbfillrect = new Checkbox("Filled Rect",cbg,false);		
		cbfilloval = new Checkbox("Filled Oval",cbg,false);		
		cbfreehand = new Checkbox("Free Hand",cbg,false);

		cbclear = new Checkbox("Clear",cbg,false);
			
		cbcolor = new Checkbox("Use color");
		
		cbline.setBounds(60,70,150,20);
		cbrect.setBounds(210,70,150,20);
		cbcircle.setBounds(360,70,150,20);		
		cbclear.setBounds(520,70,150,20);		
		cbfillrect.setBounds(60,100,150,20);
		cbfilloval.setBounds(210,100,150,20);
		cbfreehand.setBounds(360,100,150,20);

		cbcolor.setBounds(520,100,150,20);
	

		add(cbline);
		add(cbrect);
		add(cbcircle);
		add(cbclear);
		add(cbfillrect);
		add(cbfilloval);
		add(cbfreehand);
		add(cbcolor);


		cbline.addItemListener(this);
		cbrect.addItemListener(this);
		cbcircle.addItemListener(this);
		cbclear.addItemListener(this);
		cbfillrect.addItemListener(this);
		cbfilloval.addItemListener(this);
		cbfreehand.addItemListener(this);
		
//		addMouseListener(this);

		//Coordinates for the paint area
		arrx1[0]= 50;
		arry1[0]= 220;
		arrx2[0]= 950;
		arry2[0]= 679;
		type[0] ="rect";
		color_type[0] = generated_color;						

		arrx1[1]= 50;
		arry1[1]= 50;
		arrx2[1]= 950;
		arry2[1]= 200;
		type[1] ="rect";
		color_type[0] = generated_color;						

		addWindowListener(new WindowAdapter()
				{
					public void windowClosing(WindowEvent we)
					{
						old_count=2;
						setVisible(false);
					}
				});
		

		addMouseListener(new MouseAdapter()
		{	

			public void mousePressed(MouseEvent e)
			{
				//e.getModifier() returns an integer value represented by the mouse button 
				if((e.getModifiers() & InputEvent.BUTTON1_MASK)==InputEvent.BUTTON1_MASK)
				{	
							
					x1 = e.getX();
					y1 = e.getY();
					// catching mouse event on the color palettes and making the final color object
					if(x1<757 && x1>=677 && y1<141 && y1>=61)
						give_color(x1,y1,677,61,"red");
 					else if(x1<845 && x1>=765 && y1<141 && y1>=61)	
						give_color(x1,y1,765,61,"green");				
					else if(x1<933 && x1>=853 && y1<141 && y1>=61)
						give_color(x1,y1,853,61,"blue");						

					lbl2.setText("Red = " + red_value + " Green = " + green_value + " Blue = " + blue_value);	

					//left mouse click happened in the paint area only					
					if(x1>50 && x1<950 &&  y1>220 &&y1<670)
						flag=true;
					lbl.setText(" LEft Mouse Button down at x = " + x1 + " y = " + y1 + flag );
					
				}		
				else
				{
					x2 = e.getX();
					y2 = e.getY();
					if(selected())
					{
						// right mouse click happened in the paint area only
						if(flag && x2>50 && x2 <950 &&  y2>220 &&y2<670)
						{
							type[old_count] = selected_checkbox;
							arrx1[old_count] = x1;
							arry1[old_count] = y1;
								arrx2[old_count] = x2;
							arry2[old_count] = y2;
							if(cbcolor.getState())
								color_type[old_count] = generated_color;
							else
								color_type[old_count] = color_type[old_count-1];
							old_count++;
							repaint(50,200,900,470);
							flag=false;
						}
						else
							flag = false;
					}	
					lbl.setText("Right Mouse Button down at x = " + x2 + " y = " + y2 + flag +" total Line = " + old_count + selected_checkbox);
				}							

			}
		});	
	
		addMouseMotionListener(new MouseMotionAdapter()
		{
			public void mouseDragged(MouseEvent me)
			{
				if(me.getX()>50 && me.getX()<950 &&  me.getY()>220 &&me.getY()<670)
				{
					if((me.getModifiers()&InputEvent.BUTTON1_MASK)==InputEvent.BUTTON1_MASK)
					{
						lbl3.setText("Button 1 Dragged at x = " + me.getX() + " y = " + me.getY());
						if(cbfreehand.getState())
						{
							type[old_count] = "line";
							arrx1[old_count] = me.getX();
							arry1[old_count] = me.getY();
							arrx2[old_count] = arrx1[old_count];
							arry2[old_count] = arry1[old_count];
							if(cbcolor.getState())
								color_type[old_count] = generated_color;
							else
								color_type[old_count] = color_type[old_count-1];
							old_count++;
							repaint(50,200,900,470);
						}
						
				
					}
					else
						lbl3.setText("Button 2 Dragged at x = " + me.getX() + " y = " + me.getY());
				}
			}
		});	
		addMouseMotionListener(new MouseMotionAdapter()
		{
			public void mouseMoved(MouseEvent me)
			{
				if(me.getX()>50 && me.getX()<950 &&  me.getY()>220 &&me.getY()<670)
					lbl3.setText("Mouse moved at x = " + me.getX() + " y = " + me.getY());
			}
		});
		
		
	}

	public void itemStateChanged(ItemEvent ie)
	{
		flag = false;

	}


	private void give_color(int x,int y,int limit_x,int limit_y,String color)
	{

		float temp_colorx=0.0f,temp_colory=0.0f;
		int temp_color_value=0;
		
		temp_colorx = (x-limit_x)/5.0f;
		temp_colory = (y-limit_y)/5.0f;
		temp_color_value = (int)(temp_colorx+(16*((int)temp_colory)));
		if(color.equals("red"))
			red_value = temp_color_value;
		else if(color.equals("green"))
			green_value = temp_color_value;
		else
			blue_value = temp_color_value;
		repaint_generated_color = 1;		
		generated_color =new Color(red_value,green_value,blue_value);

		//Painting the palette with the generated color
		repaint(676,150,258,40);
		
			
	}
		

	public void paint(Graphics g)
	{
		double temp;
		
		
		for(int i=0;i<old_count;i++)
			if(type[i].equals("line") )
			{
				
				g.setColor(color_type[i]);  
				g.drawLine(arrx1[i],arry1[i],arrx2[i],arry2[i]);
			}
			else //if(type[i].equals("rect") || type[i].equals("clear") ||type[i].equals("circle"))
			{
				//Following two ifs are two check if x2 < x1 or y2 < y1, and tomake necessary changes
				
				g.setColor(color_type[i]);			

				if(arrx2[i] < arrx1[i])
				{
					int tempx = arrx1[i];
					arrx1[i]   = arrx2[i];
					arrx2[i]   = tempx;
				}
				if(arry2[i] < arry1[i])
				{
					int tempy = arry1[i];
					arry1[i]   = arry2[i];
					arry2[i]   = tempy;
				}
				if(type[i].equals("rect"))
				{	  
					//g.setColor(Color.blue);  
					g.drawRect(arrx1[i],arry1[i],Math.abs(arrx2[i]-arrx1[i]),Math.abs(arry2[i]-arry1[i]));
				}
				else if(type[i].equals("clear"))
				{
					g.setColor(Color.white);  
					g.fillRect(arrx1[i],arry1[i],Math.abs(arrx2[i]-arrx1[i]),Math.abs(arry2[i]-arry1[i]));
					g.setColor(generated_color);
				}
				else if(type[i].equals("fillrect"))
				{
					g.fillRect(arrx1[i],arry1[i],Math.abs(arrx2[i]-arrx1[i]),Math.abs(arry2[i]-arry1[i]));
				}
				else if(type[i].equals("filloval"))
				{
					g.fillOval(arrx1[i],arry1[i],arrx2[i]-arrx1[i],arry2[i]-arry1[i]);
				}		
				else
				{
					g.drawOval(arrx1[i],arry1[i],arrx2[i]-arrx1[i],arry2[i]-arry1[i]);
				}	
			}
				
			if(old_count==2)
			{	
				g.setColor(Color.black);
//				g.drawRect(50,50,900,150);
				

				g.drawRect(676,60,81,81);
				g.drawRect(764,60,81,81);
				g.drawRect(852,60,81,81);
				g.setColor(generated_color);
				g.fillRect(676,150,258,40);
					
				// Drawing color palette for red green blue colorss
				draw_palette(677,61,g,"red");
				draw_palette(765,61,g,"green");
				draw_palette(853,61,g,"blue");
	
							
			}
			
			if(repaint_generated_color==1)
			{
				g.setColor(generated_color);
				g.fillRect(676,150,258,40);
				repaint_generated_color=0;
			}				
	}
	private void draw_palette(int a,int b,Graphics g,String color)
	{
		Color c;
		int x=a,y=b;
		for(int i=0;i<256;i++,x=x+5)
		{
			if(color.equals("red"))
				c = new Color(i,0,0);
			else if(color.equals("green"))
				c = new Color(0,i,0);
			else
				c = new Color(0,0,i);
	
			g.setColor(c);
			g.fillRect(x,y,5,5);
			if(i%16==15)
			{
				y=y+5;	
				x = a-5;
			}
		}		
	}
	private boolean selected()
	{
		if(cbline.getState())
			selected_checkbox ="line";
		else if(cbrect.getState())
			selected_checkbox ="rect";
		else if(cbclear.getState())
			selected_checkbox ="clear";
		else if(cbfillrect.getState())
			selected_checkbox ="fillrect";
		else if(cbfilloval.getState())
			selected_checkbox ="filloval";
		else
			selected_checkbox="circle";

		if (cbline.getState() | cbrect.getState() | cbcircle.getState() | cbclear.getState()|cbfillrect.getState()|cbfilloval.getState())
			return true;
		return false;

	}


	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==i1)
		{
			old_count=2;
			red_value=0;
			green_value=0;
			blue_value=0;
	
			repaint();
		}
		else if(ae.getSource()==i2)
		{
			old_count=2;
			setVisible(false);
		}
			

	}


}