#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	int q, r;
	while (b > 0)
	{
		q = a / b;
		r = a - q * b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int a, k;
	int val;
	int ord[50], g[50];
	bool cyclic = false;
	int elements[100];
	int order;

	cout<<"Enter number: ";
	cin>>a;

	k=0;

	for (int i = 0; i < a; i++)
				if (gcd(a, i) == 1) //co-prime
					elements[k++] = i;

	elements[k] = '\0';

	printf("G = {");

	for (int i = 0; i < k; i++)
	{
			printf("%d", elements[i]);
			(i < k-1) ? printf(",") : printf("}");
	}

	order = k;

	printf("\nThe order of the group is %d.\n\n", order);

	for (int i = 0; i < k; i++)
	{
			int temp = 1;
			while (1)
			{
					val = int(pow(elements[i], temp));
					if (val % a == 1)
					{
						ord[i] = temp;
						printf("order(%d) = %d\n", elements[i], temp);
						break;
					}
					temp++;
			}

	 }

	int x = 0, count = 0;

	for (int i = 0; i < k; i++)
	{
		if (ord[i] == order)
		{
			g[x++] = elements[i];
			cyclic = true;
			count++;
		}
	}

	if (cyclic)
	{
		printf("The group is a cyclic group with %d generators\n", count);
		for (int i = 0; i < count; i++)
		  printf("g%d = %d ", i + 1, g[i]);
	}
	else
		printf("The group is not a cyclic group.\n");

}
