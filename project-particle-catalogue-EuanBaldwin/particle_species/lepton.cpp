// Particle Catalogue - Euan Baldwin - PHYS30762
// Lepton abstract class, derived from Particle
// Contains methods to manage and validate lepton properties
// Last updated: 08/05/2024

#include "lepton.h"

// Constructor
Lepton::Lepton(const std::string& name, double E, double px, double py, double pz, 
  bool antiparticle, double charge_value, double lepton_num)
  : Particle(name, E, px, py, pz, antiparticle, charge_value, 1.0/2), 
  lepton_number(antiparticle ? -lepton_num : lepton_num) {}

// Override decay product validation to include lepton number and lepton flavour checks
void Lepton::validate_decay_products() 
{
  Particle::validate_decay_products();  // Call base class method to validate charge

  int sum_electron_number = 0, sum_muon_number = 0, sum_tau_number = 0;

  for(const auto& product : decay_products) // Iterate over each decay product to accumulate the family numbers
  {
    Lepton* lepton_ptr = dynamic_cast<Lepton*>(product.get()); // Attempt to cast the decay product to a Lepton type
    if(lepton_ptr) // If successful, update the appropriate family number sums
    {
      sum_electron_number += lepton_ptr->get_electron_number();
      sum_muon_number += lepton_ptr->get_muon_number();
      sum_tau_number += lepton_ptr->get_tau_number();
    }
  }

  // Check if the accumulated family numbers match the parent particle's family numbers
  bool is_valid = (sum_electron_number == get_electron_number()) && 
    (sum_muon_number == get_muon_number()) && (sum_tau_number == get_tau_number());

  // Output an error if any family number doesn't match, and mark decay as invalid
  if(!is_valid) 
  {
    std::cerr << "\033[0;31mLepton family number inconsistency detected in " << get_name() << " decay.\033[0m" << std::endl;
    is_decay_valid = false;
  }
}
