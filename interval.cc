#include "interval.h"

double_int::double_int(double num) {
  fesetround(FE_DOWNWARD);
  this->lower = num;

  fesetround(FE_UPWARD);
  this->upper = num;

  fesetenv(FE_DFL_ENV);
}

double_int::double_int(double lower, double upper) {
  this->lower = lower;
  this->upper = upper;
}

double_int double_int::operator+(double_int x) {
  /* force round down and add the lower bounds together */
  fesetround(FE_DOWNWARD);
  double lower_bound = this->lower + x.lower;

  /* force round up and add the upper bounds together */
  fesetround(FE_UPWARD);
  double upper_bound = this->upper + x.upper;

  fesetenv(FE_DFL_ENV);
  
  /* create the new interval */
  return double_int(lower_bound, upper_bound);
}

double_int double_int::operator-(double_int x) {
  /* force round down and add the lower bounds together */
  fesetround(FE_DOWNWARD);
  double lower_bound = this->lower - x.upper;

  /* force round up and add the upper bounds together */
  fesetround(FE_UPWARD);
  double upper_bound = this->upper - x.lower;


  fesetenv(FE_DFL_ENV);
  /* create the new interval */
  return double_int(lower_bound, upper_bound);
}

double_int double_int::operator*(double_int x) {
  std::vector<double> bounds(4);

  /* force round down and add the lower bounds together */
  fesetround(FE_DOWNWARD);
  bounds[0] = this->lower*x.lower;
  bounds[1] = this->lower*x.upper;
  bounds[2] = this->upper*x.lower;
  bounds[3] = this->upper*x.upper;
  double lower_bound = *min_element(bounds.begin(), bounds.end());

  /* force round up and add the upper bounds together */
  fesetround(FE_UPWARD);
  bounds[0] = this->lower*x.lower;
  bounds[1] = this->lower*x.upper;
  bounds[2] = this->upper*x.lower;
  bounds[3] = this->upper*x.upper;
  double upper_bound = *max_element(bounds.begin(), bounds.end());

  fesetenv(FE_DFL_ENV);
  /* create the new interval */
  return double_int(lower_bound, upper_bound);
}

double_int double_int::operator/(double_int x) {
  return (*this)*double_int(1.0/x.lower, 1.0/x.upper);
}

double double_int::range() {
  fesetenv(FE_DFL_ENV);
  return this->upper - this->lower;
}

double double_int::mid() {
  fesetenv(FE_DFL_ENV);
  return (this->upper+this->lower)/2.0; 
}

void double_int::print() {
  printf("{\n" \
	    " \"bounds\":   [%.55f, %.55f],\n" \
	    " \"range\":    %.55f,\n" \
	    " \"midpoint\": %.55f\n}\n", this->lower, this->upper, this->upper-this->lower, (this->upper+this->lower)/2.0);
}
