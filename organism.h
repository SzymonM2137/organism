#ifndef ORGANISM
#define ORGANISM

#include <iostream>

template <typename species_t, bool can_eat_meat, bool can_eat_plants> 
class Organism {
private:
    const species_t species;
    uint64_t vitality;
public:
    constexpr Organism(species_t const &species, uint64_t vitality) : 
             species(species), vitality(vitality){};

    uint64_t get_vitality() const {
        return vitality;
    }

    const species_t &get_species() {
        return species;
    }


};

template<typename species_t>
using Carnivore = Organism<species_t, true, false>;

template<typename species_t>
using Omnivore = Organism<species_t, true, true>;

template<typename species_t>
using Herbivore = Organism<species_t, false, true>;

template<typename species_t>
using Plant = Organism<species_t, false, false>;

template <typename species_t, bool sp1_eats_m, bool sp1_eats_p, bool sp2_eats_m, bool sp2_eats_p>
constexpr std::tuple<Organism<species_t, sp1_eats_m, sp1_eats_p>,
                     Organism<species_t, sp2_eats_m, sp2_eats_p>,
                     std::optional<Organism<species_t, sp1_eats_m, sp1_eats_p>>>
encounter(Organism<species_t, sp1_eats_m, sp1_eats_p> organism1,
          Organism<species_t, sp2_eats_m, sp2_eats_p> organism2);

#endif 