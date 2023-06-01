#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

class Node
{
	public:
		int data;
		Node *left,*right;
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
};

class BST
{
	Node *root;
	public:
		BST()
		{
			root = NULL;
		}
		Node *getroot()
		{
			return root;
		}
		void inorder_rec(Node *root);
		void preorder_rec(Node *root);
		void postorder_rec(Node *root);
		Node *insert_BST(Node *root,int val);
		Node *delete_BST(Node *root,int key);
		Node *search_BST(Node *root,int key);
		int depth_BST(Node *root);
		Node *inorder_succ(Node *root);
		void display_leaf(Node *root);
		void levelwise(Node *root,int level);
		void mirror_image(Node *root);
		void display_levelwise(Node *root);
		Node *min_val(Node *root);
		Node *max_val(Node *root);
		void parent_child(Node *root);
};

int BST :: depth_BST(Node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return 1+max(depth_BST(root->left),depth_BST(root->right));
	}
}

void BST :: display_leaf(Node *root)
{
	if(root->left==NULL&&root->right==NULL)
	{
		cout<<root->data<<" ";
	}
	else if(root->left!=NULL)
	{
		display_leaf(root->left);
	}
	else
	{
		display_leaf(root->right);
	}
}

void BST::levelwise(Node *root,int level)
{
	if(root==NULL)
	{
		return;
	}
	else if(level==1)
	{
		cout<<root->data<<" ";
	}
	else
	{
		levelwise(root->left,level-1);
		levelwise(root->right,level-1);
	}
}

void BST::display_levelwise(Node *root)
{
	int h=depth_BST(root);
	for(int i=0;i<=h;i++)
	{
		cout<<"\nlevel "<<i<<" ";
		levelwise(root,i);	
	}
}

Node *BST::min_val(Node *root)
{
	while(root->left!=NULL)
	{
		root = root->left;
	}
	return root;
}

Node *BST::max_val(Node *root)
{
	while(root->right!=NULL)
	{
		root = root->right;
	}
	return root;
}

void BST :: mirror_image(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		mirror_image(root->right);
		cout<<root->data<<" ";
		mirror_image(root->left);
	}
}

void BST::parent_child(Node *root)
{
	if(!root)
	{
		return;
	}
	if(root->left||root->right)
	{
		cout<<"\nparent :"<<root->data;
		if(!root->right)
		{
			cout<<"\nchild "<<root->left->data<<" "<<"right is null";
		}
		else if(!root->left)
		{
			cout<<"\n chile "<<root->right->data<<" "<<"left is null ";
		}
		else
		{
			cout<<"\nchild "<<root->left->data<<" "<<root->right->data<<" ";
		}
		parent_child(root->left);
		parent_child(root->right);
	}
}

Node *BST::inorder_succ(Node *root)
{
	Node *current=root;
	while(current && current !=NULL)
	{
		current = current->left;
	}
	return current;
}

Node *BST::insert_BST(Node *root,int val)
{
	if(root==NULL)
	{
		return new Node(val);
	}
	if(val>root->data)
	{
		root->right=insert_BST(root->right,val);
	}
	else
	{
		root->left=insert_BST(root->left,val);
	}
	return root;
}

Node *BST::search_BST(Node *root,int key)
{
	if(root==NULL||root->data==key)
	{
		return root;
	}
	if(key>root->data)
	{
		return search_BST(root->right,key);
	}
	else
	{
		return search_BST(root->left,key);
	}
}

Node *BST::delete_BST(Node *root,int key)
{
	if(key>root->data)
	{
		root->right=delete_BST(root->right,key);
	}
	else if(key<root->data)
	{
		root->left=delete_BST(root->left,key);
	}
	else
	{
		if(root->left==NULL)
		{
			Node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			Node *temp=root->left;
			free(root);
			return temp;
		}
		Node *temp=inorder_succ(root->right);
		root->data=temp->data;
		root->right=delete_BST(root->right,temp->data);
	}
	return root;
}

void BST :: inorder_rec(Node *root)
{
	if(root)
	{
		inorder_rec(root->left);
		cout<<root->data<<" ";
		inorder_rec(root->right);
	}
}

void BST :: preorder_rec(Node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder_rec(root->left);
		preorder_rec(root->right);
	}
}

void BST :: postorder_rec(Node *root)
{
	if(root)
	{
		postorder_rec(root->left);
		postorder_rec(root->right);
		cout<<root->data<<" ";
	}
}


int main()
{
	BST b;
	Node *root=NULL;
	bool flag = true;
	while(flag)
	{
		cout<<"----------MENU-----------";
		cout<<"\n1.insert Node";
		cout<<"\n2.inorder traversal";
		cout<<"\n3.preorder traversal";
		cout<<"\n4.postorder traversal";
		cout<<"\n5.search Node";
		cout<<"\n6.delete Node";
		cout<<"\n7.display leaf node";
		cout<<"\n8.display tree level wise";
		cout<<"\n9.display height of tree";
		cout<<"\n10.display parent child";
		cout<<"\n11.min value of tree";
		cout<<"\n12.max value of tree";
		cout<<"\n13.display mirror";
		cout<<"\n14.exit";
		cout<<"\nenter your choice : ";
		int choice;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				int val;
				cout<<"\nenter the data of node to be inserted(enter -1 to stop)";
				cin>>val;
				root=b.insert_BST(root,val);
				while(val!=-1)
				{
					b.insert_BST(root,val);
					cin>>val;
				}
				break;
			case 2:
				cout<<"\n inorder traversal : ";
				b.inorder_rec(root);
				cout<<endl;
				break;
			case 3:
				cout<<"\n preorder traversal : ";
				b.preorder_rec(root);
				cout<<endl;
				break;
			case 4:
				cout<<"\n postorder traversal : ";
				b.postorder_rec(root);
				cout<<endl;
				break;
			case 5:
				int val1;
				cout<<"\nenter data of node to be searched : ";
				cin>>val1;
				if(b.search_BST(root,val1))
				{
					cout<<"\n search successfull";
				}
				else
				{
					cout<<"\ndata not fount ";
				}
				break;
			case 6:
				int val2;
				cout<<"\nenter data of node to be deleted : ";
				cin>>val2;
				root=b.delete_BST(root,val2);
				cout<<"\nnode has been deleted successfull ";
				b.inorder_rec(root);
				cout<<endl;
				break;
			case 7:
				cout<<"\n leaf node in tree : ";
				b.display_leaf(root);
				break;
			case 8:
				cout<<"\n level wise tree element : ";
				b.display_levelwise(root);
				break;
			case 9:
				cout<<"\n height of the tree : ";
				b.depth_BST(root);
				break;
			case 10:
				cout<<"\n parent and child node :";
				b.parent_child(root);
				break;
			case 11:
				cout<<"\nminimum value : ";
				b.min_val(root)->data;
				break;
			case 12:
				cout<<"\n max value : ";
			 	b.max_val(root)->data;
			 	break;
			case 13:
				cout<<"\n mirror image : ";
				b.mirror_image(root);
				break;
			case 14:
				flag = false;
				cout<<"-------------thanks-------------";
				break;
			default:
				cout<<"\n invalid input ";
		}
	}
	return 0;
}