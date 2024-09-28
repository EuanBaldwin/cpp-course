// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the Gluon class, derived from Boson
// Defines gluon-specific printing, including colour and anticolour
// Last updated: 08/05/2024

#ifndef GLUON_H
#define GLUON_H

#include "../boson.cpp"

class Gluon : public Boson, public Colour_charge
{
public:
  // Constructor
  Gluon(double E, double px, double py, double pz, bool antiparticle = false, 
  Colour_list col = Colour_list::Unknown, Colour_list anti_col = Colour_list::Unknown);

  // Returns boson name
  std::string get_name() const override { return "Gluon"; }

  // Prints data specific to gluons, including colour and anticolour
  void print_data() const;
};

#endif
