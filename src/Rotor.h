#ifndef ROTOR_H
#define ROTOR_H

#include "Type_fwd.h"

#include <map>

namespace enigma {

    /** Rotor */
    class Rotor {

        /** Notch and current setting */
        char notch, setting;

        /** Alphabet ring */
        std::map<char, char> ring;

    public:

        /**
         * Create a new rotor from the specified type
         * @param type Rotor's type
         * @param start_setting Rotor's starting setting
         */
        explicit Rotor(RotorType type, char start_setting = 'A');

        /**
         * Replace input letter by its corresponding output letter
         * @param in Input letter
         * @param backwards True if it input letter went through the reflector, false otherwise
         * @return Permutated input letter
         */
        char replace(char in, bool backwards = false);

        /**
         * Check if a turnover is going to occur in the next step
         * @return True if current setting is the notch, false otherwise
         */
        bool turnover();

        /**
         * Step the rotor, incrementing its current setting
         */
        void step();
    };
}

#endif
