#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
 
int n;
int x[1005];
int y[1005];
int h_x, h_y;
set<long double> slopes;
 
long double slope(int x, int y){
		return ((double)(h_y - y)) / (h_x - x);
}
 
int solve(){
 bool equal_x = false;
	for(int i = 0; i < n; i++){
		if(x[i] != h_x){
			long double m = slope(x[i], y[i]);
			slopes.insert(m);
		}
		else{
			equal_x = true;	
		}
	}
	return (equal_x ? slopes.size() + 1 : slopes.size());
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
			
	cin >> n >> h_x >> h_y;
			 
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	cout << solve() << endl;
}
