// Assignment 3 - Euan Baldwin - PHYS30762
// Program to simulate different particle detectors and their operation.
// Last updated: 08/03/2024

#include <vector>
#include <iostream>
#include <deque>
#include "particle.h"
#include "detector.h"

int main()
{
  // Initiate the particles
  std::deque<Particle> particle_list; // Using deque as it uses segmented memory allocation so don't have to pre-reserve memory
  
  particle_list.emplace_back("electron", 1.212e8); // Format: particle(string type, double velocity)
  particle_list.emplace_back("electron", 2.546e8);
  particle_list.emplace_back("muon", 9.342e7);
  particle_list.emplace_back("muon", 1.478e8);
  particle_list.emplace_back("muon", 8.461e7);
  particle_list.emplace_back("muon", 2.805e6);
  particle_list.emplace_back("antielectron", 1.016e8);
  particle_list.emplace_back("antimuon", 9.529e7);

  // Print all information about particles
  std::cout<<std::endl;
  for(const auto& p : particle_list)
    p.print_data();
  std::cout<<std::endl;

  // Initiate the detectors as off
  detector tracker("tracker", false);
  detector calorimeter("calorimeter", false);
  detector muon_chamber("muon chamber", false);
  std::cout<<std::endl;

  // Create a vector of pointers to detectors for easier iteration
  std::vector<detector*> detector_list = {&tracker, &calorimeter, &muon_chamber};

  // Turn detectors on, pass particles through them, then turn off, reset them
  for(auto& d : detector_list) 
  {
    d->turn_on();
    for(const auto& p : particle_list)
      d->detect_particle(p);
    d->print_status();
    d->turn_off();
  }

  // Pass a particle through a detector when it's off
  tracker.reset_counts();
  tracker.detect_particle(particle_list[0]);
  tracker.print_status();

  return 0;
}
