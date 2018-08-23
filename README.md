11-09-2004
CSC153-02
Project #07

Psuedocode



Include header files, function prototypes, and global variables for use within the program.

Create the showmenu() function to do all of the work, and call it from the main program.

Display a menu of choices (1 thru 5). Ask the user if they would like to purchase. If yes, get the selection and prompt the user how much it is and ask them for payment. Tell them their change and that the inventory went down 1.

At the end, when the user decides to stop purchasing, show how much money the machine made.



Source Code

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

Program Output

 Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
y
 
Which drink would you like (1 through 5):
1
 
Cola costs 75.00 cents...
Please enter your cash (up to $1):
1
 
Your change is: 0.25
Number of Cola drinks left: 19
 
Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
y
 
Which drink would you like (1 through 5):
2
 
Root Beer costs 75.00 cents...
Please enter your cash (up to $1):
.75
 
Your change is: 0.00
Number of Root Beer drinks left: 19
 
Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
y
 
Which drink would you like (1 through 5):
3
 
Lemon-Lime costs 75.00 cents...
Please enter your cash (up to $1):
1
 
Your change is: 0.25
Number of Lemon-Lime drinks left: 19
 
Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
y
 
Which drink would you like (1 through 5):
3
 
Lemon-Lime costs 75.00 cents...
Please enter your cash (up to $1):
.80
 
Your change is: 0.05
Number of Lemon-Lime drinks left: 18
 
Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
y
 
Which drink would you like (1 through 5):
4
 
Grape Soda costs 80.00 cents...
Please enter your cash (up to $1):
10
 
*** Please enter a value greater or equal to the Drinks Cost, and less than 1 **
*
 
Please enter your cash (up to $1):
1
 
Your change is: 0.20
Number of Grape Soda drinks left: 19
 
Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
y
 
Which drink would you like (1 through 5):
1
 
Cola costs 75.00 cents...
Please enter your cash (up to $1):
.65
 
*** Please enter a value greater or equal to the Drinks Cost, and less than 1 **
*
 
Please enter your cash (up to $1):
.75
 
Your change is: 0.00
Number of Cola drinks left: 18
 
Would you like to purchase a drink (Y for yes, N for no):
1: Cola
2: Root Beer
3: Lemon-Lime
4: Grape Soda
5: Cream Soda
n
 
This machine made $4.55 today!
 
 
Thank you for using our program!
 
Press any key to continue



