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
int solve(vector<int>& price, vector<int>& pages, int n, int x)
{
	if(x == 0 || n == 0)return 0;

	if(x >= price[n - 1])
		return max(solve(price, pages, n - 1, x - price[n - 1]) + pages[n - 1], solve(price, pages, n - 1, x));
	else
		return solve(price, pages, n - 1, x);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n , x;
	cin >> n >> x;
	vector<int> price(n), pages(n);
	sv(price); sv(pages);
	vector<int> dp(x + 1, 0);

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = x; j >= price[i] ; --j)

		{

			dp[j] = max(dp[j - price[i]] + pages[i], dp[j]);

		}
	}

	cout << dp[x] << '\n';
	return 0;
}