// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the W Boson class
// Implements printing of W boson-specific data, including decay products
// Last updated: 08/05/2024

#include "w_boson.h"

// Constructor
W_Boson::W_Boson(double E, double px, double py, double pz, bool antiparticle)
  : Boson("W Boson", E, px, py, pz, antiparticle, -1) {}

// Prints data specific to W bosons, including decay products
void W_Boson::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  four_momentum->print_four_momentum();
  print_decay_products();
  print_separator();
}
