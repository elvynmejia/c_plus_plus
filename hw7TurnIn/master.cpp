1b.
/************************************************************\
|  Program:  master.cpp                                      |
|  Problem:  Master program that activates the engine program|
|	         using system(…) call and then retrieves results |
|	         from file.dat and displays them on the screen   |
|  Purpose:  To use system(…)calls and fstream               |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/22/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#define w setw
using namespace std;

int main(void)
{   //ouputs x1 and x2 of the quadratic formula
    double x1, x2;
    cout << "Solving the Quadratic formula ";
    cout << "ax^2 + bx +c .\n";
    
    
    //"g++ Statistics.cpp -o ./Statistics && ./Statistics"
    system("/Users/Elvyn/Desktop/Fall2013/CS340/Homework/hw7/engine ");
    system("/Users/Elvyn/Desktop/Fall2013/CS340/Homework/hw7/engine 1  -6  8");
    system("/Users/Elvyn/Desktop/Fall2013/CS340/Homework/hw7/engine 1  4 4 filename.dat");
    
    //Standard input file declaration + open 
    ifstream IS("filename.dat", ios::in);
    IS >> x1 >> x2;
    cout <<" x1 = "<<w(3)<< x1<<" x2 = "<<w(3) << x2<<"\n.";
    return 0;
}

sfs-wifi-dhcp-135-16:hw7 Elvyn$ ./master 
Solving the Quadratic formula ax^2 + bx +c .
Please input coefficients a, b, and c 1
2
3
x1 =  -1 + i *   4
x2 =  -1 - i *   4
 x1 =   4 x2 =   2
 x1 =  -2 x2 =  -2
.sfs-wifi-dhcp-135-16:hw7 Elvyn$