1b.
/************************************************************\
|  Program:  engine.cpp                                      |
|  Problem:  Program that solves the quadratic equation  that|
|	     accepts inputs (a,b,c) as command line argumets     |
|  Purpose:  To use system(…)calls		                     |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/22/2013                                      |
\************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#define w setw
using namespace std;

int quadratic(double &a,double &b,double &c, double &x1, double &x2, int t)//t
{
      
     //To check if we will have real solution
     if(b*b - 4*a*c>=0)
     {
         x1 = (-b+sqrt(b*b -4*a*c ))/(2*a);
         x2 = (-b-sqrt(b*b -4*a*c ))/(2*a);
         return 1; 
     }
     x1 = -b/(2*a);
     x2 = (4*a*c - b*b)/(2*a);
     return 0; // false if b*b - 4*a*c<0 
}

int main(int argcnt, char *argvec[])
{
    double a =0, b =0, c =0 ;
    double x1, x2;
    int t;
    
     //if there is no command line arguments, ask user for input 
    if (argcnt == 1)
    {
       cout <<"Please input coefficients a, b, and c ";
       cin >> a >> b >> c;
       
       if(quadratic(a,b,c,x1,x2,t))//t
          cout <<" x1 = "<<w(3)<< x1<<" x2 = "<<w(3) << x2<<"\n."; 
       else
        {
          cout <<"x1 = "<<w(3)<< x1 <<" + " <<"i * "<<w(3) << x2 << endl;
          cout <<"x2 = "<<w(3)<< x1 <<" - " <<"i * "<<w(3) << x2 << endl;
        }
}
    //If command line has 3 arguments then program should display
    //the result x1 and x2 on the screen
    else if(argcnt == 4)
    {
     
        //cout << "Three Command line Arguments\n.";
        a=atof(argvec[1]);
        b=atof(argvec[2]);
        c=atof(argvec[3]);
        
        if(quadratic(a,b,c,x1,x2,t)) //t
           cout <<" x1 = "<<w(3)<< x1<<" x2 = "<<w(3) << x2<< endl;
        else
        {
           cout <<"x1 = "<<w(3)<< x1 <<" + " <<"i * "<<w(3) << x2 << endl;
           cout <<"x2 = "<<w(3)<< x1 <<" - " <<"i * "<<w(3) << x2 << endl;
        }    
    }
    
    //if there are four command line arguments(a,b,c,filename.dat) then
    //engine should take a,b,c and store the results x1 and x2 in filename.dat
    else if(argcnt == 5)
    {
       
        
        a = atof(argvec[1]);
        b = atof(argvec[2]);
        c = atof(argvec[3]);
        ofstream OS(argvec[4], ios::out);
        
        quadratic(a,b,c,x1,x2,t); // t
        OS << w(3)<< x1<<' '<<w(3) << x2<<".\n";
    }
    
    
    
}