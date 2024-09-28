// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Neutrino class
// Implements methods for printing neutrino data and converting enum to string
// Last updated: 08/05/2024

#include "neutrino.h"

// Constructor
Neutrino::Neutrino(double E, double px, double py, double pz, bool antiparticle = false, Lepton_flavour flv = Lepton_flavour::Unknown, bool interacted = false) 
  : flavour(flv), Lepton(enum_to_string(flv) + " Neutrino", E, px, py, pz, antiparticle, 0), has_interacted(interacted) 
  {}

// Converts the neutrino flavour from enum to a readable string
std::string Neutrino::enum_to_string(Lepton_flavour flv) const
{
  switch(flv)
  {
  case Lepton_flavour::Electron: return "Electron";
  case Lepton_flavour::Muon: return "Muon";
  case Lepton_flavour::Tau: return "Tau";
  default: return "Unknown";
  }
}

// Returns the name of the neutrino, including its flavour and whether it is an antiparticle
std::string Neutrino::get_name() const 
{ 
  std::string neutrino_type = enum_to_string(flavour) + (is_antiparticle ? " Anti-Neutrino" : " Neutrino");
  return neutrino_type;
}

// Prints data specific to neutrino, including flavour and interaction status
void Neutrino::print_data() const 
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_core_data();
  print_lepton_number();
  four_momentum->print_four_momentum();
  std::cout<<std::left<<std::setw(20)<<"Has Interacted:"<<(has_interacted ? "Yes" : "No")<<std::endl;
  print_separator();
}
