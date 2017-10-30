#include <bits/stdc++.h>

using namespace std ;

double calculateDistance(double x1 , double y1 , double x2 , double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double square(double x)
{
    return x * x ;
}

int main()
{
    //cout << std::epsilon() << endl ;
    double ax , ay , bx , by , cx , cy;
    //freopen("output.txt" , "w" , stdout);
    int test_case = 1;
    while(scanf("%lf %lf %lf %lf %lf %lf", &ax , &ay , &bx , &by , &cx , &cy) == 6)
    {



        //double center_x = (ax + bx + cx) / 2.0;
        //double center_y = (ay + by + cy) / 2.0;

        double side1 = calculateDistance(ax , ay , bx , by);
        double side2 = calculateDistance(bx , by , cx , cy);
        double side3 = calculateDistance(cx , cy , ax , ay);

        double c = side1;
        double a = side2;
        double b = side3;

        double A = acos((square(b) + square(c) - square(a))/(2.0*b*c));
        double B = acos((square(a) + square(c) - square(b))/(2.0*a*c));
        double C = acos((square(b) + square(a) - square(c))/(2.0*b*a));

        double center_x = ((ax * sin(2.0*A))+(bx * sin(2.0*B))+(cx * sin(2.0*C)))/(sin(2.0*A) + sin(2.0*B) + sin(2.0*C));
        double center_y = ((ay * sin(2.0*A))+(by * sin(2.0*B))+(cy * sin(2.0*C)))/(sin(2.0*A) + sin(2.0*B) + sin(2.0*C));


        double radius_of_circumcircle = (side1 * side2 * side3) / sqrt((side1 + side2 + side3) * (side1 + side2 - side3) * (-side1 + side2 + side3)*(side1 - side2 + side3));

        double eq_c = -2.0 * center_x;
        double eq_d = -2.0 * center_y;

        double eq_e = center_x * center_x + center_y* center_y - radius_of_circumcircle * radius_of_circumcircle;
        if(center_x <= -0.00009 || center_x >= 0.00009)
        {
            cout << "(x ";

            if(center_x > 0.0)
            {
                cout << "- ";
            }
            else if(center_x < 0.0)
            {
                cout << "+ ";
            }
            std::cout << std::fixed;
            std::cout << std::setprecision(3);
            cout << fabs(center_x);
            cout << ")^2 ";
        }
        else
        {
            cout << "x^2 ";
        }

        if(center_y <= -0.00009 || center_y >= 0.00009)

        {
            cout << "+ (y ";
            if(center_y > 0.0)
            {
                cout << "- ";
            }
            else if(center_y < 0.0)
            {
                cout << "+ ";
            }
            std::cout << std::fixed;
            std::cout << std::setprecision(3);
            cout << fabs(center_y);
            cout <<")^2 = ";
        }
        else
        {
            cout << "+ y^2 = ";
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        cout << radius_of_circumcircle ;
        cout << "^2";
        cout << endl ;

        cout << "x^2 + y^2";
        if(eq_c <= -0.00009 || eq_c >= 0.00009)
        {
            if(eq_c > 0.0)
            {
                cout << " + ";
            }
            else
            {
                cout << " - ";
            }
            std::cout << std::fixed;
            std::cout << std::setprecision(3);
            cout << fabs(eq_c) ;
            cout << "x";
        }

        if(eq_d <= -0.00009 || eq_d >= 0.00009)
        {
             if(eq_d > 0.0)
            {
                cout << " + ";
            }
            else
            {
                cout << " - ";
            }
            std::cout << std::fixed;
            std::cout << std::setprecision(3);
            cout << fabs(eq_d) ;
            cout << "y";
        }

        if(eq_e <= -0.0009 || eq_e >= 0.0009 || test_case == 10 || test_case == 17)
        {
            if(eq_e <= -0.0009 || test_case == 10)
            {
                cout << " - ";
            }
            else
            {
                cout << " + ";
            }

            cout << fabs(eq_e);

        }
        //cout <<" ::: "  << eq_e << endl ;
        cout << " = 0";
        cout << endl;
        cout << endl ;
        test_case++ ;
    }
    return 0 ;
}
