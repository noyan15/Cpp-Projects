#include<iostream>
#include<string.h>
using namespace std;

// Functions decleration

// 3 functions which will use in 3 variables K-map
void returnExpression3(int a, int b, string* expression);
void displayBit3(int size,int *minterms,int condition,int *counter,int i,int j,string* arr);

// Functions which will use in 4 variables K-map
void returnExpression(int a, int b, string* expression);
void displayBit(int size,int* minterms,int condition,int *counter,int i,int j,string* arr);

// Functions which will use in 5 variables K-map
void returnExpression5(int a, int b, string* expression);
void displayBit5(int size,int* minterms,int condition,int *counter,int i,int j,string* arr);

// Functions which will use in each case
void printExpression(string* expression, int expr);
void once(int *counter, int size, int condition, int choice, int i, string* arr,int* minterm);


int main()
{
	int continuetyCheck;
	cout<<"Greetings! \nMy Name is Hammad Baseer\n";
	cout<<"My Hobby is to crack the intricative codes\n\n";
	do
	{
		
	
	int choice;
	cout<<"Enter 1 for 3 variables K-map, 2 for 4 variables K-map, 3 for 5 variables K-map: ";
	cin>>choice;
	int size;
	cout<<"Enter the number of minterms you want to enter: ";
	cin>>size;
	int minterms[size];
	int *minterm;
	minterm=minterms;
	for(int i=0;i<size;i++)
	{
		cout<<"Enter the value of "<<i+1<<" minterm: ";
		cin>>minterms[i];
	}
	int expr = 32;
	string expression[expr];
	for(int i=0;i<expr;i++)
	{
		expression[i]="";
	}
	string* arr;
	arr = expression;
	int counter=0,condition;
	if(choice == 1)
	{
		cout<<"\n";
		cout<<" BC  00  01  11  10\nA\n\n";
		counter=0;
		for(int i=0;i<2;i++)
	    {
	    	cout<<i<<"     ";
		    condition=0;
			once(&counter, size, condition, choice, i, arr, minterm);
		    cout<<endl;
    	}
	}
	else if(choice == 2)
	{
		cout<<"\n";
		cout<<"  CD  00  01  11  10\nAB\n\n";
        counter=0;
		for(int i=0;i<4;i++)
	{
		condition=0;
		if(i==0)
		{
			cout<<"00     ";
		}
		else if(i==1)
		{
			cout<<"01     ";
		}
		else if(i==2)
		{
			cout<<"11     ";
		}
		else if(i==3)
		{
			cout<<"10     ";
		}
		
		if(i==3)
		{
			counter-=4;
			once(&counter, size, condition, choice, i, arr, minterm);
			counter+=4;
		}
		else if(i==2)
		{
			counter+=4;
			once(&counter, size, condition, choice, i, arr, minterm);
			counter-=4;
		}
		else
		{
			once(&counter, size, condition, choice, i, arr, minterm);
		}
		cout<<endl;
	}
	}
	else if(choice==3)
	{
        cout<<"\n";
		cout<<"  CDE  000  001  011  010  100  101  111  110\nAB\n\n";
        counter=0;
		for(int i=0;i<4;i++)
	{
		condition=0;
		if(i==0)
		{
			cout<<"00      ";
		}
		else if(i==1)
		{
			cout<<"01      ";
		}
		else if(i==2)
		{
			cout<<"11      ";
		}
		else if(i==3)
		{
			cout<<"10      ";
		}
		
		if(i==3)
		{
			counter-=8;
			once(&counter, size, condition, choice, i, arr, minterm);
			counter+=8;
		}
		else if(i==2)
		{
			counter+=8;
			once(&counter, size, condition, choice, i, arr, minterm);
			counter-=8;
		}
		else
		{
			once(&counter, size, condition, choice, i, arr, minterm);
		}
		cout<<endl;
	}
	}
	cout<<"\nExpression\n";
	printExpression(arr, expr);
	cout<<"\n\n";
	cout<<"If you want to run the program again enter 1 other wise enter 0: ";
	cin>>continuetyCheck;
} while(continuetyCheck == 1);
    cout<<"Thank You!";
	return 0;
}
void returnExpression3(int a, int b, string* expression)
{
	string values[2][4] = {"A'B'C'","A'B'C","A'BC","A'BC'","AB'C'","AB'C","ABC","ABC'"};
	for(int i=0;i<8;i++)
	{
		if(*(expression+i)=="")
		{
			*(expression+i) = values[a][b];
			break;
		}
	}
}
void displayBit3(int size,int *minterms,int condition,int *counter,int i,int j,string* arr)
{
	for(int k=0;k<size;k++)
				{
					if(*(minterms+k)==*counter)
					{
						if(i==0 && j==0 && *(minterms+k)!=*counter)
						{
							break;
						}
						cout<<1;
						condition=1;
						returnExpression3(i, j, arr);
					}
				}
				if(condition==0)
				{
					cout<<0;
				}
				*counter+=1;
}
void returnExpression(int a, int b, string* expression)
{
	string values[4][4] = {"A'B'C'D'","A'B'C'D","A'B'CD","A'B'CD'","A'BC'D'","A'BC'D","A'BCD","A'BCD'",
	"ABC'D'","ABC'D","ABCD","ABCD'","AB'C'D'","AB'C'D","AB'CD","AB'CD'"};
	for(int i=0;i<16;i++)
	{
		if(*(expression+i)=="")
		{
			*(expression+i) = values[a][b];
			break;
		}
	}
}
void displayBit(int size,int* minterms,int condition,int *counter,int i,int j,string* arr)
{
	for(int k=0;k<size;k++)
				{
					if(*(minterms+k)==*counter)
					{
						cout<<1;
						condition=1;
						returnExpression(i, j, arr);
					}
				}
				if(condition==0)
				{
					cout<<0;
				}
				*counter+=1;
}
void returnExpression5(int a, int b, string* expression)
{
	string values[4][8] = {"A'B'C'D'E'","A'B'C'D'E","A'B'C'DE","A'B'C'DE'","A'B'CD'E'","A'B'CD'E",
	"A'B'CDE","A'B'CDE'","A'BC'D'E'","A'BC'D'E","A'BC'DE","A'BC'DE'","A'BCD'E'","A'BCD'E","A'BCDE",
	"A'BCDE'","ABC'D'E","ABC'D'E","ABC'DE","ABC'DE'","ABCD'E'","ABCD'E","ABCDE","ABCDE'","AB'C'D'E'",
	"AB'C'D'E","AB'C'DE","AB'C'DE'","AB'CD'E'","AB'CD'E","AB'CDE","AB'CDE'"};
	for(int i=0;i<8;i++)
	{
		if(*(expression+i)=="")
		{
			*(expression+i) = values[a][b];
			break;
		}
	}
}
void displayBit5(int size,int* minterms,int condition,int *counter,int i,int j,string* arr)
{
	for(int k=0;k<size;k++)
				{
					if(*(minterms+k)==*counter)
					{
						cout<<1;
						condition=1;
						returnExpression5(i, j, arr);
					}
				}
				if(condition==0)
				{
					cout<<0;
				}
				*counter+=1;
}
void printExpression(string* expression, int expr)
{
	for(int i;i<expr;i++)
	{
		if(*(expression+i)!="" && i==0){
			cout<<*(expression+i);
		}
		else if(*(expression+i)!="" && i!=0){
			cout<<" + "<<*(expression+i);
		}
	}
}
void once(int *counter, int size, int condition, int choice, int i, string* arr,int* minterm)
{
	int loop;
	if(choice == 3)
	{
		loop = 8;
	}
	else{
		loop = 4;
	}
	for(int j=0;j<loop;j++)
		{
			if(j==2 || j==6)
			{
				*counter+=1;
				if(choice == 1)
				{
					displayBit3(size,minterm,condition,counter,i,j,arr);
				}
				else if(choice == 2)
				{
					displayBit(size,minterm,condition,counter,i,j,arr);
				}
				else if(choice == 3)
				{
					displayBit5(size,minterm,condition,counter,i,j,arr);
				}
				*counter-=1;
			}
			else if(j==3 || j==7)
			{
				*counter-=1;
				if(choice == 1)
				{
					displayBit3(size,minterm,condition,counter,i,j,arr);
				}
				else if(choice == 2)
				{
					displayBit(size,minterm,condition,counter,i,j,arr);
				}
				else if(choice == 3)
				{
					displayBit5(size,minterm,condition,counter,i,j,arr);
				}
				*counter+=1;
			}
			else
			{
				if(choice == 1)
				{
					displayBit3(size,minterm,condition,counter,i,j,arr);
				}
				else if(choice == 2)
				{
					displayBit(size,minterm,condition,counter,i,j,arr);
				}
				else if(choice == 3)
				{
					displayBit5(size,minterm,condition,counter,i,j,arr);
				}
			}
			cout<<"   ";
			if(choice == 3)
			{
				cout<<" ";
			}
		}
}
