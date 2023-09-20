#include "logger.h"

int main(void) {
    Logger logger_1 = Logger();
    Logger* logger_2 = new Logger();
    Logger logger_3 = Logger();
    delete logger_2;
    return 0;
}
