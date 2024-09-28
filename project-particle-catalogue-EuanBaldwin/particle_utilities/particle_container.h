// Particle Catalogue - Euan Baldwin - PHYS30762
// Header file for the particle container class
// Defines the interface to manage, count, and process collections of particles
// Last updated: 08/05/2024

#ifndef CONTAINER_H
#define CONTAINER_H

#include "../common_includes.h"
#include "../particle.h"

class Particle_container 
{
private:
  std::list<std::shared_ptr<Particle>> particles; // List to hold shared pointers to all particles in the container

public:
  // Adds a particle to the container
  void add_particle(const std::shared_ptr<Particle>& particle);

  // Getters
  const std::list<std::shared_ptr<Particle>>& get_all_particles() const { return particles; }
  size_t get_total_particles() const; // Returns the total number of particles in the container

  // Utility functions
  std::map<std::string, int> count_particles_by_type() const;
  Four_momentum sum_four_momentum() const; // Computes the total four-momentum of all particles in the container
  void clear_container() { particles.clear(); }

  // Retrieves all particles of a specific type (template function)
  // Template function must be defined here to ensure correct instantiation
  template<typename Particle_type>
  std::list<std::shared_ptr<Particle_type>> get_particles_of_type() const
  {
    std::list<std::shared_ptr<Particle_type>> sublist; // Create a list to store the particles of the specific type
    for(const auto& particle : particles) 
    {
      auto casted_ptr = std::dynamic_pointer_cast<Particle_type>(particle); // Try to dynamically cast to the specific type
      if(casted_ptr) // If the cast is successful, the particle is of the desired type, so add it to the sublist
        sublist.push_back(casted_ptr);
    }
    return sublist; // Return the sublist containing all particles of the specific type
  }

  // Prints information about each particle in the container
  void print_particles() const;
};

#endif
