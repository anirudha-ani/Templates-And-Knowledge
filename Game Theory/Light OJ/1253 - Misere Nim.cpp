#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int T ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        int k , input , ans = 0 , is_Greater = 0 ;

        scanf("%d", &k);

        for(int j = 0 ; j < k ; j++)
        {
            scanf("%d", &input);
            if(input > 1)
            {
                is_Greater = 1 ;
            }
            ans ^= input;
        }
        if(is_Greater == 1)
        {
            if(ans != 0)
            {
                printf("Case %d: Alice\n", i+1);
            }
            else
            {
                printf("Case %d: Bob\n", i+1);
            }
        }
        else
        {
            if(k%2 == 0)
            {
                printf("Case %d: Alice\n", i+1);
            }
            else
            {
                 printf("Case %d: Bob\n", i+1);
            }
        }

    }
    return 0 ;
}
