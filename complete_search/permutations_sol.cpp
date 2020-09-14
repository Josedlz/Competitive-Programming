#include<cstdio>
long long n,m,i,u[64];
int main(){
	scanf("%d%I64d",&n,&m);
	m--;
	for(i = n; --i;)
		if(!(m & (1LL << i - 1)))
			printf("%d ", n - i), u[n - i] = 1;
	for(; n; n--)
		if(!u[n])
			printf("%d ", n);
}


