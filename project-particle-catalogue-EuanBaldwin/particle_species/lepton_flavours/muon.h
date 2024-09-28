// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Muon class, derived from Lepton
// Defines muon-specific properties such as isolation status
// Last updated: 08/05/2024

#ifndef MUON_H
#define MUON_H

#include "../lepton.h"

class Muon : public Lepton 
{
private:
  bool is_isolated;

public:
  // Constructor
  Muon(double E, double px, double py, double pz, bool antiparticle = false, bool isolated = true);

  // Setter functions
  void set_isolated(bool isolated) { is_isolated = isolated; }

  // Getter functions
  Lepton_flavour get_flavour() const override { return Lepton_flavour::Muon; }
  int get_muon_number() const override { return is_antiparticle ? -1 : 1; }

  // Overriding printing functions to include specific muon data
  void print_data() const override;
  std::string get_name() const override { return is_antiparticle ? "Anti-Muon" : "Muon"; }
};

#endif
