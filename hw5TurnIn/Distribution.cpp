1b.
/************************************************************\
|  Program:  Distribution.cpp                                |
|  Problem:  Program that plots a histogram of the           |
|            distribution of numbers in random.dat           |
|  Purpose:  fstream and system calls                        |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/06/2013                                      |
\************************************************************/
#include<iostream>
#include<fstream>
#include<iomanip>
#define w setw
using namespace std;

int main(void)
{
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Entering Distribution.cpp.\n";
    char inputFilename[] = "random.txt";
    int i,j,k;
    double num;
    
    //Standard stream declare and + open, ios::in —use to read from file 
    ifstream IS(inputFilename, ios::in);
    double min=100., max=0.;
    int array[20];
    //Use to divide our range of numbers into 20 equal class widths 
    for(i =0; i <20; i++)
          array[i] = 0;
          //cout<<i<< array[i]<< ".\n";
    
    
    while(IS >> num)
    {
        if(num > max )max = num;
        else if(num < min)min = num;
        
    }
    //Reopen file to read data 
    ifstream IS1(inputFilename, ios::in);
    while(IS1 >> num)
    {
       k=int(20*(num - min)/(max - min));
       array[k]++;
        
    }
    i =0;
    
    //Display histogram 
    for(k =0; k<20; k++)
    {
       cout <<w(3)<< i << '-' <<w(3) << i+5 <<"|";
       for(j =0; j <array[k]; j++)
          cout << '*';
       cout << endl;
       i = i+5;
    }
    
    
   cout<<"Exiting Distribution.cpp and returning system control to MakeFile.cpp.\n";
   cout<<"-------------------------------------------------------------------\n";

    
    return 0; 
}

sfs-wifi-dhcp-132-216:hw5 Elvyn$ g++ Distribution.cpp -o Distribution
sfs-wifi-dhcp-132-216:hw5 Elvyn$ ./Distribution 
-------------------------------------------------------------------
Entering Distribution.cpp.
  0-  5|*
  5- 10|
 10- 15|**
 15- 20|******
 20- 25|********
 25- 30|*******
 30- 35|*************
 35- 40|*******
 40- 45|*******************
 45- 50|*****************
 50- 55|****************
 55- 60|******************************
 60- 65|*******************
 65- 70|****************
 70- 75|************
 75- 80|***************
 80- 85|****
 85- 90|*
 90- 95|******
 95-100|
Exiting Distribution.cpp and returning system control to MakeFile.cpp.
-------------------------------------------------------------------
sfs-wifi-dhcp-132-216:hw5 Elvyn$ 

