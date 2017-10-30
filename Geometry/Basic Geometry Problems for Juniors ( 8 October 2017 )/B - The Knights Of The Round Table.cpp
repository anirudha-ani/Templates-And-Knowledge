#include <bits/stdc++.h>

using namespace std ;

int main()
{
    //freopen("output.txt" , "w" , stdout);
    double side1 , side2 , side3;

    while(scanf("%lf %lf %lf", &side1 , &side2 , &side3) == 3)
    {
        if(side1 == 0 && side2 == 0 && side3 == 0)
        {
            printf("The radius of the round table is: 0.000\n");
            continue;
        }
        double ordho_porishima = (side1 + side2 + side3) / 2.0;
        double area = sqrt(ordho_porishima * (ordho_porishima - side1) * (ordho_porishima - side2) * (ordho_porishima - side3));
        double radius_of_innercircle = area / ordho_porishima;

        printf("The radius of the round table is: %.3f\n", radius_of_innercircle);
    }
    return 0;
}
