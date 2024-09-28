// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Tau class, derived from Lepton
// Defines tau-specific printing, including decay products
// Last updated: 08/05/2024

#ifndef TAU_H
#define TAU_H

#include "../lepton.h"

class Tau : public Lepton 
{
public:
  // Constructor
  Tau(double E, double px, double py, double pz, bool antiparticle = false);

  // Getters
  Lepton_flavour get_flavour() const override { return Lepton_flavour::Tau; }
  int get_tau_number() const override { return is_antiparticle ? -1 : 1; }

  // Overriding printing functions to include specific tau data
  void print_data() const override;
  std::string get_name() const override { return is_antiparticle ? "Anti-Tau" : "Tau"; }
};

#endif
