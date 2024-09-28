#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
#include <vector>

class Particle
{
protected:
  std::string type;
  std::vector<double>* four_momentum;
  int charge;
  void set_charge();

public:
  Particle();                                                                      // Default constructor
  Particle(std::string particle_type, double E, double px, double py, double pz);  // Parameterised constructor
  Particle(const Particle& other);                                                 // Copy constructor
  ~Particle() {delete four_momentum; std::cout<<"Calling destructor."<<std::endl;} // Destructor
  Particle& operator=(const Particle& other);                                      // Assignment operator
  Particle(Particle&& other) noexcept;                                             // Move constructor
  Particle& operator=(Particle&& other) noexcept;                                  // Move assignment operator
  
  // Getter functions
  std::string get_particle_type() const {return type;}
  int get_charge() const {return charge;}
  double getE() const { return (*four_momentum)[0]; }
  double getpx() const { return (*four_momentum)[1]; }
  double getpy() const { return (*four_momentum)[2]; }
  double getpz() const { return (*four_momentum)[3]; }

  // Setter functions
  void set_particle_type(const std::string& p_type);
  void setE(double E);
  void setpx(double px) { (*four_momentum)[1] = px; }
  void setpy(double py) { (*four_momentum)[2] = py; }
  void setpz(double pz) { (*four_momentum)[3] = pz; }

  // Member functions
  void print_data() const;
  Particle operator+(const Particle& other) const; // Overloading the plus operator to handle 4-vectors
  double dotProduct(const Particle& other) const;
};

#endif
