// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Muon class
// Implements printing of muon-specific data
// Last updated: 08/05/2024

#include "muon.h"

// Constructor
Muon::Muon(double E, double px, double py, double pz, bool antiparticle, bool isolated) 
  : Lepton("Muon", E, px, py, pz, antiparticle, -1), is_isolated(isolated) {}

// Prints data specific to muons, including isolation status
void Muon::print_data() const 
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  print_lepton_number();
  four_momentum->print_four_momentum(); 
  std::cout<<std::left<<std::setw(20)<<"Isolation:"<<(is_isolated ? "Yes" : "No")<<std::endl;
  print_separator();
}
