// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Tau class
// Implements printing of tau-specific data
// Last updated: 08/05/2024

#include "tau.h"

// Constructor
Tau::Tau(double E, double px, double py, double pz, bool antiparticle) 
  : Lepton("Tau", E, px, py, pz, antiparticle, -1) {}

// Prints data specific to taus, including decay information
void Tau::print_data() const 
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  print_lepton_number();
  four_momentum->print_four_momentum();
  print_decay_products();
  print_separator();
}

