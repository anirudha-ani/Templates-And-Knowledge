/**
    Problem Link - http://www.spoj.com/problems/MIXTURES/
    Solving Technique - Matrix Chin Multiplication
    Learning Source - http://www.shafaetsplanet.com/planetcoding/?p=1885
**/

#include <bits/stdc++.h>

using namespace std ;


long long int smoke[105][105];
long long int cum_color[105];

long long int matrix_chain_multiplication(long long int start , long long int finish)
{
    if(finish <= start)
        return 0 ;

    else if(smoke[start][finish] != -1)
    {
        return smoke[start][finish];
    }

    for(long long int mid = start ; mid <= finish ; mid++)
    {
        long long left_smoke = matrix_chain_multiplication(start , mid);
        long long right_smoke = matrix_chain_multiplication(mid+1 , finish);

        long long total_smoke = left_smoke + right_smoke + ((cum_color[mid] - (start>=1 ? cum_color[start-1] : 0)) % 100) * ((cum_color[finish] - cum_color[mid])%100) ;

        if(smoke[start][finish] == -1)
        {
            smoke[start][finish] = total_smoke;
        }
        else
        {
            smoke[start][finish] = min(smoke[start][finish] ,total_smoke ) ;
        }
    }
    return smoke[start][finish];
}

int main()
{

    long long int no_of_chemical , answer ,input ;

    while(scanf("%lld", &no_of_chemical) == 1)
    {
        memset(smoke , -1 , sizeof(smoke));

        for(int i = 0 ; i < no_of_chemical ; i++)
        {
            scanf("%lld" , &input);

            if(i == 0)
            {
                cum_color[i] = input;
            }
            else
            {
                cum_color[i] = cum_color[i-1] + input ;
            }
        }

        answer = matrix_chain_multiplication(0 , no_of_chemical-1);

        printf("%lld\n",answer);
    }


    return 0 ;
}
