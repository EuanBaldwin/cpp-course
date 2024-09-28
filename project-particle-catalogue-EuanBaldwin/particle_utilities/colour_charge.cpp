// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the colour charge class
// Implements methods to validate and print the colour charge(s) of particles
// Last updated: 08/05/2024

#include "colour_charge.h"

// Constructor for particles that need only one colour definition (like quarks)
Colour_charge::Colour_charge(Colour_list col)
  : colour(col), anti_colour(Colour_list::Unknown) {}

// Constructor for particles needing two colour definitions (like gluons)
Colour_charge::Colour_charge(Colour_list col, Colour_list anti_col)
  : colour(col), anti_colour(anti_col) 
  {
    // If the gluon combination is not valid, set both colours to "Unknown"
    if(!is_valid_gluon_colour_combination(col, anti_col))
    {
      print_colour_error();
      this->colour = Colour_list::Unknown;
      this->anti_colour = Colour_list::Unknown;
    }
  }

// Checks whether a given combination of colour and anti-colour is valid for gluons
bool Colour_charge::is_valid_gluon_colour_combination(Colour_list colour, Colour_list anti_colour) 
{
  // Ensure the colour and anti-colour are not direct opposites
  return !((colour == Colour_list::Red && anti_colour == Colour_list::Antired) ||
    (colour == Colour_list::Green && anti_colour == Colour_list::Antigreen) ||
    (colour == Colour_list::Blue && anti_colour == Colour_list::Antiblue));
}

// Converts a colour charge enum to its string representation
std::string Colour_charge::enum_to_string(Colour_list col) const 
{
  switch (col) 
  {
    case Colour_list::Red: return "Red";
    case Colour_list::Green: return "Green";
    case Colour_list::Blue: return "Blue";
    case Colour_list::Antired: return "Antired";
    case Colour_list::Antigreen: return "Antigreen";
    case Colour_list::Antiblue: return "Antiblue";
    default: return "Unknown";
  }
}

// Checks and updates a colour if it is not in the list of valid colours
void Colour_charge::check_and_update_colour(Colour_list &current_colour, const std::initializer_list<Colour_list> &valid_colours)
{
  // Use a lambda to check if the current_colour is in valid_colours
  auto is_valid_colour = [&valid_colours](Colour_list colour) 
  {
    return std::find(valid_colours.begin(), valid_colours.end(), colour) != valid_colours.end();
  };

  // Update colour if it's not valid
  if(!is_valid_colour(current_colour))
  {
    if(current_colour != Colour_list::Unknown)
    {
      current_colour = Colour_list::Unknown;
      print_colour_error();
    }
  }
}

// Validates and corrects colours based on whether the particle is an antiparticle
void Colour_charge::validate_and_correct_colour(bool is_antiparticle) 
{
  if(is_antiparticle) 
  {
    // Validate antiparticle colours
    check_and_update_colour(colour, {Colour_list::Antired, Colour_list::Antigreen, Colour_list::Antiblue});
    check_and_update_colour(anti_colour, {Colour_list::Red, Colour_list::Green, Colour_list::Blue});
  }
  else 
  {
    // Validate particle colours
    check_and_update_colour(colour, {Colour_list::Red, Colour_list::Green, Colour_list::Blue});
    check_and_update_colour(anti_colour, {Colour_list::Antired, Colour_list::Antigreen, Colour_list::Antiblue});
  }
}

// Prints both colour and anti-colour charges for gluons
void Colour_charge::print_two_colours() const 
{ 
  std::cout<<std::setw(20)<<"Colour:"<<enum_to_string(colour)<<" - "<<enum_to_string(anti_colour)<<std::endl; 
}
