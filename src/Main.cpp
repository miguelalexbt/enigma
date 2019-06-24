
#include "Enigma.h"

using namespace enigma;

int main() {

    // Settings
    Enigma::instance().set_rotors({ ROTOR_III, ROTOR_IV, ROTOR_I }, { 'V', 'D', 'A' });
    Enigma::instance().set_reflector(REFLECTOR_B);
    Enigma::instance().set_plugboard('A', 'B');

    // Encode/Decode message
    Enigma::instance().encode();

    return 0;
}