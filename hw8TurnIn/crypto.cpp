2.
/************************************************************\
|  Program:  crypto.cpp                                      |
|  Problem:  A program that encrypts and decrypts a given    |
|			 file.  										 |      
|  Purpose:  Application of random numbers 	                 |
|  Author :  Elvyn Mejia                                     |
|  Date   :  12/11/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#define w setw
using namespace std;

ifstream IOS;
ifstream IS1;
ofstream OS;
ofstream OS1;

char key[80];
char inputFile[80];
char outputEncrypt[80];
char outputDecrypt[80];
char readingChar[200];

void writeEncryptFile();

/*Create the sequence of random bytes from a random 
number generator with the seed obtained from user’s secret key.*/
int randomNumber(){return rand()%128;}


 

//Get get to decript file 
void getKey()
{
    cout<<"Enter key to decrypt file: ";
    cin>>key;
}

//encrypt file 
void writeEncryptFile()
{
    int i=0;
    //Supports read and write and binary reading or writig 
    IOS.open(inputFile, ios::in | ios::out | ios::binary);
    OS.open(outputEncrypt, ios::out);
        //read file, encrypt and write to file 
        while(IOS.get(readingChar[i]))
        {
            readingChar[i]^=(char)randomNumber();
            OS<<readingChar[i];
            i++;
        }
    IOS.close();
    OS.close();
    
}


//Decrypt file 
void writeDecryptFile()
{
    int i=0;
    IS1.open(outputEncrypt, ios::in|ios::binary);
    OS1.open(outputDecrypt, ios::out);
    
    while(IS1.get(readingChar[i]))
    {
        readingChar[i]^=(char)randomNumber();
        OS1<< readingChar[i];
        i++;
    }
    IS1.close();
    OS1.close();
}

//main program
int main()

{
    unsigned long int i, num=0;
	/*Prompt the user to enter a secret key and 
	use it to compute the seed of a random number generator*/
    cout<<"Enter a key: ";
    cin>>key;
    /*Prompt the user to give the names of an input file and the output coded/decoded file*/
    cout<<"Enter the name of a file to encrypt: ";
    cin>>inputFile;
    cout<<"Enter the name of a file to write encryption to: ";
    cin>>outputEncrypt;
    cout<<"Enter the name of a file to decrypt: ";
    cin>>outputDecrypt;
    
    //Conver key to an int 
    for(i=0; key[i]; i++)
        num+=(int)key[i];
    
    srand(num);//Use the key as seed for the random generator func
    
    //write encrypted file 
    writeEncryptFile();
    
    //get key to decrypt
    getKey();
    num=0;
    
    //convert key to an int and use it as a seed
    for(i=0; key[i]; i++)
        num += (int)key[i];
    //decrypt file
    
    srand(num);
    writeDecryptFile();

return 0;

}

Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ g++ crypto.cpp -o cr
Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ ./cr
Enter a key: 12345
Enter the name of a file to encrypt: in.txt
Enter the name of a file to write encryption to: out.cry
Enter the name of a file to decrypt: out.cry
Enter key to decrypt file: 12345
Elvyn@sfs-wifi-dhcp-133-95:~/Desktop/Fall2013/CS340/Homework/hw8$ 