3.
/************************************************************\
|  Program:  prog3.cpp                                       |
|  Problem:  A program that copies a given text file into    |
|            another text file in which the lines are        |
|	         numbered 1,2,3,… with the line number at the    |
|            beginning of each line.                         |
|  Purpose:  File processing using ifstream and ofstream     |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/23/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;
#define W setw

int main(void)
    {   int counter=0;
        char str[80];
        char InputName[] = "myFile.txt";//read from file
        
        //for file name use string constant or character pointer or *filename="used.car"
        char OutputName[]= "file.txt";// file to write to
        
        //standard stream declare + open 
        ifstream IS(InputName, ios::in);//Input file stream-read from
        ofstream OS(OutputName, ios::out);//Output file stream-write to
        
        cout<<"Reading from file "<<InputName<< "\n";
        cout<<"Writing to file "<<OutputName<<"\n";
        while(!(IS.eof()))//read file until EOF marker is reached
            {
                counter++;
                IS.getline(str, 80);
                
                OS<< counter <<": "<< W(10)<< str << endl;
            }
        IS.close();//close file after reading 
        OS.close();//close file after writing 
    
    }

sfs-wifi-dhcp-135-56:hw4 Elvyn$ g++ prog3.cpp -o p3
sfs-wifi-dhcp-135-56:hw4 Elvyn$ ./p3
Reading from file myFile.txt
Writing to file file.txt
sfs-wifi-dhcp-135-56:hw4 Elvyn$

//Contents of files 
myFile.txt
p         p       900     50002      9002
l         l      2013     49999      8999
s         s       234     49998      8998
j         j      1989     50001      9001


file.text
1: p         p       900     50002      9002
2: l         l      2013     49999      8999
3: s         s       234     49998      8998
4: j         j      1989     50001      9001

