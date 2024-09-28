// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the four momentum class
// Defines the interface for managing and validating four-momentum vectors of particles
// Last updated: 10/05/2024

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include "../common_includes.h"
#include "Particle_properties.h"

class Four_momentum 
{
private:
  std::vector<double> momentum; // Stores the [E, px, py, pz] components of four-momentum
  std::string name;             // The name associated with the particle
  static bool debug_mode;       // Toggle for verbose debug mode

public:
  Four_momentum();                                                                   // Default constructor
  Four_momentum(const std::string& name, double E, double px, double py, double pz); // Parameterised constructor
  Four_momentum(const Four_momentum& other);                                         // Copy constructor
  Four_momentum& operator=(const Four_momentum& other);                              // Assignment operator
  ~Four_momentum();                                                                  // Destructor
  Four_momentum(Four_momentum&& other) noexcept;                                     // Move Constructor
  Four_momentum& operator=(Four_momentum&& other) noexcept;                          // Move Assignment Operator

  // Setter functions
  static void set_debug_mode(bool mode) { debug_mode = mode; }
  void setE(double E);
  void setpx(double px) { momentum[1] = px; }
  void setpy(double py) { momentum[2] = py; }
  void setpz(double pz) { momentum[3] = pz; }

  // Getter functions
  double getE() const { return momentum[0]; }
  double getpx() const { return momentum[1]; }
  double getpy() const { return momentum[2]; }
  double getpz() const { return momentum[3]; }

  // Overloaded operators
  Four_momentum operator+(const Four_momentum& other) const;  // Vector addition
  Four_momentum operator-(const Four_momentum& other) const;  // Vector subtraction
  double operator*(const Four_momentum& other) const;  // Vector multiplication (inner product)
  Four_momentum& operator+=(const Four_momentum& other); // Vector assignment addition

  // Utility functions
  void print_four_momentum() const; // Prints the four-momentum in scientific notation
  double invariant_mass() const;    // Computes the invariant mass based on the four-momentum
  void check_mass_consistency();    // Checks invariant mass consistency
};

#endif // FOUR_MOMENTUM_H
