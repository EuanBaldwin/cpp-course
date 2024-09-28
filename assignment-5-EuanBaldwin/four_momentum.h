// Assignment 5 - Euan Baldwin - PHYS30762
// Definition of the Four_momentum class
// Encapsulates four-momentum vectors and provides utilities for particle physics calculations
// Last updated: 19/04/2024

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include "common_includes.h"

class Four_momentum 
{
private:
  std::vector<double> momentum; // Stores [E, px, py, pz]
  static bool debug_mode; // Toggle for verbose mode during development

public:
  Four_momentum();                                          // Default constructor
  Four_momentum(double E, double px, double py, double pz); // Parameterised constructor
  Four_momentum(const Four_momentum& other);                // Copy constructor
  Four_momentum& operator=(const Four_momentum& other);     // Assignment operator
  ~Four_momentum();                                         // Destructor
  Four_momentum(Four_momentum&& other) noexcept;            // Move Constructor
  Four_momentum& operator=(Four_momentum&& other) noexcept; // Move Assignment Operator

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

  // Member and friend functions
  void print_four_momentum() const;
  friend Four_momentum operator+(const Four_momentum& lhs, const Four_momentum& rhs); // Overload '+' to sum 2 4-vectors
  friend double dot_product(const Four_momentum& lhs, const Four_momentum& rhs); // Inner product of 2 4-vectors
};

#endif // FOUR_MOMENTUM_H
