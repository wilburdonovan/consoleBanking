#ifndef BANKACCT_H
#define BANKACCT_H

#include <iostream>
#include <string>
#include "bankacct.h"
#include "serial.h"
#include "randomInt.h"
#include <sstream>

using namespace std;

class BankAcct {
    public:
        BankAcct(int a, int b);
        string display();
        string show();
    private:
        int account_number;
        int pin;
        string BSB;
};

#endif
