4.
/************************************************************\
|  Program:  prog4.cpp                                       |
|  Problem:  A program that reads data from the keyboard and |
|            creates a text file called "used.car"           |
|  Purpose:  File processing using ifstream and ofstream     |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/23/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#define W setw 

int main(void)
    {   //for filename use string constant or character pointer
        char filename[]="used.car";//or *filename="used.car"
        
        ofstream OS(filename, ios::out);//Standard stream declare + open, ios::out- write to file
        
        //Declare appropriate variables to store information about a car 
        string manufacturer,model;
        int n, year, miles, cost;
        
        //prompt the user to enter the following information about each car 
        cout<<"Enter the following information about each car.\n";
        
       while (1)
       {
            cout<<"Manufacturer: ";
            cin>>manufacturer;
           
            cout<<"Model: ";
            cin>>model;
           
            cout<<"Year: ";
            cin>>year;
           
            cout<<"Miles: ";
            cin>>miles;
           
            cout<<"Cost: ";
            cin>>cost;
            //write to file 
            OS << '\n' <<manufacturer << W(10) << model << W(10)<< year << W(10) << miles << W(10) <<cost << endl;
            cout<<"If you wish to continue enter 1 else enter 0.\n";
            cin>>n;
            if(n == 0) break;
           
           }
        OS.close();//close file
        
        
        //reopen file for reading
        ifstream IS(filename, ios::in);
        cout<<"Reopen file for reading.\n";
        cout<<"The following records satisfy the following conditions:";
        cout<<" miles less than 50000 and cost less than 9000.\n ";
        while(IS >> manufacturer >> model >> year >> miles >> cost)
        {   //Display record if the following conditions are met miles < 50000 and cost<< 9000
            
            if(miles < 50000 && cost < 9000)
            {
            
                cout<< '\n'<< W(10)<< manufacturer << W(10) << model << W(10) << year << W(10) << miles
                    <<W(10) << cost << endl;
            }
        }
        IS.close();//close file after reading 
    }


sfs-wifi-dhcp-135-56:hw4 Elvyn$ g++ prog4.cpp -o p4
sfs-wifi-dhcp-135-56:hw4 Elvyn$ ./p4
Enter the following information about each car.
Manufacturer: p
Model: j
Year: 900
Miles: 50002
Cost: 9002
If you wish to continue enter 1 else enter 0.
1
Manufacturer: l
Model: l
Year: 2013
Miles: 49999
Cost: 8999
If you wish to continue enter 1 else enter 0.
1
Manufacturer: s
Model: s
Year: 234
Miles: 49998
Cost: 8998
If you wish to continue enter 1 else enter 0.
1
Manufacturer: j
Model: j
Year: 1989
Miles: 50001
Cost: 9001
If you wish to continue enter 1 else enter 0.
0
Reopen file for reading.
The following records satisfy the following conditions: miles less than 50000 and cost less than 9000.
 
         l         l      2013     49999      8999

         s         s       234     49998      8998
sfs-wifi-dhcp-135-56:hw4 Elvyn$ 