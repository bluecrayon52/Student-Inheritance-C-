//
//
//
//
//  Created by Nathaniel Clay Arnold  on 3/23/17.
//  Copyright © 2017 Nathaniel Clay Arnold . All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;


class Student{
    
    // data members
    protected:
    
        char name[21];
        char ssn[10];
        float gpa;
        int credits;
    
    public:
    
        // constructor
        Student(string const &myName, string const &mySsn,float const &myGpa,int const &myCredits){
            
            gpa = myGpa;
            credits = myCredits;
            
        // loop through myName string and assign to nam char array
           for( int i = 0; i < myName.length() && i < 21; i++){
                name[i] = myName.at(i);
           }
            
        // null termination char
            name[20] = '\0';
            
        // or try this way
           // strcpy(name, myName.c_str());
            
        // loop through mySsn string and assing to ssn char array
            for( int i = 0; i < 10 && i< mySsn.length(); i++){
                ssn[i] = mySsn.at(i);
            }
            
        // null termination char
            ssn[9] = '\0';
            
        // or try this way
          // strcpy(ssn, mySsn.c_str());
            
        }
    
        // virtual function, print all data members in nice format
        virtual void print(){
        
        }
        // pure virtual function
        virtual float tuition()const = 0;
    
};


class Grad : public Student{
    
    protected:
    
        float grad_rate;
        char* thesis;
    
    public:
    
        //constructor
        Grad(string const &myName, string const &mySsn,float const &myGpa, int const &myCredits,
             float const &myGrt, char* const &myThesis) : Student(myName, mySsn, myGpa, myCredits){
             
            grad_rate = myGrt;
            thesis = myThesis;
        
        }
    
        char* get_thesis(){
            char* a;
            return a;
        }
    
        float get_rate(){
     
            return 0.0;
        }
    
        void set_thesis(char*){
        
        }
    
        void print(){
        
        }
    
        float tuition(){
        
        }
    
};


class GradAsst : public Grad{
    
    protected:
    
        float hourPay;
        char* superviser;
        char* task;
    
    public:
    
        // constructor
        GradAsst(string const &myName, string const &mySsn,float const &myGpa, int const &myCredits,
             float const &myGrt, char* const &myThesis, float const &myHrPay, char* const &mySuper,
             char* const &myTask) : Grad( myName, mySsn, myGpa, myCredits, myGrt, myThesis){
        
            hourPay = myHrPay;
            superviser = mySuper;
            task = myTask;
        
        }
    
        char* get_supervisor(){
            char* a;
            return a;
        
        }
    
        float get_hourPay(){
            return 0.0;
        }
    
        void set_supervisor(char*){
        
        }
    
        void set_hourPay(float){
        
        }
    
        char* get_task(){
            char* a;
            return a;
        }
    
        void set_task(char*){
        
        }
    
};


class Undergrad : Student{
    
        float undergrad_rate;
        char year;
    
        int main() {
        
        // call print() and tuition() for three students using static and dynamic binding
        
        // Scan (read) file, construct students one by one, check input data
        
        // store students in a list container( one by one)
        
        // remove last student from list and insert in front of list
        
        //  using list iterator, print all students in list onto screen
        
        // initialize a vector that contains the list data
        
        // sort students according to GPA using generic sort algorithm
        
        // print all students in list onto screen again
        
            return 0;
        }
    
        // constructor
        Undergrad(string const &myName, string const &mySsn,float const &myGpa,int const &myCredits,
                  float const &myUrt,  char* const &myYear) : Student(myName, mySsn, myGpa, myCredits){
        
        }
    
        char* get_year(){
            char* a;
            return a;
        }
    
        float get_rate(){
        
            return 0.0;
        }
    
        void set_year(char*){
        
        }
    
    void print(){
        
    }
    
    float tuition(){
        
    }
    
};






























