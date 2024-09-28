// Assignment 5 - Euan Baldwin - PHYS30762
// Header file for the Muon class, derived from Lepton
// Includes definitions for muon-specific properties
// Last updated: 19/04/2024

#ifndef MUON_H
#define MUON_H

#include "../lepton.cpp"

class Muon : public Lepton 
{
private:
  bool is_isolated;

public:
  // Constructor
  Muon(double E, double px, double py, double pz, bool antiparticle = false, bool isolated = true);

  // Setter functions
  void set_isolated(bool isolated) { is_isolated = isolated; }

  // Overriding printing functions to include specific muon data
  void print_data() const override;
  std::string get_name() const override { return is_antiparticle ? "Anti-Muon" : "Muon"; }
};

#endif
