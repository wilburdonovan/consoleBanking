#include "randomInt.h"
#include <iostream>

RandomInt::RandomInt():start(1000), end(9999){
    srand(time(0));
}

RandomInt::RandomInt(int a, int b):start(a), end(b) {
    srand(time(0));
}

int RandomInt::operator()() {
    return getRandomNum(start, end);
}

//Non-member functions
/*
 * @param a: lowest value integer obtainable
 * @param b: highest value integer obtainable
 * @return : integer value between a & b
 */
int getRandomNum(int a, int b) {
    return a + (rand() % (b - a + 1));
}

