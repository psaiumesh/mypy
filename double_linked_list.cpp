#include <iostream>
#include <iomanip>
#include <curses.h>
int ch;
class node
{
	public:
		int no;
		node *lptr,*rptr;
};
class dlist
{
	public:
		node *left,*right,*ptr;
		dlist()
		{
			left=right=NULL;
		}
		void insert();
		void ftraverse();
		void btraverse();
		void del();
};
void dlist:: insert()
{
	node *p= new node();
	std::cout <<"enter the number \n";
	std::cin>>p->no;
	if(left == NULL)
	{
		left =p;
		right=p;
		p->lptr=NULL;
		p->rptr=NULL;
		return;
	}
	if(p->no <= left->no)
	{
		p->rptr=left;
		p->lptr=NULL;
		left->lptr=p;
		left=p;
		return;
	}
	if(p->no >= right->no)
	{
		right->rptr=p;
		p->lptr=right;
		right=p;
		return;
	}
	ptr=left->rptr;
	while(ptr!=NULL && p->no > ptr->no)
	{
		ptr=ptr->rptr;
	}
	if(p->no < ptr->no)
	{
		p->lptr=ptr->lptr ;
		p->rptr=ptr;
		(ptr->lptr)->rptr=p;
		ptr->lptr=p;
		return;
	}
}
void dlist:: ftraverse()
{
	if(left == NULL)
	{
		std::cout<<"list is empty \n";
		return;
	}
	ptr=left;
	while (ptr != NULL)
	{
		std::cout <<"elements in forward are"<<ptr->no<<"\n";
		ptr=ptr->rptr;
	}
}
void dlist:: btraverse()
{
	if (right==NULL)
	{
		std::cout << "list is empty \n";
		return;
	}
	ptr=right;
	while (ptr!=NULL)
	{
		std::cout <<"elements in backward are"<<ptr->no<<"\n";
		ptr=ptr->lptr;
	}
}
void dlist:: del()
{
	node *ptr,*p;
	if(left ==NULL || right == NULL)
	{
		std::cout<<" underflow \n";
		return;
	}
	int rno;
	std::cout<<"enter element to be deleted \n";
	std::cin>>rno;
	if(rno<left->no || rno> right->no)
	{
		std::cout<<"not found \n";
		return;
	}
	if(rno==left->no && rno==right->no)
	{
		p=left;
		left=NULL;
		right=NULL;
		delete p;
		return;
	}

	if (rno==left->no)
	{
		p=left;
		left=left->rptr;
		left->lptr=NULL;
		delete p;
		return;
	}
	if(rno==right->no)
	{
		p=right;
		right=right->lptr;
		right->rptr=NULL;
		delete p;
		return;
	}
	ptr=left->rptr;
	while(ptr!=NULL && rno > ptr->no)
	{
		//save = save->rptr;
		ptr=ptr->rptr;
	}
	if(ptr==NULL)
	{
		std::cout<<"element not found \n";
		return;
	}
	if(ptr->no > rno)
	{
		std::cout<<"element not found \n";
		return;
	}
	if(rno==ptr->no)
	{
		p=ptr;
		(ptr->lptr)->rptr=ptr->rptr;
		(ptr->rptr)->lptr=ptr->lptr;
		delete p;
		return;
	}
}
void menu()
{
	std::cout<<"1.insert  2.delete  3. fdisplay()    4.bdisplay   5.exit  \n";
	std::cout<< "enter your choice \n";
	std::cin>> ch;
}
int main()
{
	dlist d;
	menu();
	while(ch<=5)
	{
		switch(ch)
		{
			case 1: d.insert();
					menu();
					break;
			case 2:d.del();
				   menu();
				   break;
			case 3:d.ftraverse();
				   menu();
				   break;
			case 4:d.btraverse();
				   menu();
				   break;
			case 5:exit(1);
				   break;
		}
	}
}

