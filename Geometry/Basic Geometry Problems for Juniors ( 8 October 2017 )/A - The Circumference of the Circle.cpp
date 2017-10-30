#include <bits/stdc++.h>

using namespace std ;

#define PI 3.141592653589793

double calculateDistance(double x1 , double y1 , double x2 , double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    double x1 , x2 , x3 , y1 , y2 , y3 ;

    while(scanf("%lf %lf %lf %lf %lf %lf", &x1 , &y1 , &x2 ,&y2 , &x3 , &y3) == 6)
    {
        double side1 = calculateDistance(x1 , y1 , x2 , y2);
        double side2 = calculateDistance(x2 , y2 , x3 , y3);
        double side3 = calculateDistance(x1 , y1 , x3 , y3);

        double radius_of_circumcircle = (side1 * side2 * side3) / sqrt((side1 + side2 + side3) * (side1 + side2 - side3) * (-side1 + side2 + side3)*(side1 - side2 + side3));

        double circumference = 2 * PI * radius_of_circumcircle;

        printf("%.2f\n",circumference);
    }
    return 0;
}
