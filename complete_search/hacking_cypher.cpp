#include<bits/stdc++.h>
using namespace std;

char s[1000001];
bool b1[1000000];

int main() {
	int n,a,b,c,d;
	scanf("%s%d%d", s, &a, &b); 

	n = strlen(s); 
	c = 0;
	for(int i = 0; i < n; ++i)
		b1[i] = (c = (c * 10 + s[i] - 48) % a) || s[i + 1] == 48;
	c = 0;
	d = 1;
	for(int i = n - 1; i; --i, d = 10 * d % b)
		if(!(c = (c + (s[i] - 48) * d) % b) && !b1[i - 1])
			return printf("YES\n%.*s\n%s",i,s,s+i), 0;
	puts("NO");
}
