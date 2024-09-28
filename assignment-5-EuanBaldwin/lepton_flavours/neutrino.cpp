// Assignment 5 - Euan Baldwin - PHYS30762
// Implementation file for the Neutrino class
// Includes methods for printing neutrino data and converting enum to string
// Last updated: 19/04/2024

#include "neutrino.h"

// Constructor
Neutrino::Neutrino(double E, double px, double py, double pz, bool antiparticle, Neutrino_flavour flv, bool interacted) 
  : Lepton(E, px, py, pz, antiparticle, 0), flavour(flv), has_interacted(interacted) {}

// Converts the neutrino flavour from enum to a readable string
std::string Neutrino::flavour_to_string() const 
{
  switch(flavour) 
  {
    case Neutrino_flavour::Electron: return "Electron";
    case Neutrino_flavour::Muon: return "Muon";
    case Neutrino_flavour::Tau: return "Tau";
    default: return "Unknown";
  }
}

// Returns the name of the neutrino, including its flavour and whether it is an antiparticle
std::string Neutrino::get_name() const 
{ 
  std::string neutrino_type = flavour_to_string() + (is_antiparticle ? " Anti-Neutrino" : " Neutrino");
  return neutrino_type;
}

// Prints data specific to neutrino, including flavour and interaction status
void Neutrino::print_data() const 
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_charge();
  four_momentum->print_four_momentum();
  std::cout<<std::left<<std::setw(20)<<"Has Interacted:"<<(has_interacted ? "Yes" : "No")<<std::endl;
  print_separator();
}
