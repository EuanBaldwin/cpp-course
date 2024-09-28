// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the particle abstract base class
// Provides common properties and methods for all species of particles
// Last updated: 08/05/2024

#include "particle.h"

// Constructor
Particle::Particle(const std::string& name_value, double E, double px, double py, double pz,
  bool antiparticle, double charge_value, double spin_value) 
  : four_momentum(std::make_unique<Four_momentum>(name_value, E, px, py, pz)),
  name(name_value),
  is_antiparticle(antiparticle),
  charge(antiparticle ? -charge_value : charge_value), // Negate charge if it's an antiparticle
  spin(spin_value),
  mass(Particle_properties::get_mass(name_value)),     // Retrieve the particle's mass based on its name
  is_decay_valid(true)                                 // Assume decay is valid initially
  { 
    // Set four-momentum values for this particle and check if its mass is consistent with expectations
    set_four_momentum(name_value, E, px, py, pz); 
    check_mass_consistency(); 
  }

// Print core particle data, such as spin and charge
void Particle::print_core_data() const 
{ 
  std::cout<<std::fixed<<std::setprecision(2)<<std::setw(20)<<"Spin:"<<spin<<std::endl;
  std::cout<<std::setw(20)<<"Charge:"<<charge<<"e"<<std::endl;
}

// Validate that the decay products conserve charge
void Particle::validate_decay_products() {
  double sum_charge = 0;
  for(const auto& product : decay_products)
    sum_charge += product->get_charge();

  // If charges don't match, mark decay as invalid
  if(sum_charge != this->get_charge()) 
  {
    std::cerr<<"\033[0;31mCharge inconsistency detected in "<<get_name()<<" decay.\033[0m"<<std::endl;
    is_decay_valid = false;  // Mark the decay as invalid
  } 
  else
    is_decay_valid = true;  // Decay is valid if charge is consistent
}

// Print the names of decay products
void Particle::print_decay_products() const {
  if(!is_decay_valid) 
    std::cout<<std::left<<std::setw(20)<<"Decay Products:"<<"\033[0;31mInvalid decay detected.\033[0m"<<std::endl;
  else if(!decay_products.empty()) 
  {
    std::cout<<std::left<<std::setw(20)<<"Decay Products:";
    for(const auto& product : decay_products)
      std::cout<<product->get_name()<<", ";
    std::cout<<"\b\b "<<std::endl;  // Remove the trailing comma and space
  } 
  else
    std::cout<<std::left<<std::setw(20)<<"Decay Products:"<<"None"<<std::endl;
}
