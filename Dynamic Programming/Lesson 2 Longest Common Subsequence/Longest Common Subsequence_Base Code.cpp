/**

Dynamic programming lesson 2

Longest Common Subsequence

Also a solution of - UVA 10405 Longest Common Subsequence (https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346)

Learning source - https://www.youtube.com/watch?v=NnD96abizww&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=3#t=471.487945

Thanks to Tushar Roy :-D

**/

#include <bits/stdc++.h>

using namespace std ;

int memorization[1005][1005];

int main()
{

    char input1[1005] ;
    char input2[1005] ;

    int length1 ;
    int length2 ;

    while(gets(input1))
    {
        gets(input2);



        memset(memorization , 0 , sizeof(memorization));


        length1 = strlen(input1) ;
        length2 = strlen(input2) ;


        for(int i = 1 ; i <= length1 ; i++)
        {
            for(int j = 1 ; j <= length2 ; j++)
            {
                if(input1[i-1] == input2[j-1])
                {
                    memorization[i][j] = memorization[i-1][j-1] + 1 ;
                }
                else
                {
                    memorization[i][j] = max(memorization[i][j-1] , memorization[i-1][j]);
                }
            }
        }


        printf("%d\n" , memorization[length1][length2]);
    }

    return 0 ;
}
