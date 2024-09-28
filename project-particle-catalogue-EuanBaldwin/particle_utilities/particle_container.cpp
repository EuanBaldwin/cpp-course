// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the particle container class
// Implements methods to add, count, process, and print particles in the container
// Last updated: 08/05/2024

#include "particle_container.h"

// Adds a particle to the container
void Particle_container::add_particle(const std::shared_ptr<Particle>& particle) 
{
  particles.push_back(particle);
}

// Returns the total number of particles in the container
size_t Particle_container::get_total_particles() const 
{
  return particles.size();
}

// Counts the number of particles of each type
std::map<std::string, int> Particle_container::count_particles_by_type() const 
{
  std::map<std::string, int> counts;
  for(const auto& particle : particles) 
  {
    std::string type = particle->get_particle_name();
    counts[type]++;
  }
  return counts;
}

// Computes the total four-momentum of all particles
Four_momentum Particle_container::sum_four_momentum() const 
{
  Four_momentum sum; // Starts with zero momentum
  for(const auto& particle : particles) 
    sum += particle->get_four_momentum(); // Using the operator+=
  return sum;
}

// Prints information about each particle in the container
void Particle_container::print_particles() const 
{
  for(const auto& particle : particles) 
    particle->print_data();
}