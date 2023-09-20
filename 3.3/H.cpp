#include <chrono>
#include <iostream>
#include <string>

class TimerGuard {
   private:
    std::chrono::system_clock::time_point start;
    std::ostream& stream;
    std::string message;

   public:
    TimerGuard() : start(std::chrono::high_resolution_clock::now()), stream(std::cout), message("") {}
    TimerGuard(const std::string msg, std::ostream& strm)
        : start(std::chrono::high_resolution_clock::now()),
          stream(strm),
          message(msg) {}  // Use initializer list

    ~TimerGuard() {
        std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start;
        stream << message << diff1.count() << "\n";
    }
};

int main(void) {
    { TimerGuard timer("123", std::cout); }
    return 0;
}
