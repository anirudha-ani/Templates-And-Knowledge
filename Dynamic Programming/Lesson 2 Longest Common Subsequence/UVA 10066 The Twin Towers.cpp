/**
Problem Link - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007
Solution - Dynamic Programming (Longest Common Subsequence)
**/

#include <bits/stdc++.h>

using namespace std ;

int memorization[105][105];

int main()
{
    int N1 , N2 , input , case_no = 1 ;

    while(scanf("%d %d", &N1 , &N2) == 2 && (N1 != 0 && N2 != 0))
    {
        vector <int> data1 ;
        vector <int> data2 ;


        for(int i = 0 ; i < N1 ; i++)
        {
            scanf("%d", &input);

            data1.push_back(input);
        }

        for(int i = 0 ; i < N2 ; i++)
        {
            scanf("%d", &input);

            data2.push_back(input);
        }

        for(int i = 1 ; i <= N1 ; i++)
        {
            for(int j = 1 ; j <= N2 ; j++)
            {
                if(data1[i-1] == data2[j-1])
                {
                    memorization[i][j] = memorization[i-1][j-1] + 1;
                }
                else
                {
                    memorization[i][j] = max(memorization[i-1][j] , memorization[i][j-1]);
                }
            }
        }

        printf("Twin Towers #%d\n",case_no);
        printf("Number of Tiles : %d\n\n",memorization[N1][N2]);

        case_no++;

    }
    return 0 ;
}
