#include "enigma_m3.hpp"
using namespace enigma;

#include <iostream>

int main() {

    enigma_m3 enigma {{ rotor{ rotor::ROTOR_I }, rotor{ rotor::ROTOR_I }, rotor{ rotor::ROTOR_I }} };
    enigma.set_plugboard({{'y', 'k'}, {'k', 'y'}, {'a', 'b'}, {'u', 'e'}});

    std::cout << enigma.encode("Hello world") << std::endl;

    return 0;
}