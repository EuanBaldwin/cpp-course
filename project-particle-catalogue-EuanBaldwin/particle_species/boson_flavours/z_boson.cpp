// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Z Boson class
// Implements printing of Z boson-specific data, including decay products
// Last updated: 08/05/2024

#include "z_boson.h"

// Constructor
Z_Boson::Z_Boson(double E, double px, double py, double pz)
  : Boson("Z Boson", E, px, py, pz, false, 0) {} // Redundant anti-particle flag set to false

// Prints data specific to Z bosons, including decay products
void Z_Boson::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  four_momentum->print_four_momentum();
  print_decay_products();
  print_separator();
}
