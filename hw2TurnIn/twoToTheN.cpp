6.
/************************************************************\
|  Program:  twoToTheN.cpp                                   |
|  Problem:  A program that prints the table of function     |
|	     y=2^n                                           |
|  Purpose:  To control overflow                             |
|  Author :  Elvyn Mejia                                     |
|  Date   :  10/30/2013                                      |
\************************************************************/
#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

int main(void)
{
    int number=1;
    int power=0;
    
    while(number >= 0)
    {
        cout <<"2^"<< power << " = " << number << endl;
        
        number*=2;
        power++;
    }

}

sfs-wifi-dhcp-135-166:hw2 Elvyn$ g++ twoToTheN.cpp -o 2
sfs-wifi-dhcp-135-166:hw2 Elvyn$ ./2
2^0 = 1
2^1 = 2
2^2 = 4
2^3 = 8
2^4 = 16
2^5 = 32
2^6 = 64
2^7 = 128
2^8 = 256
2^9 = 512
2^10 = 1024
2^11 = 2048
2^12 = 4096
2^13 = 8192
2^14 = 16384
2^15 = 32768
2^16 = 65536
2^17 = 131072
2^18 = 262144
2^19 = 524288
2^20 = 1048576
2^21 = 2097152
2^22 = 4194304
2^23 = 8388608
2^24 = 16777216
2^25 = 33554432
2^26 = 67108864
2^27 = 134217728
2^28 = 268435456
2^29 = 536870912
2^30 = 1073741824
sfs-wifi-dhcp-135-166:hw2 Elvyn$ 