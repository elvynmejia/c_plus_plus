3.
/************************************************************\
|  Program:  area.cpp                                        |
|  Problem:  Calculates are of triangle and rectangle        |
|  Purpose:  Use of Heron’s formula and sentinel value       |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a,b,c;//sides of triangle 
    double sideA, sideB;//sides of rectangle
    do
    {
        cout<<"Please enter the sides of a triangle (a,b,c).:\n";
        cin>> a >> b >> c; // >> sideA >> sideB;
        cout<<"Enter the sides of a rectangle (A,B):\n";
        cin>> sideA >> sideB;
        //If one of inputs is zero or negative terminate program 
        if(a <= 0 || b <= 0 || c <= 0 || sideA <= 0 || sideB <=0){
            cout<<"You entered 0 or negative input. Good bye!.\n"; exit(1);}
        else 
        {
            //Calculate area of triangle using Heron's formula
            //step1: calculate "s" (half of the triangles perimeter)
            //s=(a+b+c)/2
            double s = (a+b+c)/2;
            //step2: Calculate area of triangle using /sqrt(s[(s-a)(s-b)(s-c)])
            double areaTr = sqrt(s*(s-a)*(s-b)*(s-c));
            
            double areaRec = sideA*sideB;//Calculate area of rectangle 
            //Display messages according to condition
            if(areaTr < areaRec) cout<<"The area of triangle is less than the area of rectangle.\n";
            else if(areaTr > areaRec)cout<<"The area of triangle is greater than the area of rectangle.\n";
            else cout<<"The area of triangle is equal to the area of rectangle.\n";
        }
    }while(1);
    
return 0;
} 

sfs-wifi-dhcp-135-166:hw2 Elvyn$ g++ area3.cpp -o a
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./a
Please enter the sides of a triangle (a,b,c):
5
5
5
Enter the sides of a rectangle (A,B):
5
2
The area of triangle is greater than the area of rectangle.
Please enter the sides of a triangle (a,b,c):
-5
5
5
Enter the sides of a rectangle (A,B):
5
2
You entered 0 or negative input. Good bye!