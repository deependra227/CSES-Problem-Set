#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sv(a) for (auto &it : a) cin >> it;
#define pv(a)  for (auto & it : a)     cout << it << " ";  cout << '\n';
#define all(x) (x).begin(), (x).end()
#define pv2(a) for(auto& it : a){for(auto i : it)cout << i << ' ';cout << '\n';}
const int MOD = 1e9 + 7;
const lli INF = 1e18 + 2;
typedef pair<int, int> pii;
int add(int a, int b) {
	if(a + b >= MOD) {
		return a + b - MOD;
	}

	return a + b;
}
int prod(int a, int b) {
	return (a * 1LL * b) % MOD;
}
bool compareBysecond(pair<lli, lli> a, pair<lli, lli> b)
{
	if (a.second == b.second) return a.first < b.first;

	return a.second < b.second;
}
int log(lli x)
{
	int cnt = 0;

	while (x > 0)
	{
		cnt++;
		x = x >> 1;
	}

	return cnt;
}
lli max(lli a, lli b)
{
	if (a < b) return b;
	else return a;
}
lli min(lli a, lli b)
{
	if (a > b) return b;
	else return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<string> matrix(n);
	sv(matrix);

	if(matrix[0][0] == '*') {
		cout << 0 << '\n';
		return 0;
	}

	vector<vector<int>> dp(n , vector<int>(n, 0));
	dp[0][0] = 1;

	for(int i = 1 ; i < n ; ++i)if(matrix[0][i] == '.')dp[0][i] = dp[0][i - 1];

	for(int i = 1 ; i < n ; ++i)if(matrix[i][0] == '.')dp[i][0] = dp[i - 1][0];

	for(int i = 1; i < n ; ++i)
	{
		for(int j = 1 ; j < n ; ++j)
		{
			if(matrix[i][j] == '.') {
				dp[i][j] = add(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}

	cout << dp[n - 1][n - 1] << '\n';
	return 0;
}