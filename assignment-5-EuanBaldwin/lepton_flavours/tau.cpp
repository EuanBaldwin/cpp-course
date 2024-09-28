// Assignment 5 - Euan Baldwin - PHYS30762
// Implementation file for the Tau class
// Manages printing of tau-specific data and decay processes
// Last updated: 19/04/2024

#include "tau.h"

// Constructor
Tau::Tau(double E, double px, double py, double pz, bool antiparticle, Decay_types mode) 
  : Lepton(E, px, py, pz, antiparticle, -1), decay_mode(mode) {}

// Prints data specific to taus, including decay information
void Tau::print_data() const 
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_charge();
  four_momentum->print_four_momentum();
  std::cout<<std::left<<std::setw(20)<<"Decay Mode:"
    <<(decay_mode == Decay_types::Hadronic ? "Hadronic" : "Leptonic")<<std::endl;
  
  // Check if there are decay products to print
  if(!decay_products.empty()) 
  {
    std::cout<<std::left<<std::setw(20)<<"Decay Products:";
    for(const auto& product : decay_products)
      std::cout<<product->get_name()<<", ";
    std::cout<<"\b\b "<<std::endl; // Remove the last comma and space
  } 
  else
    std::cout<<std::left<<std::setw(20)<<"Decay Products: "<<"None"<<std::endl;

  print_separator();
}
