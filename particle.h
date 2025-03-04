#ifndef PARTICLE_H
#define PARTICLE_H

#include<string>

class Particle
{
private:
  std::string type;
  double mass, velocity, beta;
  int charge;
  void update_beta();
  void set_rest_mass();
  void set_charge();

public:
  // Constructors and destructor
  Particle() = default;
  Particle(std::string particle_type, double particle_velocity) : velocity(particle_velocity)
  {
    set_particle_type(particle_type);
    set_velocity(particle_velocity);
    set_charge();
    set_rest_mass();
    std::cout<<"Constructing particle: "<<type<<std::endl;
  }
  ~Particle() {std::cout<<"Destructing particle: "<<type<<std::endl;}

  // Setters and getters
  std::string get_particle_type() const {return type;}
  double get_rest_mass() const {return mass;}
  int get_charge() const {return charge;}
  double get_velocity() const {return velocity;}
  double get_beta() const {return beta;}

  void set_particle_type(const std::string& p_type);
  void set_velocity(double p_velocity);

  // Member functions
  void print_data() const;
};

#endif
