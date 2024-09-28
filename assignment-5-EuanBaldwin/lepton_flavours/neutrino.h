// Assignment 5 - Euan Baldwin - PHYS30762
// Header file for the Neutrino class, derived from Lepton
// Manages neutrino-specific properties such as flavour and interaction status
// Last updated: 19/04/2024

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include "../lepton.cpp"

enum class Neutrino_flavour { Electron, Muon, Tau, Unknown}; // Enumerates neutrino flavours

class Neutrino : public Lepton 
{
private:
  Neutrino_flavour flavour;
  bool has_interacted;

public:
  // Constructor
  Neutrino(double E, double px, double py, double pz, bool antiparticle = false, 
    Neutrino_flavour flv = Neutrino_flavour::Unknown, bool interacted = false);

  // Setter functions
  void set_has_interacted(bool interacted) { has_interacted = interacted; }

  // Convert flavour enum to string
  std::string flavour_to_string() const;

  // Overriding printing functions to include specific neutrino data
  void print_data() const override;
  std::string get_name() const override;
};

#endif
