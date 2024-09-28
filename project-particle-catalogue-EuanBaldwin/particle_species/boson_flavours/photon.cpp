// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Photon class
// Implements printing of photon-specific data
// Last updated: 08/05/2024

#include "photon.h"

// Constructor
Photon::Photon(double E, double px, double py, double pz)
  : Boson("Photon", E, px, py, pz, false, 0) {} // Redundant anti-particle flag set to false

// Prints data specific to photons
void Photon::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  four_momentum->print_four_momentum();
  print_separator();
}
