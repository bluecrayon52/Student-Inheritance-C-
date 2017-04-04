// Project: C++ with STL
// CSC 261-02 Spring 2017
// HAVE ABIDED BY THE UNCG Academic Integrity Policy ON THIS ASSIGNMENT
// Nathaniel Clay Arnold

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm> 
#include <vector> 
#include <iterator>
#include <list>
#include <algorithm> 

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
            
       /* // loop through myName string and assign to nam char array
           for( int i = 0; i < myName.length() && i < 21; i++){
                name[i] = myName.at(i);
           }
            
        // null termination char
            name[20] = '\0'; */
            
        // or try this way
           strcpy(name, myName.c_str());
            
       /* // loop through mySsn string and assing to ssn char array
            for( int i = 0; i < 10 && i< mySsn.length(); i++){
                ssn[i] = mySsn.at(i);
            }
            
        // null termination char
            ssn[9] = '\0';*/
            
        // or try this way
          strcpy(ssn, mySsn.c_str());
            
        }
    
        // virtual function, print all data members in nice format
        virtual void print() const{
            
            cout<<left<<setw(20)<<name<<" "
                <<left<<setw(10)<<ssn<<" "
                <<left<<setw(10)<<credits<<" "
                <<right<<setw(10)<<gpa<<endl;
        }
    
        // pure virtual function
        virtual float tuition() const = 0;
    
};


class Grad : public Student{
    
    protected:
    
        float grad_rate;
        char* thesis;
    
    public:
    
        //constructor
        Grad(string const &myName, string const &mySsn,float const &myGpa, int const &myCredits,
             float const &myGrt, string const &myThesis) : Student(myName, mySsn, myGpa, myCredits){
             
            grad_rate = myGrt;
            thesis = new char[myThesis.size()];
            strcpy(thesis,myThesis.c_str());
        
        }
    
        char* get_thesis(){
            return thesis;
        }
    
        float get_rate(){
            return grad_rate;
        }
    
        void set_thesis(string const &myThesis){
            thesis = new char[myThesis.size()];
            strcpy(thesis,myThesis.c_str());
        }
    
        void print(){
            
            cout<<left<<setw(20)<<name<<" "
                <<setw(10)<<ssn
                <<setw(10)<<" Graduate   "
                <<setw(10)<<credits<<" "
                <<right<<setw(10)<<"$"<<fixed<<setprecision(2)<<tuition()<<" "
                <<setw(10)<<setprecision(2)<<gpa<<endl;
            cout<<endl;
            cout<<"   Thesis: "<<thesis<<endl;
            cout<<endl;
        
        }
    
        // calculate the tuition based on tuition rate up to a full time cap
        float tuition() const{
        
            float tuition = 0;
            
            int i = credits;
            
            if(i <= 11){
                tuition = grad_rate*i;
            }
            
            else tuition = grad_rate*12;
            
            return tuition;
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
             float const &myGrt, string const &myThesis, float const &myHrPay, string const &mySuper,
             string const &myTask) : Grad( myName, mySsn, myGpa, myCredits, myGrt, myThesis){
        
            hourPay = myHrPay;
            
            superviser = new char[mySuper.size()];
            strcpy(superviser,mySuper.c_str());
            
            task = new char[myTask.size()];
            strcpy(task,myTask.c_str());
        
        
        }
    
        char* get_supervisor(){
            return superviser;
        
        }
    
        float get_hourPay(){
            return hourPay;
        }
    
        void set_supervisor (string const &mySuper){
            superviser = new char[mySuper.size()];
            strcpy(superviser,mySuper.c_str());
        }
    
        void set_hourPay(float const &myHrPay){
            hourPay = myHrPay;
        
        }
    
        char* get_task(){
            return task;
        }
    
        void set_task(string const &myTask){
            task = new char[myTask.size()];
            strcpy(task,myTask.c_str());

        }
    
        void print(){
        
            cout<<left<<setw(20)<<name<<" "
                <<setw(10)<<ssn
                <<setw(10)<<" Assistant "
                <<setw(10)<<credits<<" "
                <<right<<setw(10)<<"$"<<fixed<<setprecision(2)<<tuition()<<" "
                <<setw(10)<<gpa<<endl;
            cout<<endl;
            cout<<"   Thesis: "<<thesis<<endl;
            cout<<endl;
            cout<<"   Task: "<<task<<endl;
            cout<<endl;
            cout<<"   Hourly Pay: $"<<fixed<<setprecision(2)<<hourPay<<endl;
            cout<<endl;
            cout<<"   Surpervisor: "<<superviser<<endl;
            cout<<endl;
    }
    
};


class Undergrad : Student{
    
    protected:
    float undergrad_rate;
    char* year;
    
    public:
        // constructor
        Undergrad(string const &myName, string const &mySsn,float const &myGpa,int const &myCredits,
                  float const &myUrt, string const &myYear) : Student(myName, mySsn, myGpa, myCredits){
            
            undergrad_rate = myUrt;
            year = new char[myYear.size()];
            strcpy (year,myYear.c_str());
        }
    
        char* get_year(){
            return year;
        }
    
        float get_rate(){
            return undergrad_rate;
        }
    
        void set_year(char* myYear){
            year = myYear;
        }
    
    void print() {
        
        cout<<left<<setw(20)<<name<<" "
            <<setw(10)<<ssn<<" "
            <<setw(10)<<year<<" "
            <<setw(10)<<credits<<" "
            <<right<<setw(10)<<"$"<<fixed<<setprecision(2)<<tuition()<<" "
            <<setw(10)<<gpa<<endl;
        cout<<endl;
    }
    
   float tuition() const{
       
       float tuition = 0;
       
       int i = credits;
       
       if(i <= 11){
           tuition = undergrad_rate*i;
       }
       
       else tuition = undergrad_rate*12;
       
       return tuition;
    }
    
    // overloading < operator
    bool operator<(const Undergrad &rhs) const{ return gpa < rhs.gpa; }
    
};


int main() {
    
        cout<<left<<setw(20)<<"NAME"
            <<setw(10)<<"SSN"
            <<setw(10)<<"Year"
            <<setw(10)<<"Credits"
            <<right<<setw(20)<<"Tuition"
            <<right<<setw(10)<<"GPA"<<endl;
    
    // call print() and tuition() for three students using static and dynamic binding

    Undergrad Mary("Mary","000111222",4.0,12,380, "Junior");
    
    Mary.print();
    
    Grad David ("David", "111222333", 3.7, 9, 500, "How to learn data structures using C++/STL?");
    
    David.print();
    
    GradAsst Jason("Jason", "222333444", 3.9, 9, 500, "Design of efficient algorythms", 20, "Dr.Fu", "Grading 330 projects and implementing a data mining algorithm");
    
    Jason.print();
    
    // Scan (read) file, construct students one by one, check input data
    
    ifstream ifs("underGradRost.txt");
    
    string rosterToken((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    
    
    string studentToken; // to contain all student info
    
    string dataToken;   // to contain parsed sudent data
    
    string delimit1= "\n"; // seperates students
    
    string delimit2 = " "; // seperates info

    
    list<Undergrad> UnderRost;
    float uRate = 380;
    string tmpName = " ";         //1st
    string tmpSSN = " ";          //2nd
    char* tmpYear = nullptr;      //3rd
    int tmpCredits = 0;           //4th
    float tmpGPA = 0.0;           //5th
    
    size_t pos1 = 0;
    
    // loop through all students
    while ((pos1 = rosterToken.find(delimit1)) != string::npos){
        
        studentToken = rosterToken.substr(0, pos1);
        
        int count = 1;
        size_t pos = 0;
        
        // loop through all student data
        while ((pos = studentToken.find(delimit2)) != string::npos) {
           
            dataToken = studentToken.substr(0, pos);
        
            switch(count){
                    
                case 1: tmpName =dataToken;
                    break;
                    
                case 2: tmpSSN = dataToken;
                    break;
                    
                case 3: tmpYear = new char[dataToken.size()];
                    strcpy(tmpYear,dataToken.c_str());
                    break;
                    
                case 4: tmpCredits = atoi(dataToken.c_str());
                    break;
    
                }
            
            count++;
            studentToken.erase(0, pos + delimit2.length());
            
        }
        
        dataToken = studentToken.substr(0, pos);
        tmpGPA = stof(dataToken);
        
        // store students in a list container( one by one)
        UnderRost.push_back(Undergrad(tmpName, tmpSSN, tmpGPA, tmpCredits, uRate, tmpYear));
    
        rosterToken.erase(0, pos1 + delimit1.length());
        
}

    // remove last student from list and insert in front of list
    Undergrad tempUG = UnderRost.back();
    UnderRost.pop_back();
    UnderRost.push_front(tempUG);
    
    //  using list iterator, print all students in list onto screen
    cout<<endl;
    cout<<left<<setw(20)<<"NAME"
    <<setw(10)<<" SSN"
    <<setw(10)<<"  Year"
    <<setw(10)<<"   Credits"
    <<right<<setw(20)<<"Tuition"
    <<right<<setw(10)<<"GPA"<<endl;
    
    for (list<Undergrad>::iterator i = UnderRost.begin(); i != UnderRost.end(); i++){
        i->print();
    }
    
    // initialize a vector that contains the list data
    vector<Undergrad> v{UnderRost.begin(),UnderRost.end()};

    // sort students according to GPA using generic sort algorithm
    sort(v.begin(), v.end());
    
    // print all students in list onto screen again
    cout<<endl;
    cout<<left<<setw(20)<<"NAME"
    <<setw(10)<<" SSN"
    <<setw(10)<<"  Year"
    <<setw(10)<<"   Credits"
    <<right<<setw(20)<<"Tuition"
    <<right<<setw(10)<<"GPA"<<endl;
    
    for (vector<Undergrad>::iterator i = v.begin(); i != v.end(); i++){
        i->print();
    }

    
    return 0;
}






























