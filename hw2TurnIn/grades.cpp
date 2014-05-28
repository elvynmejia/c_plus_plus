2.
/************************************************************\
|  Program:  grades.cpp                                      |
|  Problem:  Prompt user to enter points and display grade   |
|  Purpose:  Use of sentinel value nested if and switch stat-
|	mets 							     |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/
#include <iostream>
using namespace std;

int main()
{
    double grade = 0.0;
    cout<<"Please enter your grade. If a negative grade is entered, the program terminates:";
    cin>>  grade;
    //if a grade is less than 0 exit the program 
    if(grade < 0) exit(1);
        cout<<"Displaying grades using nested if statements.\n";
        //cout<<"You enter "<< grade <<" as your grade\n";
        if(grade < 0 ) exit;
        else if(grade >= 90) cout<<"You have been assigned an A.\n";
        else if(grade >= 80) cout<<"You have been assigned a B.\n";
        else if(grade >= 70) cout<<"You have been assigned a C.\n";
        else if(grade >= 60) cout<<"You have been assigned a D.\n";
        else cout<<"You have been assigned an F\n";
    
        cout<<"Displaying grades using switch statements.\n";
   
        int points = (int)grade/10;
    
        switch (points)
        {
            case 9: case 10: cout<<"You have been assigned an A.\n";break;
            case 8: cout<<"You have been assigned a B.\n"; break;
            case 7: cout<<"You have been assigned a C.\n"; break;
            case 6: cout<<"You have been assigned a D.\n"; break;
            default: cout<<"You have been assigned an F\n"; break;
        }
return 0;
}

Please enter your grade. If a negative grade is entered, the program terminates:90
Displaying grades using nested if statements.
You have been assigned an A.
Displaying grades using switch statements.
You have been assigned an A.
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./g
Please enter your grade. If a negative grade is entered, the program terminates:-2
Negative number entered. Good bye!
sfs-wifi-dhcp-135-166:hw2 Elvyn$ 