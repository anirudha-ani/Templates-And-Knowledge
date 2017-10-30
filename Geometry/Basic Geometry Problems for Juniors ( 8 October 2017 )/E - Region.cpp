#include <bits/stdc++.h>

using namespace std ;

#define PI acos(-1.0)

double square(double x)
{
    return x * x ;
}

int main()
{
    int k;
    double R1 , R2 , R3 ;
    scanf("%d", &k);

    for(int i = 0 ; i < k ; i++)
    {
        scanf("%lf %lf %lf", &R1 , &R2 , &R3);

        double a , b , c , A , B , C ;

        a = R2 + R3;
        b = R1 + R3;
        c = R1 + R2;

        //cout << "a = " << a << " b =" << b << " c = " << c << endl ;

        A = acos((square(c) + square(b) - square(a))/ (2.0 * b * c));
        B = acos((square(a) + square(c) - square(b))/ (2.0 * a * c));
        C = acos((square(a) + square(b) - square(c))/ (2.0 * b * a));
        //cout << "Total = " << A + B + C << endl ;
        double s = (a+b+c)/2.0;
        double area = sqrt(s * (s-a) * (s-b) * (s-c));

        double area_a = R1 * R1 * A / 2.0 ;
        double area_b = R2 * R2 * B / 2.0;
        double area_c = R3 * R3 * C / 2.0 ;
        //cout << " ANGLE " << endl;
        //cout << "A = " << A * 180.0 / PI << " B = " << B * 180.0 / PI << " C = " <<  C  * 180.0 / PI << endl ;
        //cout << "area = << " << area << " a = " << area_a << " b =" << area_b << " c = " << area_c << endl ;
        double remaining_area = area - area_a - area_b - area_c;

        printf("%.6f\n", remaining_area);
    }
    return 0;
}
