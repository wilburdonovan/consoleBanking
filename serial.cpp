#include "serial.h"

Serial::Serial(int a): serial_number(a) {}

int Serial::operator()() {
    serial_number++;
    return serial_number;
}



