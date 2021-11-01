#include<iostream.h>  
#include<conio.h>  
#include<stdio.h>  
#include<graphics.h>  
#include<math.h>  
#include<string.h>  
#include<stdlib.h>  
#include<dos.h>  
union REGS in,out;  
void showmouseptr()         //showing mouse pointer  
{  
in.x.ax=1;  
int86(51,&in,&out);  
}  
void hidemouseptr()       // hide mouse pointer  
{  
in.x.ax=2;  
int86(51,&in,&out);  
}  
void getmousepos(int &b,int &x,int &y)     // get mouse position  
{  
in.x.ax=3;  
int86(51,&in,&out);  
b=out.x.bx;  
x=out.x.cx;  
y=out.x.dx;  
}  
void setpos()   // setting position for mouse pointer  
{  
in.x.ax=4;  
in.x.cx=420;  
in.x.dx=320;  
int86(51,&in,&out);  
}  
void horizlimit()     // setting horizontal limit for mouse pointer  
{  
in.x.ax=7;  
in.x.cx=2;  
in.x.dx=630;  
int86(51,&in,&out);  
}  
void vertlimit()   // setting vertical limit for mouse pointer  
{  
in.x.ax=8;  
in.x.cx=1;  
in.x.dx=440;  
int86(51,&in,&out);  
}  
void press()              // press/double click/click guide  
{ while(!kbhit())  
{ setcolor(WHITE);  
outtextxy(180,440,">");  
outtextxy(450,440,"<");  
delay(1000);  
outtextxy(170,440,">");  
outtextxy(460,440,"<");  
delay(1000);  
outtextxy(160,440,">");  
outtextxy(470,440,"<");  
delay(1000);  
setcolor(BLACK);  
setfillstyle(SOLID_FILL,BLACK);  
pieslice(160,440,0,360,35);  
pieslice(460,440,0,360,26);  
delay(1000);  
}  
}  
void bar()  
{ int x=170;  
setcolor(7);  
rectangle(170,200,470,220);  
delay(15);  
setcolor(15);  
for(int i=0;i<300;i++)  
{  delay(5);  
line(x,200,x,220);  
x++; }  
}  
void loading()  
{ cleardevice();  
setcolor(WHITE);  
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);  
outtextxy(170,180,"LOADING,PLEASE WAIT");  
bar();  
}  
void exit()  
{ cleardevice(); setbkcolor(BLACK);  
setcolor(WHITE);  
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);  
outtextxy(170,180,"PROCEEDING TO EXIT...");  
bar();  
}  
void back()  
{ setcolor(11);  
line(40,400,100,400);         ///*BACK ARROW  
line(40,430,100,430);  
line(100,400,100,430);  
  line(40,400,40,385);  
  line(40,430,40,445);  
  line(40,385,0,415);  
  line(40,445,0,415);             //    BACK ARROW*/  
  // rectangle(20,400,100,430);  
  setcolor(9);  
  settextstyle(0,0,2);  
  outtextxy(30,410,"BACK");  
}  
void instruction()  
{ cleardevice();  
  setbkcolor(3);  
  setcolor(9);  
  rectangle(10,10,630,340);  
  setcolor(10);  
  rectangle(15,15,625,335);  
  setcolor(6);  
  settextstyle(1,0,4);  
  outtextxy(200,15,"INSTRUCTIONS");  
  setcolor(BLUE);  
  settextstyle(1,0,1);  
  outtextxy(20,70,"As you will press SPACE,a dialog box will appear on the screen.");  
  outtextxy(20,90,"Then,insert your value and then press ENTER to get your result.");  
  outtextxy(20,140,"Please note that until and unless,the values are inserted in ");  
  outtextxy(20,160,"the dialog box and the required result is received,one can't use ");  
  outtextxy(20,180,"the back or tutorial or clean buttons. Once the result is ");  
  outtextxy(20,200,"received, the buttons can be used then,by just clicking on ");  
  outtextxy(20,220,"them.");  
  outtextxy(20,260,"Press ESCAPE to exit from the Number System Converter.");  
}  
void finstruction()         // DECIMAL INSTRUCTIONS  
{ cleardevice();  
  setbkcolor(3);  
  setcolor(9);  
  rectangle(10,10,630,340);  
  setcolor(10);  
  rectangle(15,15,625,335);  
  setcolor(6);  
  settextstyle(1,0,4);  
  outtextxy(200,15,"INSTRUCTIONS");  
  setcolor(BLUE);  
  settextstyle(1,0,1);  
  outtextxy(20,70,"As you will press SPACE,a dialog box will appear on the screen.");  
  outtextxy(20,90,"Then,insert the INTEGER value and press ENTER to enter the");  
  outtextxy(20,110,"DECIMAL value without decimal point. Then press ENTER to get ");  
  outtextxy(20,130,"the result.");  
  outtextxy(20,160,"Please note that until and unless,the values are inserted in the");  
  outtextxy(20,180,"dialog box and the required result is received,one can't use the");  
  outtextxy(20,200,"back or tutorial or clean buttons. Once the result is received,");  
  outtextxy(20,220,"the buttons can be used then,by just clicking on them.");  
  outtextxy(20,260,"Press ESCAPE to exit from the Number System Converter.");  
}  
void note()  
{ setcolor(RED);  
  outtextxy(70,280,"You can enter integer value upto 10 digits only.");  
}  
void t_guide()      // TUTORIAL GUIDE  
{ setbkcolor(3);  
  setcolor(BLUE);  
  settextstyle(1,0,3);  
  outtextxy(55,145,"Press SPACE key to exit the TUTORIAL Window ");  
  outtextxy(130,175,"and go back to the Dialogbox. ");  
  rectangle(20,120,622,230);  
  setcolor(5);  
  rectangle(25,125,617,225);  
}  
void dialogbox()       // dialog box for entering value and giving output  
{ cleardevice();  
  setbkcolor(0);  
  setcolor(9);  
  rectangle(50,100,600,375);  
  rectangle(150,220,500,170);  
  rectangle(150,280,500,330);  
  setcolor(11);  
  line(40,400,100,400);        //*/BACK ARROW  
  line(40,430,100,430);  
  line(100,400,100,430);  
  line(40,400,40,385);  
  line(40,430,40,445);  
  line(40,385,0,415);  
  line(40,445,0,415);                      //BACK ARROW*/  
  rectangle(590,440,490,400);    //CLEAN RECTANGLE BOX  
  rectangle(230,440,390,400);  //TUTORIAL RECTANGLE BOX  
  settextstyle(8,0,4);  
  outtextxy(150,120,"Enter any value:");  
  outtextxy(150,230,"Result:");  
  setcolor(9);  
  settextstyle(0,0,2);  
  outtextxy(30,410,"BACK");  
  outtextxy(250,413,"TUTORIAL");  
  outtextxy(501,413,"CLEAN");  
}  
void fdialogbox()      // FLOAT DIALOG BOX  
{ cleardevice();  
  setbkcolor(0);  
  setcolor(9);  
  rectangle(50,100,600,375);  
  rectangle(80,220,320,170);  
  rectangle(350,220,575,170);  
  rectangle(150,280,500,330);  
  setcolor(11);  
  line(40,400,100,400);          //*/BACK ARROW  
  line(40,430,100,430);  
  line(100,400,100,430);  
  line(40,400,40,385);  
  line(40,430,40,445);  
  line(40,385,0,415);  
  line(40,445,0,415);                 //BACK ARROW*/  
  rectangle(590,440,490,400);   // CLEAN RECTANGLE BOX  
  rectangle(230,440,390,400);  //TUTORIAL RECTANGLE BOX  
  settextstyle(8,0,2);  
  outtextxy(75,120,"Enter integer value:");  
  outtextxy(350,120,"Enter decimal value:");  
  outtextxy(150,230,"Result:");  
  settextstyle(11,0,1);  
  outtextxy(360,155,"(without decimal point)");  
  setcolor(9);  
  settextstyle(0,0,2);  
  outtextxy(30,410,"BACK");  
  outtextxy(250,413,"TUTORIAL");  
  outtextxy(501,413,"CLEAN");  
}  
void yesno()             // YES/NO DIALOG BOX  
{ cleardevice();  
  settextstyle(1,0,4);  
  outtextxy(45,150,"IS YOUR NUMBER IN DECIMAL ??");  
  setcolor(WHITE);  
  setfillstyle(9,9);  
  bar(250,230,100,300);  
  bar(290,230,440,300);  
  settextstyle(1,0,7);  
  outtextxy(125,225,"Yes");  
  outtextxy(325,225,"No");  
}  
void index()                 // index of the program function  
{  
  bar3d(57,106,577,146,9,1);  
  bar3d(57,170,577,210,9,1);  
  bar3d(57,234,577,274,9,1);  
  bar3d(57,298,577,338,9,1);  
  settextstyle(7,0,4);  
  setcolor(BLUE);  
  outtextxy(155,105,"Binary Conversion");  
  outtextxy(150,169,"Decimal Conversion");  
  outtextxy(180,233,"Octal Conversion");  
  outtextxy(120,297,"Hexadecimal Conversion");  
}  
void selectionlist()         // selection list function  
{  
  settextstyle(7,0,1);  
  outtextxy(0,85,"IN WHICH NUMBER SYSTEM WOULD YOU LIKE TO CONVERT");  
  outtextxy(0,110,"YOUR NUMBER?");  
  setfillstyle(9,9);  
  settextstyle(7,0,4);  
  bar3d(67,150,567,200,9,1);  
  bar3d(67,230,567,280,9,1);  
  bar3d(67,310,567,360,9,1);  
}  
void style()  
{ settextstyle(7,0,5);  
  setcolor(WHITE);  
}  
void tutorial()  
{  cleardevice();  
   setbkcolor(3);  
   setcolor(BLUE);  
   settextstyle(1,0,4);  
   outtextxy(220,15,"TUTORIAL");  
   settextstyle(0,0,2);  
   setcolor(9);  
   rectangle(10,10,630,340);  //OUTER RECTANGLE  
   setcolor(10);  
   rectangle(15,15,625,335);  // INNER RECTANGLE  
}  
void hexbintable()       // HEX->BINARY TABLE  
{  
   setcolor(BLUE);  
   rectangle(50,75,300,90);  
   rectangle(50,75,150,330);  
   rectangle(50,90,300,105);  
   rectangle(50,105,300,120);  
   rectangle(50,120,300,135);  
   rectangle(50,135,300,150);  
   rectangle(50,150,300,165);  
   rectangle(50,165,300,180);  
   rectangle(50,180,300,195);  
   rectangle(50,195,300,210);  
   rectangle(50,210,300,225);  
   rectangle(50,225,300,240);  
   rectangle(50,240,300,255);  
   rectangle(50,255,300,270);  
   rectangle(50,270,300,285);  
   rectangle(50,285,300,300);  
   rectangle(50,300,300,315);  
   rectangle(50,315,300,330);  
   settextstyle(11,0,1 );  
   outtextxy(60,79,"Hex Digit   Binary Equivalent");  
   outtextxy(90,94, "0              0000");  
   outtextxy(90,110,"1              0001");  
   outtextxy(90,124,"2              0010");  
   outtextxy(90,140,"3              0011");  
   outtextxy(90,154,"4              0100");  
   outtextxy(90,170,"5              0101");  
   outtextxy(90,184,"6              0110");  
   outtextxy(90,200,"7              0111");  
   outtextxy(90,214,"8              1000");  
   outtextxy(90,230,"9              1001");  
   outtextxy(90,244,"A              1010");  
   outtextxy(90,260,"B              1011");  
   outtextxy(90,274,"C              1100");  
   outtextxy(90,290,"D              1101");  
   outtextxy(90,304,"E              1110");  
   outtextxy(90,320,"F              1111");  
}  
void bindect()         // BINARY TO DECIMAL TUTORIAL  
{  tutorial();  
   setcolor(6);  
   outtextxy(170,55,"BINARY->DECIMAL");  
   settextstyle(1,0,2);  
   outtextxy(100,155,"Converting Binary Fractions to Decimal");  
   setcolor(BLUE);  
   settextstyle(11,0,1);  
   outtextxy(20,75,"Any binary number can be converted to its decimal equivalent by summing");  
   outtextxy(20,85,"together the weights of the various positions in the binary number which");  
   outtextxy(20,95,"contain a 1.Let us consider a binary no. 11011.");  
   outtextxy(340,119,"(binary)");  
   outtextxy(510,149,"2  (decimal)");  
   outtextxy(20,185,"Let us take an example to illustrate the procedure.");  
   outtextxy(25,225,"0.0101");  
   outtextxy(75,229,"2");  
   rectangle(230,107,250,127);        //BINARY->DECIMAL EXAMPLE  
   rectangle(250,107,270,127);  
   rectangle(270,107,290,127);  
   rectangle(290,107,310,127);  
   rectangle(310,107,330,127);  
   settextstyle(1,0,1);  
   outtextxy(235,104,"1");  
   outtextxy(255,104,"1");  
   outtextxy(275,104,"0");  
   outtextxy(295,104,"1");  
   outtextxy(315,104,"1");  
   outtextxy(200,135,"->2 +2 +0+2 +2 =16+8+2+1=27 ");  
   settextstyle(11,0,0);  
   outtextxy(235,135,"4");  
   outtextxy(267,135,"3");  
   outtextxy(325,135,"2");  
   outtextxy(357,135,"1");             // EXAMPLE COMPLETED  
   outtextxy(130,222,"Binary Point.");  
   outtextxy(245,195,"-1");  
   outtextxy(275,195,"-2");  
   outtextxy(305,195,"-3");  
   outtextxy(335,195,"-4");  
   outtextxy(143,240,"-1");  
   outtextxy(209,240,"-2");  
   outtextxy(278,240,"-3");  
   outtextxy(343,240,"-4");  
   outtextxy(283,285,"2");  
   outtextxy(380,285,"10");  
   rectangle(230,217,260,237);  
   rectangle(260,217,290,237);  
   rectangle(290,217,320,237);  
   rectangle(320,217,350,237);  
   settextstyle(1,0,1);  
   outtextxy(242,214,"0");  
   outtextxy(272,214,"1");  
   outtextxy(300,214,"0");  
   outtextxy(330,214,"1");  
   outtextxy(237,195,"2  2  2  2");  
   outtextxy(110,242,"(0x2 )+(1x2 )+(0x2 )+(1x2 )=0+0.25+0.0625=0.3125");  
   outtextxy(220,270,"0.0101 = 0.3125");  
}  
void binoctt()       // BINARY TO OCTAL TUTORIAL  
{  tutorial();  
   setcolor(6);  
   outtextxy(190,55,"BINARY->OCTAL");  
   setcolor(BLUE);  
   settextstyle(11,0,1);  
   outtextxy(20,75,"The bits of the binary integer are grouped into groups of 3 bits starting");  
   outtextxy(20,85,"at the LSB.Then each group is converted to its octal equivalent.When the");  
   outtextxy(20,95,"binary number does not have even groups of 3 bits, we add one or two 0s to");  
   outtextxy(20,105,"the left of MSB to fill out the last group.The same process applies on");  
   outtextxy(20,115,"fractions.But after decimal point,0s are added to the right.");  
   outtextxy(20,187,"For example,");  
   outtextxy(141,217,"2");  
   outtextxy(170,185,"0 added here to ");  
   outtextxy(150,195,"make a group of 3 bits");  
   outtextxy(250,262,"2         8");  
   outtextxy(470,195,"2 0s added here to");  
   outtextxy(465,205,"make it a group of 3");  
   rectangle(65,135,575,155);  
   rectangle(65,155,575,175);  
   rectangle(65,135,220,175);  
   settextstyle(1,0,1);  
   outtextxy(70,132,"Binary Digit");  
   outtextxy(70,152,"Octal Equivalent");  
   outtextxy(225,132,"000 001 010 011 100 101 110 111");  
   outtextxy(225,152," 0    1    2   3   4    5    6    7");  
   outtextxy(30,200,"10110.0101 =            010 110 . 010 100");  
   outtextxy(288,220,"2   6     2    4");  
   outtextxy(140,246,"11010.0101 =26.24");  
}  
void binhext()  
{  tutorial();  
   setcolor(6);  
   outtextxy(155,55,"BINARY->HEXADECIMAL");  
   setcolor(BLUE);  
   hexbintable();  
   settextstyle(11,0,1);  
   outtextxy(305,75,"Binary numbers can be easily converted");  
   outtextxy(305,85,"to hexadecimal by grouping in groups of");  
   outtextxy(305,95,"four starting at the binary point. ");  
   outtextxy(305,115,"Let us consider the following example,");  
   outtextxy(330,160,"Groups in fours");  
   outtextxy(330,170,"(Inserting zeroes wherever required)");  
   outtextxy(548,148,"2");  
   outtextxy(490,248,"2         16");  
   settextstyle(1,0,1);  
   outtextxy(375,130," 1101110.010111");  
   outtextxy(338,180,"0110 1110 . 0101 1100");  
   outtextxy(358,200,"6     E   .   5    C");  
   outtextxy(330,230,"1101110.010111 = 6E.5C");  
}  
void decbint()  
{  tutorial();  
   setcolor(6);  
   outtextxy(180,55,"DECIMAL->BINARY");  
   settextstyle(1,0,2);  
   outtextxy(100,205,"Converting Decimal Fractions to Binary");  
   setcolor(BLUE);  
   settextstyle(11,0,1);  
   outtextxy(20,75,"To convert decimal number to binary number,the number is successively");  
   outtextxy(20,85,"divided by 2 and the remainders are recorded. The final binary result is");  
   outtextxy(20,95,"obtained by assembling all the remainders, with the last remainder being");  
   outtextxy(20,105,"the most significant bit(MSB). Let us consider a decimal number 26.");  
   outtextxy(20,230,"To convert decimal fraction into binary, the procedure is to successively");  
   outtextxy(20,240,"multiply the fractional part by the base (2 in this case) & collect all");  
   outtextxy(20,250,"numbers to the left of the decimal point, reading down.");  
   outtextxy(20,265,"Example:- 0.375                Integer Part");  
   outtextxy(70,275,"0.375 x 2 = 0.750             0");  
   outtextxy(70,285," 0.75 x 2 = 1.50              1");  
   outtextxy(70,295," 0.50 x 2 = 1.00              1");  
   outtextxy(20,315,"To convert a mixed number to binary,1st convert integer part ");  
   outtextxy(20,325,"to its binary equivalent, then the fractional part.");  
   line(150,140,150,200);   outtextxy(137,143,"2   26");  
   line(130,150,200,150);   outtextxy(137,153,"2   13               0");  
   line(130,160,200,160);   outtextxy(137,163,"2    6               1");  
   line(130,170,200,170);   outtextxy(137,173,"2    3               0");  
   line(130,180,200,180);   outtextxy(137,183,"2    1               1");  
   line(130,190,200,190);   outtextxy(137,193,"     0               1");  
   outtextxy(100,130,"Repeated Division    Remainders");  
   outtextxy(475,155,"10          2");  
   outtextxy(508,273,"10         2");  
   line(380,155,380,195);   //INDICATING LINE  
   line(380,155,377,158);   line(380,155,383,158); //INDICATING UPWARD ARRROW  
   outtextxy(370,143,"LSB"); outtextxy(370,200,"MSB");  
   outtextxy(400,173,"Write in this order");  
   line(380,280,380,305);      // INDICATING LINE  
   line(380,305,377,302);    line(380,305,383,302); //INDICATING DOWNWARD ARROW  
   outtextxy(390,280,"Write in this"); outtextxy(400,290,"order");  
   settextstyle(3,0,1);  
   outtextxy(450,140,"26  =11010");  
   outtextxy(455,255,"0.375  =0.011");  
}  
void decoctt()      // DECIMAL TO OCTAL TUTORIAL  
{  tutorial();  
   setcolor(6);  
   outtextxy(180,55,"DECIMAL->OCTAL");  
   settextstyle(1,0,2);  
   outtextxy(100,205,"Converting Decimal Fractions to Octal");  
   setcolor(BLUE);  
   settextstyle(11,0,1);  
   outtextxy(20,75,"To convert decimal number to octal number,the number is successively");  
   outtextxy(20,85,"divided by 8 and the remainders are recorded. The final octal result is");  
   outtextxy(20,95,"obtained by assembling all the remainders, with the last remainder being");  
   outtextxy(20,105,"the most significant bit(MSB). Let us consider a decimal number 266.");  
   outtextxy(20,230,"To convert decimal fraction into octal, the procedure is to successively");  
   outtextxy(20,240,"multiply the fractional part by the base (8 in this case) & collect all");  
   outtextxy(20,250,"numbers to the left of the decimal point, reading down.");  
   outtextxy(20,265,"Example:- 0.015625                Integer Part");  
   outtextxy(70,275,"0.015625 x 8 = 0.125             0");  
   outtextxy(70,285,"   0.125 x 8 = 1.0               1");  
   outtextxy(20,315,"To convert a mixed number to octal,1st convert integer part ");  
   outtextxy(20,325,"to its octal equivalent, then the fractional part.");  
   line(150,140,150,180);   outtextxy(137,143,"8   266");  
   line(130,150,200,150);   outtextxy(137,153,"8   33               2");  
   line(130,160,200,160);   outtextxy(137,163,"8    4               1");  
   line(130,170,200,170);   outtextxy(137,173,"     0               4");  
   outtextxy(100,130,"Repeated Division    Remainders");  
   line(380,155,380,175);   //INDICATING LINE  
   line(380,155,377,158);   line(380,155,383,158); //INDICATING UPWARD ARRROW  
   outtextxy(370,143,"LSB"); outtextxy(370,180,"MSB");  
   outtextxy(400,163,"Write in this order");  
   line(380,275,380,295);      // INDICATING LINE  
   line(380,295,377,292);    line(380,295,383,292); //INDICATING DOWNWARD ARROW  
   outtextxy(390,280,"Write in this"); outtextxy(400,290,"order");  
   outtextxy(265,195,"10       2");  
   outtextxy(293,304,"10        2");  
   settextstyle(3,0,1);  
   outtextxy(230,180,"266  =412");  
   outtextxy(200,290,"0.015625  =0.01");  
}  
void dechext()         // DECIMAL TO HEX TUTORIAL  
{  tutorial();  
   setcolor(6);  
   outtextxy(150,55,"DECIMAL->HEXADECIMAL");  
   settextstyle(1,0,2);  
   outtextxy(100,205,"Converting Decimal Fractions to Hexadecimal");  
   setcolor(BLUE);  
   settextstyle(11,0,1);  
   outtextxy(20,75,"To convert decimal number to hexadecimal number,the number is successively");  
   outtextxy(20,85,"divided by 16 and the remainders are recorded. The final hex result is");  
   outtextxy(20,95,"obtained by assembling all the remainders, with the last remainder being");  
   outtextxy(20,105,"the most significant bit(MSB). Let us consider a decimal number 423.");  
   outtextxy(20,230,"To convert decimal fraction into hex, the procedure is to successively");  
   outtextxy(20,240,"multiply the fractional part by the base (16 in this case) & collect all");  
   outtextxy(20,250,"numbers to the left of the decimal point, reading down.");  
   outtextxy(20,265,"Example:- 0.03125            Integer Part");  
   outtextxy(70,275,"0.03125 x 16 = 0.5         0");  
   outtextxy(70,285,"    0.5 x 16 = 8.0         8");  
   outtextxy(20,315,"To convert a mixed number to hex,1st convert integer part ");  
   outtextxy(20,325,"to its hex equivalent, then the fractional part.");  
   line(150,140,150,180);   outtextxy(135,143,"16  423");  
   line(130,150,200,150);   outtextxy(135,153,"16  26               7");  
   line(130,160,200,160);   outtextxy(135,163,"16   1               A");  
   line(130,170,200,170);   outtextxy(137,173,"     0               1");  
   outtextxy(100,130,"Repeated Division    Remainders");  
   line(380,155,380,175);   //INDICATING LINE  
   line(380,155,377,158);   line(380,155,383,158); //INDICATING UPWARD ARRROW  
   outtextxy(370,143,"LSB"); outtextxy(370,180,"MSB");  
   outtextxy(400,163,"Write in this order");  
   line(380,275,380,295);      // INDICATING LINE  
   line(380,295,377,292);    line(380,295,383,292); //INDICATING DOWNWARD ARROW  
   outtextxy(390,280,"Write in this"); outtextxy(400,290,"order");  
   outtextxy(265,195,"16       2");  
   outtextxy(285,304,"16       2");  
   settextstyle(3,0,1);  
   outtextxy(230,180,"423  =1A7");  
   outtextxy(200,290,"0.03125  =0.08");  
}  
void octbint()        // OCTAL TO BINARY TUTORIAL  
{ tutorial();  
  setcolor(BLUE);  
  rectangle(110,100,460,130);  
  rectangle(110,100,260,290);  
  rectangle(110,130,460,150);  
  rectangle(110,150,460,170);  
  rectangle(110,170,460,190);  
  rectangle(110,190,460,210);  
  rectangle(110,210,460,230);  
  rectangle(110,230,460,250);  
  rectangle(110,250,460,270);  
  rectangle(110,270,460,290);  
  settextstyle(1,0,1);  
  outtextxy(120,100,"OCTAL DIGIT     BINARY EQUIVALENT");  
  setcolor(6);       settextstyle(0,0,2);  
  outtextxy(190,55,"OCTAL->BINARY");  
  setcolor(BLUE);  
  settextstyle(11,0,1);  
  outtextxy(20,75,"The conversion from octal to binary is performed by converting each octal");  
  outtextxy(20,85,"digit to its 3-bit binary equivalent.The same process applies on fraction.");  
  outtextxy(20,295,"Example:");  
  outtextxy(140,300,"3   4 . 1   5 ");  
  outtextxy(124,310,"011 100 . 001 101 ");  
  outtextxy(100,320,"Thus,  34.15 = 11100.001101  ");  
  outtextxy(195,325,"8              2");  
  settextstyle(1,0,1);  
  outtextxy(170,127,"0                 000");  
  outtextxy(170,147,"1                 001");  
  outtextxy(170,167,"2                 010");  
  outtextxy(170,187,"3                 011");  
  outtextxy(170,207,"4                 100");  
  outtextxy(170,227,"5                 101");  
  outtextxy(170,247,"6                 110");  
  outtextxy(170,267,"7                 111");  
}  
void octdect()       // OCTAL TO DECIMAL TUTORIAL  
{ tutorial();  
  setcolor(6);  
  outtextxy(185,55,"OCTAL->DECIMAL");  
  setcolor(BLUE);  
  settextstyle(11,0,1);  
  outtextxy(20,75,"An octal number can be easily converted to its decimal equivalent by");  
  outtextxy(20,85,"multiplying each octal digit by its positional weight and then summing up");  
  outtextxy(20,95,"the products.");  
  outtextxy(20,115,"Let us take an example to illustrate the procedure.");  
  outtextxy(225,127,"2    1    0    -1");  
  outtextxy(233,190,"2         1         0         -1");  
  outtextxy(296,295,"8           10");  
  settextstyle(0,0,2);  
  outtextxy(315,155,".");  
  settextstyle(1,0,1);  
  rectangle(200,150,240,180);  
  rectangle(240,150,280,180);  
  rectangle(280,150,320,180);  
  rectangle(320,150,360,180);  
  outtextxy(215,125,"8   8   8   8");  
  outtextxy(215,155,"3");  
  outtextxy(255,155,"7");  
  outtextxy(295,155,"2");  
  outtextxy(335,155,"6");  
  outtextxy(160,190,"= 3 x 8 + 7 x 8 + 2 x 8 + 6 x 8");  
  outtextxy(160,220,"= 3 x 64 + 7 x 8 + 2 x 1 + 6 x 0.125");  
  outtextxy(160,250,"= 192 + 56 + 2 + 0.75 = 250.75");  
  outtextxy(180,280,"Thus, 372.6 = 250.75");  
}  
void octhext()         // OCTAL TO HEX TUTORIAL  
{ tutorial();  
  setcolor(6);  
  outtextxy(150,55,"OCTAL->HEXADECIMAL");  
  setcolor(BLUE);  
  settextstyle(11,0,1);  
  outtextxy(20,75,"To convert octal number to hexadecimal, it is easiest to first convert");  
  outtextxy(20,85,"octal to binary, then to hexadecimal.");  
  outtextxy(260,205,"(OCTAL TO BINARY)");  
  outtextxy(240,262,"(BINARY TO HEXADECIMAL)");  
  outtextxy(357,325,"8          16");  
  rectangle(105,105,575,125);  
  rectangle(105,125,575,145);  
  rectangle(105,105,210,145);  
  settextstyle(1,0,1);  
  outtextxy(125,102,"Octal ");  
  outtextxy(125,122,"Binary ");  
  outtextxy(225,102," 0    1    2   3   4    5    6    7");  
  outtextxy(225,122,"000 001 010 011 100 101 110 111");  
  rectangle(30,155,610,175);  
  rectangle(30,175,610,195);  
  rectangle(30,155,110,195);  
  outtextxy(40,152,"Binary ");  
  outtextxy(55,172,"Hex ");  
  outtextxy(40,200,"Example:-726.54");  
  outtextxy(240,215,"7    2    6 .  5    4");  
  outtextxy(225,235,"111 010 110 . 101 100");  
  outtextxy(225,270,"0001 1101 0110 . 1011");  
  outtextxy(242,290,"1     D     6   .   B");  
  outtextxy(230,310,"Thus, 726.54 = 1D6.B");  
  settextstyle(2,0,4);  
  outtextxy(120,160,"0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111");  
  outtextxy(130,180,"0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F");  
}  
void hexbint()    // HEX TO BINARY TUTORIAL  
{  tutorial();  
   setcolor(6);  
   outtextxy(150,55,"HEXADECIMAL->BINARY");  
   setcolor(BLUE);  
   hexbintable();  
   settextstyle(11,0,1 );  
   outtextxy(305,75,"Each hex digit is converted to its 4-bit ");  
   outtextxy(305,85,"binary equivalent. ");  
   outtextxy(305,95,"Consider a example, ");  
   outtextxy(60,79,"Hex Digit   Binary Equivalent");  
   outtextxy(90,94, "0              0000");  
   outtextxy(90,110,"1              0001");  
   outtextxy(90,124,"2              0010");  
   outtextxy(90,140,"3              0011");  
   outtextxy(90,154,"4              0100");  
   outtextxy(90,170,"5              0101");  
   outtextxy(90,184,"6              0110");  
   outtextxy(90,200,"7              0111");  
   outtextxy(90,214,"8              1000");  
   outtextxy(90,230,"9              1001");  
   outtextxy(90,244,"A              1010");  
   outtextxy(90,260,"B              1011");  
   outtextxy(90,274,"C              1100");  
   outtextxy(90,290,"D              1101");  
   outtextxy(90,304,"E              1110");  
   outtextxy(90,320,"F              1111");  
   outtextxy(380,178,"16                         2");  
   settextstyle(1,0,1);  
   outtextxy(345,115,"3     B      F  .    5    C ");  
   outtextxy(325,130,"0011 1011 1111 . 0101 1100");  
   outtextxy(318,160,"3BF.5C =1110111111.010111");  
}  
void hexdect()           // HEX TO DECIMAL TUTORIAL  
{  tutorial();  
   setcolor(6);  
   outtextxy(155,55,"HEXADECIMAL->DECIMAL");  
   setcolor(BLUE);  
   settextstyle(11,0,1);  
   outtextxy(20,75,"An hexadecimal number can be easily converted to its decimal equivalent by");  
   outtextxy(20,85,"multiplying each hex digit by its positional weight and then summing up");  
   outtextxy(20,95,"the products. In hexadecimal, A=10, B=11, C=12, D=13, E=14, F=15.");  
   outtextxy(20,115,"Let us take an example to illustrate the procedure.");  
   outtextxy(230,125,"2    1    0    -1   -2");  
   outtextxy(183,190,"2            1            0           -1          -2");  
   outtextxy(304,295,"16              10");  
   settextstyle(0,0,2);  
   outtextxy(315,155,".");  
   settextstyle(1,0,1);  
   rectangle(200,150,240,180);  
   rectangle(240,150,280,180);  
   rectangle(280,150,320,180);  
   rectangle(320,150,360,180);  
   rectangle(360,150,400,180);  
   outtextxy(206,125,"16  16  16  16  16");  
   outtextxy(215,155,"2");  
   outtextxy(255,155,"A");  
   outtextxy(295,155,"F");  
   outtextxy(335,155,"0");  
   outtextxy(375,155,"8");  
   outtextxy(100,190,"= 2 x 16 + 10 x 16 + 15 x 16 + 0 x 16 + 8 x 16");  
   outtextxy(100,220,"= 2 x 256 + 10 x 16 + 15 x 1 + 0 + 8/256");  
   outtextxy(100,250,"= 512 + 160 + 15 + 0.03125 = 687.03125");  
   outtextxy(180,280,"Thus, 2AF.08 = 687.03125");  
}  
void hexoctt()        // HEX->OCTAL TUTORIAL  
{ tutorial();  
  setcolor(6);  
  outtextxy(150,55,"HEXADECIMAL->OCTAL");  
  setcolor(BLUE);  
  settextstyle(11,0,1);  
  outtextxy(20,75,"To convert hexadecimal number to octal, it is easiest to first convert");  
  outtextxy(20,85,"hexadecimal to binary, then to octal.");  
  outtextxy(235,205,"(HEXADECIMAL TO BINARY)");  
  outtextxy(260,262,"(BINARY TO OCTAL)");  
  outtextxy(345,325,"16          8");  
  rectangle(30,105,610,125);  
  rectangle(30,125,610,145);  
  rectangle(30,105,110,145);  
  settextstyle(2,0,4);  
  outtextxy(130,110,"0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F");  
  outtextxy(120,130,"0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111");  
  rectangle(105,155,575,175);  
  rectangle(105,175,575,195);  
  rectangle(105,155,210,195);  
  settextstyle(1,0,1);  
  outtextxy(125,152,"Binary");  
  outtextxy(125,172,"Octal ");  
  outtextxy(225,152,"000 001 010 011 100 101 110 111");  
  outtextxy(225,172," 0    1    2   3   4    5    6    7");  
  outtextxy(40,122,"Binary ");  
  outtextxy(55,102,"Hex ");  
  outtextxy(40,200,"Example:-1D6.B");  
  outtextxy(233,215,"1     D     6   .  B");  
  outtextxy(215,235,"0001 1101 0110 . 1011");  
  outtextxy(225,270,"111 010 110 . 101 100");  
  outtextxy(242,290,"7   2    6  .   5   4");  
  outtextxy(230,310,"Thus, 1D6.B = 726.54");  
}  
int main(void)  
{ clrscr();  
  int gdriver = DETECT, gmode;  
  initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");  
  int e,b,x,y,b1,x1,y1,b2,x2,y2,b3,x3,y3,b4,x4,y4,b1a,x1a,y1a,b1a1,x1a1,  
  y1a1,b1b,x1b,y1b,b1b1,x1b1,y1b1,b1c,x1c,y1c,b1c1,x1c1,y1c1,b2a,x2a,y2a,  
  b2b,x2b,y2b,b2c,x2c,y2c,b3a,x3a,y3a,b3b,x3b,y3b,b3c,x3c,y3c,b3c1,x3c1,y3c1,  
  b4a,x4a,y4a,b4b,x4b,y4b,b4b1,x4b1,y4b1,b4c,x4c,y4c,b4c1,x4c1,y4c1;  
  int l=0,i=0;  
 // CREATING CALCULATOR FOR  FIRST PAGE  
    settextstyle(4,0,6);  
    outtextxy(25,15,"Number System Converter");  
    setcolor(9);  
    rectangle(200,100,435,425);  
    setcolor(11);  
    rectangle(215,115,420,170);  
    rectangle(215,190,260,235);  
    rectangle(215,190,260,235);  
    rectangle(295,190,340,235);  
    rectangle(375,190,420,235);  
    rectangle(215,250,260,295);  
    rectangle(295,250,340,295);  
    rectangle(375,250,420,295);  
    rectangle(215,310,260,355);  
    rectangle(295,310,340,355);  
    rectangle(375,310,420,355);  
    rectangle(215,370,260,415);  
    rectangle(295,370,420,415);  
    settextstyle(1,0,4);  
    setcolor(7);  
    outtextxy(231,193,"1");  
    outtextxy(310,193,"2");  
    outtextxy(389,193,"3");  
    outtextxy(231,250,"4");  
    outtextxy(310,250,"5");  
    outtextxy(389,250,"6");  
    outtextxy(231,310,"7");  
    outtextxy(310,310,"8");  
    outtextxy(389,310,"9");  
    outtextxy(231,370,"0");  
    outtextxy(310,370,"ENTER");  
 //PRESS ANY KEY GUIDE  
    setcolor(WHITE);  
    settextstyle(0,0,2);  
    outtextxy(220,440,"Press Any Key");  
    press();          // USING PRESS FUNCTION  
 //LOADING BAR 2ND PAGE  
    loading();  
    cleardevice();  
    abc:  
 // CREATING INDEX OF THE PROGRAM  3 PG  
     settextstyle(7,0,4);       // (FONT,HORIZ/VERT,SIZE)  
     setcolor(WHITE);   // SETS COLOR OF THE TEXT  
     outtextxy(200,20,"INDEX");  
     settextstyle(2,0,6);  
     setcolor(WHITE);  
     outtextxy(20,70,"IN WHAT SYSTEM WOULD YOU LIKE TO CHANGE YOUR NUMBER?");  
     setfillstyle(1,WHITE);        // (PATTERN/STYLE,COLOR)  
     index();                 // USING INDEX FUNCTION TO CREATE THE INDEX  
     showmouseptr();    // SHOWING MOUSE POINTER  
     setpos();       // SETTING POSITION OF MOUSE POINTER USING FUNCTION  
     horizlimit();    // SETTING HORIZONTAL LIMIT OF MOUSE PTR USING FUNCTION  
     vertlimit();    // SETTING VERTICAL LIMIT OF MOUSE PTR USING FUNCTION  
 // STARTING USE OF MOUSE POINTER  
 do  
 {  
  getmousepos(b,x,y);   //GETTING POSITION OF MOUSE POINTER  
  if(b==1)   // b=1 when left clicked  
  {  
   // INDEX->BINARY CONVERSION  
   if(x>=57 && x<=577 && y>=106 && y<=146)  
   { loading();  
     cleardevice();  
     A:  
     setcolor(WHITE);  
     settextstyle(4,0,6);  
     outtextxy(90,10,"Binary Conversion");  
     selectionlist();  
     outtextxy(160,155,"1.Binary -> Decimal");  
     outtextxy(180,235,"2.Binary -> Octal");  
     outtextxy(120,315,"3.Binary -> Hexadecimal");  
     back();  
     do  
     { getmousepos(b1,x1,y1);  
       if(b1==1)  
       { if(x1>=67 && x1<=567 && y1>=150 && y1<=200) // BINARY->DECIMAL  
     { loading();  
       yesno();  
       do  
       { getmousepos(b1a,x1a,y1a);  
         if(b1a==1)  
         { if(x1a>=100 && x1a<=250 && y1a>=230 && y1a<=300) //IF YES  
           { finstruction();  
         while(!kbhit())  
         { delay(1); }  
         C:  
         char bin[40];  
         int i,l,m;  
         long float dec=0;  
         unsigned long int num,no,sum=0, z=0,p,i1=0,r;  
         fdialogbox();  
         style();  
         outtextxy(110,20,"Binary -> Decimal");  
         //BINARY->DECIMAL PROCEDURE  
         gotoxy(20,13);  
         cin>>num;  
         no=num;  
         gotoxy(50,13);  
         cin>>bin;  
         do         //loop for integer part  
         {  
           z=num%10;    //taking out last digit  
           p=pow(2,i1);    //getting power of 2  
           r=z*p;           //multiplying last digit nd power of 2  
           sum=sum+r;  
           num=num/10;       //removing last digit  
           i1++;  
         }while(num>0);  
         l=strlen(bin);  
         for(i=0;i<l;i++)  
         { switch(bin[i])  
           {  case '0':  
              m=(0-i)-1;  
              dec=dec+0*pow(2,m);  
              break;  
              case '1':  
              m=(0-i)-1;  
              dec=dec+1*pow(2,m);  
              break;  
           }  
         } B:  
         gotoxy(27,20);  
         cout<<dec+sum;  
        do  
        { getmousepos(b1a1,x1a1,y1a1);  
          if(b1a1==1)  
          { if(x1a1>=230 && x1a1<=390 && y1a1>=400 && y1a1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               bindect();  
               while(!kbhit())  
               {  delay(1);  }  
               cleardevice();  
               fdialogbox();  
               style();  
               outtextxy(110,20,"Binary -> Decimal");  
               gotoxy(20,13);  
               cout<<no;  
               gotoxy(50,13);  
               cout<<bin;  
               goto B;  
            }  
            if(x1a1>=490 && x1a1<=590 && y1a1>=400 && y1a1<=440) //CLEAN  
            { cleardevice();  
              goto C;  
            }  
            if(x1a1>=20 && x1a1<=100 && y1a1>=400 && y1a1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
           if(x1a>=290 && x1a<=440 && y1a>=230 && y1a<=300) //IF NO  
           { instruction();  
         while(!kbhit())  
         { delay(1); }  
         CI:  
         unsigned long int num,no,sum=0, z=0,p,i1=0,r;  
         dialogbox();  
         style();  
         outtextxy(110,20,"Binary -> Decimal");  
         //BINARY->DECIMAL PROCEDURE  
         gotoxy(23,13);  
         cin>>num;  
         no=num;  
         do         //loop for integer part  
         {  
           z=num%10;    //taking out last digit  
           p=pow(2,i1);    //getting power of 2  
           r=z*p;           //multiplying last digit nd power of 2  
           sum=sum+r;  
           num=num/10;       //removing last digit  
           i1++;  
         }while(num>0);  
         BI:  
         gotoxy(27,20);  
         cout<<sum;  
        do  
        { getmousepos(b1a1,x1a1,y1a1);  
          if(b1a1==1)  
          { if(x1a1>=230 && x1a1<=390 && y1a1>=400 && y1a1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               bindect();  
               while(!kbhit())  
               {  delay(1);  }  
               cleardevice();  
               dialogbox();  
               style();  
               outtextxy(110,20,"Binary -> Decimal");  
               gotoxy(23,13);  
               cout<<no;  
               goto BI;  
            }  
            if(x1a1>=490 && x1a1<=590 && y1a1>=400 && y1a1<=440) //CLEAN  
            { cleardevice();  
              goto CI;  
            }  
            if(x1a1>=20 && x1a1<=100 && y1a1>=400 && y1a1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x1>=67 && x1<=567 && y1>=230 && y1<=280)// BINARY->OCTAL  
     { loading();  
       yesno();  
       do  
       { getmousepos(b1b,x1b,y1b);  
         if(b1b==1)  
         { if(x1b>=100 && x1b<=250 && y1b>=230 && y1b<=300) //IF YES  
           { finstruction();  
         note();  
         while(!kbhit())  
         { delay(1); }  
         Ci:  
         char bin[40];            // BIN->DEC VARIABLES  
         int i,l,m;  
         long float dec=0;  
         unsigned long int num,sum=0,numm, z=0,p,i1=0,r;  
         long int no, R[40],I=0,j;    //DEC->OCT VARIABLES  
         long double n,n1,summ=0;  
         fdialogbox();  
         style();  
         outtextxy(140,20,"Binary -> Octal");  
         // BINARY->OCTAL PROCEDURE  
         gotoxy(20,13);  
         cin>>num;  
         numm=num;  
         gotoxy(50,13);  
         cin>>bin;  
                 //BINARY->DECIMAL CONVERSION  
         do         //loop for integer part  
         {  
           z=num%10;    //taking out last digit  
           p=pow(2,i1);    //getting power of 2  
           r=z*p;           //multiplying last digit nd power of 2  
           sum=sum+r;  
           num=num/10;       //removing last digit  
           i1++;  
         }while(num>0);  
         l=strlen(bin);  
         for(i=0;i<l;i++)  
         {  switch(bin[i])  
            {  case '0':  
               m=(0-i)-1;  
               dec=dec+0*pow(2,m);  
               break;  
               case '1':  
               m=(0-i)-1;  
               dec=dec+1*pow(2,m);  
               break;  
            }  
         }     // DECIMAL->OCTAL CONVERSION  
          no=sum;   // integer part  
          n1=dec;   // decimal part  
          while(no>0)  
          { R[I]=no%8;  
            no=no/8;  
            I++;  
          }  
          Bi:  
          n=n1;  // decimal part  
          gotoxy(30,20);  
          for(j=I-1;j>=0;j--)  
          cout<<R[j];  
          if(n!=0)  
          { cout<<".";  
           do                  //Loop for decimal part  
           { summ=n*8;  
             int m=summ;  
             cout<<m;  
             n=summ-m;                    //decreasing the number till float part  
           }while(n!=0);  
          }  
        do  
        { getmousepos(b1b1,x1b1,y1b1);  
          if(b1b1==1)  
          { if(x1b1>=230 && x1b1<=390 && y1b1>=400 &&  y1b1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               binoctt();  
               while(!kbhit())  
               {  delay(1);  }  
               cleardevice();  
               fdialogbox();  
               style();  
               outtextxy(140,20,"Binary -> Octal");  
               gotoxy(20,13);  
               cout<<numm;  
               gotoxy(50,13);  
               cout<<bin;  
               goto Bi;  
            }  
            if(x1b1>=490 && x1b1<=590 && y1b1>=400 && y1b1<=440) //CLEAN  
            { cleardevice();  
              goto Ci;  
            }  
            if(x1b1>=20 && x1b1<=100 && y1b1>=400 && y1b1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
           if(x1b>=290 && x1b<=440 && y1b>=230 && y1b<=300) //IF NO  
           { instruction();  
         note();  
         while(!kbhit())  
         { delay(1); }  
         Cii:  
         unsigned long int num,numm,sum=0, z=0,p,i1=0,r; //BIN->DEC VARIABLES  
         long int no, R[40],I=0,j; // DEC->OCT VARIABLES  
         dialogbox();  
         style();  
         outtextxy(140,20,"Binary -> Octal");  
         //BINARY->OCTAL PROCEDURE  
         gotoxy(23,13);  
         cin>>num;  
         numm=num;        //BINARY->DECIMAL CONVERSION  
         do         //loop for integer part  
         {  
           z=num%10;    //taking out last digit  
           p=pow(2,i1);    //getting power of 2  
           r=z*p;           //multiplying last digit nd power of 2  
           sum=sum+r;  
           num=num/10;       //removing last digit  
           i1++;  
         }while(num>0);  
                  // DECIMAL->OCTAL CONVERSION  
         no=sum;  
         while(no>0)  
        { R[I]=no%8;  
          no=no/8;  
          I++;  
        }  
        Bii:  
        gotoxy(27,20);  
        for(j=I-1;j>=0;j--)  
        cout<<R[j];  
        do  
        { getmousepos(b1b1,x1b1,y1b1);  
          if(b1b1==1)  
          { if(x1b1>=230 && x1b1<=390 && y1b1>=400 && y1b1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               binoctt();  
               while(!kbhit())  
               {  delay(1);  }  
               cleardevice();  
               dialogbox();  
               style();  
               outtextxy(140,20,"Binary -> Octal");  
               gotoxy(23,13);  
               cout<<numm;  
               goto Bii;  
            }  
            if(x1b1>=490 && x1b1<=590 && y1b1>=400 && y1b1<=440) //CLEAN  
            { cleardevice();  
              goto Cii;  
            }  
            if(x1b1>=20 && x1b1<=100 && y1b1>=400 && y1b1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x1>=67 && x1<=567 && y1>=310 && y1<=360)  //BINARY->HEXADECIMAL  
     { loading();  
       yesno();  
       do  
       { getmousepos(b1c,x1c,y1c);  
         if(b1c==1)  
         { if(x1c>=100 && x1c<=250 && y1c>=230 && y1c<=300) //IF YES  
           { finstruction();  
         note();  
         while(!kbhit())  
         { delay(1); }  
         Ciii:  
         char bin[40];        // BIN->DEC VARIABLES  
         int i,l,m;  
         long float dec=0;  
         unsigned long int num,numm,sum=0, z=0,p,i1=0,r;  
         long int no,q,temp,i2=1,j;   // DEC->HEX VARIABLES  
         long double n,n1,summ=0;  
         char hexdec[50];  
         fdialogbox();  
         style();  
         outtextxy(70,20,"Binary -> Hexadecimal");  
         // BINARY->HEXADECIMAL PROCEDURE  
         gotoxy(20,13);  
         cin>>num;  
         numm=num;  
         gotoxy(50,13);  
         cin>>bin;  
               // BINARY->DECIMAL CONVERSION  
         do         //loop for integer part  
         {  
           z=num%10;    //taking out last digit  
           p=pow(2,i1);    //getting power of 2  
           r=z*p;           //multiplying last digit nd power of 2  
           sum=sum+r;  
           num=num/10;       //removing last digit  
           i1++;  
         }while(num>0);  
         l=strlen(bin);    // decimal part  
         for(i=0;i<l;i++)  
         { switch(bin[i])  
           { case '0':  
             m=(0-i)-1;  
             dec=dec+0*pow(2,m);  
             break;  
             case '1':  
             m=(0-i)-1;  
             dec=dec+1*pow(2,m);  
             break;  
           }  
         }     //DECIMAL->HEXADECIMAL CONVERSION  
         no=sum;  // integer part  
         n1=dec;   // decimal part  
         q=no;  
         while(q!=0)  
         {  temp=q%16; // TO CONVERT INTEGER INTO CHARACTER  
            if(temp<10)  
            temp=temp+48;  
            else  
            temp=temp+55;  
            hexdec[i2++]=temp;  
            q=q/16;  
         }  
         Biii:  
         n=n1;  
         gotoxy(30,20);  
         for(j=i2-1;j>0;j--)  
         cout<<hexdec[j];  
         if(n!=0)  
         { cout<<".";  
          do                  //Loop for decimal part  
          { summ=n*16;  
            int M=summ;  
            if(M<10)  
            cout<<M;  
            else if(M==10)  
            cout<<"A";  
            else if(M==11)  
            cout<<"B";  
            else if(M==12)  
            cout<<"C";  
            else if(M==13)  
            cout<<"D";  
            else if(M==14)  
            cout<<"E";  
            else if(M==15)  
            cout<<"F";  
            n=summ-M;         //decreasing the number till float part  
          }while(n!=0);  
           }  
        do  
        { getmousepos(b1c1,x1c1,y1c1);  
          if(b1c1==1)  
          { if(x1c1>=230 && x1c1<=390 && y1c1>=400 &&  y1c1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               binhext();  
               while(!kbhit())  
               {  delay(1);  }  
               cleardevice();  
               fdialogbox();  
               style();  
               outtextxy(70,20,"Binary -> Hexadecimal");  
               gotoxy(20,13);  
               cout<<numm;  
               gotoxy(50,13);  
               cout<<bin;  
               goto Biii;  
            }  
            if(x1c1>=490 && x1c1<=590 && y1c1>=400 && y1c1<=440) //CLEAN  
            { cleardevice();  
              goto Ciii;  
            }  
            if(x1c1>=20 && x1c1<=100 && y1c1>=400 && y1c1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
           if(x1c>=290 && x1c<=440 && y1c>=230 && y1c<=300) //IF NO  
           { instruction();  
         note();  
         while(!kbhit())  
         { delay(1); }  
         CII:  
         unsigned long int num,numm,sum=0, z=0,p,i1=0,r; //BIN->DEC VARIABLES  
         long int no,q,temp,i2=1,j;   // DEC->HEX VARIABLES  
         char hexdec[50];  
         dialogbox();  
         style();  
         outtextxy(70,20,"Binary -> Hexadecimal");  
         // BINARY->HEXADECIMAL PROCEDURE  
         gotoxy(23,13);  
         cin>>num;  
         numm=num;        //BINARY->DECIMAL CONVERSION  
         do         //loop for integer part  
         {  
           z=num%10;    //taking out last digit  
           p=pow(2,i1);    //getting power of 2  
           r=z*p;           //multiplying last digit nd power of 2  
           sum=sum+r;  
           num=num/10;       //removing last digit  
           i1++;  
         }while(num>0);  
                  // DECIMAL->HEXADECIMAL CONVERSION  
         no=sum;  // integer part  
         q=no;  
         while(q!=0)  
         {  temp=q%16; // TO CONVERT INTEGER INTO CHARACTER  
            if(temp<10)  
            temp=temp+48;  
            else  
            temp=temp+55;  
            hexdec[i2++]=temp;  
            q=q/16;  
         }  
         BII:  
         gotoxy(27,20);  
         for(j=i2-1;j>0;j--)  
         cout<<hexdec[j];  
        do  
        { getmousepos(b1c1,x1c1,y1c1);  
          if(b1c1==1)  
          { if(x1c1>=230 && x1c1<=390 && y1c1>=400 && y1c1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               binhext();  
               while(!kbhit())  
               {  delay(1);  }  
               cleardevice();  
               dialogbox();  
               style();  
               outtextxy(70,20,"Binary -> Hexadecimal");  
               gotoxy(23,13);  
               cout<<numm;  
               goto BII;  
            }  
            if(x1c1>=490 && x1c1<=590 && y1c1>=400 && y1c1<=440) //CLEAN  
            { cleardevice();  
              goto CII;  
            }  
            if(x1c1>=20 && x1c1<=100 && y1c1>=400 && y1c1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x1>=20 && x1<=100 && y1>=400 && y1<=430) // BACK  
     {   loading();  
         cleardevice();  
         goto abc;  
     }  
    }  
       if(kbhit())  
       e=getch();  
     }while(e!=27);  
   }  
// INDEX->DECIMAL CONVERSION  
   if(x>=57 && x<=577 && y>=170 && y<=210)  
   {  loading();  
      cleardevice();  
      A2:  
      setcolor(WHITE);  
      settextstyle(4,0,6);  
      outtextxy(90,10,"Decimal Conversion");  
      selectionlist();  
      outtextxy(160,155,"1.Decimal -> Binary");  
      outtextxy(180,235,"2.Decimal -> Octal");  
      outtextxy(120,315,"3.Decimal -> Hexadecimal");  
      back();  
      do  
      { getmousepos(b2,x2,y2);  
    if(b2==1)  
    {  
     if(x2>=67 && x2<=567 && y2>=150 && y2<=200)  //DECIMAL->BINARY  
     { loading();  
       instruction();  
       while(!kbhit())  
       {  delay(1); }  
       C2:  
       long int no, r[40],I=0,j;  
       long double num,n,n1=0,sum=0;  
       dialogbox();  
       style();  
       outtextxy(120,20,"Decimal -> Binary");  
       // DECIMAL->BINARY PROCEDURE  
       gotoxy(23,13);  
       cin>>num;  
       no=num;        //taking out integer part  
       n1=num-no;   //taking out decimal part  
       while(no>0)  
      { r[I]=no%2;  
        no=no/2;  
        I++;  
      }  
      B2:  
      n=n1;   //taking out decimal part  
      gotoxy(27,20);  
      for(j=I-1;j>=0;j--)  
      cout<<r[j];  
      if(n!=0)  
      { cout<<".";  
        do                  //Loop for decimal part  
       { sum=n*2;  
         int m=sum;  
         cout<<m;  
         n=sum-m;                    //decreasing the number till float part  
       }while(n!=0);  
      }  
       do  
       { getmousepos(b2a,x2a,y2a);  
         if(b2a==1)  
         { if(x2a>=230 && x2a<=390 && y2a>=400 &&  y2a<=440) //TUTORIAL  
           { cleardevice();  
         t_guide();  
         delay(4500);  
         decbint();  
         while(!kbhit())  
         {  delay(1); }  
         cleardevice();  
         dialogbox();  
         style();  
         outtextxy(120,20,"Decimal -> Binary");  
         gotoxy(23,13);  
         cout<<num;  
         goto B2;  
           }  
           if(x2a>=490 && x2a<=590 && y2a>=400 && y2a<=440) //CLEAN  
           { cleardevice();  
         goto C2;  
           }  
           if(x2a>=20 && x2a<=100 && y2a>=400 && y2a<=430) //BACK  
           { loading();  
         cleardevice();  
         goto A2;  
           }  
         } if(kbhit())  
         e=getch();  
       }while(e!=27);  
     }  
     if(x2>=67 && x2<=567 && y2>=230 && y2<=280)  //DECIMAL->OCTAL  
     { loading();  
       instruction();  
       while(!kbhit())  
       {  delay(1); }  
       C2i:  
       long int no=0, r[40],I=0,j;  
       long double num=0,n=0,n1=0,sum=0;  
       dialogbox();  
       style();  
       outtextxy(150,20,"Decimal -> Octal");  
       // DECIMAL->OCTAL PROCEDURE  
       gotoxy(23,13);  
       cin>>num;  
       no=num;        //taking out integer part  
       n1=num-no;   //taking out decimal part  
       while(no>0)  
      { r[I]=no%8;  
        no=no/8;  
        I++;  
      }  B2i:  
      n=n1;   //taking out decimal part  
      gotoxy(27,20);  
      for(j=I-1;j>=0;j--)  
      cout<<r[j];  
      if(n!=0)  
      { cout<<".";  
        do                  //Loop for decimal part  
       { sum=n*8;  
         int m=sum;  
         cout<<m;  
         n=sum-m;                    //decreasing the number till float part  
       }while(n!=0);  
      }  
       do  
       { getmousepos(b2b,x2b,y2b);  
         if(b2b==1)  
         { if(x2b>=230 && x2b<=390 && y2b>=400 &&  y2b<=440) //TUTORIAL  
           { cleardevice();  
         t_guide();  
         delay(4500);  
         decoctt();  
         while(!kbhit())  
         {  delay(1); }  
         cleardevice();  
         dialogbox();  
         style();  
         outtextxy(150,20,"Decimal -> Octal");  
         gotoxy(23,13);  
         cout<<num;  
         goto B2i;  
           }  
           if(x2b>=490 && x2b<=590 && y2b>=400 && y2b<=440) //CLEAN  
           { cleardevice();  
         goto C2i;  
           }  
           if(x2b>=20 && x2b<=100 && y2b>=400 && y2b<=430) //BACK  
           { loading();  
         cleardevice();  
         goto A2;  
           }  
         } if(kbhit())  
         e=getch();  
       }while(e!=27);  
     }  
     if(x2>=67 && x2<=567 && y2>=310 && y2<=360) // DECIMAL->HEXADECIMAL  
     { loading();  
       instruction();  
       while(!kbhit())  
       {  delay(1);  }  
       C2ii:  
       long int no,q,temp,i2=1,j;  
       long double num,n,n1=0,sum=0;  
       char hexdec[50];  
       dialogbox();  
       style();  
       outtextxy(70,20,"Decimal -> Hexadecimal");  
       // DECIMAL->HEXADECIMAL PROCEDURE  
       gotoxy(23,13);  
       cin>>num;  
       no=num;        //taking out integer part  
       n1=num-no;   //taking out decimal part  
       q=no;  
       while(q!=0)  
      {  temp=q%16; // TO CONVERT INTEGER INTO CHARACTER  
         if(temp<10)  
         temp=temp+48;  
         else  
         temp=temp+55;  
         hexdec[i2++]=temp;  
         q=q/16;  
      }  
      B2ii:  
      n=n1;  
      gotoxy(27,20);  
      for(j=i2-1;j>0;j--)  
      cout<<hexdec[j];  
      if(n!=0)           //IF IT CONSISTS OF FRACTION PART  
      { cout<<".";  
        do                  //Loop for decimal part  
       { sum=n*16;  
         int m=sum;  
         if(m<10)  
         cout<<m;  
         else if(m==10)  
         cout<<"A";  
         else if(m==11)  
         cout<<"B";  
         else if(m==12)  
         cout<<"C";  
         else if(m==13)  
         cout<<"D";  
         else if(m==14)  
         cout<<"E";  
         else if(m==15)  
         cout<<"F";  
         n=sum-m;                    //decreasing the number till float part  
       }while(n!=0);  
      }  
       do  
       { getmousepos(b2c,x2c,y2c);  
         if(b2c==1)  
         { if(x2c>=230 && x2c<=390 && y2c>=400 &&  y2c<=440) //TUTORIAL  
           { cleardevice();  
         t_guide();  
         delay(4500);  
         dechext();  
         while(!kbhit())  
         {  delay(1); }  
         cleardevice();  
         dialogbox();  
         style();  
         outtextxy(70,20,"Decimal -> Hexadecimal");  
         gotoxy(23,13);  
         cout<<num;  
         goto B2ii;  
           }  
           if(x2c>=490 && x2c<=590 && y2c>=400 && y2c<=440) //CLEAN  
           { cleardevice();  
         goto C2ii;  
           }  
           if(x2c>=20 && x2c<=100 && y2c>=400 && y2c<=430) //BACK  
           { loading();  
         cleardevice();  
         goto A2;  
           }  
         } if(kbhit())  
         e=getch();  
       }while(e!=27);  
     }  
     if(x2>=20 && x2<=100 && y2>=400 && y2<=430) // BACK  
     {   loading();  
         cleardevice();  
         goto abc;  
     }  
    }  
       if(kbhit())  
       e=getch();  
      }while(e!=27);  
   }  
// INDEX->OCTAL CONVERSION  
   if(x>=57 && x<=577 && y>=234 && y<=274)  
   { loading();  
     cleardevice();  
     A3:  
     setcolor(WHITE);  
     settextstyle(4,0,6);  
     outtextxy(90,10,"Octal Conversion");  
     selectionlist();  
     outtextxy(160,155,"1.Octal -> Binary");  
     outtextxy(180,235,"2.Octal -> Decimal");  
     outtextxy(120,315,"3.Octal -> Hexadecimal");  
     back();  
     do  
     { getmousepos(b3,x3,y3);  
       if(b3==1)  
       {  
     if(x3>=67 && x3<=567 && y3>=150 && y3<=200)  //OCTAL->BINARY  
     { loading();  
       instruction();  
       while(!kbhit())  
       { delay(1); }  
       C3:  
       char h[100];  
       dialogbox();  
       style();  
       outtextxy(160,20,"Octal -> Binary");  
       // OCTAL->BINARY PROCEDURE  
       gotoxy(23,13);  
       cin>>h;  
       B3:  
       l=strlen(h);  
       gotoxy(27,20);  
        for(i=0;i<=l;i++)  
        { switch(h[i])  
         { case '0':  
           cout<<"000";  
           break;  
           case '1':  
           cout<<"001";  
           break;  
           case '2':  
           cout<<"010";  
           break;  
           case '3':  
           cout<<"011";  
           break;  
           case '4':  
           cout<<"100";  
           break;  
           case '5':  
           cout<<"101";  
           break;  
           case '6':  
           cout<<"110";  
           break;  
           case '7':  
           cout<<"111";  
           break;  
           case '.':  
           cout<<".";  
           break;  
         }  
        }  
       do  
       { getmousepos(b3a,x3a,y3a);  
         if(b3a==1)  
         { if(x3a>=230 && x3a<=390 && y3a>=400 && y3a<=440) //TUTORIAL  
           { cleardevice();  
         t_guide();  
         delay(4500);  
         octbint();  
         while(!kbhit())  
         {  delay(1); }  
         cleardevice();  
         dialogbox();  
         style();  
         outtextxy(160,20,"Octal -> Binary");  
         gotoxy(23,13);  
         cout<<h;  
         goto B3;  
           }  
           if(x3a>=490 && x3a<=590 && y3a>=400 && y3a<=440) //CLEAN  
           { cleardevice();  
         goto C3;  
           }  
           if(x3a>=20 && x3a<=100 && y3a>=400 && y3a<=430) //BACK  
           { loading();  
         cleardevice();  
         goto A3;  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x3>=67 && x3<=567 && y3>=230 && y3<=280)  // OCTAL->DECIMAL  
     { loading();  
       instruction();  
       while(!kbhit())  
       {  delay(1);  }  
       C3i:  
       long double no,n,n1,summ=0,a;  
       long int num,i1=0,z,p,r,sum=0,j=1,b;  
       dialogbox();  
       style();  
       outtextxy(160,20,"Octal -> Decimal");  
       // OCTAL->DECIMAL PROCEDURE  
       gotoxy(23,13);  
       cin>>no;  
       num=no;  
       n1=no-num;  
       B3i:  
       n=n1;  
       do         //loop for integer part  
       { z=num%10;    //taking out last digit  
         p=pow(8,i1);   //getting power of 8  
         r=z*p;         //multiplying last digit nd power of 8  
         sum=sum+r;  
         num=num/10;    //removing last digit  
         i1++;  
       }while(num>0);  
       while(n!=0)          //decimal part conversion  
       { a=10*n;  
         b=a;  
         summ=summ+(b*(1/pow(8,j++)));  
         n=a-b;  
       }  
       gotoxy(27,20);  
       cout<<summ+sum;  
       do  
       { getmousepos(b3b,x3b,y3b);  
         if(b3b==1)  
         { if(x3b>=230 && x3b<=390 && y3b>=400 && y3b<=440) //TUTORIAL  
           { cleardevice();  
         t_guide();  
         delay(4500);  
         octdect();  
         while(!kbhit())  
         {  delay(1); }  
         cleardevice();  
         dialogbox();  
         style();  
         outtextxy(160,20,"Octal -> Decimal");  
         gotoxy(23,13);  
         cout<<no;  
         goto B3i;  
           }  
           if(x3b>=490 && x3b<=590 && y3b>=400 && y3b<=440) //CLEAN  
           { cleardevice();  
         goto C3i;  
           }  
           if(x3b>=20 && x3b<=100 && y3b>=400 && y3b<=430) //BACK  
           { loading();  
         cleardevice();  
         goto A3;  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x3>=67 && x3<=567 && y3>=310 && y3<=360) // OCTAL->HEXADECIMAL  
     { loading();  
       instruction();  
       while(!kbhit())  
       {  delay(1);  }  
       C3I:  
       long double no,n,summ=0,a;        // OCT->DEC VARIABLES  
       long int num,i1=0,z,p,r,sum=0,j=1,b;  
       long int NO,q,temp,i2=1,J;   // DEC->HEX VARIABLES  
       long double N,n1,SUM=0;  
       char hexdec[50];  
       dialogbox();  
       style();  
       outtextxy(100,20,"Octal -> Hexadecimal");  
       // OCTAL->HEX PROCEDURE  
       gotoxy(23,13);  
       cin>>no;  
       num=no;  
       n=no-num;  
       do         //loop for integer part  
       { z=num%10;    //taking out last digit  
         p=pow(8,i1);   //getting power of 8  
         r=z*p;         //multiplying last digit nd power of 8  
         sum=sum+r;  
         num=num/10;    //removing last digit  
         i1++;  
       }while(num>0);  
       while(n!=0)  
       { a=10*n;  
         b=a;  
         summ=summ+(b*(1/pow(8,j++)));  
         n=a-b;  
       }  
       n1=summ;   //decimal part  
       NO=sum;    //integer part  
       q=NO;  
       while(q!=0)  
       { temp=q%16; // TO CONVERT INTEGER INTO CHARACTER  
         if(temp<10)  
         temp=temp+48;  
         else  
         temp=temp+55;  
         hexdec[i2++]=temp;  
         q=q/16;  
       }  
       B3I:  
       N=n1;  
       gotoxy(30,20);  
       for(J=i2-1;J>0;J--)  
       cout<<hexdec[J];  
       if(N!=0)  
       { cout<<".";  
         do                  //Loop for decimal part  
        { SUM=N*16;  
          int m=SUM;  
          if(m<10)  
          cout<<m;  
          else if(m==10)  
          cout<<"A";  
          else if(m==11)  
          cout<<"B";  
          else if(m==12)  
          cout<<"C";  
          else if(m==13)  
          cout<<"D";  
          else if(m==14)  
          cout<<"E";  
          else if(m==15)  
          cout<<"F";  
          N=SUM-m;                    //decreasing the number till float part  
        }while(N!=0);  
       }  
       do  
       { getmousepos(b3b,x3b,y3b);  
         if(b3b==1)  
         { if(x3b>=230 && x3b<=390 && y3b>=400 && y3b<=440) //TUTORIAL  
           { cleardevice();  
         t_guide();  
         delay(4500);  
         octhext();  
         while(!kbhit())  
         {  delay(1); }  
         cleardevice();  
         dialogbox();  
         style();  
         outtextxy(100,20,"Octal -> Hexadecimal");  
         gotoxy(23,13);  
         cout<<no;  
         goto B3I;  
           }  
           if(x3b>=490 && x3b<=590 && y3b>=400 && y3b<=440) //CLEAN  
           { cleardevice();  
         goto C3I;  
           }  
           if(x3b>=20 && x3b<=100 && y3b>=400 && y3b<=430) //BACK  
           { loading();  
         cleardevice();  
         goto A3;  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x3>=20 && x3<=100 && y3>=400 && y3<=430) // BACK  
     {   loading();  
         cleardevice();  
         goto abc;  
     }  
       }  
       if(kbhit())  
       e=getch();  
     }while(e!=27);  
   }  
// INDEX->HEXADECIMAL CONVERSION  
   if(x>=57 && x<=577 && y>=298 && y<=338)  
   { loading();  
     cleardevice();  
     A4:  
     setcolor(WHITE);  
     settextstyle(4,0,6);  
     outtextxy(90,10,"Hexadecimal Conversion");  
     selectionlist();  
     outtextxy(120,155,"1.Hexadecimal -> Binary");  
     outtextxy(120,235,"2.Hexadecimal -> Decimal");  
     outtextxy(150,315,"3.Hexadecimal -> Octal");  
     back();  
     do  
     { getmousepos(b4,x4,y4);  
       if(b4==1)  
       { if(x4>=67 && x4<=567 && y4>=150 && y4<=200)   // HEX->BIN  
     { loading();  
       instruction();  
       while(!kbhit())  
       { delay(1); }  
       C4:  
       char hb[100];  
       dialogbox();  
       style();  
       outtextxy(70,20,"Hexadecimal -> Binary");  
       // HEXADECIMAL->BINARY PROCEDURE  
       gotoxy(23,13);  
       cin>>hb;  
       B4:  
       l=strlen(hb);  
       gotoxy(27,20);  
       for(i=0;i<l;i++)  
       { switch(hb[i])  
         { case'0':  
           cout<<"0000";  
           break;  
           case'1':  
           cout<<"0001";  
           break;  
           case'2':  
           cout<<"0010";  
           break;  
           case'3':  
           cout<<"0011";  
           break;  
           case'4':  
           cout<<"0100";  
           break;  
           case'5':  
           cout<<"0101";  
           break;  
           case'6':  
           cout<<"0110";  
           break;  
           case'7':  
           cout<<"0111";  
           break;  
           case'8':  
           cout<<"1000";  
           break;  
           case'9':  
           cout<<"1001";  
           break;  
           case'A':  
           cout<<"1010";  
           break;  
           case'B':  
           cout<<"1011";  
           break;  
           case'C':  
           cout<<"1100";  
           break;  
           case'D':  
           cout<<"1101";  
           break;  
           case'E':  
           cout<<"1110";  
           break;  
           case 'F':  
           cout<<"1111";  
           break;  
           case'.':  
           cout<<".";  
           break;  
         }  
       }  
       do  
       { getmousepos(b4a,x4a,y4a);  
         if(b4a==1)  
         { if(x4a>=230 && x4a<=390 && y4a>=400 && y4a<=440) //TUTORIAL  
        { cleardevice();  
          t_guide();  
          delay(4500);  
          hexbint();  
          while(!kbhit())  
          {  delay(1); }  
          cleardevice();  
          dialogbox();  
          style();  
          outtextxy(70,20,"Hexadecimal -> Binary");  
          gotoxy(23,13);  
          cout<<hb;  
          goto B4;  
        }  
           if(x4a>=490 && x4a<=590 && y4a>=400 && y4a<=440) //CLEAN  
        { cleardevice();  
          goto C4;  
        }  
           if(x4a>=20 && x4a<=100 && y4a>=400 && y4a<=430) //BACK  
        { loading();  
          cleardevice();  
          goto A4;  
        }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x4>=67 && x4<=567 && y4>=230 && y4<=280)  // HEX->DECIMAL  
     { loading();  
       yesno();  
       do  
       { getmousepos(b4b,x4b,y4b);  
         if(b4b==1)  
         { if(x4b>=100 && x4b<=250 && y4b>=230 && y4b<=300) //IF YES  
           { finstruction();  
         while(!kbhit())  
         { delay(1); }  
         C4i:  
         int c=1;  
         unsigned long int bi,a=0,A=0;  
         long double a1=0;  
         char hd[100],hdd[50];  
         fdialogbox();  
         style();  
         outtextxy(60,20,"Hexadecimal -> Decimal");  
         //HEX->DECIMAL PROCEDURE  
         gotoxy(20,13);  
         cin>>hd;  
         gotoxy(50,13);  
         cin>>hdd;  
         l=strlen(hd);  
         bi=l-1;  
         for(i=0;i<=l;i++)  
         { switch(hd[i])  
           { case'0':  
             a=a+0*pow(16,bi);  
             break;  
             case'1':  
             a=a+1*pow(16,bi);  
             break;  
             case'2':  
             a=a+2*pow(16,bi);  
             break;  
             case'3':  
             a=a+3*pow(16,bi);  
             break;  
             case'4':  
             a=a+4*pow(16,bi);  
             break;  
             case'5':  
             a=a+5*pow(16,bi);  
             break;  
             case'6':  
             a=a+6*pow(16,bi);  
             break;  
             case'7':  
             a=a+7*pow(16,bi);  
             break;  
             case'8':  
             a=a+8*pow(16,bi);  
             break;  
             case'9':  
             a=a+9*pow(16,bi);  
             break;  
             case'A':  
             a=a+10*pow(16,bi);  
             break;  
             case'B':  
             a=a+11*pow(16,bi);  
             break;  
             case'C':  
             a=a+12*pow(16,bi);  
             break;  
             case'D':  
             a=a+13*pow(16,bi);  
             break;  
             case'E':  
             a=a+14*pow(16,bi);  
             break;  
             case'F':  
             a=a+15*pow(16,bi);  
             break;  
           }  
           bi--;  
         }  
         B4i:  
         A=a;  
         l=strlen(hdd);  
         for(i=0;i<=l;i++)  
         { switch(hdd[i])  
           { case'0':  
             a1=a1+0*pow(16,-c);  
             break;  
             case'1':  
             a1=a1+1*pow(16,-c);  
             break;  
             case'2':  
             a1=a1+2*pow(16,-c);  
             break;  
             case'3':  
             a1=a1+3*pow(16,-c);  
             break;  
             case'4':  
             a1=a1+4*pow(16,-c);  
             break;  
             case'5':  
             a1=a1+5*pow(16,-c);  
             break;  
             case'6':  
             a1=a1+6*pow(16,-c);  
             break;  
             case'7':  
             a1=a1+7*pow(16,-c);  
             break;  
             case'8':  
             a1=a1+8*pow(16,-c);  
             break;  
             case'9':  
             a1=a1+9*pow(16,-c);  
             break;  
             case'A':  
             a1=a1+10*pow(16,-c);  
             break;  
             case'B':  
             a1=a1+11*pow(16,-c);  
             break;  
             case'C':  
             a1=a1+12*pow(16,-c);  
             break;  
             case'D':  
             a1=a1+13*pow(16,-c);  
             break;  
             case'E':  
             a1=a1+14*pow(16,-c);  
             break;  
             case'F':  
             a1=a1+15*pow(16,-c);  
             break;  
           }  
           c++;  
         }  
         gotoxy(27,20);  
         cout<<A+a1;  
        do  
        { getmousepos(b4b1,x4b1,y4b1);  
          if(b4b1==1)  
          { if(x4b1>=230 && x4b1<=390 && y4b1>=400 && y4b1<=440) //TUTORIAL  
            { cleardevice();  
              t_guide();  
              delay(4500);  
              hexdect();  
              while(!kbhit())  
              {  delay(1); }  
              cleardevice();  
              fdialogbox();  
              style();  
              outtextxy(60,20,"Hexadecimal -> Decimal");  
              gotoxy(20,13);  
              cout<<hd;  
              gotoxy(50,13);  
              cout<<hdd;  
              goto B4i;  
            }  
            if(x4b1>=490 && x4b1<=590 && y4b1>=400 && y4b1<=440) //CLEAN  
            { cleardevice();  
              goto C4i;  
            }  
            if(x4b1>=20 && x4b1<=100 && y4b1>=400 && y4b1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A4;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
           if(x4b>=290 && x4b<=440 && y4b>=230 && y4b<=300) //IF NO  
           { instruction();  
         while(!kbhit())  
         { delay(1); }  
         C4II:  
         unsigned long int bi,a=0,A;  
         char hd[100];  
         dialogbox();  
         style();  
         outtextxy(60,20,"Hexadecimal -> Decimal");  
         //HEX->DECIMAL PROCEDURE  
         gotoxy(23,13);  
         cin>>hd;  
         l=strlen(hd);  
         bi=l-1;  
         for(i=0;i<=l;i++)  
         { switch(hd[i])  
           { case'0':  
             a=a+0*pow(16,bi);  
             break;  
             case'1':  
             a=a+1*pow(16,bi);  
             break;  
             case'2':  
             a=a+2*pow(16,bi);  
             break;  
             case'3':  
             a=a+3*pow(16,bi);  
             break;  
             case'4':  
             a=a+4*pow(16,bi);  
             break;  
             case'5':  
             a=a+5*pow(16,bi);  
             break;  
             case'6':  
             a=a+6*pow(16,bi);  
             break;  
             case'7':  
             a=a+7*pow(16,bi);  
             break;  
             case'8':  
             a=a+8*pow(16,bi);  
             break;  
             case'9':  
             a=a+9*pow(16,bi);  
             break;  
             case'A':  
             a=a+10*pow(16,bi);  
             break;  
             case'B':  
             a=a+11*pow(16,bi);  
             break;  
             case'C':  
             a=a+12*pow(16,bi);  
             break;  
             case'D':  
             a=a+13*pow(16,bi);  
             break;  
             case'E':  
             a=a+14*pow(16,bi);  
             break;  
             case'F':  
             a=a+15*pow(16,bi);  
             break;  
           }  
           bi--;  
         }  
         B4II:  
         A=a;  
         gotoxy(27,20);  
         cout<<A;  
        do  
        { getmousepos(b4b1,x4b1,y4b1);  
          if(b4b1==1)  
          { if(x4b1>=230 && x4b1<=390 && y4b1>=400 && y4b1<=440) //TUTORIAL  
            { cleardevice();  
              t_guide();  
              delay(4500);  
              hexdect();  
              while(!kbhit())  
              {  delay(1); }  
              cleardevice();  
              dialogbox();  
              style();  
              outtextxy(60,20,"Hexadecimal -> Decimal");  
              gotoxy(23,13);  
              cout<<hd;  
              goto B4II;  
            }  
            if(x4b1>=490 && x4b1<=590 && y4b1>=400 && y4b1<=440) //CLEAN  
            { cleardevice();  
              goto C4II;  
            }  
            if(x4b1>=20 && x4b1<=100 && y4b1>=400 && y4b1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A4;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x4>=67 && x4<=567 && y4>=310 && y4<=360)  //HEX->OCTAL  
     { loading();  
       yesno();  
       do  
       { getmousepos(b4c,x4c,y4c);  
         if(b4c==1)  
         { if(x4c>=100 && x4c<=250 && y4c>=230 && y4c<=300) //IF YES  
           { finstruction();  
         while(!kbhit())  
         { delay(1); }  
         C4I:  
         char hexadecimal[100],hexdd[50]; //HEX->DEC VARIABLES  
         unsigned long long int b,l,i,a=0;  
         int c=1;  
         long double a1=0;  
         long    int no, r[40],I=0,j; // DEC->OCT VARIABLES  
         long double n,n1,sum=0;  
         fdialogbox();  
         style();  
         outtextxy(100,20,"Hexadecimal -> Octal");  
         //HEX->OCTAL PROCEDURE  
         gotoxy(20,13);  
         cin>>hexadecimal;  
         gotoxy(50,13);  
         cin>>hexdd;  
         l=strlen(hexadecimal);   // HEXADECIMAL->DECIMAL CONVERSION  
         b=l-1;  
         for(i=0;i<=l;i++)  
         { switch(hexadecimal[i])  
           {  case'0':  
              a=a+0*pow(16,b);  
              break;  
              case'1':  
              a=a+1*pow(16,b);  
              break;  
              case'2':  
              a=a+2*pow(16,b);  
              break;  
              case'3':  
              a=a+3*pow(16,b);  
              break;  
              case'4':  
              a=a+4*pow(16,b);  
              break;  
              case'5':  
              a=a+5*pow(16,b);  
              break;  
              case'6':  
              a=a+6*pow(16,b);  
              break;  
              case'7':  
              a=a+7*pow(16,b);  
              break;  
              case'8':  
              a=a+8*pow(16,b);  
              break;  
              case'9':  
              a=a+9*pow(16,b);  
              break;  
              case'A':  
              a=a+10*pow(16,b);  
              break;  
              case'B':  
              a=a+11*pow(16,b);  
              break;  
              case'C':  
              a=a+12*pow(16,b);  
              break;  
              case'D':  
              a=a+13*pow(16,b);  
              break;  
              case'E':  
              a=a+14*pow(16,b);  
              break;  
              case'F':  
              a=a+15*pow(16,b);  
              break;  
           }  
           b--;  
         }  
         l=strlen(hexdd);  
         for(i=0;i<=l;i++)  
         { switch(hexdd[i])  
           {  case'0':  
              a1=a1+0*pow(16,-c);  
              break;  
              case'1':  
              a1=a1+1*pow(16,-c);  
              break;  
              case'2':  
              a1=a1+2*pow(16,-c);  
              break;  
              case'3':  
              a1=a1+3*pow(16,-c);  
              break;  
              case'4':  
              a1=a1+4*pow(16,-c);  
              break;  
              case'5':  
              a1=a1+5*pow(16,-c);  
              break;  
              case'6':  
              a1=a1+6*pow(16,-c);  
              break;  
              case'7':  
              a1=a1+7*pow(16,-c);  
              break;  
              case'8':  
              a1=a1+8*pow(16,-c);  
              break;  
              case'9':  
              a1=a1+9*pow(16,-c);  
              break;  
              case'A':  
              a1=a1+10*pow(16,-c);  
              break;  
              case'B':  
              a1=a1+11*pow(16,-c);  
              break;  
              case'C':  
              a1=a1+12*pow(16,-c);  
              break;  
              case'D':  
              a1=a1+13*pow(16,-c);  
              break;  
              case'E':  
              a1=a1+14*pow(16,-c);  
              break;  
              case'F':  
              a1=a1+15*pow(16,-c);  
              break;  
           }  
           c++;  
         }           // DECIMAL->OCTAL CONVERSION  
         no=a;  
         n1=a1;  
         while(no>0)  
         { r[I]=no%8;  
           no=no/8;  
           I++;  
         }  
         B4I:  
         n=n1;  
         gotoxy(30,20);  
         for(j=I-1;j>=0;j--)  
         cout<<r[j];  
         if(n!=0)  
         { cout<<".";  
           do                  //Loop for decimal part  
           { sum=n*8;  
             int m=sum;  
             cout<<m;  
             n=sum-m;        //decreasing the number till float part  
           }while(n!=0);  
         }  
         do  
         { getmousepos(b4c1,x4c1,y4c1);  
           if(b4c1==1)  
           { if(x4c1>=230 && x4c1<=390 && y4c1>=400 && y4c1<=440) //TUTORIAL  
             { cleardevice();  
               t_guide();  
               delay(4500);  
               hexoctt();  
               while(!kbhit())  
               {  delay(1); }  
               cleardevice();  
               fdialogbox();  
               style();  
               outtextxy(100,20,"Hexadecimal -> Octal");  
               gotoxy(20,13);  
               cout<<hexadecimal;  
               gotoxy(50,13);  
               cout<<hexdd;  
               goto B4I;  
             }  
             if(x4c1>=490 && x4c1<=590 && y4c1>=400 && y4c1<=440) //CLEAN  
             { cleardevice();  
               goto C4I;  
             }  
             if(x4c1>=20 && x4c1<=100 && y4c1>=400 && y4c1<=430) //BACK  
             { loading();  
               cleardevice();  
               goto A4;  
             }  
           }  
          if(kbhit())  
           e=getch();  
         }while(e!=27);  
           }  
           if(x4c>=290 && x4c<=440 && y4c>=230 && y4c<=300) //IF NO  
           { instruction();  
         while(!kbhit())  
         { delay(1); }  
         C4ii:  
         char hexadecimal[100]; //HEX->DEC VARIABLES  
         unsigned long long int b,l,i,a=0;  
         long    int no, r[40],I=0,j; // DEC->OCT VARIABLES  
         dialogbox();  
         style();  
         outtextxy(100,20,"Hexadecimal -> Octal");  
         //HEX->OCTAL PROCEDURE  
         gotoxy(23,13);  
         cin>>hexadecimal;  
         l=strlen(hexadecimal);   // HEXADECIMAL->DECIMAL CONVERSION  
         b=l-1;  
         for(i=0;i<=l;i++)  
         { switch(hexadecimal[i])  
           {  case'0':  
              a=a+0*pow(16,b);  
              break;  
              case'1':  
              a=a+1*pow(16,b);  
              break;  
              case'2':  
              a=a+2*pow(16,b);  
              break;  
              case'3':  
              a=a+3*pow(16,b);  
              break;  
              case'4':  
              a=a+4*pow(16,b);  
              break;  
              case'5':  
              a=a+5*pow(16,b);  
              break;  
              case'6':  
              a=a+6*pow(16,b);  
              break;  
              case'7':  
              a=a+7*pow(16,b);  
              break;  
              case'8':  
              a=a+8*pow(16,b);  
              break;  
              case'9':  
              a=a+9*pow(16,b);  
              break;  
              case'A':  
              a=a+10*pow(16,b);  
              break;  
              case'B':  
              a=a+11*pow(16,b);  
              break;  
              case'C':  
              a=a+12*pow(16,b);  
              break;  
              case'D':  
              a=a+13*pow(16,b);  
              break;  
              case'E':  
              a=a+14*pow(16,b);  
              break;  
              case'F':  
              a=a+15*pow(16,b);  
              break;  
           }  
           b--;  
         }    // DECIMAL->OCTAL CONVERSION  
         no=a;  
         while(no>0)  
         { r[I]=no%8;  
           no=no/8;  
           I++;  
         }  
         B4ii:  
         gotoxy(30,20);  
         for(j=I-1;j>=0;j--)  
         cout<<r[j];  
        do  
        { getmousepos(b4c1,x4c1,y4c1);  
          if(b4c1==1)  
          { if(x4c1>=230 && x4c1<=390 && y4c1>=400 && y4c1<=440) //TUTORIAL  
            {  cleardevice();  
               t_guide();  
               delay(4500);  
               hexoctt();  
               while(!kbhit())  
               {  delay(1); }  
               cleardevice();  
               dialogbox();  
               style();  
               outtextxy(100,20,"Hexadecimal -> Octal");  
               gotoxy(23,13);  
               cout<<hexadecimal;  
               goto B4ii;  
            }  
            if(x4c1>=490 && x4c1<=590 && y4c1>=400 && y4c1<=440) //CLEAN  
            { cleardevice();  
              goto C4ii;  
            }  
            if(x4c1>=20 && x4c1<=100 && y4c1>=400 && y4c1<=430) //BACK  
            { loading();  
              cleardevice();  
              goto A4;  
            }  
          }  
         if(kbhit())  
         e=getch();  
        }while(e!=27);  
           }  
         }  if(kbhit())  
        e=getch();  
       }while(e!=27);  
     }  
     if(x4>=20 && x4<=100 && y4>=400 && y4<=430) // BACK  
     {   loading();  
         cleardevice();  
         goto abc;  
     }  
       }  
       if(kbhit())  
    e=getch();  
     }while(e!=27);  
   }  
  } if(kbhit())  
      e=getch();  
 }while(e!=27);  
  exit();  
 closegraph();  
 return 0; }  


