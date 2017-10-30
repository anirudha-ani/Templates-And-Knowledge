#include <bits/stdc++.h>
#include <unordered_set>
using namespace std ;


int grundy[105] ;


int main()
{
    int test_case , stones ;

    grundy[1] = 0;
    grundy[2] = 1;
    grundy[3] = 1;
    grundy[4] = 1;
    grundy[5] = 1;

    for(int i = 6 ; i < 105 ; i++)
    {
        if(grundy[i-2] == 0 || grundy[i-3] == 0 || grundy[i-5] == 0)
        {
            grundy[i] = 1;
        }
    }

    scanf("%d", &test_case);

    for(int i = 1 ; i <= test_case ; i++)
    {
        scanf("%d" , &stones);

        if(grundy[stones] == 0)
        {
            printf("Second\n");
        }
        else
        {
            printf("First\n");
        }
    }
    return 0;
}
