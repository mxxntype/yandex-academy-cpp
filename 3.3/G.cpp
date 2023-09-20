#include <cstddef>
#include <cstdlib>
#include <vector>

#include "logger.h"

int main(void) {
    size_t n = 0;
    std::cin >> n;

    Logger** list = reinterpret_cast<Logger**>(calloc(n, sizeof(Logger*)));

    for (size_t i = 0; i < n; i++) list[i] = new Logger();
    // for (size_t i = n; i > 0; i--) delete list[i - 1];
    for (size_t i = 0; i < n; i++) delete list[i];

    free(list);

    return 0;
}
