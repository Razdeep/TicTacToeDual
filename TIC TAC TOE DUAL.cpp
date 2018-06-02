/*
*	TIC TAC TOE DUAL PLAYER
*		By Rajdeep Roy Chowdhury
*		<rrajdeeproychowdhury@gmail.com>
*
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
*
*/

#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;
int r,c;
char data[3][3];
void printLine(int,char);
char player='X';
void showcredits();
void delay();
void initialize()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			data[i][j]='-';
}
void recognize(char n)
{
	switch(n)
	{
		case '1':
			r=2;
			c=0;
			break;
		case '2':
			r=2;
			c=1;
			break;
		case '3':
			r=2;
			c=2;
			break;	
		case '4':
			r=1;
			c=0;
			break;
		case '5':
			r=1;
			c=1;
			break;
		case '6':
			r=1;
			c=2;
			break;
		case '7':
			r=0;
			c=0;
			break;
		case '8':
			r=0;
			c=1;
			break;
		case '9':
			r=0;
			c=2;
			break;
		default:
			cout<<"error";
	}
}
void showboard()
{
	for(int i=0;i<3;i++)
	{
		cout<<"| ";
		for(int j=0;j<3;j++)
		cout<<data[i][j]<<" |";
		cout<<endl;
	}
}
int gameover()
{
	//tempo
	bool drawstate=true;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(data[i][j]=='-')
			drawstate=false;
		}
	}
	if(data[r][0]==data[r][1] && data[r][0]==data[r][2] && data[r][0]!='-')
		return 1;
	else if(data[0][c]==data[1][c] && data[1][c]==data[2][c] && data[0][c]!='-')
		return 1;
	else if(data[0][0]==data[1][1] && data[1][1]==data[2][2] && data[0][0]!='-')
		return 1;
	else if(data[0][2]==data[1][1] && data[0][2]==data[2][0] && data[0][2]!='-')
		return 1;
	else if(drawstate)
	{
		return 2;
	}
	else return 0;
}
void play()
{
	char z;
	while(1)
	{
		system("cls");
		printLine(50,'-');
		cout<<"\tTIC TAC TOE GAME"<<endl<<"\t\t\tBy RAJDEEP ROY CHOWDHURY";
		printLine(50,'-');
		cout<<endl;
		showboard();
		checkpt:
		cout<<endl<<"Considering the numpad as field input location of "<<player<<" ";
		z=getche();
		cout<<endl;
		recognize(z);
		if(data[r][c]=='-')
			data[r][c]=player;
		else{
			cout<<"Space already occupied"<<endl;
			goto checkpt;
		}
		if(player=='X')
			player='O';
		else player='X';
		int flag=gameover();
		if(flag==1)
		{
			system("cls");
			printLine(50,'-');
			cout<<"\tTIC TAC TOE GAME"<<endl<<"\t\t\tBy RAJDEEP ROY CHOWDHURY";
			printLine(50,'-');
			cout<<endl;
			showboard();
			cout<<"Game over \t"<<player<<" looses!!"<<endl;
			getch();
			break;
		}
		else if(flag==2)
		{
			system("cls");
			printLine(50,'-');
			cout<<"\tTIC TAC TOE GAME"<<endl<<"\t\t\tBy RAJDEEP ROY CHOWDHURY";
			printLine(50,'-');
			cout<<endl;
			showboard();
			cout<<"Game is a tie"<<endl;
			getch();
			break;
		}
	}
}
void printLine(int n,char c)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<c;
	cout<<endl;
}
int main()
{
	system("color 0b");
	system("title TIC TAC TOE by Rajdeep");
	char ch='n';
	do
	{
		initialize();
		play();
		cout<<"Do You want to continue playing (Y/N) ";
		ch=getche();
		cout<<endl;
	}while(ch=='y'||ch=='Y');
	showcredits();
	getch();
	return 0;
}
void showcredits()
{
	char str[]="\n\nThank You For Using... Coded by RRC\nEmail me at rrajdeeproychowdhury@gmail.com";
	for(int i=0;str[i]!='\0';i++)
	{
		cout<<str[i];
		delay();
	}
}
void delay()
{
	int i,j;
	for(i=0;i<32768;i++)
	{
		for(j=0;j<1000;j++)
		{
		
		}
	}
}
