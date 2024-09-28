// Particle Catalogue - Euan Baldwin - PHYS30762
// Main programme demonstrating the use of particle classes
// Creates particles, performs operations, and prints their properties
// Last updated: 08/05/2024

#include "particle_utilities/particle_container.h"
#include "particle_species/lepton_flavours/electron.h"
#include "particle_species/lepton_flavours/muon.h"
#include "particle_species/lepton_flavours/neutrino.h"
#include "particle_species/lepton_flavours/tau.h"
#include "particle_species/boson_flavours/gluon.h"
#include "particle_species/boson_flavours/higgs.h"
#include "particle_species/boson_flavours/photon.h"
#include "particle_species/boson_flavours/w_boson.h"
#include "particle_species/boson_flavours/z_boson.h"
#include "particle_species/quark.h"

int main() 
{
  Particle_properties::initialise_masses();
  Particle_container container;

  Particle::print_separator();
  std::cout<<"\033[1mAdding an invalid particle to the container, then clearing the container\033[0m"<<std::endl;
  Particle::print_separator();
  container.add_particle(std::make_shared<Quark>(10, 1, 2, 3, false, Quark_flavour::Up, Colour_list::Antired));
  container.print_particles();
  container.clear_container();

  std::cout<<"\033[1mAdding an invalid particle decay to the container, then clearing the container\033[0m"<<std::endl;
  Particle::print_separator();
  auto invalid_dacay = std::make_shared<Tau>(1.98e+00, -3.96e-01, 4.94e-01, 5.94e-01, true); // Leptonic anti-tau dacay
  container.add_particle(invalid_dacay);
  invalid_dacay->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, false));
  invalid_dacay->add_decay_product(std::make_shared<Neutrino>(2.20e-06, 0, 0, 0, false, Lepton_flavour::Electron, false));
  invalid_dacay->add_decay_product(std::make_shared<Neutrino>(1.55e-02, 0, 0, 0, false, Lepton_flavour::Tau, true));
  invalid_dacay->validate_decay_products();
  container.print_particles();
  container.clear_container();

  // Add quarks to the container
  container.add_particle(std::make_shared<Quark>(2.48e-03, 2.48e-04, -4.96e-04, -7.44e-04, false, Quark_flavour::Up, Colour_list::Red));
  container.add_particle(std::make_shared<Quark>(2.31e-03, 5.85e-05, 6.88e-05, 1.28e-04, true, Quark_flavour::Up, Colour_list::Antired));
  container.add_particle(std::make_shared<Quark>(5.41e-03, -6.71e-04, 1.33e-03, 2.01e-03, false, Quark_flavour::Down, Colour_list::Green));
  container.add_particle(std::make_shared<Quark>(5.41e-03, 6.71e-04, 1.33e-03, 2.01e-03, true, Quark_flavour::Down, Colour_list::Antigreen));
  container.add_particle(std::make_shared<Quark>(1.37e+00, -1.37e-01, 2.75e-01, 4.12e-01, false, Quark_flavour::Charm, Colour_list::Blue));
  container.add_particle(std::make_shared<Quark>(1.37e+00, 1.37e-01, 2.75e-01, -4.12e-01, true, Quark_flavour::Charm, Colour_list::Antiblue));
  container.add_particle(std::make_shared<Quark>(1.02e-01, 2.04e-02, 1.68e-02, -2.52e-02, false, Quark_flavour::Strange, Colour_list::Red));
  container.add_particle(std::make_shared<Quark>(1.02e-01, -2.04e-02, 1.68e-02, 2.52e-02, true, Quark_flavour::Strange, Colour_list::Antired));
  container.add_particle(std::make_shared<Quark>(1.86e+02, 1.18e+01, 3.72e+01, 5.58e+01, false, Quark_flavour::Top, Colour_list::Green));
  container.add_particle(std::make_shared<Quark>(1.86e+02, 1.18e+01, -3.72e+01, 5.58e+01, true, Quark_flavour::Top, Colour_list::Antigreen));
  container.add_particle(std::make_shared<Quark>(4.51e+00, 4.51e-01, 9.06e-01, -1.36e+00, false, Quark_flavour::Bottom, Colour_list::Blue));
  container.add_particle(std::make_shared<Quark>(4.51e+00, -4.51e-01, -9.06e-01, 1.36e+00, true, Quark_flavour::Bottom, Colour_list::Antiblue));

  // Add leptons to the container
  container.add_particle(std::make_shared<Electron>(5.90e-04, -1.34e-04, 1.68e-04, 2.02e-04, false));
  container.add_particle(std::make_shared<Electron>(5.20e-04, 6.61e-05, 4.41e-05, 5.16e-05, true));
  container.add_particle(std::make_shared<Muon>(1.18e-01, -2.36e-02, 2.94e-02, 3.54e-02, false, true));
  container.add_particle(std::make_shared<Muon>(1.18e-01, -2.36e-02, 2.94e-02, 3.54e-02, true, true));

  auto tau_hadronic = std::make_shared<Tau>(1.98e+00, -3.96e-01, 4.94e-01, 5.94e-01, false); // Hadronic tau decay
  container.add_particle(tau_hadronic);
  tau_hadronic->add_decay_product(std::make_shared<Quark>(4.80e-03, 0, 0, 0, false, Quark_flavour::Down, Colour_list::Red)); 
  tau_hadronic->add_decay_product(std::make_shared<Quark>(2.30e-03, 0, 0, 0, true, Quark_flavour::Up, Colour_list::Antired)); 
  tau_hadronic->add_decay_product(std::make_shared<Neutrino>(1.55e-02, 0, 0, 0, false, Lepton_flavour::Tau, true));
  tau_hadronic->validate_decay_products();

  auto tau_leptonic = std::make_shared<Tau>(1.98e+00, -3.96e-01, 4.94e-01, 5.94e-01, false); // Leptonic tau decay
  container.add_particle(tau_leptonic);
  tau_leptonic->add_decay_product(std::make_shared<Tau>(1.78e+00, 0, 0, 0, false));
  tau_leptonic->add_decay_product(std::make_shared<Neutrino>(1.70e-04, 0, 0, 0, true, Lepton_flavour::Muon, true));
  tau_leptonic->add_decay_product(std::make_shared<Neutrino>(1.70e-04, 0, 0, 0, false, Lepton_flavour::Muon, false));
  tau_leptonic->validate_decay_products();

  auto antitau_leptonic = std::make_shared<Tau>(1.98e+00, -3.96e-01, 4.94e-01, 5.94e-01, true); // Leptonic anti-tau decay
  container.add_particle(antitau_leptonic);
  antitau_leptonic->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, true));
  antitau_leptonic->add_decay_product(std::make_shared<Neutrino>(2.20e-06, 0, 0, 0, false, Lepton_flavour::Electron, false));
  antitau_leptonic->add_decay_product(std::make_shared<Neutrino>(1.55e-02, 0, 0, 0, true, Lepton_flavour::Tau, true));
  antitau_leptonic->validate_decay_products();

  container.add_particle(std::make_shared<Neutrino>(2.77e-06, -2.77e-07, -1.66e-06, -2.77e-08, false, Lepton_flavour::Electron, true));
  container.add_particle(std::make_shared<Neutrino>(2.62e-06, -5.23e-07, -1.31e-06, 1.31e-07, true, Lepton_flavour::Electron, true));
  container.add_particle(std::make_shared<Neutrino>(3.33e-04, 1.00e-04, -1.33e-04, -2.33e-04, false, Lepton_flavour::Muon, true));
  container.add_particle(std::make_shared<Neutrino>(1.98e-04, -7.90e-05, 5.93e-05, 1.98e-05, true, Lepton_flavour::Muon, true));
  container.add_particle(std::make_shared<Neutrino>(1.93e-02, 9.63e-03, -3.85e-03, 4.82e-03, false, Lepton_flavour::Tau, false));
  container.add_particle(std::make_shared<Neutrino>(2.04e-02, 1.22e-02, 2.04e-03, -4.58e-03, true, Lepton_flavour::Tau, false));
  
  //Add bosons to the container
  container.add_particle(std::make_shared<Gluon>(2.00e+01, 6.00e+00, 1.80e+01, 7.00e+00, false, Colour_list::Blue, Colour_list::Antired));
  container.add_particle(std::make_shared<Gluon>(2.00e+01, 6.00e+00, 1.80e+01, 7.00e+00, true, Colour_list::Blue, Colour_list::Antired));
  container.add_particle(std::make_shared<Photon>(0, 0, 0, 0));

  // Various Z Boson decays
  auto z_quark_antiquark = std::make_shared<Z_Boson>(1.26e+02, 1.48e+01, 3.69e+00, 8.49e+01);
  container.add_particle(z_quark_antiquark);
  z_quark_antiquark->add_decay_product(std::make_shared<Quark>(4.80e-03, 0, 0, 0, false, Quark_flavour::Down, Colour_list::Red));
  z_quark_antiquark->add_decay_product(std::make_shared<Quark>(4.80e-03, 0, 0, 0, true, Quark_flavour::Down, Colour_list::Antired));
  z_quark_antiquark->validate_decay_products();

  auto z_lepton_antilepton = std::make_shared<Z_Boson>(1.26e+02, 1.48e+01, 3.69e+00, -8.49e+01);
  container.add_particle(z_lepton_antilepton);
  z_lepton_antilepton->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, false));
  z_lepton_antilepton->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, true));
  z_lepton_antilepton->validate_decay_products();

  auto z_neutrino_antineutrino = std::make_shared<Z_Boson>(1.26e+02, -1.48e+01, 3.69e+00, 8.49e+01);
  container.add_particle(z_neutrino_antineutrino);
  z_neutrino_antineutrino->add_decay_product(std::make_shared<Neutrino>(2.20e-06, 0, 0, 0, false, Lepton_flavour::Electron, false));
  z_neutrino_antineutrino->add_decay_product(std::make_shared<Neutrino>(2.20e-06, 0, 0, 0, true, Lepton_flavour::Electron, true));
  z_neutrino_antineutrino->validate_decay_products();

  // Various W Boson decays
  auto w_lepton_antineutrino = std::make_shared<W_Boson>(8.75e+01, -2.92e+01, -5.83e+00, -1.75e+01, false);
  container.add_particle(w_lepton_antineutrino);
  w_lepton_antineutrino->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, false));
  w_lepton_antineutrino->add_decay_product(std::make_shared<Neutrino>(2.20e-06, 0, 0, 0, true, Lepton_flavour::Electron, true));
  w_lepton_antineutrino->validate_decay_products();

  auto w_antilepton_neutrino = std::make_shared<W_Boson>(1.03e+02, 5.81e+01, 1.29e+01, 2.58e+01, true);
  container.add_particle(w_antilepton_neutrino);
  w_antilepton_neutrino->add_decay_product(std::make_shared<Electron>(5.11e-04, 0, 0, 0, true));
  w_antilepton_neutrino->add_decay_product(std::make_shared<Neutrino>(2.20e-06, 0, 0, 0, false, Lepton_flavour::Electron, true));
  w_antilepton_neutrino->validate_decay_products();

  auto w_quark_diff_quark = std::make_shared<W_Boson>(9.05e+01, 2.09e+01, -1.74e+01, 3.13e+01, true);
  container.add_particle(w_quark_diff_quark);
  w_quark_diff_quark->add_decay_product(std::make_shared<Quark>(1.27e+00, 0, 0, 0, false, Quark_flavour::Charm, Colour_list::Red));
  w_quark_diff_quark->add_decay_product(std::make_shared<Quark>(4.18e+00, 0, 0, 0, true, Quark_flavour::Bottom, Colour_list::Antiblue));
  w_quark_diff_quark->validate_decay_products();

  // Various Higgs Boson decays
  auto higgs_z_z = std::make_shared<Higgs>(1.64e+02, 6.56e+01, 6.56e+01, -4.92e+01);
  container.add_particle(higgs_z_z);
  higgs_z_z->add_decay_product(std::make_shared<Z_Boson>(9.12e+01, 0, 0, 0));
  higgs_z_z->add_decay_product(std::make_shared<Z_Boson>(9.12e+01, 0, 0, 0));
  higgs_z_z->validate_decay_products();

  auto higgs_w_w = std::make_shared<Higgs>(1.50e+02, 1.16e+01, -1.16e+00, -8.09e+01);
  container.add_particle(higgs_w_w);
  higgs_w_w->add_decay_product(std::make_shared<W_Boson>(8.04e+01, 0, 0, 0, false));
  higgs_w_w->add_decay_product(std::make_shared<W_Boson>(8.04e+01, 0, 0, 0, true));
  higgs_w_w->validate_decay_products();

  auto higgs_photon_photon = std::make_shared<Higgs>(3.56e+02, -2.67e+02, 1.78e+02, 8.91e+01);
  container.add_particle(higgs_photon_photon);
  higgs_photon_photon->add_decay_product(std::make_shared<Photon>(0, 0, 0, 0));
  higgs_photon_photon->add_decay_product(std::make_shared<Photon>(0, 0, 0, 0));
  higgs_photon_photon->validate_decay_products();

  auto higgs_bottom_antibottom = std::make_shared<Higgs>(1.92e+02, 3.49e+01, 1.22e+02, 6.99e+01);
  container.add_particle(higgs_bottom_antibottom);
  higgs_bottom_antibottom->add_decay_product(std::make_shared<Quark>(4.51e+00, 4.51e-01, 9.06e-01, 1.36e+00, false, Quark_flavour::Bottom, Colour_list::Blue));
  higgs_bottom_antibottom->add_decay_product(std::make_shared<Quark>(4.51e+00, 4.51e-01, 9.06e-01, 1.36e+00, true, Quark_flavour::Bottom, Colour_list::Antiblue));
  higgs_bottom_antibottom->validate_decay_products();

  // Demonstrating container functionality: return all particles and print their properties
  std::cout<<"\033[1mAdding all types of particle (and decays) to the container\033[0m"<<std::endl;
  Particle::print_separator();
  std::cout<<"Total Particles: "<<container.get_total_particles()<<std::endl;
  auto counts = container.count_particles_by_type();
  for (const auto& [type, count] : counts) 
    std::cout<<"Type: "<<std::setw(19)<<std::left<<type<<" Count: "<<count<<std::endl;

  Four_momentum totalMomentum = container.sum_four_momentum();
  std::cout<<"Total "; 
  totalMomentum.print_four_momentum();

  Particle::print_separator();
  container.print_particles();

  // Demonstrating container functionality: return all particles and print their properties
  std::cout<<"\033[1mReturning only the electrons in the container and printing their properties\033[0m"<<std::endl;
  Particle::print_separator();
  auto electrons = container.get_particles_of_type<Electron>();
  for (const auto& electron : electrons) 
    electron->print_data();

  // Calculate the dot product of the first two particles' four-vectors in the container
  const auto& particles = container.get_all_particles();
  if(particles.size() >= 2) 
  {
    auto it = particles.begin();
    const auto& first_particle = *it;
    const auto& second_particle = *(++it);

    std::cout<<"\033[1mOperations using first two particles\033[0m"<<std::endl;
    Particle::print_separator();

    double dot_result = first_particle->get_four_momentum() * second_particle->get_four_momentum();
    std::cout<<std::scientific<<"Dot product of Four-momentum:   "<<dot_result<<" GeV^2"<<std::endl;

    Four_momentum addition_result = first_particle->get_four_momentum() + second_particle->get_four_momentum();
    std::cout<<"Addition of ";
    addition_result.print_four_momentum();

    Four_momentum subtraction_result = first_particle->get_four_momentum() - second_particle->get_four_momentum();
    std::cout<<"Subtraction of ";
    subtraction_result.print_four_momentum();
  }
  Particle::print_separator();
}
