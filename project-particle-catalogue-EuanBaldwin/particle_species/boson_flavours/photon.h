// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Photon class, derived from Boson
// Defines photon specific-printing
// Last updated: 08/05/2024

#ifndef PHOTON_H
#define PHOTON_H

#include "../boson.cpp"

class Photon : public Boson
{
public:
  // Constructor
  Photon(double E, double px, double py, double pz);

  // Returns boson name
  std::string get_name() const override { return "Photon"; }

  // Prints data specific to photons
  void print_data() const;
};

#endif
