#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;

class Stack
{
	struct Stk
	{
		float Operator;
		Stk *Next;
		Stk()
		{
			Next = NULL;
		}
	};
	Stk *Top;
	public:
		Stack()
		{
			Top = NULL;
		}
		int Empty();
		void Push(float Opr);
		float Pop();
};

int Stack::Empty()
{
	if(Top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Stack::Push(float Opr)
{
	Stk *Node;
	Node = new Stk;
	Node->Operator=Opr;
	Node->Next=Top;
	Top = Node;
}

float Stack::Pop()
{
	Stk *Temp = Top;
	float Opr;
	Top=Top->Next;
	Opr = Temp->Operator;
	delete Temp;
	return Opr;
}

int Priority(char Op)
{
	if(Op=='^')
	{
		return 2;
	}
	if(Op=='+'||Op=='-')
	{
		return 0;
	}
	else 
	{
		return 0;
	}
}

float Operation(char Op,float A,float B)
{
	int I=0;
	float P = 1;
	if(Op=='*')
	{
		P = A*B;
	}
	else if(Op=='/')
	{
		P = A/B;
	}
	else if(Op=='+')
	{
		P = A+B;
	}
	else if(Op=='-')
	{
		P = A-B;
	}
	else
	{
		while(I++<B)
		{
			P = P*A;
		}
	}
	return P;
}

void infixTOpostfix(char str[20])
{
	char Opr,post[20];
	int i,j=0;
	Stack S;
	for(i=0;str[i]!='\0';i++)
	{
		if(isalnum(str[i]))
		{
			post[j++] = str[i];
		}
		else
		{
			if(str[i]==')')
			{
				Opr=S.Pop();
				while(Opr!='(')
				{
					post[j++]=Opr;
					Opr=S.Pop();
				}		
			}
			else
			{
				if(str[i]=='(');
				
				else while(!S.Empty())
				{
					Opr = S.Pop();
					if(Opr!='('&& Priority(Opr)>=Priority(str[i]))
					{
						post[j++]=Opr;
					}
					else
					{
						S.Push(Opr);
						break;
					}
				}
				S.Push(str[i]);
			}
		}		
	}
	while(!S.Empty())
	{
		post[j++]=S.Pop();
		post[j]='\0';
		cout<<post;
	}
}

void infixTOprefix(char str[20])
{
	char Opr,pre[20];
	int i,j=0;
	Stack S;
	for(i=strlen(str)-1;i>=0;i--)
	{
		if(isalnum(str[i]))
		{
			pre[j++]=str[i];
		}
		else
		{
			if(str[i]==')')
			{
				
			}
			else while(!S.Empty())
			{
				Opr = S.Pop();
				if(Opr!=')'&&Priority(Opr)>Priority(str[i]))
				{
					pre[j++]=Opr;
				}
				else
				{
					S.Push(Opr);
					break;
				}
			}
			S.Push(str[i]);
		}
	}
	while(!S.Empty())
	pre[j++]=S.Pop();
	pre[j]='\0';
	for(j--;j>=0;j--)
	{
		cout<<pre[j];
	}
}

float Postfix_Evaluation(char string[20])
{
	int l=0;
	float operand1,operand2,result;
	Stack S;
	while(string[l]!='\0')
	{
		if(string[l]>='0'&& string[l]<='9')
		{
			S.Push(string[l]-48);
		}
		else
		{
			operand2 = S.Pop();
			operand1 = S.Pop();
			result = Operation(string[l],operand1,operand2);
			S.Push(result);
		}
		l++;
	}
	return S.Pop();
}

float Prefix_Evaluation(char string[20])
{
	int l = strlen(string)-1;
	float operand1,operand2,result;
	Stack S;
	while(l>=0)
	{
		if(string[l]>='0' && string[l]<='9')
		{
			S.Push(string[l]-48);
		}
		else
		{
			operand1 = S.Pop();
			operand2 = S.Pop();
			result = Operation(string[l],operand1,operand2);
			S.Push(result);
		}
		l--;
	}
	return S.Pop();
}

int main()
{
	int choice;
	char Expression[25],answer;
	do
	{
		cout<<"\n1.infix to prefix";
		cout<<"\n2.infix to postfix";
		cout<<"\n3.postfix evaluation";
		cout<<"\n4.prefix evaluation";
		cout<<"\n5.exit";
		cout<<"\nenter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nenter infix expression : ";
				cin>>Expression;
				infixTOprefix(Expression);
				break;
			case 2:
				cout<<"\nenter infix expression : ";
				cin>>Expression;
				infixTOpostfix(Expression);
				break;
			case 3:
				cout<<"\nenter postfix expression : ";
				cin>>Expression;
				cout<<"\nevaluated result : "<<Postfix_Evaluation(Expression);
				break;
			case 4:
				cout<<"\nenter prefix expression : ";
				cin>>Expression;
				cout<<"\nEvaluated result "<<Prefix_Evaluation(Expression);
				break;
			case 5:
				cout<<"exit";
				break;
		}
		cout<<"\ncontinue(y/n)...";
		cin>>answer;
	}
	while(answer=='y'||answer=='Y');
	return 0;
}
























































