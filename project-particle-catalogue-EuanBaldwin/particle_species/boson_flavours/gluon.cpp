// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the Gluon class
// Implements printing of gluon specifc data, including colour and anticolour
// Last updated: 08/05/2024

#include "gluon.h"

// Constructor
Gluon::Gluon(double E, double px, double py, double pz, bool antiparticle, Colour_list col, Colour_list anti_col)
  : Boson("Gluon", E, px, py, pz, antiparticle, 0),
    Colour_charge(col, anti_col)
    { validate_and_correct_colour(false); }

// Prints data specific to gluons, including colour and anticolour
void Gluon::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_two_colours();
  print_core_data();
  four_momentum->print_four_momentum();
  print_separator();
}