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

int t[100001][101];

int solve(vector<int>& x, int n, int m, int prev)
{
	if(n == 0) return 1;

	if(t[n][prev] != -1)return t[n][prev];

	int ans = 0;

	if(x[n - 1] == 0) {

		if(prev - 1 >= 1)
			ans = add(ans, solve(x, n - 1, m, prev - 1));

		if(prev + 1 <= m)
			ans = add(ans, solve(x, n - 1, m, prev + 1));

		ans = add(ans, solve(x, n - 1, m, prev));
	}
	else {
		if(abs(prev - x[n - 1]) > 1)return 0;

		ans = solve(x, n - 1, m, x[n - 1]);
	}

	return t[n][prev] = ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n , m;
	cin >> n >> m;
	vector<int> x(n); sv(x);
	memset(t, -1, sizeof(t));

	if(x[n - 1] == 0) {
		int ans = 0;

		for(int i = 1; i <= m ; ++i)
		{
			ans = add(ans, solve(x, n - 1, m, i));
		}

		cout << ans << '\n';
	}
	else {
		cout << solve(x, n - 1, m, x[n - 1]) << '\n';
	}

	return 0;
}
