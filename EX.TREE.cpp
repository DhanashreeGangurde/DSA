#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;

class node
{
	public:
		char data;
		node *right;
		node *left;
		node(char v)
		{
			data = v;
			left = NULL;
			right = NULL;
		}
};

class Tree
{
	public:
		node * root;
		void inorder_rec(node *temp);
		void preorder_rec(node * temp);
		void postorder_rec(node *temp);
		void inorder_nonrec(node *current);
		void preorder_nonrec(node *current);
		void postorder_nonrec(node *current);
};

void Tree::inorder_rec(node *temp)
{
	if(temp!=NULL)
	{
		inorder_rec(temp->left);
		cout<<temp->data;
		inorder_rec(temp->right);
		cout<<" ";
	}
}

void Tree::preorder_rec(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		preorder_rec(temp->left);
		preorder_rec(temp->right);
		cout<<" ";
	}
}

void Tree::postorder_rec(node *temp)
{
	if(temp!=NULL)
	{
		postorder_rec(temp->left);
		postorder_rec(temp->right);
		cout<<temp->data;
		cout<<" ";
	}
}

void Tree::inorder_nonrec(node *root)
{
	stack<node*>traversal;
	node *current = root;
	while(current!=NULL || traversal.empty()==false)
	{
		while(current!=NULL)
		{
			traversal.push(current);
			current = current->left;
		}
		current = traversal.top();
		traversal.pop();
		cout<<current->data;
		current = current->right;
	}
}
void Tree::preorder_nonrec(node *root)
{
	stack<node*>traversal;
	node *current = root;
	while(current!=NULL || traversal.empty()==false)
	{
		while(current!=NULL)
		{
			cout<<current->data;
			traversal.push(current);
			current = current->left;
		}
		current = traversal.top();
		traversal.pop();
		current = current->right;
	}
}

void Tree::postorder_nonrec(node *root)
{
	stack<node*>traversal;
	node *current = root;
	while(current!=NULL || traversal.empty()==false)
	{
		while(current!=NULL)
		{
			traversal.push(current);
			current = current->left;
		}
		node *temp;
		temp = (traversal.top())->right;
		if(temp==NULL)
		{
			traversal.pop();
			cout<<temp->data;
			while(traversal.empty()==false && temp==(traversal.top())->right)
			{
				temp = traversal.top();
				traversal.pop();
				cout<<temp->data;
			}
		}
		else
		{
			current = temp;
		}
	}
}

int main()
{
	string postfix;
	stack<node*>t;
	Tree tr;
	node *l,*r,*root;
	cout<<"\nenter postfix expression : ";
	cin>>postfix;
	for(int i=0;i<postfix.length();i++)
	{
		if(postfix[i]=='+'||postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
		{
			root = new node(postfix[i]);
			r = t.top();t.pop();
			l = t.top();t.pop();
			root->right=r;
			root->left=l;
		}
		else
		{
			root = new node(postfix[i]);
			t.push(root);
		}
	}
	while(true)
	{
		cout<<"\nexpression tree :"<<endl;
		cout<<"1.inorder recursive "<<endl;
		cout<<"2.preorder recursive "<<endl;
		cout<<"3.postorder recursive "<<endl;
		cout<<"4.inorder non recursive "<<endl;
		cout<<"5.preorder non recursive "<<endl;
		cout<<"6postorder non recursive "<<endl;
		cout<<"enter your choice :";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\ninorder recursive : ";
				tr.inorder_rec(root);
				break;
			case 2:
				cout<<"\npreorder recursive : ";
				tr.preorder_rec(root);
				break;
			case 3:
				cout<<"\npostorder recursive : ";
				tr.postorder_rec(root);
				break;
			case 4:
				cout<<"\ninorder non recursive : ";
				tr.inorder_nonrec(root);
				break;
			case 5:
				cout<<"\npreorder non recursive : ";
				tr.preorder_nonrec(root);
				break;
			case 6:
				cout<<"\npostorder non recursive : ";
				tr.postorder_nonrec(root);
				break;
			default:
				cout<<"\ninvalid input !!!";
				break;
		}
		int ans;
		cout<<"\nif you want to operate again enter 1,otherwise 0 "<<endl;
		cin>>ans;
		if(ans==1)
		{
			continue;
		}
		else
		{
			break;
		}	
	}
	return 0;
}