#include <iostream>
#include "particle.h"
using std::string;

void Particle::set_particle_type(const string& p_type) 
{
  if(p_type == "electron" || p_type == "antielectron" || p_type == "muon" || p_type == "antimuon" || p_type == "unknown")
    type = p_type;
  else
  {
    std::cerr<<"\033[0;31m"<<"Invalid particle type. Setting "<<p_type<<" to be an electron."<<"\033[0m"<<std::endl;
    type = "electron";
  }
}

void Particle::setE(double E) 
{ 
  if(E < 0) 
  {
    std::cerr<<"\033[0;31mInvalid "<<type<<" energy. Setting energy to 0.\033[0m"<<std::endl;
    E = 0;
  }
  (*four_momentum)[0] = E;
}

void Particle::set_charge() 
{
  if(type.find("anti") != string::npos)
    charge = 1;
  else
    charge = -1;
}

// Function to print info about a particle
void Particle::print_data() const 
{
  std::cout.precision(3);
  double energy = (*four_momentum)[0];
  double px = (*four_momentum)[1];
  double py = (*four_momentum)[2];
  double pz = (*four_momentum)[3];
  std::cout<<type<<": "<<charge<<"e, "<< "P = ["<<energy<<", "<<px<<", "<<py<<", "<<pz<<"] MeV"<<std::endl;
}

// Overloaded "+" operator for summing four-vectors
Particle Particle::operator+(const Particle& other) const 
{
  Particle result; // Default constructor
  result.charge = get_charge() + other.get_charge();
  result.setE(getE() + other.getE());
  result.setpx(getpx() + other.getpx());
  result.setpy(getpy() + other.getpy());
  result.setpz(getpz() + other.getpz());
  return result;
}

// Function for dot product of two particle four-vectors
double Particle::dotProduct(const Particle& other) const 
{
  return getE() * other.getE() - (getpx() * other.getpx() + getpy() * other.getpy() + getpz() * other.getpz());
}

// Default constructor
Particle::Particle() 
  : type("unknown"), four_momentum(new std::vector<double>(4, 0)) 
  {std::cout<<"Calling default constructor."<<std::endl;};

// Parameterised constructor
Particle::Particle(std::string particle_type, double E, double px, double py, double pz)
  : four_momentum(new std::vector<double>(4, 0))
{
  std::cout<<"Calling constructor."<<std::endl;
  set_particle_type(particle_type);
  setE(E); setpx(px); setpy(py); setpz(pz);
  set_charge();
}

// Copy constructor (needs to make a deep copy of the std::vector holding the 4-momentum)
Particle::Particle(const Particle& other) 
  : type(other.type), four_momentum(new std::vector<double>(*other.four_momentum)), charge(other.charge) 
  {std::cout<<"Calling copy constructor."<<std::endl;}

// Assignment operator (needs to avoid self-assignment using the *this pointer)
Particle& Particle::operator=(const Particle& other) 
{
  std::cout<<"Calling assignment operator."<<std::endl;
  if(this != &other) 
  {
    type = other.type;
    charge = other.charge;
    auto new_four_momentum = new std::vector<double>(*other.four_momentum);
    delete four_momentum;
    four_momentum = new_four_momentum;
  }
  return *this;
}

// Move constructor (needs to correctly steal the memory from the object you're calling it on)
Particle::Particle(Particle&& other) noexcept 
  : type(std::move(other.type)), four_momentum(other.four_momentum), charge(other.charge) 
{
  std::cout<<"Calling move constructor."<<std::endl;
  other.four_momentum = nullptr;
}

// Move assignment operator (needs to correctly reassign the memory from the original object)
Particle& Particle::operator=(Particle&& other) noexcept 
{
  std::cout<<"Calling move assignment operator."<<std::endl;
  if(this != &other) 
  {
    type = std::move(other.type);
    charge = other.charge;
    delete four_momentum; // Free the existing memory
    four_momentum = other.four_momentum; // Transfer ownership
    other.four_momentum = nullptr; // Nullify the old object's pointer
  }
  return *this;
}
