// Assignment 5 - Euan Baldwin - PHYS30762
// Main program demonstrating the use of particle classes
// Creates particles, performs operations, and prints their properties
// Last updated: 19/04/2024

#include "lepton_flavours/electron.h"
#include "lepton_flavours/muon.h"
#include "lepton_flavours/neutrino.h"
#include "lepton_flavours/tau.h"

int main() 
{
  std::vector<std::shared_ptr<Lepton>> particles;

  // Add two electrons
  particles.push_back(std::make_shared<Electron>(10.0, 1.0, 2.0, 3.0));
  particles.push_back(std::make_shared<Electron>(20.0, 4.0, 5.0, 6.0));

  // Add four muons
  for (int i = 0; i < 4; ++i)
    particles.push_back(std::make_shared<Muon>(30.0 + i*10, 7.0 + i*3, 8.0 + i*3, 9.0 + i*3, false, true));

  // Add one antielectron
  particles.push_back(std::make_shared<Electron>(70.0, 3.0, 4.0, 5.0, true));

  // Add one antimuon
  particles.push_back(std::make_shared<Muon>(80.0, 19.0, 20.0, 21.0, true, true));

  // Add neutrinos
  particles.push_back(std::make_shared<Neutrino>(1.0, 0.1, 0.2, 0.3, false, Neutrino_flavour::Muon));
  particles.push_back(std::make_shared<Neutrino>(2.0, 0.4, 0.5, 0.6, false, Neutrino_flavour::Electron));

  // Tau decaying into a muon, a muon antineutrino, and a tau neutrino
  auto tau = std::make_shared<Tau>(90.0, 22.0, 23.0, 24.0, false, Decay_types::Leptonic);
  tau->add_decay_product(std::make_shared<Muon>(100.0, 25.0, 26.0, 27.0));
  tau->add_decay_product(std::make_shared<Neutrino>(3.0, 0.7, 0.8, 0.9, true, Neutrino_flavour::Muon));
  tau->add_decay_product(std::make_shared<Neutrino>(4.0, 1.0, 1.1, 1.2, false, Neutrino_flavour::Tau));
  particles.push_back(tau);

  // Antitau decaying into an antielectron, an electron neutrino, and a tau antineutrino
  auto antitau = std::make_shared<Tau>(110.0, 28.0, 29.0, 30.0, true, Decay_types::Leptonic);
  antitau->add_decay_product(std::make_shared<Electron>(120.0, 31.0, 32.0, 33.0, true));
  antitau->add_decay_product(std::make_shared<Neutrino>(5.0, 1.3, 1.4, 1.5, false, Neutrino_flavour::Electron));
  antitau->add_decay_product(std::make_shared<Neutrino>(6.0, 1.6, 1.7, 1.8, true, Neutrino_flavour::Tau));
  particles.push_back(antitau);

  // Print all particles
  for (const auto& particle : particles)
    particle->print_data();

  // Create a unique pointer for a new electron and then move its data to another electron
  std::unique_ptr<Electron> electron1 = std::make_unique<Electron>(130.0, 31.0, 32.0, 33.0);
  std::unique_ptr<Electron> electron2 = std::move(electron1); // Moving ownership
  std::cout<<"Electron2 after moving data from Electron1:"<<std::endl;
  electron2->print_data();

  // Create a shared pointer for a tau lepton and simulate shared ownership
  auto shared_tau = std::make_shared<Tau>(140.0, 34.0, 35.0, 36.0, false, Decay_types::Hadronic);
  std::shared_ptr<Tau> another_shared_tau = shared_tau; // Shared ownership
  std::cout<<"Shared Tau accessed via another shared pointer:"<<std::endl;
  another_shared_tau->print_data();

  // Sum the four-vectors of the two electrons
  auto sum = particles[0]->get_four_momentum() + particles[1]->get_four_momentum();
  std::cout<<"Sum of first two electrons' ";
  sum.print_four_momentum();

  // Dot product of antielectron and antimuon four-vectors
  auto dot_result = dot_product(particles[8]->get_four_momentum(), particles[9]->get_four_momentum());
  std::cout<<"Dot product of antielectron and antimuon: "<<dot_result<<std::endl;

  return 0;
}
