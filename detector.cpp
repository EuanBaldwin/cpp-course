#include <iostream>
#include "particle.h"
#include "detector.h"

using std::string;

void detector::print_status() const
{
  std::cout<<"Detector type: "<<detector_type<<", Status: "<<(status ? "\033[0;32mOn" : "\033[0;31mOff")
  <<"\033[0m, Electrons: "<<electron_count<<", Antielectrons: "<<antielectron_count
  <<", Muons: "<<muon_count<<", Antimuons: "<<antimuon_count<<"\n"<<std::endl;
}

bool detector::detect_particle(const Particle& p)
{
  if(!status) return false; // Detector is off

  string type = p.get_particle_type();

  if((detector_type == "tracker" && (type == "electron" || type == "muon"|| type == "antielectron" || type == "antimuon")) ||
    (detector_type == "calorimeter" && type.find("electron") != string::npos) ||
    (detector_type == "muon chamber" && type.find("muon") != string::npos))
  {
    std::cout<<type<<" was detected."<<std::endl;
    if(type == "electron") ++electron_count;
    else if(type == "antielectron") ++antielectron_count;
    else if(type == "muon") ++muon_count;
    else if(type == "antimuon") ++antimuon_count;
    return true;
  }
  return false; // Particle type not detectable by this detector
}

void detector::reset_counts()
{
  set_electron_count(0);
  set_antielectron_count(0);
  set_muon_count(0);
  set_antimuon_count(0);
  std::cout<<"Resetting "<<detector_type<<" particle count."<<std::endl;
}