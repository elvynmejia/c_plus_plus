7.
/************************************************************\
|  Program:  factorial.cpp                                   |
|  Problem:  A program that prints the table of function     |
|	     y=n!                                            |
|  Purpose:  To control overflow                             |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    int i=0, factorial=1;

    while(++i)
    {
        if(i == 0) factorial = 1;
        else
        {
            factorial = factorial * i;
            cout<<" "<< i << "! = " << factorial << "\n";
        }
        //program stops execution before causing an integer overflow 
        if(i == 12) break;
    
    }
}
sfs-wifi-dhcp-135-166:hw2 Elvyn$ g++ factorial.cpp -o f
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./f
 1! = 1
 2! = 2
 3! = 6
 4! = 24
 5! = 120
 6! = 720
 7! = 5040
 8! = 40320
 9! = 362880
 10! = 3628800
 11! = 39916800
 12! = 479001600
sfs-wifi-dhcp-135-166:hw2 Elvyn$