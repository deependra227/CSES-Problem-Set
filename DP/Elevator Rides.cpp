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
	int n, x;
	cin >> n >> x;
	vector<int> weights(n); sv(weights);

	// try all subsets
	// check is ith element is in subset (mask)
	// if so, calculate the value of subset (after removing the ith element) + cost of including the ith element or something like that.


	vector<pair<int, int>> dp(1 << n);
	dp[0] = {1, 0}; // Initialize the value of empty subset

	for(int mask = 1 ; mask < (1 << n); ++mask) // try all subsets
	{
		dp[mask] = {n + 1, 0}; // initialize the value subset

		for(int i = 0 ; i < n ; ++i)
		{

			if(mask & (1 << i)) // check if the ith element is in subset (mask)
			{
				auto p = dp[mask ^ (1 << i)]; // if so, remove it and get the value subset. let we call this subset to be prevMask

				if(p.second + weights[i] <= x) // calculate the cost of including ith element in the prevMask
				{
					p.second += weights[i];
				}
				else {
					p.first++;
					p.second = weights[i];
				}

				dp[mask] = min(dp[mask], p); // check is including the ith element in prevMask gives minimum value
			}
		}
	}

	cout << dp[(1 << n) - 1].first << '\n';

	return 0;
}