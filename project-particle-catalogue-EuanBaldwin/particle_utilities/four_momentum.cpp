// Particle Catalogue - Euan Baldwin - PHYS30762
// Implementation file for the four momentum class
// Implements methods for managing and validating four-momentum vectors
// Last updated: 08/05/2024

#include "four_momentum.h"

// Toggle rule-of-five printout mode (set to false by default)
bool Four_momentum::debug_mode = false;

// Default constructor
Four_momentum::Four_momentum() : momentum(4, 0.0) 
{
  if(debug_mode){std::cout<<"Four_momentum default constructor called."<<std::endl;}
}

// Parameterised constructor
Four_momentum::Four_momentum(const std::string& name, double E, double px, double py, double pz)
  : momentum({E, px, py, pz}), name(name)
{
  if(debug_mode){std::cout<<"Four_momentum constructor called."<<std::endl;}
}

// Copy constructor
Four_momentum::Four_momentum(const Four_momentum& other) : momentum(other.momentum) 
{
  if(debug_mode){std::cout<<"Four_momentum copy constructor called."<<std::endl;}
}

// Assignment operator
Four_momentum& Four_momentum::operator=(const Four_momentum& other) 
{
  if(debug_mode)
    std::cout<<"Four_momentum assignment operator called."<<std::endl;
  if(this != &other) // Protect against self-assignment
    momentum = other.momentum; // Copy the contents of the vector
  return *this;
}

// Move Constructor
Four_momentum::Four_momentum(Four_momentum&& other) noexcept : momentum(std::move(other.momentum)) 
{
  if(debug_mode){std::cout<<"Four_momentum move constructor called."<<std::endl;}
}

// Move Assignment Operator
Four_momentum& Four_momentum::operator=(Four_momentum&& other) noexcept
{
  if(debug_mode)
    std::cout<<"Four_momentum move assignment operator called."<<std::endl;
  if(this != &other)
    momentum = std::move(other.momentum);
  return *this;
}

// Destructor
Four_momentum::~Four_momentum() 
{ 
  if(debug_mode){std::cout<<"Four_momentum destructor called."<<std::endl;}
};

// Setter function to ensure energy is positive and physical
void Four_momentum::setE(double E) 
{ 
  if(E < 0) 
  {
    std::cerr<<"\033[0;31mInvalid particle energy. Setting energy to 0.\033[0m"<<std::endl;
    E = 0;
  }
  (momentum)[0] = E;
}

// Prints the four-momentum components in scientific notation
void Four_momentum::print_four_momentum() const 
{
    std::cout<<std::left<<std::setw(20)<<"Four-momentum: "<<"["<<std::scientific;
    std::cout<<std::setw(6)<<std::setprecision(2)<<getE()<<", ";
    std::cout<<std::setw(6)<<std::setprecision(2)<<getpx()<<", ";
    std::cout<<std::setw(6)<<std::setprecision(2)<<getpy()<<", ";
    std::cout<<std::setw(6)<<std::setprecision(2)<<getpz()<<"]"<<" GeV"<<std::fixed<<std::endl;
}

// Vector addition operation
Four_momentum Four_momentum::operator+(const Four_momentum& other) const 
{
  return Four_momentum("", getE() + other.getE(), getpx() + other.getpx(), getpy() + other.getpy(), getpz() + other.getpz());
}

// Vector subtraction operation
Four_momentum Four_momentum::operator-(const Four_momentum& other) const 
{
  return Four_momentum("", getE() - other.getE(), getpx() - other.getpx(), getpy() - other.getpy(), getpz() - other.getpz());
}

// Vector addition assignment operation
Four_momentum& Four_momentum::operator+=(const Four_momentum& other) 
{
  momentum[0] += other.momentum[0];
  momentum[1] += other.momentum[1];
  momentum[2] += other.momentum[2];
  momentum[3] += other.momentum[3];
  return *this;
}

// Four-vector multiplication (inner product)
double Four_momentum::operator*(const Four_momentum& other) const 
{
  return getE() * other.getE() - (getpx() * other.getpx() + getpy() * other.getpy() + getpz() * other.getpz());
}

// Invariant mass calculation
double Four_momentum::invariant_mass() const 
{
  return sqrt(std::max(0.0, *this * *this)); // Handles negative values
}

// Checks mass consistency and adjusts the momentum if the known mass deviates from the calculated mass
void Four_momentum::check_mass_consistency() 
{
  double known_mass = Particle_properties::get_mass(name); // Retrieve known mass of the particle
  double calculated_mass = invariant_mass();
  double fractional_difference = std::fabs(known_mass - calculated_mass) / known_mass;

  if(fractional_difference > 0.01) // If more than 1% difference, four-momentum is scaled
  {
    std::cerr<<"\033[0;31mInvariant mass inconsistency for "<<name<<".\033[0m" << std::endl;
    std::cerr<<"  Known mass: "<<std::scientific<<std::setprecision(2)<<known_mass<<" GeV"<<std::endl;
    std::cerr<<"  Calculated mass: "<<std::scientific<<std::setprecision(2)<<calculated_mass<<" GeV"<<std::endl;

    // Adjust four-momentum components to match known mass
    double scale_factor = known_mass / calculated_mass;
    if(calculated_mass != 0.0)
    {
      setE(getE() * scale_factor);
      setpx(getpx() * scale_factor);
      setpy(getpy() * scale_factor);
      setpz(getpz() * scale_factor);
    }
    else // Prevents NaN in case of (0, 0, 0, 0) for massive particles
    {
      setE(known_mass);
      setpx(0);
      setpy(0);
      setpz(0);
    }
  }
}
