#include <iostream>
#include <iomanip>
#include <curses.h>
int ch;
class node
{
	public:
		int no;
		node *link;
};
class slist
{
	node *first;
	public:
	slist()
	{
		first=NULL;
	}
	void insert();
	void del();
	void disp();
};
void slist:: insert()
{
	node *ptr, *p,*save;
	p=new node();
	std::cout<< "enter the number to be inserted \n";
	std::cin>>p->no;
	if(first==NULL)
	{
		first=p;
		p->link=NULL;
		return;	
	}
	else if(p->no <=first->no)
	{
		p->link=first;
		first=p;
		return;
	}
	save=first;
	ptr=first->link;
	while(ptr!=NULL && p->no > ptr->no)
	{
		save=ptr;
		ptr=ptr->link;
	}
	if (ptr == NULL)
	{
		save->link=p;
		p->link=NULL;
		return;
	}
	if (p->no < ptr-> no)
	{
		save->link=p;
		p->link=ptr;
		return;
	}
}
void slist:: del()
{
	int rno;
	node *ptr,*p,*save;
	if (first == NULL)
	{
		std:: cout<<"underflow \n";
			return;
	}
	std::cout<<"enter the number to be deleted \n";
	std::cin>>rno;
	if(rno<first->no)
	{
		std::cout<<"number not found \n";
		return;
	}
	if(rno==first->no)
	{
		p=first;
		first=first->link;
		delete p;
		return;
	}
	save=first;
	ptr=first->link;
	while(ptr!=NULL && rno > ptr->no)
	{
		save=ptr;
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		std::cout<<"element not found \n";
		return;
	}
	if (ptr->no > rno)
	{
		std::cout<<"element not found \n";
		return;
	}
	
		
	if(rno == ptr->no)
	{
		p=ptr;
		save->link=ptr->link;
		delete p;
		return;

	}
	//if(ptr==NULL)
//	{
//		std::cout<<"element not found \n";
//		return;
//	}
}
void slist:: disp()
{
	node *ptr;
	if (first==NULL)
	{
		std::cout<<"the list is empty \n";
		return;

	}
 	ptr=first;
	while (ptr != NULL)
	{
		std::cout<<"elements are:"<<ptr->no<< "\n";
		ptr=ptr->link;
	}
}
void menu()
{
	std::cout<<" 1.insert  2.delete   3.display   4. exit \n";
	std::cout<<"enter your choice \n";
	std::cin>>ch;
}
int main()
{
	slist s;
	menu();
	while(ch<4)
	{
		switch(ch)
		{
			case 1:s.insert();
				   menu();
				   break;
			case 2:s.del();
				   menu();
				   break;
			case 3:s.disp();
				   menu();
		}
	}

}



				   




