// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the particle properties class
// Provides interface to retrieve and initialise the masses of known particles
// Last updated: 08/05/2024

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "../common_includes.h"

class Particle_properties
{
public:
  // Map to store particle names and their corresponding masses in GeV/c^2
  static std::map<std::string, double> particle_masses;

  // Initialises the mass values for various fundamental particles
  static void initialise_masses();

  // Returns the mass of a particle given its name
  static double get_mass(const std::string& particle_name);
};

#endif
