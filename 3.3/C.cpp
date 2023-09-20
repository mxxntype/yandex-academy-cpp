#include "logger.h"

int main(void) {
    Logger logger1 = Logger();
    Logger logger2 = Logger((Logger &&) logger1);
    return 0;
}
