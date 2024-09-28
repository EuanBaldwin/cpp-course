// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Quark class, derived from Particle
// Defines the Quark class with specific properties such as flavour and baryon number
// Last updated: 08/05/2024

#ifndef QUARK_H
#define QUARK_H

#include "../particle.h"

// Enum to represent quark flavours
enum class Quark_flavour { Up, Down, Charm, Strange, Top, Bottom, Unknown }; 

class Quark : public Particle, public Colour_charge
{
protected:
  double baryon_number;
  Quark_flavour flavour;
  Colour_list colour;

public:
  // Constructor
  Quark(double E, double px, double py, double pz, bool antiparticle = false,
    Quark_flavour flv = Quark_flavour::Unknown, Colour_list col = Colour_list::Unknown, double baryon_num = 1.0/3);
  virtual ~Quark() = default;

  // Getters
  int get_baryon_number() const { return baryon_number; }
  std::string get_name() const;

  // Function to set quark charge
  static double set_charge(Quark_flavour flv, bool antiparticle);

  // Validates consistent charge and baryon number in quark decays
  void validate_decay_products();

  // Utility functions for data printing 
  std::string enum_to_string(Quark_flavour flv) const;
  void print_baryon_number() const;
  void print_data() const;
};

#endif
