# Enigma

### Description:
While browsing Youtube, I came across [this](https://www.youtube.com/watch?v=G2_Q9FoD-oQ) video. I thought it was interesting and decided to implement it as a fun side project. This is a simple implementation of an [Enigma M3 machine](https://en.wikipedia.org/wiki/Enigma_machine). It allows the user to choose the rotors (and its starting positions) and the reflector to be used by the machine. It also allows to add plugs to the plugboard (order matters here!).

### Example:
```cpp
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
    
    // Initialize the enigma machine (rotors' order is right to left)
    enigma_m3 e {{ rotor1, rotor2, rotor3 }, refl };
    
    // Set plugboard entries (order matters here!)
    e.set_plugboard({ {'a', 'b'}, {'d', 'c'} });

    // Encode/decode the message    
    std::cout << e.encode("Hello world") << std::endl;

    return 0;
}
```
### Rotors supported:
- Rotor I
- Rotor II
- Rotor III
- Rotor IV
- Rotor V

### Reflectors supported:
- Reflector B
- Reflector C

### Future work:
- Add more checks for set_plugboard() method (unique pairs, etc).
- Add more rotors (VI, VII and VIII).
- Add support to set the position of the alphabet ring in each rotor (also called ringstellung).
