/**
    Base code - Coin Changing Minimum Number of Coins
    Learning Source - https://www.youtube.com/watch?v=NJuKJ8sasGk&index=20&list=PLgwE03nSxZ4GoHvoy6ay6OSBmcJ6BX2h7
**/

#include <bits/stdc++.h>

using namespace std;

#define INF 10000000

int DP[10005][105];

int main()
{
    int T ,X,N, input;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {



        vector <int> data;

        scanf("%d %d", &X , &N);

        for(int j = 0 ; j <= X ; j++)
        {
            for(int k = 0 ; k <= N ; k++)
            {
                DP[j][k] = INF;
            }
        }

        for(int j = 0 ; j <= N ; j++)
        {
            DP[0][j] = 0;
        }

        //State before DP
        for(int k = 0 ; k < N ; k++)
        {
            for(int j = 0 ; j <= X ; j++)
            {
                printf("%d ", DP[j][k]);
            }
            printf("\n");
        }


        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d", &input);

            data.push_back(input);
        }

        for(int j = 0 ; j <= X ; j++)
        {
            for(int k = 0 ; k < N ; k++)
            {
                if(j == data[k])
                {
                    DP[j][k] = 1 ;
                }
                else if(j < data[k])
                {
                    if(k != 0)
                    {
                        DP[j][k] = DP[j][k-1] ;
                    }
                }
                else
                {
                    if(k != 0)
                    {
                        DP[j][k] = min(DP[j][k-1] , 1+DP[j-data[k]][k-1]);
                    }
                }
            }
        }

        //State after DP
        for(int k = 0 ; k < N ; k++)
        {
            for(int j = 0 ; j <= X ; j++)
            {
                printf("%d ", DP[j][k]);
            }
            printf("\n");
        }

        printf("%d\n", DP[X][N-1]);
    }
    return 0 ;
}
