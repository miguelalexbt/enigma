#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include "Reflector.h"

#include <vector>
#include <map>

namespace enigma {

    /** Enigma */
    class Enigma {

        /** Rotors */
        std::vector<Rotor> rotors;

        /** Reflector */
        Reflector reflector;

        /** Plugboard */
        std::map<char, char> plugboard;

        /**
         * Create a new Enigma machine
         */
        Enigma();

    public:

        /**
         * Instance of the machine
         * @return Instance
         */
        static Enigma &instance();

        /**
         * Set machine's rotors and its starting positions
         * @param r Rotors, in order
         * @param p Starting positions of each rotor, in order
         */
        void set_rotors(const std::vector<RotorType> &r, const std::vector<char> &p);

        /**
         * Set machine's reflector
         * @param type Reflector's type
         */
        void set_reflector(ReflectorType type);

        /**
         * Set an entry in the machine's plugboard
         * @param in Input letter
         * @param out Output letter
         */
        void set_plugboard(char in, char out);

        /**
         * Encode/Decode a message
         */
        void encode();
    };
}

#endif
