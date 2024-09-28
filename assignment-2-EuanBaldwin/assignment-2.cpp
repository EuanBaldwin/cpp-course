// Assignment 2 - Euan Baldwin - PHYS30762
// Program to compute mean, standard deviation and standard error of the a set of courses. Data is read from file.
// Last updated: 21/02/2024

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>

// Defines a course structure with properties for mark, code, title, and a concatenated full title.
struct course {double mark; int code; std::string title; std::string full_title;};

// Clears any error flags and ignores the rest of the current input line
void clear_input()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Computes mean
double calc_mean(const std::vector<course>& courses)
{
  double sum = 0.0;
  for(const auto& course : courses)
    sum += course.mark;
  return courses.empty() ? 0 : sum / courses.size();
}

// Computes standard deviation
double calc_stan_dev(const std::vector<course>& courses, double mean)
{
  double sum_squared_diff = 0.0;
  for(const auto& course : courses)
    sum_squared_diff += std::pow(course.mark - mean, 2);
  return courses.empty() ? 0 : std::sqrt(sum_squared_diff / (courses.size() - 1));
}

// Computes standard error on mean
double calc_stan_err(const std::vector<course>& courses, double mean, double stan_dev)
{
  return courses.empty() ? 0 : stan_dev / std::sqrt(courses.size());
}

// Sort by title
bool sort_title(const course& a, const course& b)
{
  return a.title < b.title;
}

// Sort by course code
bool sort_code(const course& a, const course& b)
{
  return a.code < b.code;
}

// Checks if file can be opened and reads in file
std::vector<course> read_courses_from_file(std::string& data_file) 
{
  std::vector<course> courses;
  std::fstream course_stream(data_file);

  while(!course_stream.is_open())
  {
    std::cout<<"Failed to open file: "<<data_file<<". Please enter a valid filename (or '-1' to exit): ";
    std::getline(std::cin, data_file);
    if(data_file == "-1") exit(1);
    course_stream.open(data_file);
  }

  while(course_stream) 
  {
    course course;
    course_stream>>course.mark>>course.code;
    std::getline(course_stream, course.title);
    if(course.title.length() > 0) 
    {
      course.title.erase(0, course.title.find_first_not_of(" \n\r\t"));
      course.full_title = "PHYS " + std::to_string(course.code) + " " + course.title;
      courses.push_back(course);
    }
  }
  course_stream.close();
  std::cout<<"Courses read in: "<<courses.size()<<std::endl;
  return courses;
}

// Main function
int main()
{
  // Define variables
  std::vector <course> courses;
  std::string data_file, sort_style, num_courses;

  // Ask user to enter filename
  std::cout<<"Enter data filename: ";
  std::getline(std::cin, data_file);
  courses = read_courses_from_file(data_file);

  // Ask for sorting of courses and sort appropriately
  std::cout<<"Sort the courses by title or course code? (title/code): ";
  while(!(std::cin>>sort_style) || (sort_style != "title" && sort_style != "code"))
  {
    std::cout<<"Input invalid. Please enter either 'title' or 'code': ";
    clear_input();
  }

  if(sort_style == "title")
    std::sort(courses.begin(), courses.end(), sort_title);
  else
    std::sort(courses.begin(), courses.end(), sort_code);

  // Ask whether to print all courses or just one years worth, then remove unecessary courses 
  std::cout<<"Do you want to print all the courses or a specific year's courses? (all/year): ";
  while(!(std::cin>>num_courses) || (num_courses != "all" && num_courses != "year"))
  {
    std::cout<<"Input invalid. Please enter either 'all' or 'year': ";
    clear_input();
  }

  if(num_courses=="year")
  {
    std::string year;
    std::cout<<"Enter the year (first digit of the course code): ";
    while(!(std::cin>>year) || (year != "1" && year != "2" && year != "3" && year != "4"))
    {
      std::cout<<"Input invalid. Please enter 1, 2, 3 or 4: ";
      clear_input();
    }

    std::vector<course> filtered_courses;
    for(const auto& course : courses)
    {
      if(course.code / 10000 == stoi(year)) // Assumes format is YXXXX
        filtered_courses.push_back(course);
    }
    courses = std::move(filtered_courses);
  }

  // Print sorted course list using an iterator
  std::vector<course>::iterator it;
  for(it = courses.begin(); it != courses.end(); ++it)
    std::cout<<it->full_title<<std::endl;

  // Compute mean, standard error on mean and standard deviation and print to 1 decimal place
  double mean = calc_mean(courses);
  double stan_dev = calc_stan_dev(courses, mean);

  std::cout<<std::fixed<<std::setprecision(1);
  std::cout<<"\nMean mark: "<<mean<<"%"<<std::endl;
  std::cout<<"Standard deviation: "<<stan_dev<<"%"<<std::endl;
  std::cout<<"Standard error on mean: "<<calc_stan_err(courses, mean, stan_dev)<<"%"<<std::endl;
  return 0;
}
