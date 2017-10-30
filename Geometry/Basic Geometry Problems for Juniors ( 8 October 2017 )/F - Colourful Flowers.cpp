#include <bits/stdc++.h>

using namespace std ;

#define PI acos(-1.0)

double square(double x)
{
    return x * x ;
}
int main()
{
    double side1 , side2 , side3;

    while(scanf("%lf %lf %lf", &side1 , &side2 , &side3) == 3)
    {

        double ordho_porishima = (side1 + side2 + side3) / 2.0;
        double area = sqrt(ordho_porishima * (ordho_porishima - side1) * (ordho_porishima - side2) * (ordho_porishima - side3));
        double radius_of_circumcircle = (side1 * side2 * side3) / sqrt((side1 + side2 + side3) * (side1 + side2 - side3) * (-side1 + side2 + side3)*(side1 - side2 + side3));
        double radius_of_innercircle = area / ordho_porishima;

        double area_circum = PI * square(radius_of_circumcircle);
        double area_inner = PI * square(radius_of_innercircle);

        double red = area_inner;
        double violets = area - area_inner;
        double yellow = area_circum - area;

        printf("%.4f %.4f %.4f\n", yellow , violets , red);

    }
    return 0;
}
