// Assignment 5 - Euan Baldwin - PHYS30762
// Header file for the Electron class, derived from Lepton 
// Manages electron-specific properties and behaviours
// Last updated: 19/04/2024

#ifndef ELECTRON_H
#define ELECTRON_H

#include "../lepton.cpp"

class Electron : public Lepton 
{
private:
  std::vector<double> energy_deposited; // Energies deposited in EM_1, EM_2, HAD_1, HAD_2
  std::default_random_engine generator; // Engine for random energy distribution
  std::uniform_real_distribution<double> distribution; // Uniform distribution for energy fractions

public:
  // Constructor
  Electron(double E, double px, double py, double pz, bool antiparticle = false);

  // Setter functions
  void set_energies() { distribute_energy(); }

  // Getter functions
  double get_em_1() const { return energy_deposited[0]; }
  double get_em_2() const { return energy_deposited[1]; }
  double get_had_1() const { return energy_deposited[2]; }
  double get_had_2() const { return energy_deposited[3]; }

  // Member functions
  void distribute_energy(); // Distributes energy among different detector components
  void print_energy_depositied() const; // Prints the energy deposited by the electron

  // Overriding printing functions to include specific electron data
  void print_data() const override;
  std::string get_name() const override { return is_antiparticle ? "Anti-Electron" : "Electron"; }
};

#endif
