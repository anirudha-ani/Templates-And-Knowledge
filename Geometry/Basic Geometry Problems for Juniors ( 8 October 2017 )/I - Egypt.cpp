#include <bits/stdc++.h>

using namespace std ;

int main()
{
    long long int side[3] ;

    while(scanf("%lld %lld %lld", &side[0] , &side[1] , &side[2]))
    {
        if(side[2] == 0 && side[1]==0 && side[0] == 0)
        {
            return 0;
        }

        sort(side , side+3);

        if((side[0] * side[0] + side[1] * side[1]) == (side[2] * side[2]))
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}
