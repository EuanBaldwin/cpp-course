#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
#include "particle.h"

class detector
{
private:
  std::string detector_type;
  bool status; // true for on, false for off
  int electron_count = 0, antielectron_count = 0, muon_count = 0, antimuon_count = 0;

public:
  // Constructors & destructor
  detector() : status(false) {}
  detector(const std::string& type, bool is_on) : detector_type(type), status(is_on) 
  {std::cout<<"Constructing dector: "<<detector_type<<std::endl;}
  ~detector() {std::cout<<"Destructing detector: "<<detector_type<<std::endl;}

  // Setters and getters
  std::string get_detector_type() const {return detector_type;}
  double get_status() const {return status;}
  int get_electron_count() const {return electron_count;}
  int get_antielectron_count() const {return antielectron_count;}
  int get_muon_count() const {return muon_count;}
  int get_anitmuon_count() const {return antimuon_count;}

  void set_electron_count(const int& count) { electron_count = count; }
  void set_antielectron_count(const int& count) { antielectron_count = count; }
  void set_muon_count(const int& count) { muon_count = count; }
  void set_antimuon_count(const int& count) { antimuon_count = count; }

  // Turn detector on/off
  void turn_on() {status = true;}
  void turn_off() {status = false;}

  // Member functions
  void reset_counts();
  bool detect_particle(const Particle& p);
  void print_status() const;
};

#endif
