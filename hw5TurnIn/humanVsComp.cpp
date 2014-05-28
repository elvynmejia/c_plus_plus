1.
/************************************************************\
|  Program:  HumanVsComp.cpp                                 |
|  Problem:  A game where the computer and the user          |
|            alternatively guess the value of a random       |
|            selected number between 1 and 99(or any other   |
|            maximun value) Record the number of guesses and |
             the player with the minumun number of guesses   |
             wins.                                           |
|  Purpose:  Make use of the rand() function                 |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/06/2013                                      |
\************************************************************/
#include <iostream>

using namespace std;

int randomNum(void){
    srand(time(NULL));
    return rand()%99+1;

}

int human(int guess, int input, int count){
    
    while (input > 0 && input <100)
       if (input > guess){
             cout << "Too Big!\n";
             count ++;
             cout << "Guess? number 1 to 99: ";
             cin >> input;
       }
       else if(input < guess){
             cout << "Too Small!\n";
             count++;
             cout << "Guess? number 1 to 99: ";
             cin >> input;
       }
       else{
             cout <<"Correct!\n";
             count++;
             return count;
       }
     
             
       
   
}

int computer(int guess, int count){
    char check;
    int max = 99;
    int min = 1;
    int mid = (max + min)/2;
    while(1){
         cout << "The guess from computer: "<< guess <<"\n";
         cout << "Is it correct press '>','<',or '=': \n";
         cin >> check;
         //mid /= 2;
         
         if(check == '>'){
             guess = guess+ (mid+1);
             count++;
             max = max- (mid+1);
             
         }
         else if(check == '<'){
             guess = guess- (mid+1);
             count++;
             min = min+ (mid+1);
             
         }
         else if(check == '='){
             count++;
             cout << "I found it!\n";
             break;
         }
         if(!(max > min)){
             cout << "You are cheating!\n";
             return 0;
             break;
         }
              
    
    }
    return count;
}

void human_Comp(int count_User ,int count_Computer){
     if(count_User == count_Computer)
         cout << "Ties!\n";
     else if(count_User < count_Computer)
         cout << "User WinS!\n";
     else
         cout << "Computer Wins!\n";

}

int main(void){
    
    
    int input,guess, count_User =0, count_Computer =0;
   
    guess = randomNum();
    
    
    cout << "Welcome to guessing game human vs computer'!\n";
    
    cout << "Guess? number 1 to 99: ";
    cin >> input;
    
    count_User =  human(guess,input,count_User);
    
    cout<<"That's correct\n";
    cout<<"Let us now change the roles.\n";
    
    guess = randomNum();
    
    count_Computer = computer(guess,count_Computer );
                  
    cout << "I've tried : " << count_Computer<<"\n";
    human_Comp(count_User, count_Computer);
    cout << "Score human vs computer: " << count_User <<" : " << count_Computer <<".\n";
   
    return 0;
}


sfs-wifi-dhcp-132-216:hw5 Elvyn$ ./hv
Welcome to guessing game human vs computer'!
Guess? number 1 to 99: 99
Too Big!
Guess? number 1 to 99: 50
Too Big!
Guess? number 1 to 99: 25
Too Small!
Guess? number 1 to 99: 34
Too Small!
Guess? number 1 to 99: 35
Too Small!
Guess? number 1 to 99: 35
Too Small!
Guess? number 1 to 99: 36
Too Small!
Guess? number 1 to 99: 37
Too Small!
Guess? number 1 to 99: 50
Too Big!
Guess? number 1 to 99: 38
Too Small!
Guess? number 1 to 99: 39
Too Small!
Guess? number 1 to 99: 37
Too Small!
Guess? number 1 to 99: 36
Too Small!
Guess? number 1 to 99: 45
Correct!
That's correct
Let us now change the roles.
The guess from computer: 60
Is it correct press '>','<',or '=': 
>
The guess from computer: 86
Is it correct press '>','<',or '=': 
>
The guess from computer: 99
Is it correct press '>','<',or '=': 
=
I found it!
I've tried : 3
Computer Wins!
Score human vs computer: 14 : 3.
sfs-wifi-dhcp-132-216:hw5 Elvyn$ 