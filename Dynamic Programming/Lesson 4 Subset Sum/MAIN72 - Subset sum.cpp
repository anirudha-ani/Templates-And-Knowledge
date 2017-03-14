/**
    Problem Link = http://www.spoj.com/problems/MAIN72/
    Solving Technique - Subset Sum Dynamic Programming
    Learning Resouce - https://www.youtube.com/watch?v=s6FhG--P7z0&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=4
**/

#include <bits/stdc++.h>

using namespace std ;

bool DP[100005][105];
bool possible[100005];
vector <int> data ;

int main()
{
    int T , N , input ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &N);
        data.clear();

        int MAX_SUM = 0 ;
        memset(possible , 0 , sizeof(possible));
        possible[0] = true ;

        int ans = 0 ;

        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d", &input);

            data.push_back(input);

            MAX_SUM += input;
        }

        for(int j = 0  ; j < 105 ; j++)
        {
            DP[0][j] = true ;
        }

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j <= MAX_SUM ; j++)
            {
                if(possible[j])
                {
                    DP[j][i] = true;
                    continue;
                }

                if(j==data[i])
                {
                    DP[j][i] = true ;
                }
                else if(j < data[i])
                {
                    if(i!=0)
                    {
                        DP[j][i] = DP[j][i-1];
                    }
                    else
                    {
                        DP[j][i] = false ;
                    }
                }
                else
                {
                    if(i != 0)
                    {
                        DP[j][i] = DP[j][i-1] | DP[j-data[i]][i-1];
                    }
                    else
                    {
                        DP[j][i] = false ;
                    }
                }

                if(DP[j][i] == true)
                {
                    //cout << " j = " << j << endl;
                    possible[j] = true ;
                    ans += j ;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0 ;
}
