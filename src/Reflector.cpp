#include "Reflector.h"

#include <vector>

using namespace std;

namespace enigma {

    Reflector::Reflector(ReflectorType type) {

        vector<char> permutations;

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

        for (int i = 0; i < 26; ++i)
            ring.insert({'A' + i, permutations[i]});
    }

    char Reflector::replace(char in) {
        return ring.at(in);
    }
}