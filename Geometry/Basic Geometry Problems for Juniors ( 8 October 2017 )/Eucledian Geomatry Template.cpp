
#include <bits/stdc++.h>

using namespace std ;

#define PI 3.141592653589793

double calculateDistance(double x1 , double y1 , double x2 , double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double square(double x)
{
    return x * x ;
}
//***************ALL ABOUT CIRCUMCIRCLE******************************//

//GIVEN THREE VERTEX POINTs of A TRIANGLE FIND THE RADIUS/CIRCUMFERENCE/CENTER OF CIRCUMCIRCLE

void circumCircle(double ax , double ay , double bx , double by , double cx , double cy)
{
    double side1 = calculateDistance(ax , ay , bx , by);
    double side2 = calculateDistance(bx , by , cx , cy);
    double side3 = calculateDistance(cx , cy , ax , ay);

    double c = side1;
    double a = side2;
    double b = side3;

    double radius_of_circumcircle = (side1 * side2 * side3) / sqrt((side1 + side2 + side3) * (side1 + side2 - side3) * (-side1 + side2 + side3)*(side1 - side2 + side3));

    double circumference = 2 * PI * radius_of_circumcircle;

    double center_x = ((ax * sin(2.0*A))+(bx * sin(2.0*B))+(cx * sin(2.0*C)))/(sin(2.0*A) + sin(2.0*B) + sin(2.0*C));
    double center_y = ((ay * sin(2.0*A))+(by * sin(2.0*B))+(cy * sin(2.0*C)))/(sin(2.0*A) + sin(2.0*B) + sin(2.0*C));


}


//***************ALL ABOUT INNERCIRCLE******************************//
//GIVEN THREE SIDES of A TRIANGLE FIND THE RADIUS OF INNERCIRCLE
void innerCircle(double side1 . double side2 , double side3)
{
    double radius_of_innercircle = 0.0;
    if(side1 == 0 && side2 == 0 && side3 == 0)
    {
        radius_of_innercircle = 0.0;
    }
    double ordho_porishima = (side1 + side2 + side3) / 2.0;
    double area = sqrt(ordho_porishima * (ordho_porishima - side1) * (ordho_porishima - side2) * (ordho_porishima - side3));
    radius_of_innercircle = area / ordho_porishima;
}


//************* MEDIANS *********************

//Given three medians calculate the area of triangle
//Using Heron's formula

void area_from_median(double median1 , double median2 , double median3)
{
    double semi_Sum = (median1 + median2 + median3) / 2.0;
    double area;
    if(median1 >= semi_Sum || median2 >= semi_Sum || median3 >= semi_Sum || semi_Sum == 0.0)
    {
        area = -1.000
    }
    else
    {
        area = 4.0 / 3.0 * sqrt(semi_Sum * (semi_Sum - median1) * (semi_Sum - median2) * (semi_Sum - median3));
    }

}


//***********VALID TRIANGLE **********************/

int checkValidTriangle(long long int side1 , long long int side2 , long long int side3)
{
    // 1 - Invalid
    // 2 - Equilateral
    // 3 - Isosceles
    // 4 - Scalene

    int status_code ;

    if((side1 + side2 <= side3) ||(side3 + side2 <= side1)||(side1 + side3 <= side2) || (side1 <= 0) || (side2 <= 0) || (side3 <= 0))
    {
        status_code = 1;
    }
    else if(side1 == side2 && side2 == side3)
    {
        status_code = 2;
    }
    else if(side1 == side2 || side2 == side3 || side1 == side3)
    {
        status_code = 3;
    }
    else
    {
        status_code = 4;
    }

    return status_code ;
}
