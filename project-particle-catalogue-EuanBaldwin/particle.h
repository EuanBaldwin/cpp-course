// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the particle abstract base class
// Provides common properties and methods for all species of particles
// Last updated: 08/05/2024

#ifndef PARTICLE_H
#define PARTICLE_H

#include "particle_utilities/particle_properties.h"
#include "particle_utilities/four_momentum.h"
#include "particle_utilities/colour_charge.h"

class Particle
{
protected:
  std::unique_ptr<Four_momentum> four_momentum;
  std::vector<std::shared_ptr<Particle>> decay_products;
  bool is_antiparticle;
  double charge;
  double spin;
  std::string name;
  double mass;
  bool is_decay_valid;

public:
  Particle(const std::string& name_value, double E, double px, double py, double pz,
  bool antiparticle = false, double charge_value = 0, double spin_value = 0);
  virtual ~Particle() = default;
  
  // Getter functions
  std::string get_particle_name() const { return name; }
  bool get_is_antiparticle() const { return is_antiparticle; }
  double get_charge() const { return charge; }
  double get_spin() const { return spin; }
  double getE() const { return four_momentum->getE(); }
  double getpx() const { return four_momentum->getpx(); }
  double getpy() const { return four_momentum->getpy(); }
  double getpz() const { return four_momentum->getpz(); }
  const Four_momentum& get_four_momentum() const { return *four_momentum; }
  virtual int get_electron_number() const { return 0; }
  virtual int get_muon_number() const { return 0; }
  virtual int get_tau_number() const { return 0; }
  const std::vector<std::shared_ptr<Particle>>& get_decay_products() const { return decay_products; }

  // Setter functions
  void set_four_momentum(const std::string& name, double E, double px, double py, double pz) 
  { four_momentum->setE(E); four_momentum->setpx(px); four_momentum->setpy(py); four_momentum->setpz(pz); }
  void setE(double E) { four_momentum->setE(E); }
  void setpx(double px) { four_momentum->setpx(px); }
  void setpy(double py) { four_momentum->setpy(py); }
  void setpz(double pz) { four_momentum->setpz(pz); }

  // Function to ensure particles have valid invariant masses
  void check_mass_consistency() { four_momentum->check_mass_consistency(); }

  // Decay functions
  void add_decay_product(std::shared_ptr<Particle> product) { decay_products.push_back(product); }
  void validate_decay_products(); // Validates consistent charge

  // Utility functions for data printing 
  virtual void print_data() const = 0;
  virtual std::string get_name() const = 0;
  void print_core_data() const;
  void print_decay_products() const;
  static void print_separator() { std::cout<<"-------------------------------------------------------------------"<<std::endl; }
};

#endif
