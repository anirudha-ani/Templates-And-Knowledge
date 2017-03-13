/**
    Problem Link - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
    Solving Technique - Matrix Chain Multiplication
    Learning Source - http://www.shafaetsplanet.com/planetcoding/?p=1885
**/

#include <bits/stdc++.h>

using namespace std ;

int DP[1005][1005];
int cut[55];
int l , n ;

int solve(int start , int finish)
{
    //cout << start << " " << finish <<endl;
    if(finish <= start)
    {
        return 0;
    }
    else if(DP[start][finish] != 0)
    {
        return DP[start][finish];
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(cut[i] > start && cut[i] < finish)
        {
            int ans = finish - start + solve(start , cut[i]) + solve(cut[i] , finish);
            if(DP[start][finish] == 0)
            {
                DP[start][finish] = ans;
            }
            else
            {
                DP[start][finish] = min(ans , DP[start][finish]);
            }
        }
    }
    //cout << "S = " << start << " F = " << finish << " Ans = " << DP[start][finish] << endl ;
    return DP[start][finish];
}

int main()
{


    while(scanf("%d", &l) && l != 0)
    {
        memset(DP , 0 , sizeof(DP));
        scanf("%d", &n) ;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &cut[i]);
        }

        int ans = solve(0 , l);
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0 ;
}
