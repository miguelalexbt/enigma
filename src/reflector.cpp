#include "reflector.hpp"

namespace enigma {

reflector::reflector(const reflector_type type) {
    std::array<char, 26> permutations;

    switch (type) {
        case REFLECTOR_B:
            permutations = {
                    'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O',
                    'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T'
            };
            break;
        case REFLECTOR_C:
            permutations = {
                    'F', 'V', 'P', 'J', 'I', 'A', 'O', 'Y', 'E', 'D', 'R', 'Z', 'X',
                    'W', 'G', 'C', 'T', 'K', 'U', 'Q', 'S', 'B', 'N', 'M', 'H', 'L'
            };
            break;
    }

    for (int i = 0; i < 26; ++i) {
        ring.insert({'A' + i, permutations[i]});
    }
}

char reflector::replace(const char in) const {
    return ring.at(in);
}

} // namespace enigma