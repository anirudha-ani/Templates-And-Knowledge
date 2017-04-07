/**
This is a clever trick learned from forthright48 to reduce a O(n^3)
Dynamic Prgramming Solution to a O(n^2) Solution
It take away n complexity so it is called thief optimization ;-)

Problem link - http://lightoj.com/volume_showproblem.php?problem=1200


**/


#include <bits/stdc++.h>



using namespace std;

#define MAX_CAPACITY 10005
#define MAX_ITEM 105

vector <int> weight_list ;
vector <int> price_list ;
int T , n , W , price , quantity , weight;

int DP[MAX_CAPACITY][MAX_ITEM];

int knapsack_thiefOptimization(int capacity , int currentItem)
{
    if(currentItem >= n)
    {
        return 0;
    }

    if(DP[capacity][currentItem] != -1)
    {
        return DP[capacity][currentItem];
    }

    else
    {
        int profit1 = 0 ;

        if(capacity - weight_list[currentItem] >= 0)
        {
            profit1 = price_list[currentItem] + knapsack_thiefOptimization(capacity - weight_list[currentItem] , currentItem);
        }

        int profit2 = knapsack_thiefOptimization(capacity , currentItem+1);

        DP[capacity][currentItem] = max(profit1 , profit2);
        return DP[capacity][currentItem];
    }
}

int main()
{


    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        weight_list.clear();
        price_list.clear();
        memset(DP , -1 , sizeof(DP));

        scanf("%d %d", &n , &W);

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d %d %d", &price , &quantity , &weight);

            W -= quantity * weight;

            weight_list.push_back(weight);
            price_list.push_back(price) ;
        }

        if(W < 0)
        {
            printf("Case %d: Impossible\n", i+1);
        }
        else
        {
            int answer = knapsack_thiefOptimization(W , 0);
            printf("Case %d: %d\n", i+1 , answer);
        }
    }

    return 0;
}
