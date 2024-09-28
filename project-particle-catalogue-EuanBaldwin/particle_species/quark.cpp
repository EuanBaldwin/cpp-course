// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Quark class, derived from Particle
// Contains methods to manage and validate quark properties
// Last updated: 08/05/2024

#include "quark.h"

// Constructor
Quark::Quark(double E, double px, double py, double pz, bool antiparticle, Quark_flavour flv, Colour_list col, double baryon_num)
  : flavour(flv),
  Particle(enum_to_string(flv), E, px, py, pz, antiparticle, set_charge(flv, antiparticle), 1.0/2),
  Colour_charge(col),
  baryon_number(antiparticle ? -baryon_num : baryon_num)
  { validate_and_correct_colour(antiparticle); }

// Determines the charge of the quark based on its flavour and antiparticle status
double Quark::set_charge(Quark_flavour flv, bool antiparticle) 
{
  double charge;
  switch(flv) 
  {
    case Quark_flavour::Up: case Quark_flavour::Charm: case Quark_flavour::Top:
      charge = 2.0 / 3.0; // Up-type quarks (Up, Charm, Top) have a positive charge of +2/3
      break;
    case Quark_flavour::Down: case Quark_flavour::Strange: case Quark_flavour::Bottom:
      charge = -1.0 / 3.0; // Down-type quarks (Down, Strange, Bottom) have a negative charge of -1/3
      break;
    default: 
      charge = 0; // Default charge for Unknown flavour
  }
  return charge;
}

// Prints data related to quarks, including name, colour, baryon number, and four-momentum
void Quark::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_colour();
  print_core_data();
  print_baryon_number();
  four_momentum->print_four_momentum();
  print_separator();
}

// Prints the baryon number of the quark
void Quark::print_baryon_number() const
{
  std::cout<<std::setw(20)<<"Baryon number:"<<baryon_number<<std::endl;
}

// Retrieves the name of the quark based on its flavour and whether it's an antiparticle
std::string Quark::get_name() const
{
  std::string quark_type = enum_to_string(flavour) + (is_antiparticle ? " Anti-Quark" : " Quark");
  return quark_type;
}

// Converts a quark flavour enum to its string representation
std::string Quark::enum_to_string(Quark_flavour flv) const
{
  switch(flv)
  {
    case Quark_flavour::Up: return "Up";
    case Quark_flavour::Down: return "Down";
    case Quark_flavour::Charm: return "Charm";
    case Quark_flavour::Strange: return "Strange";
    case Quark_flavour::Top: return "Top";
    case Quark_flavour::Bottom: return "Bottom";
    default: return "Unknown"; // If the flavour is unknown or unspecified, return "Unknown"
  }
}

// Override decay product validation to include baryon number checks
void Quark::validate_decay_products()
{
  Particle::validate_decay_products(); // Call base class method to validate charge

  int sum_baryon_number = 0;
  for(const auto& product : decay_products) // Iterate over each decay product to accumulate the baryon numbers
  {
    Quark* quark_ptr = dynamic_cast<Quark*>(product.get()); // Attempt to cast the decay product to a Quark type
    if(quark_ptr) // If successful, add the quark's baryon number to the total sum
      sum_baryon_number += quark_ptr->get_baryon_number();
  }

  // Check if the accumulated baryon number matches the parent quark's baryon number
  if(sum_baryon_number != this->get_baryon_number())
  {
    std::cerr<<"\033[0;31mBaryon number inconsistency detected in "<<get_name()<<" decay.\033[0m"<<std::endl;
    is_decay_valid = false;
  }
}
