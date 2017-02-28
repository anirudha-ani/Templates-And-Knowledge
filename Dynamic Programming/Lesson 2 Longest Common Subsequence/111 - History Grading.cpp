#include <bits/stdc++.h>

using namespace std ;

int memorization[22][22];
int data3[22];
int data4[22];

int main()
{

    int input ;
    int length = 0 ;

    scanf("%d", &length);

    for(int i = 0 ; i < length ; i++)
    {
        scanf("%d", &input);
        data4[input-1] = i+1;
    }

    while(scanf("%d", &input) == 1)
    {
        data3[input-1] = 1;
        for(int i = 1 ; i < length ; i++)
        {
            scanf("%d", &input);
            data3[input-1] = i+1;
        }


        for(int i = 1 ; i <= length ; i++)
        {
            for(int j = 1 ; j <= length ; j++)
            {
                if(data4[i-1] != data3[j-1])
                {
                    memorization[i][j] = max(memorization[i-1][j] , memorization[i][j-1]);
                }
                else
                {
                    memorization[i][j] = 1 + memorization[i-1][j-1];
                }

            }

        }
        printf("%d\n" , memorization[length][length]);

    }

    return 0 ;
}
