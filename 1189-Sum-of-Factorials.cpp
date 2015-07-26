#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{

	int t;
	unsigned long long fact[22];
	long long x;

	fact[0] = 1;

	for (int i = 1; i <= 20; i++) {
		fact[i] = fact[i-1] * i;
	}

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%lld", &x);
		stack <int> q;
		int i = 20;
		while(i >= 0) {
			if(fact[i] <=  x) {
				x -= fact[i];
				q.push(i);
			}

			i--;
		}

		if(x == 0) {
			printf("Case %d: ", cs);
			while(q.size() != 1) {
				printf("%d!+", q.top());
				q.pop();

			}

			printf("%d!\n", q.top());
			q.pop();

		}

		else {
			printf("Case %d: impossible\n", cs);
		}

	}


}







