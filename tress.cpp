#include <iostream>
#include <iomanip>
int ch;
class node
{
	public:
		int data;
		node *left,*right;
};
class bstree
{
	public:
		node *root;
		bstree()
		{
			root=NULL;
		}
		node *r()
		{
			return root;
		}
		void insert(node *);
		void del(node *);
		void preord(node *ptr);
		void inord(node *ptr);
		void postord(node *ptr);
};
void bstree::inord(node *ptr)
{
	if (ptr== NULL)
	{
		std::cout<<"empty tree \n";
		return;
	}
	if (ptr->left!=NULL)
		inord(ptr->left);
	std::cout<<" "<<ptr->data;
	if(ptr->right !=NULL)
		inord(ptr->right);
}
void bstree::preord(node *ptr)
{
	if (ptr == NULL)
	{
		std::cout<<"empty tree \n";
		return;
	}
	std::cout<<" " <<ptr->data;
	if(ptr->left != NULL)
		preord(ptr->left);
	if(ptr->right != NULL)
		preord(ptr->right);
}
void bstree::postord(node *ptr)
{
	if(ptr== NULL)
	{
		std::cout<<"empty tree \n";
		return;
	}
	if (ptr->left !=NULL)
		postord(ptr->left);
	if(ptr->right !=NULL)
		postord(ptr->right);
	std::cout<< "  " <<ptr->data;
}
void bstree::insert(node *ptr)
{
	node *p,*save;
	p= new node();
	int item;
	std::cout<<"enter item to be inserted \n";
	std::cin>>p->data;
	if(root == NULL)
	{

		root=p;
		p->left =NULL;
		p->right=NULL;
		std::cout<<"hello\n";
		return;
	}
	save = root;
	ptr=root;
	while(ptr != NULL)
	{
		if(p->data == ptr->data)
		{
			std::cout<<"element alreadY \n";
			std::cout<<"element is \n"<<ptr->data;
			return;
		}
		if(p->data  < ptr->data)
		{
			save =ptr;
			ptr=ptr->left;
		}
		if(ptr != NULL)
		{

			if (p->data  > ptr->data)
				{
					save =ptr;
					ptr=ptr->right;
					}
				}
	}
		if (ptr==NULL)
		{
			if(save->data > p->data )
			{
				save ->left =p;
				p->left=NULL;
				p->right=NULL;
				return;
			}
			else 
			{
				save ->right =p;
				p->left=NULL;
				p->right=NULL;
				return;
			}
		}
}
void bstree:: del(node *ptr)
{
	node *save,*p;
	int rno;
	std::cout<<"enter element to be deleted \n";
	std::cin>>rno;
	if(root== NULL)
	{
		std::cout<<"tree is empty \n";
		return;
	}

	if(root ->left == NULL && root->right == NULL)
	{
		if(rno==root->data)
		{
			root = NULL;
			return;
		}
		else 
		{
			std::cout<<"element not found \n";
			return;
		}

	}
	ptr=root;
	save = root;
	if(rno==root->data)
	{
		if(root->left!=NULL && root->right== NULL)
		{
			ptr=root->left;
			root->left=NULL;
			root=ptr;
			return;
		}
		if(root->left==NULL && root->right !=NULL)
		{
			ptr=root->right;
			root->right=NULL;
			root=ptr;
			return;
		}
	}

	if(rno < root -> data )
	{
		ptr=ptr->left;
	}
	if (rno > root->data )
	{
		ptr=ptr->right;
	}
	while(ptr!=NULL && rno !=ptr->data)
	{

		std::cout<<"in rno not equal to ptr-data\n";
		if (rno <ptr->data)
		{
			save=ptr;
			ptr=ptr->left;
		}
		if(rno > ptr->data)
		{
			save =ptr;
			ptr=ptr->right;
		}
	}
	if(ptr==NULL)
	{
		std::cout<<"element not found \n";
		return;
	}


	if(rno == ptr->data)
	{
		if (ptr->left == NULL && ptr->right == NULL)
		{
			std::cout<<"no childs\n";
			if (ptr->data < save ->data )
			{
				p=ptr;
				save->left=NULL;
				delete p;
				return;
			}
			if(ptr->data > save->data )
			{
				p=ptr;
				save->right=NULL;
				delete p;
				return;
			}
		}
		if(ptr->left == NULL || ptr->right == NULL)
		{
			std::cout<<"one child is present \n";
			if (ptr ->left == NULL)
			{
				if (save->data < ptr->data)
				{
					save->right =ptr->right;
					p=ptr;
					ptr->right=NULL;
					ptr->left=NULL;
					delete p;
					return;
				}
				if(save ->data > ptr->data)
				{
					save->left =ptr->right;
					p=ptr;
					ptr->left=NULL;
					ptr->right=NULL;
					delete p;
					return;
				}
			}
			if(ptr->right == NULL)
			{


				if (save->data < ptr->data )
				{
						save->right =ptr->left;
						p=ptr;
						ptr->left=NULL;
						ptr->right=NULL;
						delete p;
						return;
				}
				if(save ->data > ptr->data )
				{
						save->left =ptr->left;
						p=ptr;
						ptr->left=NULL;
						ptr->right=NULL;
						delete p;
						return;
				}
			}
		}
		if(ptr->left != NULL && ptr->right !=NULL)
			{
				std::cout<<"in two child nodes \n";
				node *t1,*s1,*t2;
				int k=0;
				t1=ptr->right;
				while(t1->left  != NULL)
				{
					std::cout<<"in while loop\n";
					s1=t1;
					t1=t1->left;
					k=k+1;
				}
				if(k==0)
				{

					if(t1->right == NULL)
					{
						std::cout<<"i am in t1->right = null in k=1 \n";
						ptr->data =t1->data ;
						ptr->right = NULL;
						delete t1;
						return;
					}
					if(t1->right != NULL)
		

					{
						std::cout<<"i am in t1->right != NULL in k=1 \n";
						ptr->data=t1->data;
						ptr->right=t1->right;
						t1->right=NULL;
						delete t1;
						return;
					}
				}
				if(k>0)
				{
					if(t1->right == NULL)
					{

						std::cout<<" i am in t1 right == null in k>1 \n";
						ptr->data=t1->data;
						//ptr->right=ptr->right;
						s1->left=NULL;
						t1->right=NULL;
						t1->left=NULL;
						delete t1;
						return;
					}
					if(t1->right != NULL)
					{
//t2=ptr->right;       
						std::cout<<"value is :"<<(ptr->right)->data;
						ptr->data=t1->data;
                        std::cout<<"value is:"<<(ptr->right)->data;
						s1->left=t1->right;
//						ptr->right=t2;
						t1->right=NULL;
						delete t1;
						return;
					}
				}
			}
	}
}
void menu()
{
	std::cout<<"\n 1:insert  2:delete  3:preorder   4:inorder  5:postorder  6:exit";
	std::cout<<"\n enter your choice";
	std::cin>>ch;
}
int main()
{
	bstree bs;
	menu();
	while(ch<6)
	{
		switch(ch)
		{
			case 1: bs.insert(bs.r());
					break;
			case 2:bs.del(bs.r());
				   break;
			case 3:bs.preord(bs.r());
				   break;
			case 4:bs.inord(bs.r());
				   break;
			case 5:bs.postord(bs.r());
				   break;
		}
		menu();
	}
}


