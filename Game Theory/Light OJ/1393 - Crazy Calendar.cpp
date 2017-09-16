#include <bits/stdc++.h>

using namespace std ;

#define lol long long int
int main()
{
    lol T ;

    scanf("%lld", &T);

    for(lol i = 0 ; i < T ; i++)
    {
        lol row , col , input , ans = 0;

        scanf("%lld %lld", &row , &col);

        for(lol j = 0 ; j < row ; j++)
        {
            for(lol k = 0 ; k < col ; k++)
            {
                scanf("%lld", &input);

                if(((row - j) + (col - k)) %2 != 0)
                {
                    ans ^= input;
                }
            }
        }
        if(ans == 0)
        {
            printf("Case %lld: lose\n",i+1);
        }
        else
        {
            printf("Case %lld: win\n", i+1);
        }
    }
    return 0 ;
}
