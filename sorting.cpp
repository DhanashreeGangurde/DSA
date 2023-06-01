#include<iostream>
#include<cstring>
using namespace std;

struct Student
{
	string name;
	int roll_no;
	float sgpa;
};

class Stud
{
	private:
		struct Student S[30];
		int n=0;
	public:
		int num();
		void insert();
		void display(int ch);
		void Lsearch(float key);
		void Bsearch(string key);
		void Bsort();
		void Isort();
		void Qsort(int low,int high);
		int part(int low,int high);
};

int Stud :: num()
{
	return n;
}

void Stud :: insert()
{
	int num;
	if(n>30)
	{
		cout<<"\nrecords are full";
	}
	else
	{
		cout<<"\n----------------------------------";
		cout<<"\nenter number of student to be added : ";
		cin>>num;
		if(num>0)
		{
			for(int i=n;i<n+num;i++)
			{
				cout<<"\n enter name "<<i+1 <<" : ";
				cin.ignore(1);
				getline(cin,S[i].name);
				cout<<"\nenter roll no : ";
				cin>>S[i].roll_no;
				if(S[i].roll_no<0)
				{
					cout<<"\npleade enter positive roll no!!!";
					return ;
				}
				for(int j=0;j<n;j++)
				{
					if(S[i].roll_no==S[j].roll_no)
					{
						cout<<"\nroll number are alerady exists!!!";
						return;
					}
				}
				cout<<"\nenter your SGPA : ";
				cin>>S[i].sgpa;
			}
			n = n+num;
		}
		else
		{
			cout<<"\nplease enter a positive number ";
			return;
		}
	}
}

void Stud::display(int ch)
{
	cout<<"\nthe value you entered are :- ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n name :- "<<S[i].name;
		cout<<"\nroll number :- "<<S[i].roll_no;
		cout<<"\nsgpa :- "<<S[i].sgpa;
	}
}

void Stud::Lsearch(float key)
{
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(S[i].sgpa==key)
		{
			flag=1;
			cout<<"\nstudent found ";
			cout<<"student "<<i+1<<"\n";
			cout<<"name : "<<S[i].name<<"\n";
			cout<<"roll number : "<<S[i].roll_no<<"\n";
			cout<<"SGPA : "<<S[i].sgpa<<"\n";
		}
	}
	if(!flag)
	{
		cout<<"student not found ";
	}
}

void Stud::Bsearch(string key)
{
	if(n==0)
	{
		cout<<"no data available ";
	}
	int left = 0;
	int right = n-1;
	int middle =0;
	int flag =0;
	while(left<=right)
	{
		middle = (left+right)/2;
		if(S[middle].name==key)
		{
			flag = 1;
			cout<<"\nstudent found ";
			cout<<"\nstudent "<<middle+1<<"\n";
			cout<<"\n name "<<S[middle].name<<"\n";
			cout<<"\n roll number "<<S[middle].roll_no<<"\n";
			cout<<"\n sgpa "<<S[middle].sgpa<<"\n";
		}
		if(S[middle].name>=S[left].name)
		{
			if(S[left].name<=key&&key<S[middle].name)
			{
				right = middle-1;
			}
			else
			{
				left = middle + 1;
			}
		}
		else
		{
			if(S[middle].name<key&&key<=S[right].name)
			{
				left = middle + 1;
			}
			else
			{
				right = middle - 1;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\nstudent not found ";
	}
}

void Stud :: Bsort()
{
	int last = n-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;i<last;j++)
		{
			if(S[j].roll_no>S[j+1].roll_no)
			{
				int temp = S[j].roll_no;
				S[j].roll_no = S[j+1].roll_no;
				S[j+1].roll_no = temp;
				
				float temp1 = S[i].sgpa;
				S[j].sgpa = S[j+1].sgpa;
				S[j+1].sgpa = temp1;
				
				string temp2 = S[i].name;
				S[j].name = S[j+1].name;
				S[j+1].name = temp2;
			}
		}
		last = last -1;
	}
	display(0);
}

void Stud :: Isort()
{
	for(int i=0;i<n;i++)
	{
		string key = S[i].name;
		int temp1 = S[i].roll_no;
		float temp2 = S[i].sgpa;
		int j = i-1;
		while(j>=0 && key<S[i].name)
		{
			S[j+1].name = S[j].name;
			S[j+1].roll_no = S[j].roll_no;
			S[j+1].sgpa = S[j].sgpa;
			j = j - 1;
		}
		S[j+1].name = key;
		S[j+1].roll_no = temp1;
		S[j+1].sgpa = temp2;
	}
}

void Stud :: Qsort(int low,int high)
{
	if(low<high)
	{
		int pi = part(low,high);
		Qsort(low,pi-1);
		Qsort(pi + 1,high);
	}
}

int Stud :: part(int low,int high)
{
	float pivot = S[high].sgpa;
	int i = (low - 1);
	for(int j = low;j<high;j++)
	{
		if(S[j].sgpa <= pivot)
		{
			i++;
			
			float temp = S[i].sgpa;
			S[i].sgpa = S[i].sgpa;
			S[j].sgpa = temp;
			
			int temp1 = S[i].roll_no;
			S[i].roll_no = S[j].roll_no;
			S[j].roll_no = temp1;
			
			string temp2 = S[i].name;
			S[i].name = S[j].name;
			S[j].name = temp2;
		}
	}
	float temp = S[i+1].sgpa;
	S[i+1].sgpa = S[high].sgpa;
	S[high].sgpa = temp;
	
	int temp1 = S[i+1].roll_no;
	S[i+1].roll_no = S[high].roll_no;
	S[high].roll_no = temp1;
	
	string temp2 = S[i+1].name;
	S[i+1].name = S[high].name;
	S[high].name = temp2;
	return i+1;
}
int main()
{
	Stud S1;
	string name;
	int op,rno;
	float sgpa;
	S1.insert();
	
	int ch=1;
	while(ch)
	{
		cout<<"\n--------------------------";
		cout<<"\nenter the operation ";
		cout<<"\n1.insert data ";
		cout<<"\n2.display data ";
		cout<<"\n3.search record by sgpa ";
		cout<<"\n4.search record by name ";
		cout<<"\n5.sort data by roll no ";
		cout<<"\n6.sort data by name ";
		cout<<"\n7.display first 10 toppers";
		cout<<"\n8.exit";
		cout<<"\nenter the choice ";
		cin>>op;
		switch(op)
		{
			case 1:
				S1.insert();
				break;
			case 2:
				S1.display(0);
				break;
			case 3:
				cout<<"\nenter th sgpa : ";
				cin>>sgpa;
				S1.Lsearch(sgpa);
				break;
			case 4:
				S1.Isort();
				cout<<"\nenter the name : ";
				cin.ignore(1,'\n');
				getline(cin,name);
				S1.Bsearch(name);
				break;
			case 5:
				S1.Bsort();
				break;
			case 6:
				S1.Isort();
				S1.display(0);
				break;
			case 7:
				cout<<"\nprinting details of 10 toppers : ";
				S1.Qsort(0,S1.num());
				S1.display(1);
				break;
			case 8:
				ch=0;
		}		break;
	}
	return 0;
}