5.
/************************************************************\
|  Program:  pattern.cpp                                     |
|  Problem:  Function that prints a desired sequence of      |
|            triangles.                                      |	                                                   |  Purpose:  The use of nested for loops.                    |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/
#include <iostream>
using namespace std;
//function that prints a pattern 
void triangle(int n)
{
    int row;//control rows
    int col;//control columns
    for(row =1; row <= n*2-1 ; row++, cout << endl)
    {for(col = 1; col <= n ; col++)
            //Print a pattern using these conditions 
            cout << (row + col >=n+1 && row-col <n ? '*': ' ');
    }
}

int main(void)
{
    int n;//user input
    int i;//control structure 
    //Prompt the user for a desire sequence of triagles 
    cout<<"Enter a number (n) to print a sequence of triangles";
    cin>> n;
    
    for(int i =1; i <= n; i++, cout<<endl)
        triangle(i);
}
sfs-wifi-dhcp-135-166:hw2 Elvyn$ g++ pattern.cpp -o p
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./p
Enter a number (n) to print a sequence of triangles5
*

 *
**
 *

  *
 **
***
 **
  *

   *
  **
 ***
****
 ***
  **
   *

    *
   **
  ***
 ****
*****
 ****
  ***
   **
    *

sfs-wifi-dhcp-135-166:hw2 Elvyn$ 