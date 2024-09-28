// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Higgs Boson class
// Implements printing of Higgs boson-specific data, including decay products
// Last updated: 08/05/2024

#include "higgs.h"

// Constructor
Higgs::Higgs(double E, double px, double py, double pz)
  : Boson("Higgs Boson", E, px, py, pz, false, 0, 0) {} // Redundant anti-particle flag set to false
  
// Prints data specific to higgs bosons, including decay products
void Higgs::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  four_momentum->print_four_momentum();
  print_decay_products();
  print_separator();
}
