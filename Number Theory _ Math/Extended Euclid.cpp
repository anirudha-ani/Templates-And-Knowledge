#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

pii extendedEuclid(int a, int b)
{
    // returns x, y | ax + by = gcd(a,b)
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}


int main()
{
    pii ans = extendedEuclid(6 , 2);
    cout << ans.x << " " << ans.y << endl ;
    return 0;
}
