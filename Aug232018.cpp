//Kevin Nguyen
#include <iostream>
#include <fstream>
using namespace std;

class point {
    private:
        int x;
        int y;

    public:
        point(int = 0, int = 0);
        ~point(){};
        void setall(int,int); // do All Tests through set functions 
        int getx();
        void gety(int&); // return y into a global variable 
        void print();
 };

int main () {
    point A;
    point B(-5);
    point C(7,11);

    // create an dynamic array of points 
    point *p;
    p = new point [7];
    p[0].setall(12,14);// all three are excactly the same 
    (*p).setall(12,14);
    p->setall(12,14); // this is what we should use
    p++; // move foward by one object, adding the size of object
    //cd extra on server extra cd  extra\extra1>
    return 0;
}

point::point(int a, int b) {
    setall(a,b);
}

void point::setall(int a, int b) {
    x = (a < 0) ? 0 : b; // if a is negative set x to 0 otherwise set x to a;
    y = (b < 0) ? 0 : b; // if b is negative set y to 0 otherwise set y to b;
}