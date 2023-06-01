#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
		bool lthread;
		bool rthread;
		
		node(int data)
		{
			this->data = data;
			left=NULL;
			right=NULL;
			lthread=true;
			rthread=true;
		}
};

class TBT
{
	public:
		node *root;
		TBT()
		{
			root = NULL;
		}
		node *insert(node *root,int val)
		{
			node *curr=root;
			node *parent = NULL;
			while(curr!=NULL)
			{
				if(curr->data==val)
				{
					return root;
				}
				parent = curr;
				if(val<curr->data)
				{
					if(curr->lthread==false)
					{
						curr=curr->left;
					}
					else 
					{
						break;
					}
				}
				else if(val>curr->data)
				{
					if(curr->rthread==false)
					{
						curr=curr->right;
					}
					else
					{
						break;
					}
				}		
			}
			node *newnode=new node(val);
			if(parent==NULL)
			{
				root = newnode;
				root->left=NULL;
				root->right=NULL;
				return root;
			}
			else if(val>parent->data)
			{
				newnode->right=parent->right;
				newnode->left=parent;
				parent->rthread=false;
				parent->right=newnode;
			}
			else if(val<parent->data)
			{
				newnode->left=parent->left;
				newnode->right=parent;
				parent->lthread=false;
				parent->left=newnode;
			}
			return root;
		}
		node *inordersuccessor(node *temp)
		{
			if(temp->rthread==true)
			{
				return temp->right;
			}
			temp=temp->right;
			while(temp->lthread==false)
			{
				temp=temp->left;
			}
			return temp;
		}
		void inorder(node *root)
		{
			if(root==NULL)
			{
				cout<<"\nempty tree ";	
			}	
			else
			{
				node *temp=root;
				while(temp->lthread==false)
				{
					temp = temp->left;
				}
				while(temp!=NULL)
				{
					cout<<temp->data<<" ";
					temp = inordersuccessor(temp);
				}
			}
		}
		node *inorderpredessor(node *temp)
		{
			if(temp->lthread==true)
			{		
				return temp->left;
			}
			temp = temp->left;
			while(temp->rthread==false)
			{
				temp = temp->right;
			}
			return temp;
		}
		void preorder(node *root)
		{
			if(root==NULL)
			{
				cout<<"\nempty tree ";
			}
			cout<<root->data<<" ";
			if(root->lthread==false)
			{
				preorder(root->left);
			}
			if(root->rthread==false)
			{
				preorder(root->right);
			}
		}
		void preorder_nonrec(node *root)
		{
			if(root==NULL)
			{
				cout<<"\nempty tree ";
			}
			while(root!=NULL)
			{
				cout<<root->data<<" ";
				if(root->lthread==false)
				{
					root = root->left;
				}
				else if(root->rthread==false)
				{
					root = root->right;
				}
				else
				{
					while(root!=NULL&&root->rthread==true)
					{
						root = inordersuccessor(root);
					}
					if(root!=NULL)
					{
						root = root->right;
					}
				}
			}
		}
		void postorder(node *root)
		{
			if(root==NULL)
			{
				cout<<"\nempty tree ";
			}
			if(root->lthread==false)
			{
				preorder(root->left);
			}
			if(root->rthread==false)
			{
				preorder(root->right);
			}
			cout<<root->data<<" ";
		}
};

/*node TBT::*insert(node *root,int val)
{
	node *curr=root;
	node *parent = NULL;
	while(curr!=NULL)
	{
		if(curr->data==val)
		{
			return root;
		}
		parent = curr;
		if(val<curr->data)
		{
			if(curr->lthread==false)
			{
				curr=curr->left;
			}
			else 
			{
				break;
			}
		}
		else if(val>cutt->data)
		{
			if(curr->rthread==false)
			{
				curr=curr->right;
			}
			else
			{
				break;
			}
		}
	}
	node *newnode=new node(val);
	if(parent==NULL)
	{
		root = newnode;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(val>parent->data)
	{
		newnode->right=parent->right;
		newnode->left=parent;
		parent->rthread=false;
		parent->right=newnode;
	}
	else if(val<parent->data)
	{
		newnode->left=parent->left;
		newnode->right=parent;
		parent->lthread=false;
		parent->left=newnode;
	}
	return root;
}

node TBT :: *inordersuccessor(node *temp)
{
	if(temp->rthread==true)
	{
		return temp->right;
	}
	temp=temp->right;
	while(temp->lthread==false)
	{
		temp=temp->left;
	}
	return temp;
}

void TBT::inorder(node *root)
{
	if(root==NULL)
	{
		cout<<"\nempty tree ";	
	}	
	else
	{
		node *temp=root;
		while(temp->lthread==false)
		{
			temp = temp->left;
		}
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = inordersuccessor(temp);
		}
	}
} 

node TBT:: *inorderpredessor(node *temp)
{
	if(temp->lthread==true)
	{
		return temp->left;
	}
	temp = temp->left;
	while(temp->rthread==false)
	{
		temp = temp->right;
	}
	return temp;
}

void TBT::preorder(node *root)
{
	if(root==NULL)
	{
		cout<<"\nempty tree ";
	}
	cout<<root->data<<" ";
	if(root->lthread==false)
	{
		preorder(root->left);
	}
	if(root->rthread==false)
	{
		preorder(root->right);
	}
} 

void TBT::preorder_nonrec(node *root)
{
	if(root==NULL)
	{
		cout<<"\nempty tree ";
	}
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		if(root->lthread==false)
		{
			root = root->left;
		}
		else if(root->rthread==false)
		{
			root = root->right;
		}
		else
		{
			while(root!=NULL&&root->rthread==true)
			{
				root = inordersuccessor(root);
			}
			if(root!=NULL)
			{
				root = root->right;
			}
		}
	}
}

void TBT::postorder(node *root)
{
	if(root==NULL)
	{
		cout<<"\nempty tree ";
	}
	if(root->lthread==false)
	{
		preorder(root->left);
	}
	if(root->rthread==false)
	{
		preorder(root->right);
	}
	cout<<root->data<<" ";
}
*/

int main()
{
	TBT obj;
	int choice,n,val;
	do
	{
		cout<<"\n--------MENU---------";
		cout<<"\n1.insert element in tree";
		cout<<"\n2.display inorder";
		cout<<"\n3.display preorder";
		cout<<"\n4.display postorder";
		cout<<"\n5.display inorder with recurrsion";
		cout<<"\n6.exit";
		cout<<"\nenter the choice";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				obj.root=(obj.insert(obj.root,10));
				cout<<"\nroot of threaded binary tree:10";
				cout<<"\nenter the number of element you want ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"\nenter value ";
					cin>>val;
					obj.insert(obj.root,val);
				}
				break;
			case 2:
				cout<<"\nthreaded binary tree using inorder : ";
				obj.inorder(obj.root);
				break;
			case 3:
				cout<<"\nthreaded binary tree using preorder : ";
				obj.preorder(obj.root);
				break;
			case 4:
				cout<<"\nthreaded binary tree using postorder : ";
				obj.postorder(obj.root);
				break;
			case 5:
				cout<<"\nthreaded binary tree using preorder with recurssion : ";
				obj.preorder_nonrec(obj.root);
				break;
			default:
				break;
		}
	}while(choice<6);
	return 0;
}
