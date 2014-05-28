1.
/************************************************************\
|  Program:  prog1.cpp                                       |
|  Problem:  A program that reads a date as a string in the  |
|            form 10/19/72 and displays the same date as     |
|            October, 19, 1972.                              |
|  Purpose:  Make use of string class                        |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/23/2013                                      |
\************************************************************/
#include <iostream>
#include <string>


using namespace std;

int main(void)
{
    
    //declare and initialize an array of strings to contain the months in a year 
    string months[13] = {"January", "February", "March", "April", "May",
                        "June", "July", "August", "September",
                        "October", "November", "December"};
    string date;
    //prompt use to enter a date
    cout<<"Enter a date in the folowing format dd/mm/yy.\n";
    getline(cin, date);
    
    //Declare and initialize variables to store substring of input date 
    int i=0,day=0,month=0,year=0;
    
    //Read a sequence of characters as long as it is not the '/' charater
    //obtain month
    while(date[i] != '/')
        {
        //
        month = 10*month + date[i] - '0';//converting from string to digit
        i++;//move the pointer to point to the next character 
        }
        i++;//move the pointer to point to the next character 
    //Obtain day
    while(date[i] != '/')
        {
            day = 10*day + date[i] - '0';
            i++;
        }
        i++;
    //Obtain year, stop when '\0' is reached 
    while(date[i] != '\0')
        {
            year = 10* year + date[i] - '0';
            i++;
        }
      
    if(year <= 30) year += 2000;
    else year +=1900;
    //Display date using the string class
    cout<<"Display date using the string class.\n";
    cout<< months[month-1]<< ' '<< day <<","<< year <<"."<<endl;
    
}

sfs-wifi-dhcp-135-56:hw4 Elvyn$ g++ prog1.cpp -o p1
sfs-wifi-dhcp-135-56:hw4 Elvyn$ ./p1
Enter a date in the folowing format dd/mm/yy.
10/19/72
Display date using the string class.
October 19,1972.
sfs-wifi-dhcp-135-56:hw4 Elvyn$ 