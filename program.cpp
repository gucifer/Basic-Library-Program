#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

const int SIZE=100;

int count=0;

struct book
{
	int bno;
	char bname[20];
	char author[20];
	float price;
	int ncopy;
	int nissue;
};
book b[SIZE];

void addbook(); //add one book detail
void display(); //display all book detail
void searchno(); //search book with bookno
void searchname(); //search book with bookname
void display(book); //display detail of one book
void modifybook(); //modify book detail
void deletebook(); //delete book detail

void main()
{
	int choice;
	do{
		clrscr();
		cout<<"\n\n\t\tMain Menu";
		cout<<"\n1.Add book details";
		cout<<"\n2.Display all books";
		cout<<"\n3.Search book by bookno";
		cout<<"\n4.Search book by bookname";
		cout<<"\n5.Modify book details";
		cout<<"\n6.Delete book details";
		cout<<"\n7.Exit";
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			clrscr();
			addbook();
			break;
			
			case 2:
			clrscr();
			if(count==0)
			{
				cout<<"\nNo book exists";
				cout<<"\nPlease run option one first";
				break;
			}
			display();
			break;
			
			case 3:
			clrscr();
			if(count==0)
			{
				cout<<"\nNo book exists";
				cout<<"\nPlease run option one first";
				break;
			}
			searchno();
			break;
			
			case 4:
			clrscr();
			if(count==0)
			{
				cout<<"\nNo book exists";
				cout<<"\nPlease run option one first";
				break;
			}
			searchname();
			break;
			
			case 5:
			clrscr();
			if(count==0)
			{
				cout<<"\nNo book exists";
				cout<<"\nPlease run option one first";
				break;
			}
			modifybook();
			break;
			
			case 6:
			clrscr();
			if(count==0)
			{
				cout<<"\nNo book exists";
				cout<<"\nPlease run option one first";
				break;
			}
			deletebook();
			break;
			
			case 7:
			cout<<"\nExit from program...Bye";
			break;
			
			default:
			cout<<"\n\nInvalid choice";
			
		}
		cout<<"\n\nPress any key to continue...";
		getch();
	}while(choice!=7);
	

}

void addbook()
{
	cout<<"Enter book details\n";
	cout<<"Bookno:";
	cin>>b[count].bno;
	cout<<"Bookname:";
	cin>>b[count].bname;
	cout<<"Author";
	gets(b[count].author);
	cout<<"Price:";
	cin>>b[count].price;
	cout<<"No. of copies:";
	cin>>b[count].ncopy;
	
	bcount.nissue=0;
	count++;
}

void display()
{
	int i;
	for(i=0;i<count;i++)
	{
		cout<<"\nBookno :"<<b[i].bno;
		cout<<"\nBookname :"<<b[i].bname;
		cout<<"\nAuthor :"<<b[i].author;
		cout<<"\nPrice :"<<b[i].price;
		cout<<"\nNo of copy :"<<b[i].ncopy;
		cout<<"\nNo of issue :"<<b[i].nissue;
	}cout<<"\n----------------------------------------------";
}

void searchno()
{
	int no,i,flag=0;
	cout<<"Enter book number to search:";
	cin>>no;
	for(i=0;i<count;i++)
	{
		if(b[i].bno==no)
		{
			cout<<"\nBook found";
			display(b[i]);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\n\nInvalid bookno";
	}
	
}

void searchname()
{
	char name[20];
	int i,flag=0;
	cout<<"Enter book name to search:";
	gets(name);
	for(i=0;i<count;i++)
	{
		if(strcmp(b[i].bname,name)==0)
		{
			cout<<"\nBook found";
			display(b[i]);
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		cout<<"\n\nInvalid bookno";
	}
}

void display(book b1)
{
	cout<<"-----------------------------\n";
	cout<<"Bookno:";
	cout<<b[count].bno;
	cout<<"\nBookname:";
	cout<<b[count].bname;
	cout<<"\nAuthor";
	cout<<b[count].author;
	cout<<"\nPrice:";
	cout<<b[count].price;
	cout<<"No. of copies:";
	cout<<b[count].ncopy;
	cout<<"\n-----------------------------\n";
}

void modifybook()
{
	int no,i,flag=0;
	char ch;
	cout<<"Enter bookno to modify:";
	cin>>no;
	for(i=0;i<count;i++)
	{
		if(b[i].bno==no)
		{
			cout<<"\nBook found";
			flag=1;
			cout<<"\nCurrent Details of book:\n";
			display(b[i]);
			cout<<"\nDo you want to modify(y/n):";
			cin>>ch;
			if(ch=="y"||ch=="Y")
			{
				cout<<"Enter book details\n";
	cout<<"Bookno:";
	cin>>b[count].bno;
	cout<<"Bookname:";
	cin>>b[count].bname;
	cout<<"Author";
	gets(b[count].author);
	cout<<"Price:";
	cin>>b[count].price;
	cout<<"No. of copies:";
	cin>>b[count].ncopy;
	cout<<"\nRecord is modified";
	
	cout<<"\n\nModified Record";
	display(b[i]);
			}
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nInvalid book no";
	}
}

void deletebook()
{
	int no,i,flag=0;
	char ch;
	cout<<"Enter book no to delete";
	cin>>no;
	for(i=0;i<count;i++)
	{
		if(b[i].bno==no)
		{
			cout<<"\nBook found";
			cout<<"\nBook details\n";
			display(b[i]);
			flag=1;
			cout<<"\nAre you sure to delete(y/n)";
			cin>>ch;
			if(ch=="y"||ch=="Y")
			{
				for(int j=i;j<count;j++)
				{
					b[j]=b[j+1];
				}
				count--;
				cout<<"\n\nRecord Deleted Sucessfully";
			}
			break;
		}
	}
	if(!flag)
	{
		cout<<"\nInvalid book no";
	}
}

e