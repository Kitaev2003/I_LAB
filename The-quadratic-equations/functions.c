#define There_are_no_roots 0
#define One_root 1
#define Two_roots 2
#define The_coefficients_are_zero 3

int cmp_with_zero(double val)
    {
    if (fabs(val) < 0.0001)
        {
        return 1;
        }
    else
        {
        return 0;
        }
    }

double Discriminant_(double a, double b, double c)
    {
    return b*b - 4*a*c;
    }

double Square_equation( double a, double b, double c, double* x1, double* x2)
    {

    if (cmp_with_zero(a) && cmp_with_zero(b))
        {
        return The_coefficients_are_zero;
        }
    else

        if (cmp_with_zero(a) != 0 && cmp_with_zero(b) == 0 && cmp_with_zero(c) == 0)
            {
            *x1 = -c/b;

            return One_root;
            }
        else

            if (cmp_with_zero(a) == 0 && cmp_with_zero(b) != 0 && cmp_with_zero(c) != 0)
                {
                *x1 = 0;

                return One_root;
                }
            else

                if (cmp_with_zero(a) != 0 && cmp_with_zero(b) == 0 && cmp_with_zero(c) != 0)
                    {
                    *x1 = 0;

                    return One_root;
                    }
                else

                    if (cmp_with_zero(a) == 0 && cmp_with_zero(b) != 0 && c < 0)
                        {
                        *x1 = sqrt(c/a);
                        *x2 = -sqrt(c/a);

                        return Two_roots;
                        }
                    else

                        if (cmp_with_zero(a) == 0 && cmp_with_zero(b) == 0 && cmp_with_zero(c) != 0)
                            {
                            *x1 = 0;
                            *x2 = -b/a;

                            return Two_roots;
                            }
                        else

                            if (Discriminant_(a, b, c) < 0)
                                {
                                return There_are_no_roots;
                                }
                            else

                                if (cmp_with_zero(Discriminant_(a, b, c)) == 1)
                                    {
                                    *x1 = -b/(2*a);

                                    return One_root;
                                    }
                                else

                                    if (Discriminant_(a, b, c) > 0)
                                        {
                                        *x1 = (-b + sqrt(Discriminant_(a, b, c)))/(2*a);
                                        *x2 = (-b - sqrt(Discriminant_(a, b, c)))/(2*a);

                                        return Two_roots;
                                        }
                                    else
                                        {
                                        return There_are_no_roots;
                                        }
    }

void Print_function(double a, double b, double c)
    {

    double x1 = NAN, x2 = NAN;

    if (Square_equation(a, b, c, &x1, &x2) == There_are_no_roots)
        {
        printf("There are no roots");
        }

    if (Square_equation(a, b, c, &x1, &x2) == One_root)
        {
        printf("x = %f",x1);
        }

    if  (Square_equation(a, b, c, &x1, &x2) == Two_roots)
        {
        printf("x1 = %f, x2 = %f",x1, x2);
        }

    if  (Square_equation(a, b, c, &x1, &x2) == The_coefficients_are_zero)
        {
        printf("Infinite number of roots");
        }
    }

void Unit_Test_Square_equation()
    {
//Test #1//
    double x1 = NAN, x2 = NAN;

    if (Square_equation(1, 5, -6, &x1, &x2) == Two_roots)
        {
        Print_function(1, 5, -6);
        printf("\nTest #1 was successful ! \n");
        printf("----------------------------\n");
        }
    else
        {
        printf("\nTest #1 did NOT pass the test !!!\n");
        printf("----------------------------\n");
        }
//Test #2//

    if (Square_equation(2, 5, 3, &x1, &x2) == Two_roots)
        {
        Print_function(2, 5, 3);
        printf("\nTest #2 was successful !\n");
        printf("----------------------------\n");
        }
    else
        {
        printf("\nTest #2 did NOT pass the test !!!\n");
        printf("----------------------------\n");
        }
    //Test #3//

    if (Square_equation(0, 34, 0, &x1, &x2) == One_root)
        {
        Print_function(0, 34, 0) ;
        printf("\nTest #3 was successful !\n");
        printf("----------------------------\n");
        }
    else
        {
        printf("\nTest #3 did NOT pass the test !!!\n");
        printf("----------------------------\n");
        }
    //Test #4//

    if (Square_equation(34, 3, 9, &x1, &x2) == There_are_no_roots)
        {
        Print_function(34, 3, 9);
        printf("\nTest #4 was successful !\n");
        printf("----------------------------\n");
        }
    else
        {
        printf("\nTest #4 did NOT pass the test !!!\n");
        printf("----------------------------\n");
        }
    //Test #5//

    if (Square_equation(0.000001, 0.000000001, 0.000000000001, &x1, &x2) == The_coefficients_are_zero)
        {
        Print_function(0.000001, 0.000000001, 0.000000000001);
        printf("\nTest #5 was successful !\n");
        printf("----------------------------\n");
        }
    else
        {
        printf("\nTest #5 did NOT pass the test !!!\n");
        printf("----------------------------\n");
        }
    }
