#include <iostream>
#include <cmath>
 
using namespace std;
typedef long long ll;
int main()
{
	ll n; bool c=0;
	cin >> n;
	for (ll x = (int)sqrt(n)-100; x <= sqrt(n)+1; x++) {
		if (x <= 0) continue;
		int s = 0, t = x;
		while (t) s += t % 10, t /= 10;
		if (x * (x + s) == n) cout << x, c = 1;
	}
	if (!c) cout << -1;
	return 0;
}
