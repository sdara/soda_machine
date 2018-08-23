#include<iostream.h>
#include<ctype.h>
#include<iomanip.h>

//constant and global variable
const Elements=5;
int WentThruOnce=0;
float TotalSales=0;

//stucture for program
struct SodaMachine
{
	char DrinkName[50];
	float DrinkCost;
	int NumberInMachine;
};

//initialize the array of stuctures with elements and values
	SodaMachine TheMachine[Elements] = {
	{"Cola",.75,20},
	{"Root Beer",.75,20},
	{"Lemon-Lime",.75,20},
	{"Grape Soda",.80,20},
	{"Cream Soda",.80,20}
	};

//function prototypes
void ShowMenu(void);

void main(void)
{
cout << setiosflags(ios::fixed | ios::right | ios::showpoint) << setprecision(2);
ShowMenu();
	
	
}


/*
this showmenu function shows the menu and asks the user
which item they want and then calculates their change after they have entered
an amount
*/
void ShowMenu(void)
{
	char DnkNum;
	int DrinkNNum;
	
	do
	{
	cout<<"Would you like to purchase a drink (Y for yes, N for no):"<<endl;
	for(int i=0;i<Elements;i++){
	cout<< i+1<<": "<< TheMachine[i].DrinkName<<endl;
	}

	cin>>DnkNum;
	if(toupper(DnkNum) != 'Y' && toupper(DnkNum) != 'N')
	cout<<endl<<" *** Please enter 'Y' or 'N' ***"<<endl<<endl;
	}while(toupper(DnkNum) != 'Y' && toupper(DnkNum) != 'N');

	if(toupper(DnkNum) == 'Y'){
	
	do{

	cout<<endl<<"Which drink would you like (1 through "<<Elements<<"):"<<endl;
	cin>>DrinkNNum;
	if(DrinkNNum<1 || DrinkNNum> Elements)
	cout<<endl<<"*** Please enter a number from 1 to "<<Elements<<" ***"<<endl;
	}while(DrinkNNum<1 || DrinkNNum>Elements);

	if((TheMachine[DrinkNNum-1].NumberInMachine-1)>=0)
	{
	float GiveCash;
	cout << endl<<TheMachine[DrinkNNum-1].DrinkName << " costs " << TheMachine[DrinkNNum-1].DrinkCost *100<<" cents..."<<endl;
	do{
	cout<<"Please enter your cash (up to $1):"<<endl;
	cin>>GiveCash;
	if(GiveCash<TheMachine[DrinkNNum-1].DrinkCost || GiveCash>1)
	cout<<endl<<"*** Please enter a value greater or equal to the Drinks Cost, and less than 1 ***"<<endl<<endl;
	}while(GiveCash<TheMachine[DrinkNNum-1].DrinkCost || GiveCash>1);
	cout<<"\nYour change is: " << (GiveCash-(TheMachine[DrinkNNum-1].DrinkCost))<<endl;
	TotalSales+=TheMachine[DrinkNNum-1].DrinkCost;
	
	TheMachine[DrinkNNum-1].NumberInMachine--;
	cout<<"Number of "<<TheMachine[DrinkNNum-1].DrinkName<<" drinks left: "<<TheMachine[DrinkNNum-1].NumberInMachine<<endl<<endl;
	}else{
	cout<<TheMachine[DrinkNNum-1].DrinkName<<" drinks are sold out!"<<endl<<endl;
	}
	//repeat the function
	ShowMenu();
	}else{
		cout<<"\nThis machine made $"<<TotalSales<<" today!\n\n";
	cout<<"\nThank you for using our program!\n\n";
	}
}