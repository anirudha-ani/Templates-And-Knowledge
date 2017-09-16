#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int T ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        int k , input1 , input2 , answer = 0 ;

        scanf("%d", &k);

        for(int i = 0 ; i < k ; i++)
        {
            scanf("%d", &input1);
            scanf("%d", &input2);

            answer ^= (input2 - input1 - 1);
        }

        if(answer == 0)
        {
            printf("Case %d: Bob\n", i+1);
        }
        else
        {
            printf("Case %d: Alice\n", i+1);
        }
    }
    return 0 ;
}
