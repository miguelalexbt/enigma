#pragma once

#include <map>
#include <string>
#include <vector>

#include "rotor.hpp"
#include "reflector.hpp"

namespace enigma {

/**
 * Implementation of an Enigma M3.
 */
class enigma_m3 final {
public:
    using rotor_type = rotor::rotor_type;
    using reflector_type = reflector::reflector_type;
    using plug_type = std::pair<char, char>;

    /**
     * @brief Set machine's rotors and reflector.
     * @param rotors Rotors to be used, in order.
     * @param reflector Reflector to be used.
     */
    explicit enigma_m3(
        const std::array<rotor, 3>& rotors = {{ rotor{ rotor_type::ROTOR_I }, rotor{ rotor_type::ROTOR_II }, rotor{ rotor_type::ROTOR_III } }},
        const reflector& reflector = reflector{ reflector_type::REFLECTOR_C }
    );

    /**
     * @brief Set an entry in the machine's plugboard. The order of the entries matter (one might overwrite another).
     * @param in_out Pair of input and output letter.
     */
    void set_plugboard(const std::vector<plug_type>& in_out);

    /**
     * @brief Encode/Decode a message.
     * @param input String to be encoded/decoded.
     * @return Encoded/Decoded string.
     */
    std::string encode(const std::string& input);

private:
    /** Rotors */
    std::array<rotor, 3> rotors_;

    /** Reflector */
    reflector reflector_;

    /** Plugboard */
    std::map<char, char> plugboard_;
};

} // namespace enigma