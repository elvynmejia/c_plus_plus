1.
/************************************************************\
|  Program:  MakeFile.cpp                                    |
|  Problem:  A program that creates a file random.dat that   |
|            contains 200 random numbers where each number   |
|            is the sum of 12 random values rand( )%9.       |
|  Purpose:  Use of rand() fucntion and system commands      |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/06/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
//#define MAX 200
//#define SUM 12
using namespace std;

//Function that returns a random value
int randomValues(void)
{
    return rand()%9;

}

int main()
{   cout<<"MakeFile.cpp.\n";
    cout<<"200 random numbers have been created and written to file random.txt.\n";
    char outPutFileName[]="random.txt";

    ofstream OS(outPutFileName, ios::out);//Standard stream declare + open, ios::out—write to file
    
    //Declare and initialize appropriate variables to compute the mean, standard deviation
    //and coefficient of variation
    int sum=0, number=0, i,j;
    for(i=1; i<= 200; i++)
    {   //each number is the the sum of 12 random values
        for(j=1; j<12; j++) number += randomValues();
            
        //write number to file
        // i <<"i:" <<j<<"j:"<< — use to test whether the right data is written to file 
        OS<<number<<endl;
        //reset number to 0 to start a new sum of 12 values
        //repeat this until 200 numbers have been generated
        number=0;
    }
    OS.close();
    
    /*  Use system command to activate Statistics.cpp that reads numbers from
        random.txt and computes and displays the mean value, standard deviation,
        and coefficients of variation.
        Use system control to activate Distribution.cpp that read numbers
        from random.txt and displays the distrinution of the data 
    */
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Now Passing control to Statistics.cpp.\n";
    system("g++ Statistics.cpp -o ./Statistics && ./Statistics");
    cout<<"Now Passing control to Distribution.cpp.\n";
    system("g++ Distribution.cpp -o Dist && ./Dist");
return 0;
}

sfs-wifi-dhcp-132-216:hw5 Elvyn$ g++ MakeFile.cpp -o mf
sfs-wifi-dhcp-132-216:hw5 Elvyn$ ./mf
MakeFile.cpp.
200 random numbers have been created and written to file random.txt.
-------------------------------------------------------------------
Now Passing control to Statistics.cpp.
-------------------------------------------------------------------
Entering Statistics.cpp.
Mean is 44.315.
Standard deviation is 638.615.
Coefficient of variation is 14.4108.
Exiting Statistics.cpp and returning system control to MakeFile.cpp.
-------------------------------------------------------------------
Now Passing control to Distribution.cpp.
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
We are back to MakeFile.cpp(Main Program).
sfs-wifi-dhcp-132-216:hw5 Elvyn$ 
