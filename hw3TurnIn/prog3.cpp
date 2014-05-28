3.
/************************************************************\
|  Program:  prog3.cpp                                       |
|  Problem:  Binary search using iterative and recursive     |
|             functions                                      |
|  Purpose:  Compare their run times                         |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/16/2013                                      |
\************************************************************/
#include <iostream>
using namespace std;

    //Function for time measurements 
double sec(void)
    {
       return double(clock())/CLOCKS_PER_SEC;
    }

    //Iterative function of binary search
int iterativeFunc(int a[], int size, int x)
    {
        //Declare and initialize auxiliary variables 
        int low =0;
        int high = size-1;
        int mid;
        for(;;)
        { //loop until array is empty 
            mid = (low +high)/2;        
            if(x >a[mid]) // is user input x greater than mid 
                low = mid+1; // low = mid+1
            else if(x <a[mid])// is user input x less than mid
                high = mid-1;// high = mid-1
            else if(x == a[mid]) // is x foud and at mid, return mid 
                return mid; 
            else
                return -1; // not found
        }
    } 

    //Recursive function of binary search 
int recursiveFunc(int a[], int low, int high, int x)
    {
        int mid = (low+high)/2;
        if(low>high) return -1; // retunr if object was not found 
        if(x<a[mid]) return recursiveFunc(a, low, mid-1, x); // high = mid-1
        if(x>a[mid]) return recursiveFunc(a, mid+1, high, x);// low = mid+1
        return mid; // return found object 
    }

    //Main function 
int main(void)
    {
        int i,j;
        int a[100000];//change zise of array 
        for(i=0; i<100000; i++)
            a[i] = i;
        //obtain size of array
        int size = sizeof(a)/sizeof(a[0]);
        
             // start time
        double start_time = sec();
        for(j = 0; j<200; j++) 
            for(i=0; i<size; i++)//Call iterative function 
            if (a[i]!=a[iterativeFunc(a,size,i)]) cout << "ERROR\n";
        double last_time = sec();
    
            //Display run time 
        cout<< "Measuring difference for iterative binary search function: "; 
        cout<< last_time - start_time << ".\n";
    
        start_time = last_time;    
        for(j = 0; j<200; j++)    
            for(i=0; i<size; i++)//Call recursive function 
            if (a[i]!=a[recursiveFunc(a,0,size,i)]) cout <<"ERROR\n";
        last_time = sec();
    
            //Display run time 
        cout << "Measuring difference for recursive binary search function: "; 
        cout<< last_time-start_time << ".\n"; 
    
    }


sfs-wifi-dhcp-132-41:hw3 Elvyn$ g++ prog3.cpp -o p3
sfs-wifi-dhcp-132-41:hw3 Elvyn$ ./p3
Measuring difference for iterative binary search function: 2.39048.
Measuring difference for recursive binary search function: 3.42668.
sfs-wifi-dhcp-132-41:hw3 Elvyn$
