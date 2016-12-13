#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

bool isPrime[MAX];

int countSieve()
{
    memset(isPrime , 1 , sizeof(isPrime));

    for(int i = 2 ; i * i <= MAX ; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = i * i ; j <= MAX ; j += i)
            {
                isPrime[j] = false ;
            }
        }
    }
}
int main()
{
    countSieve();

    int x ;
    while(cin >> x)
    {
        if(isPrime[x])
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0 ;
}
