// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the colour charge class
// Defines the interface for managing particle colour charges
// Last updated: 08/05/2024

#ifndef COLOUR_H
#define COLOUR_H

#include "../common_includes.h"

// Enum class representing possible colour charges
enum class Colour_list { Red, Green, Blue, Antired, Antigreen, Antiblue, Unknown }; 

class Colour_charge 
{
protected:
  Colour_list colour;       // The main colour of the particle
  Colour_list anti_colour;  // The anti-colour (used for gluons)

public:
  Colour_charge(Colour_list col);                       // Constructor for particles with only one colour definition (quarks)
  Colour_charge(Colour_list col, Colour_list anti_col); // Constructor for particles with both colour and anti-colour (gluons)

  // Getters
  Colour_list get_colour() const { return colour; }
  Colour_list get_anti_colour() const { return anti_colour; }

  // Converts a colour charge enum to its string representation
  std::string enum_to_string(Colour_list col) const;

  // Functions to validate colour
  static bool is_valid_gluon_colour_combination(Colour_list colour, Colour_list anti_colour);
  void check_and_update_colour(Colour_list &current_colour, const std::initializer_list<Colour_list> &valid_colours);
  void validate_and_correct_colour(bool is_antiparticle);

  // Utility functions for data printing 
  void print_colour_error() const { std::cerr<<"\033[0;31mInvalid colour(s). Setting to Unknown.\033[0m"<<std::endl; }
  void print_colour() const { std::cout<<std::setw(20)<<"Colour:"<<enum_to_string(colour)<<std::endl; }
  void print_two_colours() const;
};

#endif
