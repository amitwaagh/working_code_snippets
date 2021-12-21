#include <cstdlib>
#include <iostream>
#include <string>

// replace operator new and delete to log allocations
void* operator new(std::size_t n) {
    std::cout << "[Allocating " << n << " bytes]";
    return malloc(n);
}
void operator delete(void* p) throw() {
    free(p);
}

int main() {
    for (size_t i = 0; i < 24; ++i) {
        std::cout << i << ": " << std::string(i, '=') << std::endl;
    }
}


#include <cstdlib>
#include <iostream>
#include <string>

// replace operator new and delete to log allocations
void* operator new(std::size_t n) {
    std::cout << "Allocating " << n << " bytes" << std::endl;
    return malloc(n);
}
void operator delete(void* p) throw() {
    free(p);
}

int main() {
    std::string s;
    for (size_t i = 0; i != 1000000; ++i) {
        s += '.';
    }
}
