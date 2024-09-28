// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Z Boson class, derived from Boson
// Defines Z boson-specific printing, including decay products
// Last updated: 08/05/2024

#ifndef Z_BOSON_H
#define Z_BOSON_H

#include "../boson.cpp"

class Z_Boson : public Boson
{
public:
  // Constructor
  Z_Boson(double E, double px, double py, double pz);

  // Returns boson name
  std::string get_name() const override { return "Z Boson"; }

  // Prints data specific to Z bosons, including decay products
  void print_data() const;
};

#endif
