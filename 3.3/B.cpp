#include "logger.h"

int main(void) {
    Logger logger1;
    Logger logger2 = Logger(logger1);
    return 0;
}