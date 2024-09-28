// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the W Boson class, derived from Boson
// Defines W boson-specific printing, including decay products
// Last updated: 08/05/2024

#ifndef W_BOSON_H
#define W_BOSON_H

#include "../boson.cpp"

class W_Boson : public Boson
{
public:
  // Constructor
  W_Boson(double E, double px, double py, double pz, bool antiparticle = false);

  // Returns boson name
  std::string get_name() const override { return is_antiparticle ? "W+ Boson" : "W- Boson"; }

  // Prints data specific to W bosons, including decay products
  void print_data() const;
};

#endif
