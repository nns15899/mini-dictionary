#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define dict "dictionary.txt"
using namespace std;

FILE *data;
int n=0;
int q=0;

struct lib {char word[20], mean[50];};
struct lib a[500];

void search(void);    //to search a word
void new1(void);       //to add a word
void list(void);        //to show list of all words
void deletew(void);      //to delete a word

int main()
{
	system("cls");
	system("color c0");
	int mode;

	while(1)
	{
		system("cls");
		cout<<"\n\n\n____________________________________________________________________________________________________________\n\n"<<endl;
		cout<<"\t\t\t|MINI DICTIONARY|"<<endl;
        cout<<"\t\t|LOVELY PROFESSIONAL UNIVERSITY|"<<endl;
        cout<<"\t---------------------------------------------"<<endl;
        cout<<"______________________________________________________________________________________________________________________"<<endl;
        cout<<"\tprepared by:NIRBHAY NARAYAN SINGH"<<endl;
        cout<<"\tRegistration no-********"<<endl;
        cout<<"\tsubmitted to:************";
		cout<<"\n_______________________________________________________________________________\n\n"<<endl;

		cout<<"\n\t\t\t1.SEARCH WORD.\n\t\t\t2.SHOW LIST OF WORDS.\n\t\t\t3.ADD WORDS.\n\t\t\t4.DELETE WORD.\n\t\t\t5.EXIT."<<endl;
		cout<<"\n_______________________________________________________________________________\n"<<endl;
           cout<<"\t\t\t|Made With Love In INDIA |"<<endl;


		cout<<"\n\n\t\t\tENTER MODE: "<<endl;
       
		cout<<"\t\t\t";cin>>mode;
		switch(mode)
		{
			case 1:
				search();
				break;
			case 2:
				list();
				break;
			case 3:
				new1();
				break;
			case 4:
				deletew();
				break;
			case 5:
				exit(0);
			default:
				cout<<"\nChoose only from modes 1-5"<<endl;
		}
	}

}

void new1(void)
{
	system("cls");
	system("color 0D");
	char ch;

	data=fopen(dict,"a");

	if(data==NULL)
	cout<<"File does not exist."<<endl;

	else
	do
	{
		gets(a[n].word);  /*added this statement to avoid gets() bug. The compiler wasn't taking input for first gets() statement.
		That's why added it as a very first statement of this function so that the compiler starts taking input from the second gets() statement i.e. for words.*/

		cout<<"\nEnter word: "<<endl;
		gets(a[n].word);

		cout<<"\nEnter meaning: "<<endl;
		gets(a[n].mean);


		fprintf(data,"%s    %s\n", a[n].word, a[n].mean);
        
		
		n++;

		cout<<"\nAdd more words? (y/n)"<<endl;

	}
	while((ch=getche())=='y');

	fclose(data);
}

void list(void)
{
	data=fopen(dict,"r");

	if(data==NULL)
	cout<<"File does not exist."<<endl;

	else
	{
		cout<<"\n________________________________________________________________________________\n"<<endl;
		cout<<"WORDS"<<"\t\t\tMEANING"<<endl;
		cout<<"________________________________________________________________________________\n"<<endl;
		while(fscanf(data,"%d",a[q].word) != EOF)  /*since EOF returns an integer value therefore used %d instead of %s coz char to int conversion is invalid*/
		{
			fscanf(data,"%s\t%[^\n]s\t%[^\n]s\t%[^\n]s\n", &a[q].word, &a[q].mean);  /* [^\n] allows scanf() to take multi-word input until enter isn't pressed.*/
			cout<<a[q].word<<"\t\t\t"<<a[q].mean<<endl;
			q++;
		}
	}
	fclose(data);
	cout<<"\nPress any key for main menu."<<endl;
    cout<<"\t\t\t\t\t|Made With Love In INDIA |"<<endl;
	getch();
}


void search(void)
{
	system("cls");
	system("color 09");
	int w=0;
	char search[20];
	do
	{
		gets(search); //because of gets bug.
		cout<<"\n\nEnter word to search:"<<endl;
		gets(search);
		data=fopen(dict,"r");
		if(data==NULL)
		cout<<"File does not exist."<<endl;
		else
		{
			while(fscanf(data,"%d",a[w].word) != EOF) //used %d instead of %s coz of invalid conversion from char to int
			{
				fscanf(data,"%s\t%[^\n]s\t%[^\n]s\t%[^\n]s\n", &a[w].word, &a[w].mean);
				if(strcmp(a[w].word,search)==0)
				{
					cout<<"\n________________________________________________________________________________\n"<<endl;
                    cout<<  "WORDS"  <<  "\t\t\tMEANING" <<endl;
					cout<<"________________________________________________________________________________\n"<<endl;
                    cout<<a[w].word<<"\t\t\t"<<a[w].mean<<endl<<endl<<endl;
                       cout<<"\t\t\t\t\t|Made With Love In INDIA |"<<endl;
					w++;
				}
			}
		}
		fclose(data);
		cout<<"\n\nSearch more words?(y/n):"<<endl;
	}
	while(getche()=='y');
}

void deletew(void)
{
	system("cls");
	system("color 0E");
	char worddel[20];
	int i=0;
	FILE *data2;
	do
	{
		data=fopen(dict,"r");

		gets(worddel);
		cout<<"\nEnter word: "<<endl;
		gets(worddel);

		data2=fopen("replica.txt","a");
		rewind(data);

		while((fscanf(data,"%s\t%[^\n]s\t%[^\n]s\t%[^\n]s\n", &a[i].word, &a[i].mean))!=EOF)
		{
			if(strcmp(a[i].word, worddel)!=0)  //all the words from dict except the one which is being entered by the user for deletion, are copied on replica.text
			fprintf(data2,"%s\t%s\t%s\t%s\n", a[i].word, a[i].mean);
			i++;
		}

		fclose(data);
		fclose(data2);

		remove(dict); //deletes dict
		rename("replica.txt",dict); //renames replica.txt as dict
		cout<<"\nDelete more words?(y/n)"<<endl;
	}
	while(getche()== 'y');
}

