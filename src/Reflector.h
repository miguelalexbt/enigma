#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "Type_fwd.h"

#include <map>

namespace enigma {

    /** Reflector */
    class Reflector {

        /** Alphabet ring */
        std::map<char, char> ring;

    public:

        /**
         * Create a new reflector from the specified type
         * @param type Reflector's type
         */
        explicit Reflector(ReflectorType type);

        /**
         * Replace input letter by its corresponding output letter
         * @param in Input letter
         * @return Permutated input letter
         */
        char replace(char in);
    };
}

#endif
