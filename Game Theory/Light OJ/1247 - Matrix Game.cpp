#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int T;

    scanf("%d",&T);

    for(int i=0 ; i < T ; i++)
    {
        long long int row , col , input ;

        scanf("%lld %lld", &row , &col);

        long long int ans = 0 ;

        for(int j = 0 ; j < row ; j++)
        {
            long long int total = 0 ;
            for(int k = 0 ; k < col ; k++)
            {
                scanf("%lld" , &input);
                total += input ;
            }
            ans ^= total;
        }

        if(ans == 0)
        {
            printf("Case %d: Bob\n" , i+1);
        }
        else
        {
            printf("Case %d: Alice\n", i+1);
        }
    }
    return 0;
}
