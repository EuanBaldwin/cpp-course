// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Neutrino class, derived from Lepton
// Defines neutrino-specific properties such as flavour and interaction status
// Last updated: 08/05/2024

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include "../lepton.h"

class Neutrino : public Lepton 
{
private:
  Lepton_flavour flavour;
  bool has_interacted;

public:
  // Constructor
  Neutrino(double E, double px, double py, double pz, bool antiparticle, Lepton_flavour flv, bool interacted);

  // Getter functions
  Lepton_flavour get_flavour() const override { return flavour; }
  int get_electron_number() const override { return flavour == Lepton_flavour::Electron ? (is_antiparticle ? -1 : 1) : 0; }
  int get_muon_number() const override { return flavour == Lepton_flavour::Muon ? (is_antiparticle ? -1 : 1) : 0; }
  int get_tau_number() const override { return flavour == Lepton_flavour::Tau ? (is_antiparticle ? -1 : 1) : 0; }

  // Setter functions
  void set_has_interacted(bool interacted) { has_interacted = interacted; }

  // Convert flavour enum to string
  std::string enum_to_string(Lepton_flavour flv) const;

  // Overriding printing functions to include specific neutrino data
  void print_data() const override;
  std::string get_name() const override;
};

#endif
