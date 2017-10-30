#include <bits/stdc++.h>

using namespace std ;

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


int main()
{
    int test_case ;
    long long int side1 , side2 , side3;
    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%lld %lld %lld", &side1 , &side2 , &side3);

        int result = checkValidTriangle(side1 , side2 , side3);

        if(result == 1)
        {
            printf("Case %d: Invalid\n", i+1);
        }
        else if(result == 2)
        {
            printf("Case %d: Equilateral\n", i+1);
        }
        else if(result == 3)
        {
            printf("Case %d: Isosceles\n", i+1);
        }
        else if(result == 4)
        {
            printf("Case %d: Scalene\n", i+1);
        }
    }
}
