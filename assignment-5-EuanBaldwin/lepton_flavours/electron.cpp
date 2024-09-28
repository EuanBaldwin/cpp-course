// Assignment 5 - Euan Baldwin - PHYS30762
// Implementation file for the Electron class
// Includes methods for energy distribution and printing electron data
// Last updated: 19/04/2024

#include "electron.h"

// Constructor
Electron::Electron(double E, double px, double py, double pz, bool antiparticle) 
  : Lepton(E, px, py, pz, antiparticle, -1), energy_deposited(4, 0.0), 
  generator(std::chrono::system_clock::now().time_since_epoch().count()) 
  { distribute_energy(); }

// Distributes the total energy of the electron into different detector components
void Electron::distribute_energy() 
{
  double total_energy = getE();
  std::vector<double> fractions(4);
  double sum_fractions = 0.0;

  // Generate random fractions and their sum
  for(auto& fraction : fractions)
    fraction = distribution(generator);
  sum_fractions = std::accumulate(fractions.begin(), fractions.end(), 0.0);

  // Distribute total energy based on generated fractions, ensuring the sum matches the total energy
  for(int i = 0; i < 4; ++i)
    energy_deposited[i] = total_energy * (fractions[i] / sum_fractions);
}

// Prints the energy deposited by the electron in various detector components
void Electron::print_energy_depositied() const 
{
  std::cout<<std::left<<std::setw(20)<<"Energy Deposited:"
    <<"["<<std::fixed<<std::setprecision(2)<<std::right
    <<std::setw(6)<<get_em_1()<<", "<<std::setw(6)<<get_em_2()<<", "
    <<std::setw(6)<<get_had_1()<<", "<<std::setw(6)<<get_had_2()<<"]"<<std::endl;
}

// Prints data specific to electrons, including energy deposition
void Electron::print_data() const
{
  std::cout<<std::left<<std::setw(20)<<get_name()<<std::endl;
  print_charge();
  four_momentum->print_four_momentum();
  print_energy_depositied();
  print_separator();
}
