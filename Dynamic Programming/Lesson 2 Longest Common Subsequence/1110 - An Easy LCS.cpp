/**
Problem Link LightOJ 1110 - An Easy LCS (http://lightoj.com/volume_showproblem.php?problem=1110)

Solution - Longest Common Subsequence
Also - path print 

**/

#include <bits/stdc++.h>

using namespace std ;

int LCS[105][105];
string backTrack[105][105];

int main()
{
    ios::sync_with_stdio(false);

    int T ;
    string input1 , input2 , ans ;

    cin >> T ;

    for(int i = 0 ; i < T ; i++)
    {
        for(int j = 0 ; j < 105 ; j++)
        {
            for(int k = 0 ; k < 105 ; k++)
            {
                backTrack[j][k] = "";
            }
        }
        cin >> input1 ;
        cin >> input2 ;

        int input1Length = input1.length();
        int input2Length = input2.length();


        for(int j = 1 ; j <= input1Length ; j++)
        {
            for(int k = 1 ; k <= input2Length ; k++)
            {
                if(input1[j-1] == input2[k-1])
                {
                    LCS[j][k] = LCS[j-1][k-1] + 1 ;
                    backTrack[j][k] = backTrack[j-1][k-1]+input1[j-1] ;
                }
                else
                {
                    LCS[j][k] = max(LCS[j-1][k] , LCS[j][k-1]);

                    if(LCS[j-1][k] == LCS[j][k-1])
                    {
                        backTrack[j][k] = backTrack[j-1][k] < backTrack[j][k-1] ? backTrack[j-1][k] : backTrack[j][k-1];
                    }
                    else if(LCS[j-1][k] > LCS[j][k-1])
                    {
                        backTrack[j][k] = backTrack[j-1][k] ;
                    }
                    else if(LCS[j-1][k] < LCS[j][k-1])
                    {
                        backTrack[j][k] = backTrack[j][k-1] ;
                    }
                }
            }
        }
        if( LCS[input1Length][input2Length] == 0 )
        {
            cout << "Case " << i+1 << ": :(" << endl;
            continue;
        }
        //cout << LCS[input1Length][input2Length] << endl ;





        cout << "Case " << i+1 << ": " << backTrack[input1Length][input2Length] << endl ;

    }
    return 0 ;
}
