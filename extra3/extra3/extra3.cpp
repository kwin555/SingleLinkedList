#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <array>

using namespace std;

class arrayStack {
private:
    int *array;
    int currentIndex = 0;
    int size;
    
public:
    // by default array is going to have 10 int elements
    arrayStack();
    arrayStack(int initialSize);
    ~arrayStack();
    bool isFull();
    bool isEmpty();
    int getSize();
    void resize(int newSize);
    void addElement(int element);
    void removeElement();
    void removeAll();
    void print();
};

int main() {
    arrayStack array = arrayStack(5);
    array.addElement(4);
    array.addElement(5);
    array.addElement(6);
    array.addElement(8);
    array.addElement(10);
    array.print();
    array.removeAll();
    array.print();
    return 0;
}
//constructor that sets the size of the array
arrayStack::arrayStack(int initialSize) {
    size = initialSize;
    array = new int[initialSize];
    //initializes all elements to zero in the array
    for (int i = 0; i < size; i++) {
        array[i]= -1;
    }
}
// destructor that deletes the array
arrayStack::~arrayStack() {
    delete[] array;
}

bool arrayStack::isFull() {
    return (size == currentIndex) ? true : false;
}

bool arrayStack::isEmpty() {
    return (array[currentIndex] == -1 && currentIndex == 0) ? true : false;
}
// add the element to the index and puts the value there too
void arrayStack::addElement(int value) {
    if (isFull()) {
        cout << "please remove an element, the arraystack is full" << endl;
    } else {
        array[currentIndex] = value;
        currentIndex++;
    }
    
}

void arrayStack::removeElement() {
    if (isEmpty()) {
        cout << "empty list, please add elements to the list" << endl;
    } else if (currentIndex == 0 && array[currentIndex] != -1) {
        array[currentIndex] = -1;
        currentIndex = 0;
        cout << "emement has been removed" << endl;
    } else {
        currentIndex--;
        cout << "element has been removed" << endl;
    }
}

// gets the size of the array
int arrayStack::getSize() {
    return currentIndex;
}
// reize
void arrayStack::resize(int newSize) {
    if (newSize > size) { // only allows you to resize an array if the new size is larger than old array
        int *temp; // temp points to integer value
        temp = new int [newSize]; //creates a new temp int array
        for(int i = 0; i < newSize; i++) {
            temp[i] = array[i]; //sets the elements of the old array to the new array
        }
        delete array; // deletes the array's old memory references
        array = temp; // points array to the new temp array memory location
        size = newSize; // sets the brand new size
    } else {
        cout << "make sure your new size is larger than the current size of the array" << endl;
    }
}

void arrayStack::removeAll() {
    for(int i = 0; i < size; i++) {
        array[i] = -1;
    }
    currentIndex = 0;
}

void arrayStack::print() {
    if(!isEmpty()) {
        for (int i = 0; i < currentIndex; i++) {
            cout << array[i] << " ";
        }
    } else {
        cout << "array is empty";
    }
    cout << endl;
}
