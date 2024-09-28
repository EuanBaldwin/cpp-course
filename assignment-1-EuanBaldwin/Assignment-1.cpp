// Assignment 1 - Euan Baldwin - PHYS30762
// Program to calculate transition energy using simple Bohr formula
// Last updated: 6/2/24

#include<iostream>
#include<iomanip>
#include<cmath>
#include<limits>

const double J_in_eV = 1.602e-19; // Conversion factor from eV to Joules

// Calculate transition energy based on the Bohr model
double energy_calc(int Z, int n_i, int n_j)
{
  return 13.6 * pow(Z, 2) * (1/pow(n_j, 2) - 1/pow(n_i, 2));
}

// Clears any error flags and ignores the rest of the current input line
void clearInput()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prompts user for atomic number and initial/final quantum numbers, ensuring valid input
void get_numbers(int& Z, int& n_i, int& n_j)
{
  do 
  {
    std::cout<<"Please enter the atomic number (Z): ";
    while(!(std::cin>>Z) || Z <= 0) // Validates atomic number
    {
      std::cout<<"Input invalid. Please enter a positive integer: ";
      clearInput();
    }

    std::cout<<"Please enter the initial quantum number (n_i): ";
    while(!(std::cin>>n_i) || n_i <= 0) // Validates initial quantum number
    {
      std::cout<<"Input invalid. Please enter a positive integer: ";
      clearInput();
    }

    std::cout<<"Please enter the final quantum number (n_j): ";
    while(!(std::cin>>n_j) || n_j <= 0) // Validates final quantum number
    {
      std::cout<<"Input invalid. Please enter a positive integer: ";
      clearInput();
    }

    if(n_j >= n_i) // Ensures n_j < n_i for a valid transition
    {
      std::cout<<"Invalid quantum numbers. n_j must be less than n_i.\n";
    }
  } while(n_j >= n_i);
}

int main()
{
  int Z, n_i, n_j; // Atomic number, initial quantum number, final quantum number
  char unit, repeat; // Unit for energy output (Joules or eV), repeat flag
  
  do
  {
    // Ask user to enter atomic number and initial and final quantum numbers
    get_numbers(Z, n_i, n_j);

    // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
    double energy = energy_calc(Z, n_i, n_j);

    // Ask user whether to output in eV or J
    std::cout<<"Output energy in Joules (J) or eV (e)? ";
    while(!(std::cin>>unit) || (unit != 'J' && unit != 'e')) // Validates unit choice
    {
      std::cout<<"Input invalid. Please enter either J or e: ";
      clearInput();
    }

    std::cout << std::setprecision(3);

    if(unit == 'e')
    {
      std::cout<<"Transition energy: "<<energy<<" eV"<<std::endl;  // Output answer in eV
    }
    else
    {
      energy *= J_in_eV; // Converts energy to Joules
      std::cout<<"Transition energy: "<<energy<<" J"<<std::endl; // Output answer in J
    }

    // Ask user whether they want to repeat
    std::cout<<"Enter Y/y to calculate another transition's energy or enter anything else to exit: ";
    std::cin>>repeat;
    clearInput();
  } while(repeat == 'Y' || repeat == 'y');

  return 0;
}