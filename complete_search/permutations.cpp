#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;


int n, m;
vi numbers(10);

ll f(){
	ll total = 0;
	for(int i = 0; i < n; i++){
		ll s = 0;
		for(int j = i; j < n; j++){
			int mn = 11;
			for(int k = i; k <= j; k++){
				mn = min(mn, numbers[k]);	
			}
			s += mn;
		}
		total += s;
	}
	return total;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; m--;
	numbers[0] = 1;
	for(int i = 1; i < n; i++){
		numbers[i] = numbers[i - 1] + 1;
	}
	vector<vi> res;
	ll mx = 0;
	do{
		ll f_curr = f();
		
		if(f_curr == mx){
			res.push_back(numbers);
		}
		if(f_curr > mx){
			res.clear();
			res.push_back(numbers);
			mx = f_curr;
		}
	}while(next_permutation(numbers.begin(), numbers.end()));
	vi& ans = res[m];
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}
