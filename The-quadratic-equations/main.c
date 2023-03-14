#include "heading.h"

int main()
    {
    Unit_Test_Square_equation();

    double a = NAN, b = NAN, c = NAN;

    assert(scanf("%lg", &a ) == 1);
    assert(scanf("%lg", &b ) == 1);
    assert(scanf("%lg", &c ) == 1);

    Print_function(a, b, c);

    return 0;
    }
