// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the particle properties class
// Implements the functions to initialise and retrieve particle masses
// Last updated: 08/05/2024

#include "Particle_properties.h"

// Map to store particle names and their corresponding masses in GeV/c^2
std::map<std::string, double> Particle_properties::particle_masses;

void Particle_properties::initialise_masses()
{
  particle_masses["Up"] = 0.0023;                    // Up quark
  particle_masses["Charm"] = 1.275;                  // Charm quark
  particle_masses["Top"] = 173.07;                   // Top quark
  particle_masses["Down"] = 0.0048;                  // Down quark
  particle_masses["Strange"] = 0.095;                // Strange quark
  particle_masses["Bottom"] = 4.18;                  // Bottom quark

  particle_masses["Electron"] = 0.511 * 1e-3;        // Electron
  particle_masses["Muon"] = 0.1057;                  // Muon
  particle_masses["Tau"] = 1.777;                    // Tau lepton

  particle_masses["Electron Neutrino"] = 0.0000022;  // Electron neutrino
  particle_masses["Muon Neutrino"] = 0.00017;        // Muon neutrino
  particle_masses["Tau Neutrino"] = 0.0155;          // Tau neutrino

  particle_masses["Gluon"] = 0;                      // Gluon (massless)
  particle_masses["Photon"] = 0;                     // Photon (massless)
  
  particle_masses["Z Boson"] = 91.2;                 // Z boson
  particle_masses["W Boson"] = 80.4;                 // W boson
  particle_masses["Higgs Boson"] = 126;              // Higgs boson
}

// Search for the particle's mass by its name
double Particle_properties::get_mass(const std::string& particle_name) 
{
  try 
  {
    if(particle_name.empty()) // Check if the particle name is empty (valid use case to return four-momentum operations)
      return std::numeric_limits<double>::quiet_NaN(); // Return NaN as a representation of undefined mass
  
    auto it = particle_masses.find(particle_name); // Attempt to find the particle name in the map

    if(it != particle_masses.end()) // If found, return the corresponding mass
      return it->second;

    // If not found, throw an exception
    throw std::invalid_argument("Particle name '"+particle_name+"' not found in particle masses.");
  } 
  catch(const std::exception& e) // Print error message and return a default value
  {
    std::cerr<<"Error: "<<e.what()<<std::endl;
    return 0;
  }
}
