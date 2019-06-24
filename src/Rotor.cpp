#include "Rotor.h"

#include <vector>
#include <iostream>

using namespace std;

namespace enigma {

    Rotor::Rotor(RotorType type, char start_setting) {

        vector<char> permutations;

        switch (type) {
            case ROTOR_I:
                permutations = {
                        'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O',
                        'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'
                };

                notch = 'Q';

                break;
            case ROTOR_II:
                permutations = {
                        'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W',
                        'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'
                };

                notch = 'E';

                break;
            case ROTOR_III:
                permutations = {
                        'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z',
                        'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'
                };

                notch = 'V';

                break;
            case ROTOR_IV:
                permutations = {
                        'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R',
                        'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'
                };

                notch = 'J';

                break;
            case ROTOR_V:
                permutations = {
                        'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N',
                        'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'
                };

                notch = 'Z';

                break;
        }

        for (int i = 0; i < 26; ++i)
            ring.insert({'A' + i, permutations[i]});

        setting = start_setting;
    }

    char Rotor::replace(char in, bool backwards) {

        char offset = in + (setting - 'A');

        if (offset > 'Z')
            offset -= 26;

        char value = 0;

        // Before reflector
        if (!backwards) {
            value = ring.at(offset) - (setting - 'A');
        }
        // After reflector
        else {
            for (auto &i : ring) {
                if (i.second == offset) {
                    value = i.first - (setting - 'A');
                    break;
                }
            }
        }

        if (value < 'A')
            value += 26;

        return value;
    }

    bool Rotor::turnover() {
        return setting == notch;
    }

    void Rotor::step() {
        if (++setting > 'Z')
            setting = 'A';
    }
}