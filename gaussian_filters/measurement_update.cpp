#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

double new_mean, new_var;

tuple<double, double> measurement_update(double mean1, double var1, double mean2, double var2)
{
    new_mean = (pow(var2, 2.0) * mean1 + pow(var1, 2.0) * mean2) / (pow(var2, 2.0) + pow(var1, 2.0));
    new_var = 1 / (1 / pow(var2, 2.0) + 1 / pow(var1, 2.0));
    return make_tuple(new_mean, new_var);
}

int main()
{

    tie(new_mean, new_var) = measurement_update(10, 8, 13, 2);
    printf("[%f, %f]", new_mean, new_var);
    return 0;
}