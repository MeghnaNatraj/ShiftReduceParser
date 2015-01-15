#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#define TRUE 1
#define FALSE 0
void header();
void main()
{
  char *p[3]={"SS+","SS*","a"},*q[2]={"0S1","01"},*string,stack[10]="",*input,*pos;
  int done=FALSE,found=0,i,foundProd,lengthStack,choice;
  clrscr();
  header();
  cout<<"\n Which production do you wish to choose ?";
  cout<<"\n\n(1) S --> SS+/SS*/a";
  cout<<"\n(2) S --> 0S1/01 ";
  cout<<"\n(3) Exit";
  cout<<"\n\n Enter your choice :";
  cin>>choice;
  switch(choice)
  {
  case 1 : header();
	   cout<<"\n Production : S --> SS+/SS*/a ";
	   cout<<"\n String : ";
	   cin>>string;
	   strcpy(input,string);
	   cout<<"\n\nSTACK\t\tINPUT\t\tACTION\n";
	   while(done==FALSE)
	   {
	       pos=NULL;found=0;
	       for(i=0;i<3;i++)
	       {
		  if(strcmp(pos=strstr(stack,p[i]),NULL)!=0)
		  {
		     found=1;
		     foundProd=i;
		     break;
		 }
	       }
	       cout<<"\n$"<<stack<<"\t\t"<<input<<"$\t\t";
	       if(strlen(input)==0&&strcmp(stack,"S")==0) { cout<<"ACCEPTED"; done=TRUE;}
	       else if(strlen(input)==0&&strcmp(stack,"S")>0&&found!=1) { cout<<"Error"; goto end; }
	       else if(found)
	       {
		  cout<<"Reduce S->"<<p[foundProd];
		  *pos='S';
		  *(pos+1)='\0';
	       }
	      else
	      {
		   cout<<"Shift";
		   lengthStack=strlen(stack);
		   stack[lengthStack]=*(input);
		   stack[lengthStack+1]='\0';
		   input++;
	       }
	   }
	   break;
  case 2 : header();
	   cout<<"\n Production : S --> 0S1/01 ";
	   cout<<"\n String : ";
	   cin>>string;
	   strcpy(input,string);
	   cout<<"\n\nSTACK\t\tINPUT\t\tACTION\n";
	   while(done==FALSE)
	   {
	       pos=NULL;found=0;
	       for(i=0;i<2;i++)
	       {
		  if(strcmp(pos=strstr(stack,q[i]),NULL)!=0)
		  {
		     found=1;
		     foundProd=i;
		     break;
		 }
	       }
	       cout<<"\n$"<<stack<<"\t\t"<<input<<"$\t\t";
	       if(strlen(input)==0&&strcmp(stack,"S")==0) { cout<<"ACCEPTED"; done=TRUE;}
	       else if(strlen(input)==0&&strcmp(stack,"S")>0&&found!=1) { cout<<"Error"; goto end; }
	       else if(found)
	       {
		  cout<<"Reduce S->"<<p[foundProd];
		  *pos='S';
		  *(pos+1)='\0';
	       }
	      else
	      {
		   cout<<"Shift";
		   lengthStack=strlen(stack);
		   stack[lengthStack]=*(input);
		   stack[lengthStack+1]='\0';
		   input++;
	       }
	   }
	   break;
  case 3 : exit(0);
  default : cout<<"\n\nWrong Option !!";delay(2000);exit(0);
  }
  end : getch();
	cout<<"\n\n  Hope you enjoyed parsing  ";
	delay(2000);
	exit(0);
  }
 void header()
 {
   clrscr();
   cout<<"\n\n**************************************************************";
   cout<<"\n\n                SHIFT REDUCE PARSER                            ";
   cout<<"\n\n**************************************************************\n\n";
 }