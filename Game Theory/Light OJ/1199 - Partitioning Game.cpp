#include <bits/stdc++.h>

using namespace std ;

int grundy[10005];

int calculate_grundy(int number)
{
    if(grundy[number] != -1)
    {
        return grundy[number];
    }

    set <int> MEX_SET ;

    for(int i = 1 ; i <= number/2 ; i++)
    {
        if(i == number - i)
        {
            break;
        }
        MEX_SET.insert(calculate_grundy(i) ^ calculate_grundy(number - i)) ;

    }

    for(int j = 0 ; j <= number ; j++ )
    {
        if(MEX_SET.find(j) == MEX_SET.end())
        {
            grundy[number] = j;
            return j;
        }
    }
}


int main()
{
    memset(grundy , -1 , sizeof(grundy));
    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 0;


    int T;

    scanf("%d" , &T);

    for(int i = 0 ; i < T ; i++)
    {
        int n , input , current_nim_sum = 0;
        scanf("%d", &n);

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d",&input);

            current_nim_sum ^= calculate_grundy(input);

        }

        if(current_nim_sum == 0)
        {
            printf("Case %d: Bob\n", i+1);
        }
        else
        {
            printf("Case %d: Alice\n", i+1);
        }
    }
    return 0;
}
