//Problem link - http://lightoj.com/volume_showproblem.php?problem=1400
//Solution technique - Stable Marriage
//Source - http://www.shafaetsplanet.com/planetcoding/?p=1187
//Code - Self implementation

#include <bits/stdc++.h>

using namespace std;

struct preference
{
    int value ;
    int preferability ;

    preference(int v , int p)
    {
        value = v;
        preferability = p;
    }

    bool operator < (const preference &another) const
    {
        return preferability < another.preferability;
    }
};

int c_pref[205][205];
int e_pref[205][205];

int connection[205];

int main()
{
    int T ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        int n , input ;

        memset(c_pref , -1 , sizeof(c_pref));
        memset(e_pref , -1 , sizeof(e_pref));
        memset(connection , -1 , sizeof(connection));

        priority_queue <preference> employee[205];
        priority_queue <preference> company[205] ;

        scanf("%d", &n);
        //cout << "Here" << endl ;
        for(int j = 1 ; j <= n ; j++)
        {
            for(int k = n ; k > 0 ; k--)
            {
                scanf("%d", &input);

                employee[j].push(preference(input , k));

                e_pref[j][input] = k;
            }
        }
        //cout << "Here" << endl ;
        for(int j = n+1 ; j <= 2*n ; j++)
        {
            for(int k = n ; k > 0 ; k--)
            {
                scanf("%d", &input);

                company[j].push(preference(input , k));

                c_pref[j][input] = k;
            }
        }
        int connection_counter = 0;
        //cout << "Here" << endl ;
        while(connection_counter < n)
        {
            //cout << connection_counter << endl ;
            for(int j = 1 ; j <= n ; j++)
            {
                while(connection[j] == -1)
                {
                    preference topper = employee[j].top();
                    employee[j].pop();

                    if(connection[topper.value] == -1)
                    {
                        connection[j] = topper.value;
                        connection[topper.value] = j;
                        connection_counter++;
                    }
                    else
                    {
                        if(c_pref[topper.value][connection[topper.value]] < c_pref[topper.value][j])
                        {
                            connection[connection[topper.value]] = -1;
                            connection_counter--;
                            connection[topper.value] = j;
                            connection[j] = topper.value;
                            connection_counter++;
                        }
                    }
                }
            }
        }
        printf("Case %d:",i+1 );
        for(int j = 1 ; j <= n ; j++)
        {
            printf(" (%d %d)",j,connection[j]);

        }
        printf("\n");
    }
    return 0;
}
