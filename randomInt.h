#ifndef RANDONINT_H
#define RANDONINT_H
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomInt {
    public:
        RandomInt();
        RandomInt(int a, int b);
        int operator()();
    private:
        int start;
        int end;
};

// Function Prototypes
int getRandomNum(int a, int b);

#endif


