#include <bits/stdc++.h>

using namespace std;

int main()
{
   int T;

   scanf("%d", &T);

   for(int i = 0 ; i < T ; i++)
   {
      int n , x ; vector <int> a , b ;
      scanf("%d", &n);
      for(int j = 0 ; j < n ; j++)
      {
          scanf("%d", &x);
          a.push_back(x);
      }
      for(int j = 0 ; j < n ; j++)
      {
          scanf("%d", &x);
          b.push_back(x);
      }
      int result  =  0 ;
      for(int j = 0 ; j < n ; j++)
      {
          result ^= ((b[j] - a[j])-1);
      }
      if(result == 0)
      {
        printf("Case %d: black wins\n", i+1);
      }
      else
      {
         printf("Case %d: white wins\n", i+1);
      }
   }

   return 0;
}
