1.
/************************************************************\
|  Program:  integtral1.cpp                                  |
|  Problem:  A programt that computes A using the Monte Carlo|
|            method. Use the result to compute e(now e=A+1). |
|            Analyze the accuracy of your result as the func |
|            tion of the number of generated random numbers  |
|            and compare it with the accuracy oftained if the|
|            integral is computed using a trapezoid method.  |
|  Purpose:  To use random numbers                           |
|  Author :  Elvyn Mejia                                     |
|  Date   :  12/11/2013                                      |
\************************************************************/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;




// A = e-1 = from integral(e^x) with limits of integration 0<= x <=1
double ArbitraryArea = exp(1.0) - 1; 

//Uniform random number generator 
double urn()
{ 
    return double(rand())/double(RAND_MAX);
}
//check for accuracy of result 
void checkError(double error)
{
    if(error <0)
        //if negative value convert to positive 
        error = -error;
    if(error < 0.00001 )
       cout << "Accurate result!\n";
    else
       cout <<setw(10)<< "The error percent is: " <<setw(10)<< error <<"%.\n";
}

//Use the trapezoid method to calculate area of the
//integral of e^x from o to 1
void trapezoidMethod(double a, double b)
{
    long int size,n;
    double h, areaTrapezoid;


    //double Area_Trapozoid;
    cout << "___Trapozoid Method___\n"; 
    for( size = 10; size <=1000; size *=10 )
    {
       
       a =0; 
       h = (b-a)/double(size); // the interval gap!
       areaTrapezoid = (exp(a) + exp(b))/2.0;
       a = a+h;
       for(cout<< endl, n =1; n < size; n++)
       { 
             
           areaTrapezoid += (exp(a));
           a = a+h;
       
       }
       areaTrapezoid *=h; 
       
       cout <<"The area using " <<setw(5)<< size 
            <<" numbers is : "<<  areaTrapezoid<<". ";

       double error = (areaTrapezoid -ArbitraryArea)/areaTrapezoid*100.0;
       //Call checkError to check accuracy of result 
       checkError(error);
    }
    cout << endl; 
}
//Use Monte Carlo numerical integration 
//to calculate area of the
//integral of e^x from o to 1
void monteCarlo(double a, double b)
{
     
     int k =0;//To count the number of point under the graph 
     double x, y, monteArea;
     long int n, size;


     cout<<"___Monte Carlo Method___\n";
     for(size = 100; size <=1000000; size*=100)
     {
     
        k =0; 
        monteArea = exp(1.0);
        srand(time(NULL));
        for (cout << endl,n=0; n<size; n++)
        {
            //Generate random number for x and y 
            x = urn(); 
            y = exp(1)*urn();
            //if the value of y lies under the graph count it 
            if(exp(x) >= y) k++;
            
        }
        //the ratio n/N, where n is k
        monteArea *= double(k)/double(n);
        
        cout <<"The area using " <<setw(5)<< size 
            <<" numbers is : "<<  monteArea<<".";
        double error = (monteArea -ArbitraryArea)/monteArea*100;
        //Call checkError to check accuracy of result 
       checkError(error);
        
     }
         
}
//Main program 
int main(void){
    //Limits of integration a and b
    double a =0, b=1;
    cout << "Arbitrary Area: " << ArbitraryArea <<".\n"; 
    
    //Call respective functions 
    trapezoidMethod(a,b);
    monteCarlo(a,b);
    
    cout <<"\n";
    
    return 0;
}


Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ g++ integral1.cpp -o int1
Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ ./int1 
Arbitrary Area: 1.71828.
___Trapozoid Method___

The area using    10 numbers is : 1.71971. The error percent is:  0.0832501%.

The area using   100 numbers is : 1.7183. The error percent is: 0.000833325%.

The area using  1000 numbers is : 1.71828. Accurate result!

___Monte Carlo Method___

The area using   100 numbers is : 1.7397.The error percent is:    1.23116%.

The area using 10000 numbers is : 1.7079.The error percent is:   0.608079%.

The area using 1000000 numbers is : 1.71863.The error percent is:   0.020315%.

Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ 
