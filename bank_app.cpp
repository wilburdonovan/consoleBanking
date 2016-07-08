#include <iostream>
#include "randomInt.h"
#include "serial.h"
#include "bankacct.h"
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

//Prototypes
void addAccounts (vector<BankAcct> &currentAccts);
void showCurrentAccounts (string filename);
void writeToFile(string message);
void addAccountsWithExceptionHandling (vector<BankAcct> &currentAccts);


class BankError : public std::logic_error {
public:
    BankError(string x);
    string what();
private:
    string reason;
};

BankError::BankError(string x) : logic_error(x), reason(x){}

string BankError::what() {
    return reason;
}

int main () {

    vector<BankAcct> allAccounts;

    showCurrentAccounts("bank_account.txt");

    addAccountsWithExceptionHandling(allAccounts);

    return 0;
}


/* Create new accounts and save to the system
 * @param currentAccts: A vector of Bank Accounts
 */
void addAccounts (vector<BankAcct> &currentAccts) {
    bool repeat = true;

    while (repeat) {
        int sequence = 0;
        int beginAcct = 0;
        RandomInt randomPin;

        cout << "\nEnter the number of bank accounts (<10), 0 to quit" << endl;
        cin >> sequence;

        if (sequence == 0) {
            repeat = false;
            break;
        }
        if (sequence > 9) {
            throw BankError("Too many accounts. You requested " + to_string(sequence) + " accounts.");
        }

        cout << "Enter the start value of account number" << endl;
        cin >> beginAcct;

        Serial acctNumber{beginAcct-1};

        for (signed int i = 0; i < sequence; i++) {
            BankAcct newAcct(acctNumber(), randomPin());
            newAcct.display();
            writeToFile(newAcct.show());
            currentAccts.push_back(newAcct);
        }

    }

}// End of addAccounts()

/* Shows the accounts currently stored
 * @param filename: Name of text file information is stored on
 */
void showCurrentAccounts (string filename) {
    fstream inputfile;
    string fileValue;
    int linesInFile = 0;

    inputfile.open(filename);

    if (inputfile.fail()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    cout << "Current Accounts Stored:" << endl;

    while(getline(inputfile, fileValue)){
        cout << fileValue << endl;
        linesInFile++;
    }

    if(linesInFile == 1 || linesInFile == 0) {
        cout << "      " << filename << " is currently empty. There are no stored accounts." << endl;
    }

    inputfile.close();
} //End of showCurrentAccounts()


/* Write a message to "bankUSQ_account.txt"
 * @param message: A string that you want written to bankUSQ_account.txt
 */
void writeToFile(string message) {
    fstream outfile;

    outfile.open("bank_account.txt", fstream::app);

    if (outfile.is_open()) {
        outfile << message << endl << endl;
    }

    outfile.close();
} //End of writeToFile()


/* Creates new accounts, stores new accounts, uss exception handling from creating too many accounts at once
 * @param currentAccts: A vector of bank accounts
 */
void addAccountsWithExceptionHandling (vector<BankAcct> &currentAccts) {
    char repeat;

    try {
        addAccounts(currentAccts);
    } catch (BankError &e) {
         cout << "Bank Error Occured" << endl << e.what() << " Retry? (y/n)" << endl;
         cin >> repeat;

         if (repeat == 'y') {
            addAccountsWithExceptionHandling(currentAccts);
         } else {
            cout << "Thank You for using Bank";
         }
    }
}
