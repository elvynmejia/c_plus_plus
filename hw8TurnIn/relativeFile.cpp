3.
/************************************************************\
|  Program:  rFile.cpp                                       |
|  Problem:  A program that stores 10 customers in a relative|
|			 file.The program then prompts the user to enter |
|			 the account number, directly access the selected|
|			 customer, and modifies the balance by adding %5 |
|			 interest. Operate directly on the original file |
|			 without using auxiliary files.				     |
|  Purpose:  Application of relative files and structs       |
|  Author :  Elvyn Mejia                                     |
|  Date   :  12/11/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define SIZE 10

//A customer record contains account number, name and balance. 
struct client 
{
	int account;
	char name[20];
	double balance;

};
//create a relative file that stores 10 customers
void createCustomers(char filename[], int fileZise)
{	cout<<"Make file: Creating a relative file of " <<fileZise<<" customers.\n";

	//Open file for writing 
	ofstream OS(filename, ios::out);
	if(!OS){cerr<<"File open error.\n"; exit(1);}

	//create an empty record 
	client blankRecords = {0, "",0.0};
	while(fileZise)
	{
		OS.write((char*)&blankRecords, sizeof(blankRecords));
		fileZise--;
	}
	cout<<"File was created successfully.\n";
	OS.close();

}

//populate file 
void populateFile(char filename[], int maxRec)
{
	client customer;
	cout<<endl;
	cout<<"Populate relative file with 10 clients.\n";
	//open file for random access
	//Supports both read and write 
	fstream IOS(filename, ios::in | ios::out);
	if(!IOS){cerr<<filename<<" file open error.\n"; exit(1);}
	cout<<"Enter: Account 0-" << maxRec<<" Name, Balance. (0 0 0 to exit).\n";
	cin>>customer.account >>customer.name >>customer.balance;
	
	while(0< customer.account)
	{
		IOS.seekp((customer.account -1)*sizeof(client));//positioning for put operation
		IOS.write((char*)&customer, sizeof(customer));
		cout<<"Enter: Account" << maxRec<<" Name, Balance. (0 0 0 to exit).\n";
		cin>>customer.account >> customer.name >>customer.balance;
	}
	IOS.close();
}

//Sequentail display of records
void showFile(char filename[])
{
	client customer;
	int n=0;
	void *ptr;
	//Open file for read
	ifstream IS(filename, ios::in);
	if(!IS){cerr<<"File open error.\n"; exit(1);}
	cout<<"Show contents of file " << filename<<".\n";
	while(ptr=IS.read((char*)&customer, sizeof(customer)))
	{
		//<<setw(3)<< ++n 
		cout<<"\n"<<setw(6)<<customer.account<<setw(20)
		<<customer.name<<setw(10)<<customer.balance;
	}
	IS.close();
}

//Update file by adding the interest 5% to given account number 
void unpdateFile(char filename[], int maxRec)
{
	client customer;
	int accNumber;
	
	//open file for random access
	//Supports both read and write 
	fstream IOS(filename, ios::in | ios::out);
	if(!IOS){cerr<<filename <<" file open error.\n"; exit(1);}
	
	cout<<"Enter an account number so that we can add 5 percent to it.\n";
		cin>>accNumber;
	//ensure that account number is in between 1 and 10
	while(1)
	{	

		if(accNumber <= 0 || accNumber > 10) break;
		IOS.seekg((accNumber-1)*sizeof(client));//positioning for get operation
		IOS.read((char*)&customer, sizeof(customer));
		cout<<setw(6)<<customer.account<<setw(20)<<customer.name<<setw(10)
		<<customer.balance<<endl;
		//clientRecord.balance +=clientRecord.balance*0.05;
		customer.balance +=customer.balance*0.05;
		IOS.seekp((accNumber-1)*sizeof(client));//positioning for put operation
		IOS.write((char*)&customer, sizeof(customer));

		cout<<"Enter an account number so that we can add 5 percent to it to it.\n";
		cin>>accNumber;
	}
	IOS.close();
}

//Main program 
int main()
{	
	char fileName[]="customers.txt";
	createCustomers(fileName, SIZE);
	//showFile(fileName);
	populateFile(fileName, SIZE);
	unpdateFile(fileName, SIZE);
	showFile(fileName);
	cout<<endl;
	return 0;
}

Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ g++ relFile.cpp -o rFile
Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ ./rFile 
Make file: Creating a relative file of 10 customers.
File was created successfully.

Populate relative file with 10 clients.
Enter: Account 0-10 Name, Balance. (0 0 0 to exit).
1 Elvyn 12345
Enter: Account10 Name, Balance. (0 0 0 to exit).
2 Mauricio 123456
Enter: Account10 Name, Balance. (0 0 0 to exit).
3 Julita 1234.54
Enter: Account10 Name, Balance. (0 0 0 to exit).
4 Henry 324.00
Enter: Account10 Name, Balance. (0 0 0 to exit).
5 Juan 33245.9
Enter: Account10 Name, Balance. (0 0 0 to exit).
6 Mirian 3245.09
Enter: Account10 Name, Balance. (0 0 0 to exit).
7 Kevin 34567
Enter: Account10 Name, Balance. (0 0 0 to exit).
8 Mike 342.89
Enter: Account10 Name, Balance. (0 0 0 to exit).
9 Luna 342.0
Enter: Account10 Name, Balance. (0 0 0 to exit).
10 Camaron 54.00
Enter: Account10 Name, Balance. (0 0 0 to exit).
 0 0 0
Enter an account number so that we can add 5 percent to it.
1
     1               Elvyn     12345
Enter an account number so that we can add 5 percent to it to it.
0
Show contents of file customers.txt.

     1               Elvyn   12962.2
     2            Mauricio    123456
     3              Julita   1234.54
     4               Henry       324
     5                Juan   33245.9
     6              Mirian   3245.09
     7               Kevin     34567
     8                Mike    342.89
     9                Luna       342
    10             Camaron        54
Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ 