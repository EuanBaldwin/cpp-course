#include <iostream>
#include "particle.h"

const double LIGHT_SPD = 2.99792458e8; // Speed of light in vacuum in meters per second
const double ELECTRON_MASS = 0.51099895;  // Electron mass in MeV
const double MUON_MASS = 105.6583755; // Muon mass in MeV

using std::string;

void Particle::update_beta() 
{
  beta = velocity / LIGHT_SPD;
}

void Particle::set_particle_type(const string& p_type) 
{
  if(p_type == "electron" || p_type == "antielectron" || p_type == "muon" || p_type == "antimuon")
    type = p_type;
  else
  {
    std::cerr<<"\033[0;31m"<<"Invalid particle type. Setting "<<p_type<<" to be an electron."<<"\033[0m"<<std::endl;
    type = "electron";
  }
}

void Particle::set_rest_mass() 
{
  if(type.find("electron") != string::npos)
    mass = ELECTRON_MASS;
  else if(type.find("muon") != string::npos)
    mass = MUON_MASS;
}

void Particle::set_velocity(double p_velocity) 
{
  if(p_velocity >= 0 && p_velocity <= LIGHT_SPD)
    velocity = p_velocity;
  else
  {
    std::cerr<<"\033[0;31m"<<"Invalid "<<type<<" velocity. Setting to default: "<<LIGHT_SPD<<"\033[0m"<<std::endl;
    velocity = LIGHT_SPD;
  }
  update_beta();
}

void Particle::set_charge() 
{
  if(type.find("anti") != string::npos)
    charge = 1;
  else
    charge = -1;
}

void Particle::print_data() const 
{
  std::cout.precision(3);
  std::cout<<type<<": "<<mass<<" MeV, "<<charge<<"e, "<<velocity<<" m/s, β = "<<beta<<std::endl;
}
