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
lli segTree[1000000];
void build(vector<int>& a, int start, int end, int pos)
{
	if(start == end)
	{
		segTree[pos] = a[start];
		return;
	}

	int m = (start + end) / 2;
	build(a, start, m, 2 * pos + 1);
	build(a, m + 1, end, 2 * pos + 2);
	segTree[pos] = 0;
}
lli query(int k, int start, int end, int pos)
{
	if( start == end) return segTree[pos];

	int m = (start + end) / 2;

	if(k <= m)
		return segTree[pos] + query(k, start, m, 2 * pos + 1);

	return segTree[pos] + query(k, m + 1, end, 2 * pos + 2);
}
void update(int l, int r, lli delta, int start, int end, int pos)
{

	if(l <= start && end <= r)
	{
		segTree[pos] += delta;
		return;
	}

	if(start == end || start > r || end < l)
		return;



	int m = (start + end) / 2;
	update(l , r , delta , start, m, 2 * pos + 1);
	update(l , r , delta , m + 1, end, 2 * pos + 2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<int> x(n);
	sv(x);
	build(x, 0, n - 1, 0);

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int a, b , c;
			cin >> a >> b >> c;
			update(a - 1, b - 1, c, 0, n - 1, 0);
		}
		else {
			int k ;
			cin >> k;
			cout << query(k - 1, 0, n - 1, 0) << '\n';
		}

	}

	return 0;
}