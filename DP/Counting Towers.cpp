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
	//                                      _  _
	// dp[i][1] = last blocks are separate | || |
	//                                   _ _
	// dp[i][2] = last blocks are fused |   |

	// transition:
	//              _  _    _  _    _  _    _  _     _ _
	//  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
	// | || | =>   | || |, | || |, | || |, | || |,  | | |
	//              _ _    _ _    _ _
	//  _ _        |   |  |_|_|  |_ _|
	// |   |  =>   |   |, |   |, |   |

	// dp[i][1] = dp[i-1][1]*4 + dp[i-1][2]
	// dp[i][2] = dp[i-1][1] + dp[i-1][2]*2

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int left = 1 , right = 1;

		for(int i = 2; i <= n ; ++i)
		{
			int currLeft = add(prod(left , 4) , right);
			int currRight = add(left , prod(right , 2));
			left = currLeft;
			right = currRight;
		}

		cout << add(left, right) << '\n';
	}

	return 0;
}