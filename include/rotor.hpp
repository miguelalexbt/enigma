#pragma once

#include <map>

namespace enigma {

/**
 * Implementation of a rotor. Supports rotors I, II, III, IV and V.
 */
class rotor final {
public:
    /** Rotor's types */
    enum rotor_type {
        ROTOR_I, ROTOR_II, ROTOR_III, ROTOR_IV, ROTOR_V
    };

    /**
     * @brief Create a new rotor from the specified type, starting at the specified position.
     * @param type Rotor's type.
     * @param start_setting Rotor's starting position.
     */
    explicit rotor(const rotor_type type, const char start_position = 'A');

// protected:
    /**
     * @brief Replace input letter by its corresponding output letter.
     * @param in Input letter.
     * @param backwards True if the input letter went through the reflector, false otherwise.
     * @return Permutated input letter.
     */
    char replace(const char in, bool backwards = false) const;

    /**
     * @brief Check if a turnover is going to occur in the next step.
     * @return True if current position is the notch, false otherwise.
     */
    bool turnover() const;

    /**
     * @brief Step the rotor, incrementing its current position.
     */
    void step();

private:
    /** Notch and current position */
    char notch, position;

    /** Alphabet ring */
    std::map<char, char> ring;

    friend class enigma_m3;
};

} // namespace enigma