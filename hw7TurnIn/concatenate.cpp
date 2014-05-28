2.
/************************************************************\
|  Program:  concatenate.cpp                                 |
|  Problem:  Append dynamic char array add to the end of str |
|  Purpose:  To use dynamic char arrays                      |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/22/2013                                      |
\************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

//Func append that concatenates two dynamic character arrays
char *append(char *str, char *add)
{    //Return concatenation of str and add
     static char buffer[100]; 
     char *p = buffer; 
     while(*p++ = *str++); 
     p--; 
     while(*p++ = *add++);
       
     return buffer;
}

int main(void)
{
    int size = 50;
    //Dynamic allocation of character arrays 
    char *str = new char[size]; 
    char *add =  new char[size];
 /*
    char name[80];
    char last[80];
    
    int count=0;
    
    cout<<"Please input your name, press Enter, and input your last name\n.";
    while(count<5)
    {
        //cout<<"Please input your name, press Enter, and input your last name\n.";
        cin>>name;
        cin>>last;
        
        str=name;
        add=last;
        str=append(str, add);
        cout<<str<<endl;
        count++;
    }
*/
    
    char name[] =  "Elvyn Mejia";
    char status[] = " loves C++ programming!";
    str = name;
    add = status;
    //Concatenate add at the end of str
    str = append(str, add);
    cout << str << endl;

    return 0;
}

sfs-wifi-dhcp-134-137:hw7 Elvyn$ g++ concatenate.cpp -o conc
sfs-wifi-dhcp-134-137:hw7 Elvyn$ ./conc
Elvyn Mejia loves C++ programming!
sfs-wifi-dhcp-134-137:hw7 Elvyn$ 