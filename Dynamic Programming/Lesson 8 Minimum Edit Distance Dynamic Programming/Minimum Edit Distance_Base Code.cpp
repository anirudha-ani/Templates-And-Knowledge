/**

Problem - SPOJ EDIST Edit Distance (http://www.spoj.com/problems/EDIST/)

Solution - Dynamic Programming (Longest Common Subsequence/Minimum Edit Distance) + Levenshtein Distance (https://en.wikipedia.org/wiki/Levenshtein_distance)


Learning Source - https://www.youtube.com/watch?v=We3YDTzNXEk
**/

#include <bits/stdc++.h>

using namespace std ;

int memorization[2005][2005];

int main()
{
    int T ;
    string A , B ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        cin >> A ;
        cin >> B ;

        int length1 = A.length();
        int length2 = B.length();
        for(int j = 1 ; j < 2005 ; j++ )
        {

            memorization[j][0] = j;
            memorization[0][j] = j ;
        }
        for(int j = 1 ; j <= length1 ; j++ )
        {
            for(int k = 1 ; k <= length2 ; k++)
            {
                int cost = 0 ;
                //cout << A[j-1] << " " << B[k-1] << endl;
                if(A[j-1] == B[k-1])
                {
                    cost = 0 ;
                }
                else
                {
                    cost = 1 ;
                }
                //cout << A[j-1] << " " << B[k-1] << endl;
                memorization[j][k] = min( min(memorization[j-1][k] , memorization[j][k-1]) + 1 , memorization[j-1][k-1] + cost ) ;

            }
        }
        printf("%d\n",memorization[length1][length2] );
    }
    return 0 ;
}
