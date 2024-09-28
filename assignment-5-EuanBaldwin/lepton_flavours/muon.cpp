// Assignment 5 - Euan Baldwin - PHYS30762
// Implementation file for the Muon class
// Handles printing of muon-specific data
// Last updated: 19/04/2024

#include "muon.h"

// Constructor
Muon::Muon(double E, double px, double py, double pz, bool antiparticle, bool isolated) 
  : Lepton(E, px, py, pz, antiparticle, -1), is_isolated(isolated) {}

// Prints data specific to muons, including isolation status
void Muon::print_data() const 
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_charge();
  four_momentum->print_four_momentum(); 
  std::cout<<std::left<<std::setw(20)<<"Isolation:"<<(is_isolated ? "Yes" : "No")<<std::endl;
  print_separator();
}
