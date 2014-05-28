4.
/************************************************************\
|  Program:  fibo.cpp                                        |
|  Problem:  Function that tests if a given number, n , is a |
|            Fibonacci number                                |
|  Purpose:  To use Heron's formula and functions            |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
//Function returns 1 if n is a Fibonacci number 
int FiboTest(int n)
{
    //A number is a Finonacci number iff (5*nn + 4) or (5*n*n -4) is a perfect square.
    //to check if a number is a perfect square take the square root, round to the nearest integer
    //and square the result. If this is the same as the the original number n then the original number
    //n is a perfect aquare/
    int a = (5*(pow(n,2))+ 4);//(5*n*n + 4)
    int a1 = sqrt(a);
    int a2 = pow(a1,2);
    
    int b = (5*(pow(n,2)) - 4);//(5*n*n - 4)
    int b1 = sqrt(b);
    int b2 = pow(b1,2);
    
    //check if the original number n is a perfect square, if yes teturn 1 
    if(b == b2 || a == a2) return 1;
}

int main(void)
{
    int n;
    cout<<"Enter an integer to test if it is a Fibonacci number: ";
    cin>> n;
    
    if(FiboTest(n)==1) cout<<"The number that you entered is a Fibonacci number.\n";
    else cout<< "The numeber that you enter is not a Fibonacci number.\n";
}

fs-wifi-dhcp-135-166:hw2 Elvyn$ g++ fibo.cpp -o f
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./f
Enter an integer to test if it is a Fibonacci number: 1
The number that you entered is a Fibonacci number.
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./f
Enter an integer to test if it is a Fibonacci number: 5
The number that you entered is a Fibonacci number.
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./f
Enter an integer to test if it is a Fibonacci number: 7
The numeber that you enter is not a Fibonacci number.
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./f
Enter an integer to test if it is a Fibonacci number: 10
The numeber that you enter is not a Fibonacci number.
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./f
Enter an integer to test if it is a Fibonacci number: 13
The number that you entered is a Fibonacci number.
sfs-wifi-dhcp-135-166:hw2 Elvyn$ 
