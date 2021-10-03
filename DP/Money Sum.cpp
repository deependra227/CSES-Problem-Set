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
	vector<int> coins(n); sv(coins);
	int sum = 0;

	for(auto& it : coins) sum += it;

	bool dp[sum + 1];
	memset(dp, false, sizeof(dp));

	// for(int i = 0 ; i < n; ++i)dp[coins[i]] = true;

	for(int i = 0 ; i < n ; ++i)
	{

		for(int j = sum ; j  >= coins[i]; --j)
			dp[j] = (dp[j - coins[i]] || dp[j]);

		dp[coins[i]] = true;
	}

	vector<int> ans;

	for(int i = 1; i <= sum; ++i)
		if(dp[i])ans.push_back(i);

	cout << ans.size() << '\n';
	pv(ans);
	return 0;
}