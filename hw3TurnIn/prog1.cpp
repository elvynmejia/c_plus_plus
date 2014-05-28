1.
/************************************************************\
|  Program:  prog1.cpp                                       |
|  Problem:  To determine the number of times an integer     | 
|            value x occurs in an array.                     |
|  Purpose:  Use of iterative and recursive functions        |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/16/2013                                      |
\************************************************************/
#include<iostream>
using namespace std;


//Iterative function 
int iterativeFunc(int a[],int size, int x)
    {
        //Declare and initialized auxiliary variables
        //Traverse array of ints
        int i, count =0;
        for(i =0; i< size ; i++)
            //If the user input, x , matches a number in a[], count it
           if(x == a[i]) count++;
              
     return count;    
    } 


//Recursive function 
int recursiveFunc(int a[],int size, int x)
    {
        int count = 0;
        //If the user input, x , matches a number in a[], count it
        if (x == a[size-1]) count++;
        
        if (size <=0) return 0;
    //Decrement size of array a[]
    return recursiveFunc(a, size-1, x ) + count;
    }

//Main program 
int main(void)
    {

        int array[] = {1,2,2,3,3,3,4,5,5,6,6,0};
        
        //Determine size of array[]
        int size = sizeof(array)/sizeof(array[0]);
        int x;
        //Prompt use for input 
        cout << "Enter a number, x , to determine how many times it occurs in array: ";
        cin >> x; 
    
        //Display iterative version 
        cout << "----Iterative Version----\n"; 
        
        cout << "The number " << x << " that you entered occurs "
        <<iterativeFunc(array, size, x)<< " time(s).\n";
        
        //display recursive function 
        cout << "----Recursive Version----\n"; 
        cout << "The number " << x << " that you entered occurs " 
        <<recursiveFunc(array, size, x)<< " time(s).\n";
    }


sfs-wifi-dhcp-132-41:hw3 Elvyn$ g++ prog1.cpp -o p1
sfs-wifi-dhcp-132-41:hw3 Elvyn$ ./p1
Enter a number, x , to determine how many times it occurs in array: 4
----Iterative Version----
The number 4 that you entered occurs 1 time(s).
----Recursive Version----
The number 4 that you entered occurs 1 time(s).
sfs-wifi-dhcp-132-41:hw3 Elvyn$ ./p1
Enter a number, x , to determine how many times it occurs in array: 3
----Iterative Version----
The number 3 that you entered occurs 3 time(s).
----Recursive Version----
The number 3 that you entered occurs 3 time(s).
sfs-wifi-dhcp-132-41:hw3 Elvyn$ 
