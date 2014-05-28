1.
/************************************************************\
|  Program:  prog1Cstring.cpp                                       |
|  Problem:  A program that reads a date as a string in the  |
|            form 10/19/72 and displays the same date as     |
|            October, 19, 1972.                              |
|  Purpose:  Make use of C-strings                           |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/23/2013                                      |
\************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
int main(void)	
	{
    //declare and initialize an array of strings to contain the months in a year 
     string months[13] = {"January", "February", "March", "April", "May",
                        "June", "July", "August", "September",
                        "October", "November", "December"};
    
    char str[80];
    //Declare and initialize variables to store substring of input date  
    int i=0, month= 0, day=0, year=0;
    //Prompt the user to enter a date
    cout<<"Enter a date in the following format dd/mm/yy.\n";
    cin.getline(str, 80);//read a line of text
    
    //Read a sequence of characters as long as it is not the '/' charater
    //obtain month 
    while(str[i] != '/')
        {
        
        month = 10*month + str[i] - '0';//converting from string to digit
        i++;//move the pointer to point to the next character 
        }
        i++;//move the pointer to point to the next character
    //obtain day 
    while(str[i] != '/')
        {
            day = 10*day + str[i] - '0';
            i++;
        }
        i++;
    //obtain year, stop when '\0' is reached 
    while(str[i] != '\0')
        {
            year = 10* year + str[i] - '0';
            i++;
        }
        //i++;
        
    if (year <= 30) year +=2000;
        else
        year += 1900;
   
    //Diplay the dat e.g. October 19,1972.
    //Display date using C-strings
    cout<<"Display date using C-strings.\n";
    cout<< months[month-1]<< ' '<< day <<", "<< year <<"."<<endl;

	}

sfs-wifi-dhcp-135-56:hw4 Elvyn$ g++ prog1Cstring.cpp -o c
sfs-wifi-dhcp-135-56:hw4 Elvyn$ ./c
Enter a date in the following format dd/mm/yy.
10/19/72
Display date using C-strings.
October 19, 1972.
sfs-wifi-dhcp-135-56:hw4 Elvyn$ 