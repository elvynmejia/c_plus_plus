2.
/************************************************************\
|  Program:  prog1.cpp                                       |
|  Problem:  Computes the sum of components of an array      |                    
|  Purpose:  Use of iterative and recursive functions and    |
|            built in functions                              |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/16/2013                                      |
\************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

        //Create random numbers from 0 t0 1
        //using the built in fuction double(rand())/double(RAND_MAX);
double rando(void)
    {
        return double(rand())/double(RAND_MAX);
    }

        //Use the following function for time measurements 
double sec(void)
    {
        return double(clock())/CLOCKS_PER_SEC;
    } 

        //Iterative sum function 
double iterativeFunc(double a[], int size)
    {
        //declare and initialized auxiliary variables 
        int i;
        double sum = 0.0;
        //Traverse the array and accumulate its values addition 
        for(i =0; i < size ; i++)
             sum += a[i];
        return sum;
    }

        //Recurvise sum function 
double recurviseFunc(double a[], int size)
    {
        //Return from function if array is empty 
        if (size <=0) return 0;
        return recurviseFunc(a, size-1)+a[size-1];
    }

//Main program 
int main(void)
    {
    
            //Initialize array a[] to 100
        double a[100];
        int i;
    
            //Obtain size of array a[]
        int size = sizeof(a)/sizeof(a[0]);
    
            //populate array with random numbers 
        for(i =0; i<100 ;i++) a[i] = rando();
          
    
            //start the time
        double initialTime= sec();
            // Use megaboom number to have at least 3 seconds
            //Call iterative function 
        for(i =0; i<10000000; i++) iterativeFunc(a, size);
    
        double elapsedTime = sec();
        cout << "The sum of components of array using an iterative function is  " << iterativeFunc(a, size)<< ".\n";
        cout << "Time elapsed from iterative function is : ";
            //Display measuring differences in execution time for iterative func 
        cout << elapsedTime  - initialTime << ".\n";
    
    
            //Start time 
        initialTime= elapsedTime ;
            //use megaboom number to have at least 3 sec
            //call recursive function 
        for(i =0; i<10000000; i++) recurviseFunc(a,size);
        elapsedTime  = sec(); // new last time for recursive method
        cout << "The sum of components of array using a recursive function is "<<  recurviseFunc(a,size)<<".\n";
        cout << "Time elapsed from recursive function is : ";
        //Display measuring differences in execution time for recursive func
        cout << elapsedTime  - initialTime << ".\n";
    
    
}

sfs-wifi-dhcp-132-41:hw3 Elvyn$ g++ prog2.cpp -o p2
sfs-wifi-dhcp-132-41:hw3 Elvyn$ ./p2
The sum of components of array using an iterative function is  51.8425.
Time elapsed from iterative function is : 2.9784.
The sum of components of array using a recursive function is 51.8425.
Time elapsed from recursive function is : 7.06065.
sfs-wifi-dhcp-132-41:hw3 Elvyn$ 