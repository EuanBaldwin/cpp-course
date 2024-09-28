// Particle Catalogue - Euan Baldwin - PHYS30762
// Boson abstract class, derived from Particle
// Contains methods to manage boson properties
// Last updated: 08/05/2024

#ifndef BOSON_CPP
#define BOSON_CPP

#include "../particle.h"

class Boson : public Particle
{
protected:

public:
  // Constructor
  Boson(const std::string& name, double E, double px, double py, double pz, bool antiparticle = false, double charge_value = 0, double spin_value = 1)
    : Particle(name, E, px, py, pz, antiparticle, charge_value, spin_value) {}
  virtual ~Boson() = default;

  // Utility functions for data printing 
  virtual std::string get_name() const = 0;
  virtual void print_data() const = 0;
};

#endif
