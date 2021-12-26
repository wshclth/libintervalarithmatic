#ifndef INTERVAL_ARITHMATIC
#define INTERVAL_ARITHMATIC

/* Expose FE_* to force IEEE rounding standards on the CPU */
#include <fenv.h>
#include <math.h>

#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/**
 * double_int provides interval arithmatic in the form of doubles.
 * 
 * Interval Arithmatic provides rigorousu floating point operations high
 * precision mathematical computations. That being said, interval arithmatic
 * is 3x slower than just ignoring the floating point error and looking the
 * other way. I'll let you decide based on the importance of your calculation
 * what you would like to do...
 */
class double_int
{
  public:
    
    /*
     * Lower is the lower bound on this interval
     */
    double lower = 0;

    /*
     * Upper is the upper bound on this interval
     */
    double upper = 0;
    
    /**
     * Load a normal number as an intervaled value
     * @param num the number to compute its floating point interval on.
     */
    double_int(double num);

    /**
     * Creates a new doubled interval based on given interval values
     * @param lower the lower bound
     * @param upper the upper bound
     */
    double_int(double lower, double upper);
    
    // Operator overloading
    double_int operator+(double_int x);
    double_int operator-(double_int x);
    double_int operator*(double_int x);
    double_int operator/(double_int x);

    double mid();
    double range();

    /**
     * Prints the interval
     * [ lower_bound, upper_bound ]
     */
    void print();
};

#endif
