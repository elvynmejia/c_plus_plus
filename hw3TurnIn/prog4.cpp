4.
/************************************************************\
|  Program:  prog4.cpp                                       |
|  Problem:  Recursive function line(n) to display a line    |
|            with n asterisks. A recursive function histogram|        	     
|             plots a histogram using                        |
|             recursive calls of the                         |
|            function line.                                  |
|  Purpose:  recursive functions and recursive calls         |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/16/2013                                      |
\************************************************************/
#include <iostream>
using namespace std;

    //Recursive function line()
int line(int n){
    cout <<'*'; // print asterisks 
    if (n<=1) return 0; //Return from function if number of asterisks to print is 1 or less
    return line(n-1);
    
}
    //Main function 
int main(void)
    {
        int j;
    
            //The histogram is specified using the array int histogram[] = {3,4,5,4,3};
        int histogram[] = {3,4,5,4,3};
            //Obtain size of array histogram 
        int size = sizeof(histogram)/sizeof(histogram[0]);
            //Traverse array histogram[]
        for(j =0; j< size; j++)
            {
                // call recrusive function line()
                line(histogram[j]);
                cout <<"\n";
            }
    
    }


sfs-wifi-dhcp-132-41:hw3 Elvyn$ g++ prog4.cpp -o p4
sfs-wifi-dhcp-132-41:hw3 Elvyn$ ./p4
***
****
*****
****
***
sfs-wifi-dhcp-132-41:hw3 Elvyn$ 
