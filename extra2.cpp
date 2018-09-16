#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;
class student {
    private: 
        char *name;
        double gradePoint;
    public:
        student(char *newname ="", double gpa = 0.0) { // creating newname to point to a char. 
            setName(newname);
            setGpa(gpa);
        }

        void setName(char *newName) {
            int length = strlen(newName);
            name = new char[length + 1];
            strcpy(name,newName);
        }
        void setGpa (double gpa) {
            gradePoint = gpa;
        }

        char* getName(){
            return name;
        }

        double getGpa() {
            return gradePoint;
        }
 
        ~student() {
            delete [] name; // if compiler has error comment out delete
        }
};

int main() {
    student s1("bob", 4.0); // creating a new instance of s1 with name as "bob" with a 4.0 GPA
    student *students = new student [100]; //creating a pointer to point to a memory location that holds 100
    //making every array memory location in p student value "shasta" and a gpa of 4.0
    for (int i = 0; i < 100; i++) {
        students->setName("Shasta");
        students->setGpa(4.0);
        students++; // incrementing by size of student object
    }
    students-=100; //returning the memory location back to the beginning
    // outputting the contents in the array 
    for (int i = 0; i < 100; i++) {
       cout << "The student's name is " << students->getName() << "\nThe student's Gpa is " 
       << students->getGpa() << "." << endl; 
        students++; // incrementing by size of student object
    }
    return 0;
}