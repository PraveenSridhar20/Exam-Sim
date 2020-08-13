#include<graphics.h>
#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip.h>
#include<math.h>

char c=253;//pow
char c1=251;//sqrt
char c2=248;//degree
char c3=143;//angstromm
char c4=227;//pi
char c5=236;//inifinity
char c6=238;//belongs to
char c7=243;//less than or equal to
char c8=242;//greater than or equal to
char c9=140;//i cap
char c10=244;//integral ul
char c11=245;//integral ll
char c12=196;//hori st line
char c13=179;//vert st line
char c14=159;//function
char chx[2]={253,'\0'};//subscript 2 using graphics
char c15[2]={234,'\0'};//ohm
char c16[2]={230,'\0'};//mu

char q[20];
int qno=0,n=0,status=0,sum=0,rt=0;
float ca=0,cap=0,cac=0,cam=0,cae=0;
char temp[10];
int driver=DETECT,mode;

class student
{
 int nf,es,rank;
 long roll;
 char name[50],electsub[50],result[20];
 int mp,mc,mm,me,ms;
 int mpp,mcp,mmp,mep;
 char gp,gc,gm,ge,go;

 public:

 student();
 student(student&);
 void input();
 void disp();
 void calc();
 void check(char);
 void disp_list();
 void modrank(int);
 int retes();
 int retrank();
 int retms();
 int retmpp();
 int retmcp();
 int retmmp();
 int retmep();
}s,e[100];


void sort()
{
 fstream f;
 f.open("Student.dat",ios::in|ios::binary);

 while(f.read((char*)&e[n],sizeof(student)))
  n++;
 e[n]=s;
 n++;
 student temp;

 for (int i=0;i<n;i++)
 {
  for (int j=0;j<n-1-i;j++)
  {
   if (e[j].retms()< e[j+1].retms())
   {
    temp=e[j];
    e[j]=e[j+1];
    e[j+1]=temp;
   }
  }
 }

 for (i=0;i<n;i++)
  e[i].modrank(i+1);

 for (i=0;i<n;i++)
  if (e[i].retms()==e[i+1].retms())
   e[i+1].modrank(e[i].retrank());
 f.close();

 f.open("Student.dat",ios::out|ios::binary);
 i=0;

 while(i<n)
 {
  f.write((char*)&e[i],sizeof(student));
  ++i;
 }

 f.close();
}

void calc_avg()
{
 sum=0;
 for (int i=0;i<n;i++)
  sum+=e[i].retms();
 ca=sum/n;

 sum=0;
 for (i=0;i<n;i++)
  sum+=e[i].retmpp();
 cap=sum/n;

 sum=0;
 for (i=0;i<n;i++)
  sum+=e[i].retmcp();
 cac=sum/n;

 sum=0;
 for (i=0;i<n;i++)
  sum+=e[i].retmmp();
 cam=sum/n;

 sum=0;
 for (i=0;i<n;i++)
  sum+=e[i].retmep();
 cae=sum/n;
}

void load(void)
{

 for (int i=1;i<=100;i++)
 {
  delay(65);
  clrscr();
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   Loading ";
  if (i%3==0) cout<<"\\";
  else if (i%3==1) cout<<"|";
  else if (i%3==2) cout<<"/";
 }

 delay(1000);
 clrscr();
}



void timer()
{
 for (int i=400;i>=-200;i--)
 {
  delay(10);
  cleardevice();
  gotoxy(28,1);

  cout<<"Your time starts in:"<<(i+300)/100;

  //spider

  circle(100,100+i,10);
  ellipse(100,130+i,360,0,10,20);
  line(100,110+i,130,98+i);
  line(130,98+i,130,70+i);
  line(100,110+i,140,105+i);
  line(140,105+i,140,65+i);
  line(100,110+i,70,98+i);
  line(70,98+i,70,70+i);
  line(100,110+i,60,105+i);
  line(60,105+i,60,65+i);
  line(100,110+i,130,122+i);
  line(130,122+i,130,160+i);
  line(100,110+i,140,115+i);
  line(140,115+i,140,170+i);
  line(100,110+i,70,122+i);
  line(70,122+i,70,160+i);
  line(100,110+i,60,122+i);
  line(60,122+i,60,170+i);

  //bat

  line(510,100+i,505,90+i);
  line(510,100+i,516,100+i);
  line(516,100+i,521,90+i);
  line(505,90+i,505,105+i);
  line(521,90+i,521,105+i);
  ellipse(505,95+i,180,270,25,10);
  line(480,95+i,450,95+i);
  ellipse(442,110+i,0,90,30,15);
  ellipse(482,130+i,0,90,30,20);
  line(482,110+i,472,110+i);
  line(543,110+i,553,110+i);
  ellipse(543,130+i,90,180,30,20);
  ellipse(583,110+i,90,180,30,15);
  ellipse(522,95+i,270,0,25,10);
  line(548,95+i,578,95+i);
 }
}

void corr()
{
 sound(415);//sa
 delay(100);
 sound(466);//ga
 delay(100);
 sound(523);//pa
 delay(100);
 sound(622);//sa
 delay(100);
 nosound();
}

void wrong()
{
 sound(261);
 delay(200);
 sound(220);
 delay(200);
 nosound();
}

void rankload()
{
 int a;
 float b;
 for (int p=0;p<4;p++)
 {
  delay(1000);
  cleardevice();
  outtextxy(240,210,"RANK LIST LOADING");
  for (int j=0;j<=20;j++)
  {
   for(double i=0;i<j;i+=0.0045)
   {
    b=j*j-(i*i);
    float y=sqrt(b);

    if (j<=5)
    a=BLUE;
    else if (j<=6)
    a=BLACK;
    else if(j<=10)
    a=RED;
    else if (j<=11)
    a=BLACK;
    else if (j<=15)
    a=WHITE;
    else if (j<=16)
    a=BLACK;
    else if (j<=20)
    a=RED;

    putpixel(300+i,250-y,a);
    putpixel(300-i,250-y,a);
    putpixel(300+i,250+y,a);
    putpixel(300-i,250+y,a);
   }
  }
  outtextxy(296,246,"*");
 }
 delay(1000);
 cleardevice();
}

void geninst()
{

 gotoxy(1,1);
 cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
 cout<<" marks:100\nPress the enter key to see the next instruction";
 cout<<"\n\nGeneral instructions:";
 getch();

 for (int i=0;i<=400;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,500-i,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,515-i,"answer correct");
  delay(5);
 }
 getch();

 for (i=0;i<=370;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,500-i,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,515-i,"choice");
  delay(5);
 }
 getch();

 for (i=0;i<=320;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,500-i,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,515-i,"every wrong answer and 0 if skipped (press E for the same)");
  delay(5);
 }
 getch();

 for (i=0;i<=280;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
  outtextxy(1,500-i,"4.You are allowed to attempt each question only once and cant change");
  outtextxy(21,515-i,"an answer once marked");
  delay(5);
 }
 getch();

 for (i=0;i<=240;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
  outtextxy(1,220,"4.You are allowed to attempt each question only once and cant change");
  outtextxy(21,235,"an answer once marked");
  outtextxy(1,500-i,"5.Type in any one out of the 4 choices A,B,C,D from your keyboard to");
  outtextxy(21,515-i,"mark an answer. To skip a question (you cant attempt it again),");
  outtextxy(21,530-i,"press E");
  delay(5);
 }
 getch();

 for (i=0;i<=180;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
  outtextxy(1,220,"4.You are allowed to attempt each question only once and cant change");
  outtextxy(21,235,"an answer once marked");
  outtextxy(1,260,"5.Type in any one out of the 4 choices A,B,C,D from your keyboard to");
  outtextxy(21,275,"mark an answer. To skip a question (you cant attempt it again),");
  outtextxy(21,290,"press E");
  outtextxy(1,500-i,"6.Rough work sheets will be provided by your invigilator on request.");
  outtextxy(21,515-i,"The invigilator will ask you to click the finish test button('T') ");
  outtextxy(21,530-i,"once the time is up");
  delay(5);
 }
 getch();

 for (i=0;i<=120;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
  outtextxy(1,220,"4.You are allowed to attempt each question only once and cant change");
  outtextxy(21,235,"an answer once marked");
  outtextxy(1,260,"5.Type in any one out of the 4 choices A,B,C,D from your keyboard to");
  outtextxy(21,275,"mark an answer. To skip a question (you cant attempt it again),");
  outtextxy(21,290,"press E");
  outtextxy(1,320,"6.Rough work sheets will be provided by your invigilator on request.");
  outtextxy(21,335,"The invigilator will ask you to click the finish test button('T') ");
  outtextxy(21,350,"once the time is up");
  outtextxy(1,500-i,"7.Your score will be displayed along with the answer key,report card & rank");
  delay(5);
 }
 getch();

 for (i=0;i<=80;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
  outtextxy(1,220,"4.You are allowed to attempt each question only once and cant change");
  outtextxy(21,235,"an answer once marked");
  outtextxy(1,260,"5.Type in any one out of the 4 choices A,B,C,D from your keyboard to");
  outtextxy(21,275,"mark an answer. To skip a question (you cant attempt it again),");
  outtextxy(21,290,"press E");
  outtextxy(1,320,"6.Rough work sheets will be provided by your invigilator on request.");
  outtextxy(21,335,"The invigilator will ask you to click the finish test button('T') ");
  outtextxy(21,350,"once the time is up");
  outtextxy(1,380,"7.Your score will be displayed along with the answer key,report card & rank");
  outtextxy(1,490-i,"8.You will hear the following sound when your answer is right.Press any key to");
  outtextxy(21,505-i,"hear the sound");
  delay(5);
 }
 getch();
 corr();

 for (i=0;i<=40;i+=20)
 {
  cleardevice();
  gotoxy(1,1);
  cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
  cout<<" marks:100\nPress the enter key to see the next instruction";
  cout<<"\n\nGeneral instructions:";
  outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
  outtextxy(21,115,"answer correct");
  outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
  outtextxy(21,155,"choice");
  outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
  outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
  outtextxy(1,220,"4.You are allowed to attempt each question only once and cant change");
  outtextxy(21,235,"an answer once marked");
  outtextxy(1,260,"5.Type in any one out of the 4 choices A,B,C,D from your keyboard to");
  outtextxy(21,275,"mark an answer. To skip a question (you cant attempt it again),");
  outtextxy(21,290,"press E");
  outtextxy(1,320,"6.Rough work sheets will be provided by your invigilator on request.");
  outtextxy(21,335,"The invigilator will ask you to click the finish test button('T') ");
  outtextxy(21,350,"once the time is up");
  outtextxy(1,380,"7.Your score will be displayed along with the answer key,report card & rank");
  outtextxy(1,410,"8.You will hear the following sound when your answer is right.Press any key to");
  outtextxy(21,425,"hear the sound");
  outtextxy(1,490-i,"9.You will hear the following sound when your answer is wrong.Press any key to");
  outtextxy(21,505-i,"hear the sound");
  delay(5);
 }
 getch();
 wrong();

 cleardevice();
 gotoxy(1,1);

 cout<<"\t\t\t\t\bAnnual examination\nClass:XII\t\t\t\t\t\t\tTime:1 hour\nMax";
 cout<<" marks:100\nPress the enter key to see the next instruction";
 cout<<"\n\nGeneral instructions:";
 outtextxy(1,100,"1.This test consists of 20 questions all of objective type single ");
 outtextxy(21,115,"answer correct");
 outtextxy(1,140,"2.All questions are compulsory and there is no overall or any internal ");
 outtextxy(21,155,"choice");
 outtextxy(1,180,"3.Each question carries +5 marks for every correct answer, -2 for");
 outtextxy(21,195,"every wrong answer and 0 if skipped (press E for the same)");
 outtextxy(1,220,"4.You are allowed to attempt each question only once and cant change");
 outtextxy(21,235,"an answer once marked");
 outtextxy(1,260,"5.Type in any one out of the 4 choices A,B,C,D from your keyboard to");
 outtextxy(21,275,"mark an answer. To skip a question (you cant attempt it again),");
 outtextxy(21,290,"press E");
 outtextxy(1,320,"6.Rough work sheets will be provided by your invigilator on request.");
 outtextxy(21,335,"The invigilator will ask you to click the finish test button('T') ");
 outtextxy(21,350,"once the time is up");
 outtextxy(1,380,"7.Your score will be displayed along with the answer key,report card & rank");
 outtextxy(1,410,"8.You will hear the following sound when your answer is right.Press any key to");
 outtextxy(21,425,"hear the sound");
 outtextxy(1,450,"9.You will hear the following sound when your answer is wrong.Press any key to");
 outtextxy(21,465,"hear the sound.You wont hear a sound if you skip.Press any key to continue.");
 getch();

}

void credits()
{
 settextstyle(1,0,7);
 setcolor(YELLOW);

 for (int i=0;i<=1200;i+=3)
 {
  cleardevice();
  outtextxy(190,480-i,"CREDITS");
  outtextxy(40,575-i,"PRAVEEN SRIDHAR");
  outtextxy(90,650-i,"GOUTHAMNATH");
  outtextxy(40,725-i,"AKSHAY NATH PAI");
  outtextxy(60,800-i,"SRIJEYARANKESH");
  outtextxy(60,875-i,"Done under the ");
  outtextxy(130,930-i,"guidance of ");
  outtextxy(60,1000-i,"MRS.HEMALATHA");
  delay(20);
 }

 setcolor(10);
 settextstyle(4,0,7);
 outtextxy(90,150,"THANK YOU!!!");
 delay(10000);
}


void fun_list()
{
 s.calc();
 sort();
 calc_avg();
 s.disp();
 rankload();
 cout<<"\t\t\t\tMark List\n\nRoll no\t\t  Name\t\t\t\b\bTotal\t\tRank\n";
 for(rt=0;rt<n;rt++)
 {
  e[rt].disp_list();
  cout<<endl;
 }
 cout<<"\n\n Press any key twice continue";
 getch();
 getch();
 credits();
 closegraph();
 exit(0);
}


student::student()
{
 roll=0;
 nf=0;
 es=0;
 rank=0;
 strcpy(name,NULL);
 strcpy(electsub,NULL);
 strcpy(result,NULL);
 mp=mc=mm=me=ms=0;
 mpp=mcp=mmp=mep=0;
 gp=gc=gm=ge=go=0;
}

student::student(student &s1)
{
 roll=s1.roll;
 nf=s1.nf;
 es=s1.es;
 rank=s1.rank;
 strcpy(name,s1.name);
 strcpy(electsub,s1.electsub);
 strcpy(result,s1.result);
 mp=s1.mp;
 mc=s1.mc;
 mm=s1.mm;
 me=s1.me;
 ms=s1.ms;
 mpp=s1.mpp;
 mcp=s1.mcp;
 mmp=s1.mmp;
 mep=s1.mep;
 gp=s1.gp;
 gc=s1.gc;
 gm=s1.gm;
 ge=s1.ge;
 go=s1.go;
}

int student::retes()
{
 return es;
}

int student::retms()
{
 return ms;
}

int student::retrank()
{
 return rank;
}

int student::retmpp()
{
 return mpp;
}

int student::retmcp()
{
 return mcp;
}

int student::retmmp()
{
 return mmp;
}

int student::retmep()
{
 return mep;
}

void student::modrank(int a)
{
 rank=a;
}

void student::check (char a)
{
 if (qno<20)
 {
  cin>>q[qno];

  if (q[qno]=='A'||q[qno]=='a'||q[qno]=='B'||q[qno]=='b'||q[qno]=='C'||q[qno]=='c'||q[qno]=='D'||q[qno]=='d'||q[qno]=='T'||q[qno]=='t')
  {

   if (qno<5)
   {
    if (q[qno]==tolower(a)||q[qno]==toupper(a)) {mp+=5;corr();}
    else if (q[qno]=='E'||q[qno]=='e') {mp+=0;q[qno]=' ';}
    else if (q[qno]=='T'||q[qno]=='t') {q[qno]='\0';fun_list();}
    else {mp-=2;wrong();}
   }

   else if (qno>=5&&qno<10)
   {
    if (q[qno]==tolower(a)||q[qno]==toupper(a)) {mc+=5;corr();}
    else if (q[qno]=='E'||q[qno]=='e') {mc+=0;q[qno]=' ';}
    else if (q[qno]=='T'||q[qno]=='t') {q[qno]='\0';fun_list();}
    else {mc-=2;wrong();}
   }

   else if (qno>=10&&qno<15)
   {
    if (q[qno]==tolower(a)||q[qno]==toupper(a)) {mm+=5;corr();}
    else if (q[qno]=='E'||q[qno]=='e') {mm+=0;q[qno]=' ';}
    else if (q[qno]=='T'||q[qno]=='t') {q[qno]='\0';fun_list();}
    else {mm-=2;wrong();}
   }

   else if (qno>=15&&qno<20)
   {
    if (q[qno]==tolower(a)||q[qno]==toupper(a)) {me+=5;corr();}
    else if (q[qno]=='E'||q[qno]=='e') {me+=0;q[qno]=' ';}
    else if (q[qno]=='T'||q[qno]=='t') {q[qno]='\0';fun_list();}
    else {me-=2;wrong();}
   }
  }

  else {me+=0;q[qno]=' ';}
  qno++;

  cleardevice();
  gotoxy(1,1);
 }
}

void student::input()
{
 cout<<"Enter your full roll no.:";
 cin>>roll;
 cout<<"Enter your name:";
 gets(name);
 cout<<"Enter your elective subject(Biology or Computer science):";
 gets(electsub);
 if (strcmpi(electsub,"biology")==0||strcmpi(electsub,"computer science")==0)
 status=1;

 while (status==0)
 {
  cout<<"Invalid choice. Please re enter the correct elective subject";
  cout<<" or type exit to \nexit:";
  gets(electsub);
  if (strcmpi(electsub,"biology")==0||strcmpi(electsub,"computer science")==0)
  status=1;
  else if(!strcmpi(electsub,"exit"))
  {
   cout<<"Press any key to exit";
   getch();
   exit(0);
  }
 }

 if (strcmpi(electsub,"biology")==0) es=1;
 else if (strcmpi(electsub,"computer science")==0) es=2;
 delay(500);
}

void student::calc()
{
 ms=mp+mc+me+mm;
 mpp=mp*4;
 mcp=mc*4;
 mmp=mm*4;
 mep=me*4;

 {
  if (mpp<=100&&mpp>=90) gp='A';
  else if (mpp<90&&mpp>=75) gp='B';
  else if (mpp<75&&mpp>=60) gp='C';
  else if (mpp<60&&mpp>=45) gp='D';
  else if (mpp<45&&mpp>30) gp='E';
  else if (mpp<=30) {gp='F';nf++;}
 }

 {
  if (mcp<=100&&mcp>=90) gc='A';
  else if (mcp<90&&mcp>=75) gc='B';
  else if (mcp<75&&mcp>=60) gc='C';
  else if (mcp<60&&mcp>=45) gc='D';
  else if (mcp<45&&mcp>30) gc='E';
  else if (mcp<=30) {gc='F';nf++;}
 }

 {
  if (mmp<=100&&mmp>=90) gm='A';
  else if (mmp<90&&mmp>=75) gm='B';
  else if (mmp<75&&mmp>=60) gm='C';
  else if (mmp<60&&mmp>=45) gm='D';
  else if (mmp<45&&mmp>30) gm='E';
  else if (mmp<=30) {gm='F';nf++;}
 }

 {
  if (mep<=100&&mep>=90) ge='A';
  else if (mep<90&&mep>=75) ge='B';
  else if (mep<75&&mep>=60) ge='C';
  else if (mep<60&&mep>=45) ge='D';
  else if (mep<45&&mep>30) ge='E';
  else if (mep<=30) {ge='F';nf++;}
 }

 {
  if (ms<=100&&ms>=90) go='A';
  else if (ms<90&&ms>=75) go='B';
  else if (ms<75&&ms>=60) go='C';
  else if (ms<60&&ms>=45) go='D';
  else if (ms<45&&ms>30) go='E';
  else if (ms<=30) go='F';
 }

 {
  if (nf>=2) strcpy(result,"Failed");
  else strcpy(result,"Passed");
 }
}

void student::disp()
{
 cleardevice();
 gotoxy(1,1);
 char ans[21]="BCACBCDADACBBCDDABDC";
 cleardevice();
 gotoxy(1,1);
 int d=0,p=0;
 cout<<"Key:On the LHS of the slash is the correct answer and on the RHS is";
 cout<<" your\nresponse\n";
 cout<<"\n\t\t\t\t    Physics";
 cout<<"\n\n\n\n\n\t\t\t\t   Chemistry";
 cout<<"\n\n\n\n\n\n\t\t\t\t  Mathematics";
 if (es==1)
 cout<<"\n\n\n\n\n\n\t\t\t\t    Biology";
 else if (es==2) cout<<"\n\n\n\n\n\n\n\t\t\t\t\bComputer Science";
  cout<<"\n\n\n\n\n\n\t\t\t\b\bThe total marks secured is "<<ms<<"/100";
 cout<<"\n\nPress any key twice to continue";
 for 	(int i=0;i<=19;i++)
 {
  int v=0;
  if (i<=8)
  temp[v++]=i+49;
  else if(i>8&&i<=18)
  {
   temp[v++]='1';
   if(i!=8) temp[v++]=i+39;
   else temp[v++]='0';
  }
  else if (i>18)
  {
   temp[v++]='2';
   if (i!=18) temp[v++]=i+29;
   else temp[v++]='0';
  }
  temp[v++]='.';
  temp[v++]=ans[i];
  temp[v++]='\\';
  temp[v++]=q[i];
  temp[v++]='\0';
  if (q[i]==ans[i]) setcolor(GREEN);
  else if (q[i]==' '||q[i]==NULL) setcolor(WHITE);
  else  setcolor(RED);
  if (i%5==0&&i!=0) {d++;p=0;}
  p++;
  outtextxy(10+(100*p),80+(d*100),temp);
 }
 getch();
 getch();
 setcolor(WHITE);
 cleardevice();
 gotoxy(1,1);

 cout<<"\t\t\t\tReport card\n";
 cout<<"\nRoll number:"<<roll<<endl;
 cout<<"Name:"<<name<<endl;
 cout<<"\n\nSubject\t\t\t\tMarks\t\tGrade\tAverage\n";
 cout<<"Physics\t\t\t\t "<<setprecision(2)<<mpp<<"\t\t  "<<gp;
 cout<<'\t'<<setprecision(2)<<cap<<endl;
 cout<<"Chemistry\t\t\t "<<setprecision(2)<<mcp<<"\t\t  "<<gc;
 cout<<'\t'<<setprecision(2)<<cac<<endl;
 cout<<"Mathematics\t\t\t "<<setprecision(2)<<mmp<<"\t\t  "<<gm;
 cout<<'\t'<<setprecision(2)<<cam<<endl;
 if (strcmpi(electsub,"computer science")==0)
 cout<<"Computer Science\t\t ";
 else if (strcmpi(electsub,"biology")==0)
 cout<<"Biology\t\t\t\t ";
 cout<<setprecision(2)<<mep<<"\t\t  "<<ge<<'\t'<<setprecision(2)<<cae<<endl;
 cout<<"Total score\t\t\t "<<ms<<"\t\t  "<<go<<'\t'<<setprecision(2)<<ca;
 cout<<"\nResult:"<<result<<"\n\nPress any key twice to continue";
 getch();
 getch();
 cleardevice();
 gotoxy(1,1);
}

void student::disp_list()
{
 cout<<"  "<<roll<<"\t\t"<<name;
 gotoxy(40,rt+4);
 cout<<ms<<"\t\t  ";
 if (nf<2)
  cout<<rank;
 else
  cout<<'-';
}

void main()
{
 clrscr();
 load();
 s.input();
 clrscr();
 initgraph(&driver,&mode,"c:\\tc\\bgi");
 geninst();
 timer();
 cleardevice();
 gotoxy(1,1);

 cout<<"\t\t\t   Your time starts now!!\n\t\t\t\t  Physics";

 //q1
 {
  cout<<"\nQ1.The box of a pinhole camera of length L has a hole of radius ";
  cout<<"a.It is assumed that the hole is illuminated by a parallel beam of";
  cout<<" light of wavelength x the \nspread of the spot (obtained on the";
  cout<<" opposite wall of the camera) is the sum of  the geometric spread";
  cout<<" and the spread due to diffraction. The spot would have its mimimum";
  cout<<" size(say b) when:\n";
  cout<<"A.a="<<c1<<"(xL) and b=(2x"<<c<<")/L\n";
  cout<<"B.a="<<c1<<"(xL) and b="<<c1<<"(4xL)\n";
  cout<<"C.a=x"<<c<<"/L and b="<<c1<<"(4xL)\n";
  cout<<"D.a=x"<<c<<"/L and b=(2x"<<c<<")/L\n";
  s.check('B');
 }

 //q2
 {
  cout<<"\nQ2.Two identical wires A and B, each oflength l,carry the same ";
  cout<<"current i. Wire Ais bent into a circle of radius R and wire B is ";
  cout<<"bent to form a square of side a.If B1 and B2 are the values of ";
  cout<<"magnetic field at the centres of the circle and  the square ";
  cout<<"respectively, then the ratio B1/B2 is:\n";
  cout<<"A."<<c4<<c<<"/(16"<<c1<<"2)\n";
  cout<<"B."<<c4<<c<<"/16\n";
  cout<<"C."<<c4<<c<<"/(8"<<c1<<"2)\n";
  cout<<"D."<<c4<<c<<"/8\n";
  s.check('C');
 }

 //q3
 {
  cout<<"\nQ3.Assume an electirc field E=30x"<<c<<c9<<" exists in space.Then";
  cout<<" the potential \ndifference Va-Vo, where Vo is the potential at the";
  cout<<" origin and Va is the\npotential at x=2m is:\n";
  cout<<"A.-80V\n";
  cout<<"B.80V\n";
  cout<<"C.120V\n";
  cout<<"D.-120V\n";
  s.check('A');
 }

 //q4
 {
  cout<<"\nQ4.Half lives of two radioactive elements A and B are 20 minutes ";
  cout<<"and 40 minutes respectively.Initially, the samples have equal ";
  cout<<"number of nuclei.After 80 minutesthe ratio of decayed numbers of A ";
  cout<<"and B will be\n";
  cout<<"A.4:1\n";
  cout<<"B.1:4\n";
  cout<<"C.5:4\n";
  cout<<"D.1:16\n";
  s.check('C');
 }

 //q5
 {
  cout<<"\nQ5.\n\n\n\n\n\n\n\n\n\nThe circuit shown here has 2 batteries of ";
  cout<<"8V and 16V and 3 resistors of 3"<<c15<<",9"<<c15<<"\nand 9"<<c15;
  cout<<" and a capacitor of 5"<<c16<<"F.How much is the current I in the ";
  cout<<"circuit at steadystate?\n";
  cout<<"A.1.6A\n";
  cout<<"B.0.67A\n";
  cout<<"C.2.5A\n";
  cout<<"D.0.25A\n";
  for (int i=0,j=-5;i<=25;i+=5,j+=5)
  {
   if(i%2)
   line(200+j,10,200+i,5);
   else
   line(200+j,5,200+i,10);
  }//resistance loop1
  line(190,10,195,5);
  line(225,5,230,10);
  line(150,10,190,10);
  line(150,10,150,40);
  line(140,40,160,40);//capacitor plate upper
  line(140,49,160,49);//capacitor plate lower
  line(150,49,150,79);
  line(230,10,260,10);
  line(150,10,100,10);
  for (i=0,j=-5;i<=25;i+=5,j+=5)
  {
   if(i%2)
   line(70+j,10,70+i,5);
   else
   line(70+j,5,70+i,10);
  }//resistance loop2
  line(95,5,100,10);
  line(60,10,65,5);
  line(60,10,40,10);
  line(40,10,40,50);
  line(25,50,55,50);//battery LU
  line(32,57,48,57);//battery LL
  line(40,57,40,134);
  line(150,119,150,134);
  line(40,134,260,134);
  line(260,10,260,50);
  line(260,134,260,57);
  line(275,50,245,50);//battery RU
  line(268,57,252,57);//battery RL
  line(220,134,216,130);//Current arrow LRU
  line(220,134,216,138);//current arrow LRL
  line(100,134,96,130);//Current arrow LLU
  line(100,134,96,138);//Current arrow LLL
  line(260,20,264,24);//current arrow UR
  line(260,20,256,24);//current arrow UL
  for (i=0,j=-5;i<=35;i+=5,j+=5)
  {
   if(i%2)
   line(155,84+j,150,84+i);
   else
   line(150,84+j,155,84+i);
  }//resistance loop 3
  outtextxy(205,15,"9");
  outtextxy(213,15,c15);
  outtextxy(75,15,"3");
  outtextxy(83,15,c15);
  outtextxy(160,95,"9");
  outtextxy(168,95,c15);
  outtextxy(165,43,"5 F");
  outtextxy(173,43,c16);
  outtextxy(55,54,"8V");
  outtextxy(275,54,"16V");
  outtextxy(100,140,"I1");
  outtextxy(220,140,"I2");
  outtextxy(267,20,"I");
  s.check('B');
 }

 cout<<"\t\t\t\t   Chemistry";

 //q6
 {
  cout<<"\nQ6.In the chemical reaction";
  cout<<"\n\n\n\n\t\t\t   "<<(char)253;
  line(202,100,222,120);
  line(182,120,182,140);
  line(202,100,182,120);
  line(222,120,222,140);
  line(222,140,202,160);
  line(182,140,202,160);
  circle(202,130,10);
  line(202,100,202,85);
  outtextxy(200,75,"NH");
  line(235,130,320,130);
  outtextxy(255,115,"NaNO");
  outtextxy(287,120,chx);
  outtextxy(240,135,"HCl,278K");
  line(320,130,315,125);
  line(320,130,315,135);
  outtextxy(330,125,"A");
  line(350,130,420,130);
  line(420,130,415,125);
  line(420,130,415,135);
  outtextxy(367,115,"CuCN");
  line(380,135,375,140);
  line(375,140,385,140);
  line(380,135,385,140);
  outtextxy(430,125,"B");
  cout<<"\n\n\n\n\n\n\nThe compounds A and B respectively are\n";
  cout<<"A.Nitrobenzene and fluorobenzene\n";
  cout<<"B.Phenol and benzene\n";
  cout<<"C.Benzene diazonium chloride and benzonitrile\n";
  cout<<"D.Nitrobenzene and chlorobenzene\n";
  s.check('C');
 }

 //q7
 {
  cout<<"\nQ7.Sodium metal crystallises in a body centred cubic lattice";
  cout<<" with a unit cell\nedge of 4.29"<<c3<<".The radius of sodium";
  cout<<" atom is approximately:\n";
  cout<<"A.3.22"<<c3<<'\n';
  cout<<"B.5.72"<<c3<<'\n';
  cout<<"C.0.93"<<c3<<'\n';
  cout<<"D.1.86"<<c3<<'\n';
  s.check('D');
 }

 //q8
 {
  cout<<"\nQ8.Two Faraday of electricity is passed through a solution of ";
  cout<<"CuSO4. The mass ofCopper deposited at the cathode is:";
  cout<<"(at. mass of Cu=63.5 amu)\n";
  cout<<"A.63.5g\n";
  cout<<"B.2g\n";
  cout<<"C.127g\n";
  cout<<"D.0g\n";
  s.check('A');
 }

 //q9
 {
  cout<<"\nQ9.The reaction of Zinc with dilute and concentrated nitric ";
  cout<<"acid, respectively, produces:\n";
  cout<<"A.NO2 and NO\n";
  cout<<"B.NO and NO2\n";
  cout<<"C.NO2 and N2O\n";
  cout<<"D.N2O and NO2\n";
  s.check('D');
 }

 //q10
 {
  cout<<"\nQ10.Which one of the following complexes shows optical";
  cout<<" isomerism?\n";
  cout<<"A.cis[Co(en)2Cl2]Cl\n";
  cout<<"B.trans[Co(en)2Cl2]Cl\n";
  cout<<"C.[Co(NH3)4Cl2]Cl\n";
  cout<<"D.[Co(NH3)3Cl3]\n";
  s.check('A');
 }

 cout<<"\t\t\t\tMathematics";

 //q11
 {
  cout<<"\n\t\t\t\t\t\t\t\t   "<<9<<"\n\t\t\t\t\t\t\t\t   "<<c10<<"\nQ11.";
  cout<<"Let [.] denote the greatest integer function.Then the value";
  cout<<" of "<<c13<<'['<<c1<<"x] dx  is\n\t\t\t\t\t\t\t\t   "<<c11;
  cout<<"\n\t\t\t\t\t\t\t\t   "<<0<<endl;
  cout<<"A.6\n";
  cout<<"B.8\n";
  cout<<"C.13\n";
  cout<<"D.0\n";
  s.check('C');
 }

 //q12
 {
  cout<<"\nQ12.If "<<c14<<"(x)+2"<<c14<<"(1/x)=3x,x not equal to 0 and S={x";
  cout<<c6<<"R:"<<c14<<"(x)="<<c14<<"(-x)}.Then S:\n";
  cout<<"A.contains exactly one element\n";
  cout<<"B.contains exactly two elements\n";
  cout<<"C.contains more than 2 elements\n";
  cout<<"D.is an empty set\n";
  s.check('B');
 }

 //q13
 {
  cout<<"\nQ13.A wire of length 2 units is cut into 2 parts which are bent";
  cout<<" respectively to form a sqaure of side x units and a circle of";
  cout<<" radius r units.If the sum of areasof the square and the circle";
  cout<<" so formed is minimum, then:\n";
  cout<<"A.(4-"<<c4<<")x="<<c4<<"r\n";
  cout<<"B.x=2r\n";
  cout<<"C.2x=r\n";
  cout<<"D.2x=(4+"<<c4<<")r\n";
  s.check('B');
 }

 //q14
 {
  cout<<"\nQ14.The system of equations\nx+ky-z=0\nkx-y-z=0\nx+y-kz=0";
  cout<<"\nhas a non trivial solution for _______ value(s) of k\n";
  cout<<"A.1\n";
  cout<<"B.2\n";
  cout<<"C.3\n";
  cout<<"D.infinite\n";
  s.check('C');
 }

 //q15
 {
  cout<<"Q15.Which of the following functions is represented by the graph?";
  line(500,30,500,460);
  line(400,250,600,250);
  line(500,30,495,35);
  line(500,30,505,35);
  outtextxy(510,35,"Y");
  putpixel(500,250,RED);
  line(500,460,495,455);
  line(500,460,505,455);
  outtextxy(510,455,"Y\'");
  line(400,250,405,255);
  line(400,250,405,245);
  outtextxy(405,260,"X\'");
  line(600,250,595,245);
  line(600,250,595,255);
  outtextxy(595,260,"X");
  outtextxy(505,255,"O");
  delay(1000);
  for(double i=0;i<189;i+=0.001)
  {
   double y=sin(i/20);
   y*=20;
   putpixel(500+y,250-i,RED);
   putpixel(500-y,250+i,RED);
  }
  cout<<"\n\nA.tan  x\nB.cos  x\nC.sin x\nD.sin  x\n";
  outtextxy(40,30,"-1");
  outtextxy(40,45,"-1");
  outtextxy(40,78,"-1");
  s.check('D');
 }

 if (s.retes()==1)
 {

  cout<<"\t\t\t\tBiology\n";

  //q16
  {
   cout<<"\nQ16.Meroblastic cleavage is an example of:\n";
   cout<<"A.Spiral\n";
   cout<<"B.Total\n";
   cout<<"C.Horizontal\n";
   cout<<"D.Partial/parietal\n";
   s.check('D');
  }

  //q17
  {
   cout<<"\nQ17.Hereditary information is indicated by:\n";
   cout<<"A.Sequence of nucleic acids\n";
   cout<<"B.Position of nucleic acid\n";
   cout<<"C.Number of nucleic acid\n";
   cout<<"D.All of these\n";
   s.check('A');
  }

  //q18
  {
   cout<<"\nQ18.Cancer cells can be easily destroyed by radiation due to:\n";
   cout<<"A.Fast mutation\n";
   cout<<"B.Rapid cell division\n";
   cout<<"C.Lack of mutation\n";
   cout<<"D.Lack of oxygen\n";
   s.check('B');
  }

  //q19
  {
   cout<<"\nQ19.Which of the following enzye is used to cut DNA molecule in ";
   cout<<"rDNA technology?";
   cout<<"A.Ligase\n";
   cout<<"B.Phosphatase\n";
   cout<<"C.Ribonuclease\n";
   cout<<"D.Restriction enzymes\n";
   s.check('D');
  }

  //q20
  {
   cout<<"\nQ20.Human population growth curve is a:\n";
   cout<<"A.S shaped curve\n";
   cout<<"B.Parabola\n";
   cout<<"C.J shaped curve\n";
   cout<<"D.Zig zag curve\n";
   s.check('C');
  }
 }

 else if (s.retes()==2)
 {

  cout<<"\t\t\t\tComputer Science\n";

  //q16
  {
   cout<<"\nQ16.The output of an OR gate is connected to both inputs of a";
   cout<<" NAND gate.The\ncombination will serve as a:\n";
   cout<<"A.AND gate\n";
   cout<<"B.OR gate\n";
   cout<<"C.NOT gate\n";
   cout<<"D.NOR gate\n";
   s.check('D');
  }

  //q17
  {
   cout<<"\nQ17.The device which establishes an intelligent connection ";
   cout<<"between a local\nnetwork and external network with completely";
   cout<<" different structures is:\n";
   cout<<"A.Gateway\n";
   cout<<"B.Router\n";
   cout<<"C.Modem\n";
   cout<<"D.Hub\n";
   s.check('A');
  }

  //q18
  {
   cout<<"\nQ18.Study the following code and select the correct possible ";
   cout<<"ouput\n\n";
   cout<<"const int max=3;\n";
   cout<<"void main()\n{\n";
   cout<<"randomize();\n";
   cout<<"int div;\n";
   cout<<"div=1+random(max);\n";
   cout<<"for (int i=1;i<3;i++)\n";
   cout<<"cout<<100%div<<'#'<<div++<<'#';\n}\n\n";
   cout<<"A.0#1#0#2#\n";
   cout<<"B.0#1#1#2#\n";
   cout<<"C.1#3#1#2#\n";
   cout<<"D.5#4#4#3#\n";
   s.check('B');
  }

  //q19
  {
   cout<<"\nQ19.An array S[20][30] is stored in memory along the row with";
   cout<<" each element\noccupying 4 bytes.Find the memory location of the";
   cout<<" element S[15][5], if element\nS[20][10] is stored at memory ";
   cout<<"location 5500\n";
   cout<<"A.3860\n";
   cout<<"B.5060\n";
   cout<<"C.3820\n";
   cout<<"D.5080\n";
   s.check('D');
  }

  //q20
  {
   cout<<"\nQ20.The value of the postfix 5,2,*,3,-,1,+,10,2,/,5,-,> is:\n";
   cout<<"A.8\n";
   cout<<"B.0\n";
   cout<<"C.1\n";
   cout<<"D.None of the above\n";
   s.check('C');
  }
 }
 fun_list();
}
