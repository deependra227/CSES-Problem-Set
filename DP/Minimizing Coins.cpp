#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sv(a) for (auto& it : a) cin >> it;
#define pv(a)  for (auto& it : a)     cout << it << " ";  cout << '\n';
#define all(x) (x).begin(), (x).end()
#define pv2(a) for(auto& it : a){for(auto i : it)cout << i << ' ';cout << '\n';}
const int MOD = 1e9 + 7;
const lli INF = 1e18 + 2;
typedef pair<int, int> pii;

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
lli solve(vector<int>& c, int n, int x)
{
	if(x == 0)return 0;

	if(n == 0)return INT_MAX;

	if(x >= c[n - 1])
		return min(solve(c, n, x - c[n - 1]) + 1,  solve(c, n - 1, x));
	else
		return solve(c, n - 1, x);
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
	vector<int> c(n);
	sv(c);
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(-9999999999999ms);
	int ans = solve(c, n, x);
	cout << (ans != INT_MAX ? ans : -1 	 ) << '\n';



	return 0;
}