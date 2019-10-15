#include<bits/stdc++.h>
using namespace std;
int p,n,total=0;

void generate_polynomials(vector<int> polynomial,int i)
{
	if(i==n)
	{
		for(int j=0;j<n;j++)
				if(j==n-1)
					cout<<polynomial[j]<<"x0";
				else
					cout<<polynomial[j]<<"x"<<n-j-1<<"+";
		total++;		
		cout<<endl;
		return;
	}

	for(int k=0;k<p;k++)
	{
		polynomial[i]=k;
		generate_polynomials(polynomial,i+1);
	}

}

int main()
{
	cout<<"Enter maximum coeffiecient : ";
	cin>>p;
	cout<<"Enter maximum degree : ";
	cin>>n;
	vector<int> polynomial(n);
	generate_polynomials(polynomial,0);
	cout<<"Total polynomials are : "<<total<<endl;
}