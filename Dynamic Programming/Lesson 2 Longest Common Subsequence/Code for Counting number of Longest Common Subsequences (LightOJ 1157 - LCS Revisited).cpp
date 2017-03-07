/**
Problem link - http://lightoj.com/volume_showproblem.php?problem=1157

problem is simple . But be careful about overcounting ;
**/

#include <bits/stdc++.h>

using namespace std;

int LCS[1005][1005];
int ways[1005][1005];
int main()
{
    int T ;
    char input1[10005];
    char input2[10005];
    int length1 ;
    int length2 ;

    for(int i = 0 ; i < 1005 ; i++)
    {
        ways[i][0] = 1 ;
        ways[0][i] = 1 ;
    }

    scanf("%d", &T);
    gets(input1);
    for(int i = 0 ; i < T ; i++)
    {
        gets(input1);
        gets(input2);

        length1 = strlen(input1);
        length2 = strlen(input2);

        for(int j = 1 ; j <= length1 ; j++)
        {
            for(int k = 1 ; k <= length2 ; k++)
            {
                if(input1[j-1] == input2[k-1])
                {
                    LCS[j][k] = LCS[j-1][k-1] + 1 ;
                    ways[j][k] = ways[j-1][k-1];
                }
                else
                {
                    if(LCS[j-1][k] == LCS[j][k-1])
                    {
                        LCS[j][k] = LCS[j-1][k];
                        ways[j][k] = ways[j-1][k] + ways[j][k-1]; //Overcounting May occur

                        if(LCS[j][k-1] == LCS[j-1][k-1]) // Avoiding overcounting
                        {
                            ways[j][k] -= ways[j-1][k-1];
                        }

                        ways[j][k] = (ways[j][k] + 1000007)%1000007;
                    }
                    else if(LCS[j-1][k] > LCS[j][k-1])
                    {
                        LCS[j][k] = LCS[j-1][k];
                        ways[j][k] = ways[j-1][k];
                    }
                    else if(LCS[j-1][k] < LCS[j][k-1])
                    {
                        LCS[j][k] = LCS[j][k-1];
                        ways[j][k] = ways[j][k-1];
                    }
                }
            }
        }
        printf("Case %d: %d\n",i+1 , ways[length1][length2]);
    }


    return 0 ;
}
