#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

int * ppp(int i)
{
	static int q;
	int * r;
	q = i * 5;
	r = &q;
	return r;
}
int main()
{
	int *qqq;
	qqq = ppp(6);
	cout << qqq;
	getchar();
}

