1.
/************************************************************\
|  Program:  studentClass.cpp                                |
|  Problem:  1. Create the class student that includes the 
|            following information about student: name, age
|             and gpa.Write the following members functions:
|            (a) Constructor that creates objects of the
|             student class.
|            (b) read that prompts the user to enter from the
|            keyboard student name, age and gpa.
|            To terminate reading the user should enter the
|            EOF (ctrl-D in Unix and Ctrl-Z in
|            DOS).
|            (c) show that displays on the screen student
|            name, age and gpa.
|           (d) writefile that writes a record
|           (name, age, gpa) into the file student.dat.
|           (e) getgpa that returns gpa of the student.
|           (f) readfile that reads the student record from
|           the file student.dat .
|           Write a main program that demonstrates the work
|           with this class. Declare all necessary objects
|           and variables. Using read and writefile create
|           the student.dat. After closing the file student.
|           dat reopen it for reading. Read and display all
|           students from the file and compute and display
|           the average gpa for all of them.
|
|  Purpose:  Use of classes and fstream                      |
|  Author :  Elvyn Mejia                                     |
|  Date   :  11/14/2013                                      |
\************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define w setw
using namespace std;

class student
{
    //Define data that describes the object-student(e.g. name, age, gpa)
    private:
        string name;
        int age;
        double gpa;
    //define all the following member functions
    
    public:
        //(a) Constructor that creates objects of the student class.
        //constructor and initializer
        student()
        {
            string name = "";
            age = 0;
            gpa = 0.0;
        
        }
    
        student(string stdName, int stdAge, double stdGpa)
        {
            name =stdName;
            age = stdAge;
            gpa= stdGpa;
        }
    
        //FUNCTION PROTOTYPE
        //This technique is convenient for any (large) function
        int read(void);
        void show(void);
        void writefile(ofstream &);
        double getgpa(void);
        int readfile(ifstream &);
}; //this list might be empty 
    

     /*
        (b) read that prompts the user to enter from the
            keyboard student name, age and gpa.
            To terminate reading the user should enter the
            EOF (ctrl-D in Unix and Ctrl-Z in
            DOS).
    */
    int student::read()
    {
        
        cout<<"When you are done entering student information enter ctrl-D or Ctrl-Z.\n";
        cin>> name >> age >> gpa;
        return !(cin.eof());
    }

    //(c) show that displays on the screen student name, age and gpa.
    void student::show()
    {
        //cout<<"Displaying student name, age and gpa that you entered from the console.\n";
        cout<<"Name "<< name <<w(4)<<" Age "<<age<<w(4)<<" Gpa "<<gpa <<".\n";
    
    }

    //(d) writefile that writes a record (name, age, gpa) into the file student.dat.
    void student::writefile(ofstream& OS)
    {
        OS<<w(5)<<name<<w(5)<<age<<w(5)<<gpa<<endl;
    }

    //(e) getgpa that returns gpa of the student.
    double student::getgpa()
    {
        return gpa;
    }

    //(f) readfile that reads the student record from the file student.dat.
    int student::readfile(ifstream& IS)
    {
        IS>>name>>age>>gpa;
        
        return !(IS.eof());
    
    
    }

/*
    Write a main program that demonstrates the work
    with this class. Declare all necessary objects
    and variables. Using read and writefile create
    the student.dat. After closing the file student.dat
    reopen it for reading. Read and display all
    students from the file and compute and display
    the average gpa for all of them.
*/

int main()
{
    student stdRecords;
    int counter=0; double avgGPA=0.0;
    char writefile[]="student.txt";
    
    //Standard stream declare + open, ios::in —use to read from file 
    ifstream IS("student.txt", ios::in);
    //Standard stream declare + open, ios::out —use to write to file 
    ofstream OS("student.txt", ios::out);
    
    //call read() to read student records from keyboard
    cout<<"Please enter student name, age and gpa(e.g. Elvyn 24 3.50).\n";
    while(stdRecords.read())
    {
        stdRecords.writefile(OS);
        counter++;
    }
    cout<<"Displaying student name, age and gpa that you entered from the console.\n";
    while(stdRecords.readfile(IS))
    {
        avgGPA +=stdRecords.getgpa();
        stdRecords.show();
    }
    
    OS.close();
    IS.close();
    avgGPA /=counter;
    
    cout<<"The average GPA for all students is " << avgGPA<<"\n.";


return 0;
}


.sfs-wifi-dhcp-133-54:hw6 Elvyn$ g++ studentClass.cpp -o sc
sfs-wifi-dhcp-133-54:hw6 Elvyn$ ./sc
Please enter student name, age and gpa(e.g. Elvyn 24 3.50).
When you are done entering student information enter ctrl-D or Ctrl-Z.
Henry
23
3.4
When you are done entering student information enter ctrl-D or Ctrl-Z.
Elvyn
3.5
When you are done entering student information enter ctrl-D or Ctrl-Z.
Mirian
4.00
When you are done entering student information enter ctrl-D or Ctrl-Z.
Juan
23 
3.4
When you are done entering student information enter ctrl-D or Ctrl-Z.
Kevin
21 
3.00
When you are done entering student information enter ctrl-D or Ctrl-Z.
Julita
23
3.75
When you are done entering student information enter ctrl-D or Ctrl-Z.
Displaying student name, age and gpa that you entered from the console.
Name Henry Age 23 Gpa 3.4.
Name Elvyn Age 3 Gpa 0.5.
Name Mirian Age 4 Gpa 0.
Name Juan Age 23 Gpa 3.4.
Name Kevin Age 21 Gpa 3.
Name Julita Age 23 Gpa 3.75.
The average GPA for all students is 2.34167
.sfs-wifi-dhcp-133-54:hw6 Elvyn$ 




