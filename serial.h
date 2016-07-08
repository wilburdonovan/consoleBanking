#ifndef SERIAL_H
#define SERIAL_H
#include <iostream>

using namespace std;

class Serial {
    public:
        Serial(int a);
        int operator()();
    private:
        int serial_number;
};

#endif

