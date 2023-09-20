#include "logger.h"

int main(void) {
    Logger logger_1 = Logger();
    Logger logger_2 = Logger();
    logger_1 = logger_2;
    logger_1 = (Logger &&) logger_2;
    return 0;
}
