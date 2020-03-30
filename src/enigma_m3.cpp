#include "enigma_m3.hpp"

namespace enigma {

enigma_m3::enigma_m3(const std::array<rotor, 3>& rotors, const reflector& reflector)
    : rotors_ { rotors }, reflector_ { reflector }
{
    for (int i = 0; i < 26; ++i) {
        plugboard_.insert({'A' + i, 'A' + i});
    }
}

void enigma_m3::set_plugboard(const std::vector<plug_type>& in_out) {
    for (auto& entry : in_out) {
        char in = toupper(entry.first);
        char out = toupper(entry.second);

        if ((in < 'A' || in > 'Z') || (out < 'A' || out > 'Z'))
            throw std::invalid_argument("plugboard entries must range from a/A to z/Z.");

        // Correct previous connected letter
        plugboard_[plugboard_[in]] = plugboard_[in];
        plugboard_[plugboard_[out]] = plugboard_[out];

        // Connect two letters
        plugboard_[in] = out;
        plugboard_[out] = in;
    }
}

std::string enigma_m3::encode(const std::string& input) {
    std::string output;

    for (auto c : input) {
        
        c = toupper(c);

        // Ignore non alphabetic characters
        if (c < 'A' || c > 'Z')
            continue;

        // Turnovers
        bool turnover1 = rotors_[0].turnover(), turnover2 = rotors_[1].turnover();

        // The first rotor always steps
        rotors_[0].step();

        // The second and third rotor steps if there's a turnover at the second rotor
        if (turnover2) {
            rotors_[1].step();
            rotors_[2].step();
        }
        // The second rotor steps if there's a turnover at the first rotor
        else if (turnover1) {
            rotors_[1].step();
        }

        // Plugboard in
        c = plugboard_.at(c);

        // First pass
        for (auto it = rotors_.begin(); it != rotors_.end(); ++it) {
            c = it->replace(c);
        }

        // Reflector
        c = reflector_.replace(c);

        // Second pass (reverse)
        for (auto it = rotors_.rbegin(); it != rotors_.rend(); ++it) {
            c = it->replace(c, true);
        }

        // Plugboard out
        c = plugboard_.at(c);

        output += c;
    }

    return output;
}

}