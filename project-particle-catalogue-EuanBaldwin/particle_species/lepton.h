// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Lepton class, derived from Particle
// Defines the Lepton class with specific properties such as flavour and lepton number
// Last updated: 08/05/2024

#ifndef LEPTON_H
#define LEPTON_H

#include "../particle.h"

enum class Lepton_flavour { Electron, Muon, Tau, Unknown}; // Enumerates lepton flavours

class Lepton : public Particle
{
protected:
  int lepton_number;

public:
  // Constructor
  Lepton(const std::string& name, double E, double px, double py, double pz, 
    bool antiparticle = false, double charge_value = 0, double lepton_num = 1);
  virtual ~Lepton() = default;

  // Getters
  int get_lepton_number() const { return lepton_number; }
  virtual Lepton_flavour get_flavour() const = 0;
  int get_electron_number() const { return 0; }
  int get_muon_number() const { return 0; }
  int get_tau_number() const { return 0; }

  // Utility functions for data printing 
  virtual std::string get_name() const = 0;
  void print_lepton_number() const { std::cout<<std::setw(20)<<"Lepton number:"<<lepton_number<<std::endl; }
  virtual void print_data() const = 0;

  // Validates consistent charge, lepton number and lepton flavour in lepton decays
  void validate_decay_products();
};

#endif