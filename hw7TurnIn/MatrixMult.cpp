1.
/************************************************************\
|  Program:  staticMatrixMult.cpp                            |
|  Problem:  Two matrix multiplication programs              |
|  Purpose:  To use static matrices and matrix multiplication|
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/22/2013                                      |
\************************************************************/

#include <iostream>
#include <iomanip>
#define w setw

using namespace std;
const int SIZE=4;
void static_matrix(int n, int a[][SIZE],  int b[][SIZE], int c[][SIZE]){
    int i,j,k;
    for (i =0; i<n; i++ )
       for(j =0; j<n; j++)
          for(c[i][j]=k=0; k<n; k++)
             c[i][j] += a[i][k]*b[k][j];
    
}

void dynamicMatrix(int n, int* a, int* b, int *c){
     int i,j,k;
     for(i =0; i<n; i++)
        for(j =0; j<n; j++)
           for(*(c+i*n+j)=k=0; k<n; k++)
              *(c+i*n+j)+= *(a+i*n+k) * *(b+n*k+j);
}

int main(void){
    cout << "___Static Matrix___" << endl; 
    int i,j;
    int a[SIZE][SIZE]; 
    int b[SIZE][SIZE]; 
    int c[SIZE][SIZE];
    
    //Generate array A and B with random interger numbers 
    cout << "___Static Array A___ " << endl;
    for(i =0; i<SIZE; i++)
    {
      for(j =0; j<SIZE; j++)
      {
        a[i][j] = rand()%20;
        cout <<w(3)<< a[i][j] <<' ';
      } 
      cout << endl;
    }
    cout << endl;
    cout <<"___Static Array B___" << endl;
    for(i =0; i<SIZE; i++){
      for(j =0; j<SIZE; j++){
        b[i][j] = rand()%20;
        cout <<w(3)<< b[i][j] <<' ';
        }
      cout << endl;
    }
    
    cout << endl;
    
    //Compute static matrix multiplication 
    static_matrix(SIZE,a,b,c);
    cout <<"___Static Array Multiplication___" << endl;
    
    for(i=0; i< SIZE; i++){
      for(j=0; j<SIZE; j++)
        cout <<w(3)<<c[i][j] <<' ';
      cout << endl;
    }
    cout << endl;
    
    
    cout << "___Dynamic Array___" << endl;
    
    //4*4 is 16 == size
    int size =16; 
    int* dynamic_a = new int[size]; 
    int* dynamic_b = new int[size];
    int* dynamic_c = new int[size];
    
    //POpulate array A and B with random integer numbers
    cout << "___Dynamic Array A___" << endl;
    for(i =0; i<SIZE; i++){
      for(j =0; j<SIZE; j++){
        *(dynamic_a+i*SIZE+j) = rand()%20;
        cout <<w(3)<< *(dynamic_a+i*SIZE+j) <<' ';
        }
      cout << endl;
    }
    cout << endl;
    cout << "___Dynamic Array B___" << endl; 
    for(i =0; i<SIZE; i++)
    {
      for(j =0; j<SIZE; j++)
      {
        *(dynamic_b+i*SIZE+j) = rand()%20;
        cout <<w(3)<< *(dynamic_b+i*SIZE+j) <<' ';
      }
      cout << endl;
    }
    cout << endl;
    
    //Compute dynamic matrix multiplication
    dynamicMatrix(SIZE, dynamic_a,dynamic_b,dynamic_c );
    
    //Diplay dynamic matrix multiplication
    cout << "___Dynamic Array Multiplication___ " << endl;    
    for(i=0; i< SIZE; i++)
    {
      for(j=0; j<SIZE; j++)
        cout <<w(3)<<*(dynamic_c+i*SIZE+j) <<' ';
      cout << endl;  
    }
    cout << endl; 
    
   
    return 0;
    
}


sfs-wifi-dhcp-134-137:hw7 Elvyn$ g++ matrixMult.cpp -o m
sfs-wifi-dhcp-134-137:hw7 Elvyn$ ./m
___Static Matrix___
___Static Array A___ 
  7   9  13  18 
 10  12   4  18 
  3   9   0   5 
 12   2   7   3 

___Static Array B___
  7   9   0  12 
  3   9   9  17 
  0  13  19  18 
 16  15  17   6 

___Static Array Multiplication___
364 583 634 579 
394 520 490 504 
128 183 166 219 
138 262 202 322 

___Dynamic Array___
___Dynamic Array A___
 12   7  10  13 
 19   9  19   1 
  7  12  13  16 
  5   5   8  11 

___Dynamic Array B___
 14  17   1  13 
  8   4   8  10 
  4  16  10   3 
  2   6   9   4 

___Dynamic Array Multiplication___ 
290 470 285 308 
416 669 290 398 
278 471 377 314 
164 299 224 183 

sfs-wifi-dhcp-134-137:hw7 Elvyn$ 

