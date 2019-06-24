#include "Enigma.h"

#include <string>
#include <iostream>

using namespace std;

namespace enigma {

    Enigma &Enigma::instance() {
        static Enigma instance;
        return instance;
    }

    Enigma::Enigma() : reflector(REFLECTOR_B) {

        /*
         * - Default settings:
         * Rotor order: III, II, I
         * Starting positions: A, A, A
         * Reflector: B
         * Plugboard: each letter to itself
        */

        rotors = {
                Rotor(ROTOR_III),
                Rotor(ROTOR_II),
                Rotor(ROTOR_I)
        };

        for (int i = 0; i < 26; ++i)
            plugboard.insert({'A' + i, 'A' + i});
    }

    void Enigma::set_rotors(const vector<RotorType> &r, const vector<char> &p) {

        if (r.size() != 3)
            throw invalid_argument("must select 3 rotors");
        else if (p.size() != 3)
            throw invalid_argument("must select 3 starting positions");

        for (int i = 0; i < r.size(); ++i) {

            // Check for duplicate rotors
            for (int j = i + 1; j < r.size(); ++j) {
                if (r[i] == r[j])
                    throw invalid_argument("rotors must be different");
            }

            // Check for invalid starting positions
            if ((p[i] < 'a' || p[i] > 'z') && (p[i] < 'A' || p[i] > 'Z'))
                throw invalid_argument("starting positions must range from A to Z (or a to z)");

            rotors[i] = Rotor(r[i], toupper(p[i]));
        }
    }

    void Enigma::set_reflector(ReflectorType type) {
        reflector = Reflector(type);
    }

    void Enigma::set_plugboard(char in, char out) {

        // Correct previous connected letter
        plugboard[plugboard[in]] = plugboard[in];
        plugboard[plugboard[out]] = plugboard[out];

        // Connect two letters
        plugboard[in] = out;
        plugboard[out] = in;
    }

    void Enigma::encode() {

        cout << "Enter string to encode: ";

        string in, out;
        getline(cin, in);

        for (auto c : in) {

            // Ignore non alphabetic characters
            if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
                continue;

            c = toupper(c);

            // Turnovers
            bool turnover1 = rotors[0].turnover(), turnover2 = rotors[1].turnover();

            // The first rotor always steps
            rotors[0].step();

            // The second and third rotor steps if there's a turnover at the second rotor
            if (turnover2) {
                rotors[1].step();
                rotors[2].step();
            }
            // The second rotor steps if there's a turnover at the first rotor
            else if (turnover1) {
                rotors[1].step();
            }

            // Plugboard in
            c = plugboard.at(c);

            // First pass
            for (auto it = rotors.begin(); it != rotors.end(); ++it) {
                c = it->replace(c);
            }

            // Reflector
            c = reflector.replace(c);

            // Second pass
            for (auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
                c = it->replace(c, true);
            }

            // Plugboard out
            c = plugboard.at(c);

            out += c;
        }

        cout << "Encoded string: " << endl << out << endl;
    }
}