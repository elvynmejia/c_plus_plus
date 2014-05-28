2.
/************************************************************\
|  Program:  triangleClass.cpp                               |
|  Problem:  Create the class triangle that includes three   |
|            sides of a triangle.                            |
|  Purpose:  Use of classes, member functions and fstream    |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/15/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#define w setw
using namespace std;

class triangle
{   //Define data that describes the object-triangle 
    private:
        double sideA, sideB, sideC;
    //define member functions
    //constructor and anitializer
    //(a) triangle – constructor that creates objects of that class.
    public:
        triangle()
        {
            sideA=sideB=sideC=0.0;
        }
    
        triangle( double side1, double side2, double side3)
        {
            sideA = side1;
            sideB = side2;
            sideC = side3;
        }
    
        //Function prototype
        int readfile(ifstream&);
        void show(void);
        int isequilateral();
    
};//this list might be empty 

    /*
    (b) readfile that reads 3 sides from the file triangle.dat. Read until the EOF is
    detected.
    */

    int triangle::readfile(ifstream& IS)
    {
        IS>>sideA>>sideB>>sideC;
        return !(IS.eof());
        
    }

    /*(c) show that displays on the screen 3 sides of triangle, perimeter and area.
    Use the following formulas:
    Perimeter = a+b+c
    Area = sqrt(s*(s-a)*(s-b)*(s-c)), where s=(a+b+c)/2 is the semi-perimeter.
    */
    void triangle::show(void)
    {
        double area, perimeter, s =0.0;
        
        perimeter = sideA + sideB + sideC;
        
        s = (sideA + sideB + sideC)/2;
        
             //sqrt(s*(s-a)*(s-b)*(s-c));
        area = sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
        
        
        
        cout<<"Side a= "<<sideA<<w(4)<<" side b="<<sideB<<w(4)<<" side c="<<sideC<<w(4)<<" perimeter="
            <<perimeter<<w(4)<<" area="<<area<<".\n";
        }

    /*
    (d) isequilateral that checks whether the triangle is equilateral (it must be a triangle
    and all sides must be equal.)
    */

    int triangle::isequilateral()
    {
        if(sideA == sideB && sideB == sideC )
        return 1;
        else return 0;
    }

    /*
    Create the input file triangle.dat using an editor and insert values needed for
    testing of all functions. Write a main program that demonstrates 
    the work with this class. Declare all objects and variables.
    Display only equilateral triangles from the input file.
    */

int main()
{
    char inputFileName[]="triangle.txt";
    triangle triangleData;
    //Standard stream declare + open, ios::in-use to read from file 
    ifstream IS(inputFileName, ios::in);
    
    
    cout<<"Display 3 sides of triangle, perimeter and area.\n";
    while(triangleData.readfile(IS))
    {
        if(triangleData.isequilateral())
            triangleData.show();
        //else cout<<"No equilateral triangle to display. Good bye!\n";
    }
return 0;
}


sfs-wifi-dhcp-133-54:hw6 Elvyn$ g++ triangleClass.cpp -o tr
sfs-wifi-dhcp-133-54:hw6 Elvyn$ ./tr
Display 3 sides of triangle, perimeter and area.
Side a= 2 side b=2 side c=2 perimeter=6 area=1.73205.
Side a= 3 side b=3 side c=3 perimeter=9 area=3.89711.
sfs-wifi-dhcp-133-54:hw6 Elvyn$ 
    
    
    
    
    
    
    
    
    
    
    