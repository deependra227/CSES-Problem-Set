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
string temp = "";
lli t[11][20][2][2];
lli solve(string& s, char c, int i, int isL , int flag)
{


	if(i == s.length())
		return 1;

	if(t[c - '0'][i][isL][flag] != -1)return t[c - '0'][i][isL][flag] ;

	char upper = (flag ? s[i] : '9');
	lli ans = 0;

	for(char k = '0' ; k <= upper; ++k)
	{
		if(!isL && k == c)continue;

		ans += solve(s, k, i + 1, (isL && (k == '0')), (flag && (k == upper)) );
	}

	return t[c - '0'][i][isL][flag]  = ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	lli a, b;
	cin >> a >> b;
	string s1 = to_string(a - 1);
	string s2 = to_string(b );
	memset(t, -1, sizeof t);
	lli ans1 = (a - 1 >= 0 ? solve(s1, '0', 0, 1, 1) : 0)   ;
	memset(t, -1, sizeof t);
	lli ans2 =  solve(s2, '0', 0, 1, 1) ;
	cout <<  ans2 - ans1 << '\n';
	return 0;
}