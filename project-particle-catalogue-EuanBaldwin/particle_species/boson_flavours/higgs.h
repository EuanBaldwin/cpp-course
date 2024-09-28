// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Higgs Boson class, derived from Boson
// Defines Higgs boson-specific printing, including decay products
// Last updated: 08/05/2024

#ifndef HIGGS_H
#define HIGGS_H

#include "../boson.cpp"

class Higgs : public Boson
{
public:
  // Constructor
  Higgs(double E, double px, double py, double pz);

  // Returns boson name
  std::string get_name() const override { return "Higgs Boson"; }
  
  // Prints data specific to higgs bosons, including decay products
  void print_data() const;
};

#endif
