// Assignment 5 - Euan Baldwin - PHYS30762
// Header file for the Tau class, derived from Lepton
// Defines tau-specific properties, including decay modes and products
// Last updated: 19/04/2024

#ifndef TAU_H
#define TAU_H

#include "../lepton.cpp"

enum class Decay_types { Hadronic, Leptonic }; // Enumerates tau decay types

class Tau : public Lepton 
{
private:
  Decay_types decay_mode;
  std::vector<std::shared_ptr<Lepton>> decay_products;

public:
  // Constructor
  Tau(double E, double px, double py, double pz, bool antiparticle = false, Decay_types mode = Decay_types::Hadronic);

  // Setter functions
  void set_decay_mode(Decay_types mode) { decay_mode = mode; }

  // Add a decay product to the tau
  void add_decay_product(std::shared_ptr<Lepton> product) { decay_products.push_back(product); }

  // Overriding printing functions to include specific tau data
  void print_data() const override;
  std::string get_name() const override { return is_antiparticle ? "Anti-Tau" : "Tau"; }
};

#endif
