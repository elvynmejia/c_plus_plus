3.
/************************************************************\
|  Program:  studentStruct.cpp                               |
|  Problem:  A program that reads students records from      |
|            students.txt and creates an array of students   |
|	         structures S[]                                  |
|  Purpose:  File processing and Structs                     |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/06/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

//A text file students.txt contains student records (name, date of birth, and GPA)
char inputFile[]="students.txt";
//Standard stream declare + open, ios::in— use to read from file
ifstream IS(inputFile, ios::in);

struct Date
{   int month;
    int day;
    int year;
};

struct Student
{   string name;
    Date dob; //dob is an object of type Date 
    double GPA;
} S[200];

//main program
int main()
{
    int i=0;
    double meanGPA=0.0,stdevGPA=0.0,coefficientGPA=0.0;
    double meanAge=0.0,stdevAge=0.0,coefficientAge=0.0;
    
    /*
    Process all records from the array S and
     compute the mean value,
    the standard deviation, and the coefficient
     of variation for student age, and for student GPA.
    */
    
    while(IS >>S[i].name >> S[i].dob.month >> S[i].dob.day >>S[i].dob.year >>S[i].GPA)
    {
    
    //get age from current year
    meanAge+= 2013 -S[i].dob.year;
    stdevAge+=pow(2013 - S[i].dob.year, 2.0);
    
    meanGPA += S[i].GPA;
    stdevGPA += pow(S[i].GPA, 2.0);
    i++;
    }
    
    //Calculate mean, std and coefficient of variation for student age
    meanAge /=i;
    stdevAge = stdevAge -pow(meanGPA, 2.0);
    stdevAge =sqrt(stdevAge);
    coefficientAge = stdevAge/meanAge;
    
    //Calculate mean, std and coefficient of variation for student age
    meanGPA /=i;
    stdevGPA = stdevGPA -pow(meanGPA, 2.0);
    stdevGPA = sqrt(stdevGPA);
    coefficientGPA = stdevGPA/meanGPA;
    
    //Display Age calculation
    cout<<"The mean age is " << meanAge <<".\n";
    cout<<"The age standard deviation is "<<stdevAge<<".\n";
    cout<<"The age coefficient of variation is "<<coefficientAge <<".\n";
    cout<<"----------------------------------\n";
    
    //Dislplay GPA calculations
    cout<<"The mean GPA is "<<meanGPA<<" .\n";
    cout<<"The GPA standard deviation is "<<stdevGPA<<".\n";
    cout<<"The GPA coefficient of variation is "<<coefficientGPA<<".\n";

return 0;
}

sfs-wifi-dhcp-132-216:hw5 Elvyn$ g++ studentStruct.cpp -o ss
sfs-wifi-dhcp-132-216:hw5 Elvyn$ ./ss
The mean age is 23.1667.
The age standard deviation is 53.1695.
The age coefficient of variation is 2.29509.
----------------------------------
The mean GPA is 3.33333 .
The GPA standard deviation is 7.61668.
The GPA coefficient of variation is 2.28501.
sfs-wifi-dhcp-132-216:hw5 Elvyn$ 