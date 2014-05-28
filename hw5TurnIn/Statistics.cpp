1a.
/************************************************************\
|  Program:  Statistics.cpp                                  |
|  Problem:  Program activated by system command.            |
|            Reads numbers from random.dat, and for          |
|            these numbers computes and displays             |
|            the mean value, standard deviation,             |
|            and coefficient of variation.                   |     
|  Purpose:  fstream and system command                      |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/06/2013                                      |
\************************************************************/



#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;
int main()
{   cout<<"-------------------------------------------------------------------\n";
    cout<<"Entering Statistics.cpp.\n";
    double number, sum=0.0, mean=0.0, stdev=0.0, coefficient_var=0.0;
    int counter=0;//coun the numbers in file data.txt 
    
    char inputFileName[]="random.txt";//file to read from
    //Standard stream declare + open, ios::in —use to read from file 
    ifstream IS(inputFileName, ios::in);
    //read file and compute mean, standard deviation and coefficient of variation 
    while( IS>>number)
    {   
        sum +=number;
        stdev+=pow(number,2.0);
        counter++;
    }
    IS.close();
    
    //Calculate mean, std, and coefficient variation 
    mean=sum/counter;
    stdev =stdev - pow(mean,2.0);
    stdev = sqrt(stdev);
    coefficient_var=stdev/mean;
    
    //Display mean, std, and coefficient variation
    cout<<"Mean is " << mean <<".\n";
    cout<<"Standard deviation is " << stdev <<".\n";
    cout<<"Coefficient of variation is " << coefficient_var <<".\n";
    cout<<"Exiting Statistics.cpp and returning system control to MakeFile.cpp.\n";
    cout<<"-------------------------------------------------------------------\n";
    
return 0;
}

sfs-wifi-dhcp-132-216:hw5 Elvyn$ g++ Statistics.cpp -o Statistics
sfs-wifi-dhcp-132-216:hw5 Elvyn$ ./Statistics
-------------------------------------------------------------------
Entering Statistics.cpp.
Mean is 44.315.
Standard deviation is 638.615.
Coefficient of variation is 14.4108.
Exiting Statistics.cpp and returning system control to MakeFile.cpp.
-------------------------------------------------------------------
sfs-wifi-dhcp-132-216:hw5 Elvyn$ 
