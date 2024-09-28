// Assignment 4 - Euan Baldwin - PHYS30762
// Practice special functions and operators in C++ classes
// Last updated: 16/03/2024

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "particle.h"

using std::string;

int main()
{
  // Initiate the particle list - Format: particle(type, energy, px, py, pz) all in MeV
  std::vector<Particle> particle_list;
  particle_list.reserve(8);  // Reserve space for the particles to prevent unecessary moving/destruction of vector

  // Format: particle(type, energy in MeV, px, py, pz all in MeV/c)
  particle_list.emplace_back("electron", 123, 0.1, 0.2, 0.3);
  particle_list.emplace_back("electron", 500, 0.4, 0.5, 0.6);
  particle_list.emplace_back("muon", 10, 0.7, 0.8, 0.9);
  particle_list.emplace_back("muon", 10, 1.0, 1.1, 1.2);
  particle_list.emplace_back("muon", 30, 1.3, 1.4, 1.5);
  particle_list.emplace_back("muon", 95, 1.6, 1.7, 1.8);
  particle_list.emplace_back("antielectron", 478, 1.9, 2.0, 2.1);
  particle_list.emplace_back("antimuon", 70, 2.2, 2.3, 2.4);

  // Print out the data from all the particles
  std::cout<<std::endl;
  for(const auto& p : particle_list)
    p.print_data();
  std::cout<<std::endl;

 // Sum the four-momenta of the two electrons
  auto sum_electrons = particle_list[0] + particle_list[1];
  std::cout<<"Sum of electrons' four-momenta = ";
  sum_electrons.print_data();
  std::cout<<std::endl;

  // Do the dot product of the first two muons
  double dotProduct_muons = particle_list[2].dotProduct(particle_list[3]);
  std::cout<<"Dot product of the first two muons' four-momenta = "<<dotProduct_muons<<" MeV²"<<std::endl<<std::endl;

  // Assignment operator of an electron to a new electron
  Particle new_electron;
  new_electron = particle_list[0];
  std::cout<<"After assignment - ";
  new_electron.print_data();
  std::cout<<std::endl;

  // Copy constructor of the first muon to a new muon
  Particle copied_muon = particle_list[2];
  std::cout<<"Copied particle - ";
  copied_muon.print_data();
  std::cout<<std::endl;

  // Move the antielectron into another antielectron using the move constructor
  Particle moved_antielectron = std::move(particle_list[6]);
  std::cout<<"Moved particle - ";
  moved_antielectron.print_data();
  std::cout<<std::endl;

  // Assign the antimuon to another antimuon using the move assignment
  Particle another_antimuon;
  another_antimuon = std::move(particle_list[7]);
  std::cout<<"After move assignment - ";
  another_antimuon.print_data();
  std::cout<<std::endl;

  return 0;
}
