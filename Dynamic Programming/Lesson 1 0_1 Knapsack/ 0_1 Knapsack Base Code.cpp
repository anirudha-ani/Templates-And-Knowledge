/**

Dynamic programming Lesson 1

Basic implementation of 0/1 Knapsack

Learning Source - https://www.youtube.com/watch?v=8LusJS5-AGo&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr

Also a solution of problem - UVA 10130 Supersale (https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1071)

Thanks to Tushar Roy :-D

**/

#include <bits/stdc++.h>

using namespace std ;

int memorization[1005][35];

int main()
{
    int test_cases , number_of_objects , price , weight , number_of_people , weight_limit , answer ;

    scanf("%d", &test_cases);

    for(int i = 0 ; i < test_cases ; i++)
    {

        vector <int> price_list ;
        vector <int> weight_list ;

        memset(memorization , 0 , sizeof(memorization));

        scanf("%d" , &number_of_objects);

        for(int j = 0 ; j < number_of_objects ; j++)
        {
            scanf("%d %d", &price , &weight);

            price_list.push_back(price);
            weight_list.push_back(weight);

        }

        for(int j = 0 ; j < number_of_objects ; j++)
        {
            for(int k = 0 ; k < 35 ; k++)
            {
                if(k < weight_list[j])
                {
                    if(j-1 >= 0)
                    {
                        memorization[j][k] = memorization[j-1][k];
                    }

                }
                else
                {
                    if(j-1 >= 0)
                    {
                        memorization[j][k] = max(price_list[j] + memorization[j-1][k-weight_list[j]] , memorization[j-1][k]);
                    }
                    else
                    {
                        memorization[j][k] = price_list[j] ;
                    }
                }
            }
        }

        answer = 0 ;

        scanf("%d", &number_of_people);

        for(int j = 0 ; j < number_of_people ; j++)
        {
            scanf("%d", &weight_limit);

            answer += memorization[number_of_objects - 1][weight_limit];
        }
        printf("%d\n", answer);

    }
    return 0 ;
}
