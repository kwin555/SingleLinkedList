//Kevin Nguyen
#include <iostream>
#include <fstream>
using namespace std;

class point {
    private:
    // private members that represent the x and y coordinate of a point 
        int x;
        int y;

    public:
    // public prototypes that list the functionallity of the class 
        point(int = 0, int = 0);
        ~point(){};
        void setall(int,int); // do All Tests through set functions 
        int getX();
        int getY(); // return y into a global variable 
        void print();
 };

int main () {
    point A;//default case
    point B(5);// default y case 
    point C(7,11);//use of constructor fully
    point D(-5,-7); //should set of if statement in setall 
    A.print(); //(0,0)
    B.print(); //(-5,0)
    C.print(); //(7,11)
    D.print(); //(0,0)
    // create an dynamic array of points 
    point *p;
    p = new point [7];
    // p[0].setall(12,14);// all three are excactly the same 
    // (*p).setall(12,14);
    // p->setall(12,14); // this is what we should use
    // p++; // move foward by one object, adding the size of object
    //cd extra on server extra cd  extra\extra1>
    for (int i = 0; i < 7; i++) {
        p->setall(12,14);
        p->print();

        p++;
    }

    
    return 0;
}
// contructor that sets the points to positive numbers only
point::point(int a, int b) {
    setall(a,b);
}


void point::setall(int a, int b) {
    //setall makes sure the pass values are postive 
    x = (a < 0) ? 0 : a; // if a is negative set x to 0 otherwise set x to a;
    y = (b < 0) ? 0 : b; // if b is negative set y to 0 otherwise set y to b;
}

int  point::getX() {
    //retrieves the x value of the point object
    return x;
}

int point::getY() {
    //retrieves the y value of the point object
    return y;
}

void point::print () {
    cout <<"("<< this->getX() << "," << this->getY() << ")" << endl;
}