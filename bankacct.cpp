#include "bankacct.h"

BankAcct::BankAcct(int a, int b): account_number(a), pin(b), BSB("324-001"){}

string BankAcct::display() {
    string acctNo = BSB + "-" + std::to_string(account_number);
    cout << "Bank Acct No: " << acctNo << endl;
    cout << "PIN: " << std::to_string(pin) << endl << endl;
    return "I dont know why this is a string instead of a void function";
}

string BankAcct::show() {
    return to_string(account_number) + "\n" + to_string(pin);
}
