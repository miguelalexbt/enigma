#pragma once

#include <map>

namespace enigma {

/**
 * Implementation of a reflector. Supports reflectors B and C.
 */
class reflector final {
public:
    /** Reflector's types */
    enum reflector_type {
        REFLECTOR_B, REFLECTOR_C
    };

    /**
     * @brief Create a new reflector from the specified type.
     * @param type Reflector's type.
     */
    explicit reflector(const reflector_type type);

protected:
    /**
     * @brief Replace input letter by its corresponding output letter.
     * @param in Input letter.
     * @return Permutated input letter.
     */
    char replace(const char in) const;

private:
    /** Alphabet ring */
    std::map<char, char> ring;

    friend class enigma_m3;
};

}