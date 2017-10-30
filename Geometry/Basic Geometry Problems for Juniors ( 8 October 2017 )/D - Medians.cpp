#include <bits/stdc++.h>

using namespace std ;

double area_from_median(double median1 , double median2 , double median3)
{
    double semi_Sum = (median1 + median2 + median3) / 2.0;
    double area;
    if(median1 >= semi_Sum || median2 >= semi_Sum || median3 >= semi_Sum || semi_Sum == 0.0)
    {
        area = -1.000;
    }
    else
    {
        area = 4.0 / 3.0 * sqrt(semi_Sum * (semi_Sum - median1) * (semi_Sum - median2) * (semi_Sum - median3));
    }
    return area;
}

int main()
{
    double x , y , z ;

    while(scanf("%lf %lf %lf", &x ,&y , &z) == 3)
    {
        double area = area_from_median(x , y , z);

        printf("%.3f\n", area);
    }
}
