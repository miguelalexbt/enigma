#include <iostream>

#include "enigma_m3.hpp"
using namespace enigma; // for convenience

int main() {

    // Rotor IV, starting at 'A'
    rotor rotor1 { rotor::ROTOR_IV, 'A' };
    
    // Rotor I, starting at 'Q'
    rotor rotor2 { rotor::ROTOR_I, 'Q' };
    
    // Rotor III, starting at 'L'
    rotor rotor3 { rotor::ROTOR_III, 'L' };
    
    // Reflector C
    reflector refl { reflector::REFLECTOR_C };
    
    // Initialize the enigma machine
    enigma_m3 e {{ rotor1, rotor2, rotor3 }, refl };
    
    // Set plugboard entries (order matters here!)
    e.set_plugboard({ {'a', 'b'}, {'d', 'c'} });

    // Encode/decode the message    
    std::cout << e.encode("Hello world") << std::endl;

    return 0;
}