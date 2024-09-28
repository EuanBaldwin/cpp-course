// Assignment 5 - Euan Baldwin - PHYS30762
// Implementation of Four_momentum class methods
// Handles physics-related calculations and operations on four-momentum vectors
// Last updated: 19/04/2024

#include "four_momentum.h"

// Toggle rule-of-five printout mode (set to false by default)
bool Four_momentum::debug_mode = false;

// Default constructor
Four_momentum::Four_momentum() : momentum(4, 0.0) 
{
  if(debug_mode){std::cout<<"Four_momentum default constructor called."<<std::endl;}
}

// Parameterised constructor
Four_momentum::Four_momentum(double E, double px, double py, double pz) : momentum({E, px, py, pz}) 
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

// Setter function to ensure energy is positive
void Four_momentum::setE(double E) 
{ 
  if(E < 0) 
  {
    std::cerr<<"\033[0;31mInvalid particle energy. Setting energy to 0.\033[0m"<<std::endl;
    E = 0;
  }
  (momentum)[0] = E;
}

// Print four-momentum vector
void Four_momentum::print_four_momentum() const 
{
  std::cout<<std::left<<std::setw(20)<<"Four-momentum:"<<"["<<std::fixed<<std::setprecision(2)
    <<std::right<<std::setw(6)<<getE()<<", "<<std::setw(6)<<getpx()<<", "
    <<std::setw(6)<<getpy()<<", "<<std::setw(6)<<getpz()<<"]"<<std::endl;
}

// Function to overide + operator to sum two four-momentum vectors
Four_momentum operator+(const Four_momentum& lhs, const Four_momentum& rhs) 
{
  return Four_momentum(lhs.getE() + rhs.getE(), lhs.getpx() + rhs.getpx(), 
    lhs.getpy() + rhs.getpy(), lhs.getpz() + rhs.getpz());
}

// Function to compute inner product of two four-momentum vectors
double dot_product(const Four_momentum& lhs, const Four_momentum& rhs) 
{
  return lhs.getE() * rhs.getE() - (lhs.getpx() * rhs.getpx() + 
    lhs.getpy() * rhs.getpy() + lhs.getpz() * rhs.getpz());
}
