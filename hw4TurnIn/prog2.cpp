2.
/************************************************************\
|  Program:  prog2.cpp                                       |
|  Problem:  A program that reads a line of text and computes| 
|            and displays the number of upper, and lower case|
|            letters and digits in a line of text.           |
|            make own functions isupper,islower, isdigit and |
|            getline.                                        |
|  Purpose:  Use of the C-strings                            |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/23/2013                                      |
\************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//isupper func
int isupper(char a )
    {   
    if ('A' <= a && a<= 'Z') return 1; 
    else return 0;
    }

//islower func
int islower(char a)
    {
    if('a' <= a && a <= 'z') return 1;
    else return 0;
    }

//isdigit func
int isdigit(char a)
    {
    if ('0' <= a && a<= '9')return 1;
    else return 0; 

    }


//getline func
void getline(char *str, int size)
    {
    
    int i=0;
    //read character by character 
    while(i<size && (str[i]=cin.get())!='\n') i++;

    //terminate the string
    str[i]='\0';//same as str[i]=0
    }

int main(void)
{   
    char str[80];
    //Declare and initialize counter variables
    int i, lower=0,upper=0, digit=0;
    
    cout<<"Enter a line of text (e.g. Csc 210 Fall 2013): \n";
    
    cin.getline(str,80);
    
    for(i=0; str[i]; i++)//same as (for i=0; str[i] !='\0'; i++)
    {
        if(isupper(str[i])) upper++;
        else if(islower(str[i])) lower++;
        else if(isdigit(str[i])) digit++;
    }
    cout<<"Upper case latters "<< upper << ", lower case letters " << lower << ", digits " << digit << ".\n";
}

sfs-wifi-dhcp-135-56:hw4 Elvyn$ g++ prog2.cpp -o p2
sfs-wifi-dhcp-135-56:hw4 Elvyn$ ./p2
Enter a line of text (e.g. Csc 210 Fall 2013): 
Csc 210 Fall 2013 
Upper case latters 2, lower case letters 5, digits 7.
sfs-wifi-dhcp-135-56:hw4 Elvyn$ 