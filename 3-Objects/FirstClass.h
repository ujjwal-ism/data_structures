//
// Created by jesse hartloff on 9/7/15.
//

#ifndef CSE250_FALL2015_FIRSTCLASS_H
#define CSE250_FALL2015_FIRSTCLASS_H

class FirstClass{

private:
    int size; // no convention used
//    int mSize; // Various conventions for member variables
//    int m_size;
//    int _size;

public:
    FirstClass();
    FirstClass(int n);
    int getSize();
    void setSize(int); // don't need to name variables

};

#endif //CSE250_FALL2015_FIRSTCLASS_H
