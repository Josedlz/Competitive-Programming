#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

ll n;

int f(int x){
	int y = 0;
	while (x > 0) y += x % 10, x /= 10;
	return y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;				
	for(int i = 1; i <= 90; i++){
		ll a = i * i + 4 * n;	
		ll b = sqrt(a);
		if(b * b == a){
			b = (-i + b) / 2;
			if(f(b) == i){
				return cout << b, 0;
			}
		}
	}
	cout << -1;
}


