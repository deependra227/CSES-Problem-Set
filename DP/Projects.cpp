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
	vector<vector<int>> arr(n, vector<int>(3));

	for(int i = 0 ; i < n ; ++i)
		cin >> arr[i][1] >> arr[i][0] >> arr[i][2];

	sort(all(arr));
	vector<lli> dp(n);
	dp[0] = arr[0][2];

	for(int i = 1 ; i < n ; ++i)
	{
		dp[i] = 0;
		int l = 0 , r = i - 1;

		while(l <= r)
		{
			int m = (l + r) / 2;

			if(arr[m][0] < arr[i][1]) l = m + 1;
			else r = m - 1;
		}

		if(r == -1) dp[i] = max(dp[i - 1], arr[i][2]);
		else dp[i] = max(dp[i - 1], dp[r] + arr[i][2]);
	}

	cout << dp[n - 1] << '\n';
	return 0;
}