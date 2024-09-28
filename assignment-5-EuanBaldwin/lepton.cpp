// Assignment 5 - Euan Baldwin - PHYS30762
// Abstract base class for leptons
// Provides common properties and methods for all types of leptons and their antiparticles
// Last updated: 19/04/2024

#ifndef LEPTON_CPP
#define LEPTON_CPP

#include "four_momentum.h"

class Lepton
{
protected:
  std::unique_ptr<Four_momentum> four_momentum;
  bool is_antiparticle;
  int charge;

public:
  Lepton(double E, double px, double py, double pz, bool antiparticle = false, int charge_value = 0) 
    : four_momentum(std::make_unique<Four_momentum>(E, px, pz, py)),
    is_antiparticle(antiparticle), charge(antiparticle ? -charge_value : charge_value) { set_four_momentum(E, px, py, pz); }
  virtual ~Lepton() = default;
  
  // Getter functions
  bool get_is_antiparticle() const { return is_antiparticle; }
  const Four_momentum& get_four_momentum() const { return *four_momentum; }
  double getE() const { return four_momentum->getE(); }
  double getpx() const { return four_momentum->getpx(); }
  double getpy() const { return four_momentum->getpy(); }
  double getpz() const { return four_momentum->getpz(); }

  // Setter functions
  void set_four_momentum(double E, double px, double py, double pz) 
  { four_momentum->setE(E); four_momentum->setpx(px); four_momentum->setpy(py); four_momentum->setpz(pz); }
  void setE(double E) { four_momentum->setE(E); }
  void setpx(double px) { four_momentum->setpx(px); }
  void setpy(double py) { four_momentum->setpy(py); }
  void setpz(double pz) { four_momentum->setpz(pz); }

  // Member functions for printing
  virtual void print_data() const = 0;
  virtual std::string get_name() const = 0;
  void print_charge() const { std::cout<<std::setw(20)<<"Charge:"<<charge<<"e"<<std::endl; }
  static void print_separator() { std::cout<<"----------------------------------------------------"<<std::endl; }
};

#endif
