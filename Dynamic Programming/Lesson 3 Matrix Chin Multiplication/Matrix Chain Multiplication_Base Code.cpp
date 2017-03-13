/**
Matrix Chain Multiplication
Base code taken from = http://www.shafaetsplanet.com/planetcoding/?p=1885
Learning material - https://www.youtube.com/watch?v=vgLJZMUfnsU&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=3
**/

#include <bits/stdc++.h>

#define MAX 100
int row[MAX], col[MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int f(int beg,int end)
{
	if(beg>=end)return 0;
	if(visited[beg][end])return dp[beg][end];
	int ans=1<<30; //২^৩০ কে ইনফিনিটি ধরছি
	for(int mid=beg; mid<end;mid++) //দুইভাগে ভাগ করছি
	{
		int opr_left = f(beg, mid); //opr = multiplication operation
		int opr_right = f(mid+1, end);
		int opr_to_multiply_left_and_right = row[beg]*col[mid]*col[end];
		int total = opr_left + opr_right + opr_to_multiply_left_and_right;
		ans = min(ans, total);
	}
	visited[beg][end] = 1;
	dp[beg][end] = ans;
	return dp[beg][end];
}

int main()
{
	int n;
	cin>>n;
	rep(i,n)cin>>row[i]>>col[i];
	cout<<f(0,n-1)<<endl;
}
