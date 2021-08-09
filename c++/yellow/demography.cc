#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;
  Gender gender;
  bool is_employed;
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }

  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;

  nth_element(
    begin(range_copy), middle, end(range_copy), [](const Person& lhs, const Person& rhs) {
      return lhs.age < rhs.age;
    }
  );

  return middle->age;
}

void PrintStats(vector<Person> people) {
  auto female_end = partition(begin(people), end(people), [](const Person& p) {
    return p.gender == Gender::FEMALE;
  });

  auto female_employed_end = partition(begin(people), female_end, [](const Person& p) {
    return p.is_employed;
  });

  auto male_employed_end = partition(female_end, end(people), [](const Person& p) {
    return p.is_employed;
  });

  cout << "Median age = "
       << ComputeMedianAge(begin(people), end(people)) << endl;
  cout << "Median age for females = "
       << ComputeMedianAge(begin(people), female_end) << endl;
  cout << "Median age for males = "
       << ComputeMedianAge(female_end, end(people)) << endl;
  cout << "Median age for employed females = "
       << ComputeMedianAge(begin(people), female_employed_end) << endl;
  cout << "Median age for unemployed females = "
       << ComputeMedianAge(female_employed_end, female_end) << endl;
  cout << "Median age for employed males = "
       << ComputeMedianAge(female_end, male_employed_end) << endl;
  cout << "Median age for unemployed males = "
       << ComputeMedianAge(male_employed_end, end(people)) << endl;
}

int main() {
  vector<Person> persons = {
    {31, Gender::MALE, false},
    {40, Gender::FEMALE, true},
    {24, Gender::MALE, true},
    {20, Gender::FEMALE, true},
    {80, Gender::FEMALE, false},
    {78, Gender::MALE, false},
    {10, Gender::FEMALE, false},
    {55, Gender::MALE, true},
  };

  PrintStats(persons);

  return 0;
}
