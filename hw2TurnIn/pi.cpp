1.
/************************************************************\
|  Program:  pi.cpp                                          |
|  Problem:  Approximate the value of pi by adding 20 terms  |
|  Purpose:  The use of while and do loop                    |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

//function that calculates the value of pi using the while loop
double whileLoop()
{
    int i = 0;
    int limit = 20;
    double pi= 0.0;
    
    //Approximate the value of pi suing the formula a BBP-type formula
    //of the form 	4sum_(k=0)^(20)((-1)^k)/(2k+1) where k=i 
    while(i < limit)
    {
        pi += pow(-1.0, i)/(2.0*(i) + 1.0);
        i++;
    }
    
return pi;    
}


//function that calculates the value of pi using the do loop
double doLoop()
{
    int i = 0;
    int limit = 20;
    double pi = 0.0;
    
    do
    {
        pi += pow(-1.0, i)/(2.0*(i) + 1.0);
        i++;
        
    }while(i < limit);
    
return pi;
}

int main(void)
{
    //Call function whileLoop()
    cout<<"The approximation of pi using the while loop is " << 4*whileLoop() <<"\n.";
    //call function doLoop()
    cout<<"The approximation of pi using the do loop is    " << 4*doLoop() <<"\n.";
}


sfs-wifi-dhcp-135-166:hw2 Elvyn$ g++ pi.cpp -o p
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./p
The approximation of pi using the while loop is 3.09162
The approximation of pi using the do loop is    3.09162


