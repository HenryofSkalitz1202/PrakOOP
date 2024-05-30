#include "Weed.hpp"

Weed::Weed() : many(1) {}

Weed::Weed(int n) : many(n) {}

Weed::Weed(const Weed &other) : many(other.many) {}

Weed::~Weed() {}

void Weed::step() {
    for (int i = 0; i < many; ++i) {
        std::cout << "kresek...";
    }
    std::cout << std::endl;
}
