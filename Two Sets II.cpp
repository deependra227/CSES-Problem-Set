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
	lli sum = n * (n + 1) / 2;

	if(sum % 2) {
		cout << 0 << '\n';
	}
	else {
		sum /= 2;
		int dp[n][sum + 1];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;

		for(int i = 1 ; i < n ; ++i)
		{
			for(int j = 0 ; j <= sum; ++j)
			{
				if(j >= i)
					dp[i][j] = add(dp[i - 1][j], dp[i - 1][j - i]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		cout << dp[n - 1][sum] << '\n';
	}

	return 0;
}