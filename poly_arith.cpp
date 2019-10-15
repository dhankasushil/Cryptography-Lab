#include<bits/stdc++.h>
using namespace std;
void add_poly(vector<int> v1,vector<int> v2,int n)
{
	for(int i=n-1;i>=0;i--)
	{
		if(i>0)
		cout<<(v1[i]+v2[i])%2<<"x^"<<i<<"+";
		else
		cout<<(v1[i]+v2[i])%2<<"x^"<<i<<endl;	
	}
}

vector<int> sub_poly(vector<int> v1,vector<int> v2,int n)
{
	/*for(int i=n-1;i>=0;i--)
	{
		if(i>0)
		cout<<(v1[i]+v2[i])%2<<"x^"<<i<<"+";
		else
		cout<<(v1[i]+v2[i])%2<<"x^"<<i<<endl;	
	}*/

	vector<int> v3(n,0);

	for(int i=n-1;i>=0;i--)
		v3[i]=v1[i]^v2[i];

	return v3;

}

vector<int> mul_poly(vector<int> v1,vector<int> v2,int n)
{
	vector<int> v3(2*n,0);

	for(int i=n-1;i>=0;i--)
		for(int j=n-1;j>=0;j--)
		{
			v3[i+j]+=v1[i]*v2[j];
		}

	/*for(int i=2*n-2;i>=0;i--)
	{
		if(i>0 && v3[i]>0)
		cout<<v3[i]<<"x^"<<i<<"+";
		else if(i==0 && v3[i]>0)
		cout<<v3[i]<<endl;	
	}*/

	return v3;

}

vector<int>  div_poly(vector<int> v1,vector<int> v2,int n)
{
	vector<int> v3;

	vector<int> v5(n,0);
	vector<int> v6(n,0);

	v3=v1;

	int pos=-1;

	for(int i=n-1;i>=0;i--)
	{
		if(v2[i]!=0)
		{
			pos=i;break;
		}
	}

	if(pos!=-1)
	{
		while(1)
		{
			int cnt=0,f=0;

			for(int i=n-1;i>=0;i--)
			{
				if(v3[i]!=0)
				{
					cnt=1;

					if(pos>i)
						{f=1;break;}
					else
					{
						vector<int> v4(n,0);

						v4[i-pos]=v3[i]/v2[pos];
						v5[i-pos]=v3[i]/v2[pos];

						v6=mul_poly(v4,v2,n);
						v3=sub_poly(v3,v6,n);
						break;
					}
				}
			}

			if(f==1 || cnt==0)
				break;
		}

		cout<<"\nQuotient : ";
		for(int i=n-1;i>=0;i--)
		{
			cout<<v5[i]<<"x^"<<i<<" ";
		}

		cout<<"\nRemainder: ";
		for(int i=n-1;i>=0;i--)
		{
			cout<<v3[i]<<"x^"<<i<<" ";
		}

		return v3;

	}


}


void gcd_poly(vector<int> v1,vector<int> v2,int n)
{

	vector<int> v4,v5;
	v4=v1;
	v5=v2;

	while(1)
	{

		vector<int> v3 = div_poly(v4,v5,n);

		int cnt=0;

		for(int i=n-1;i>=0;i--)
		{
			v3[i]=abs(v3[i])%2;
			if(v3[i]>0)
				cnt=1;
		}

		if(cnt==0)
		{
			cout<<"Final iteration : "; break;
		}
		else
		{
			v4=v5;
			v5=v3;
		}
	}






}

int main()
{
	int n;
	cout<<"Enter the maximum of degrees of both polynomial :";
	cin>>n;
	n=n+1;
	vector<int> v1(n);
	vector<int> v2(n);

	cout<<"Enter the coefficients for 1st polynomial :\n";

	for(int i=n-1;i>=0;i--)
	{
		cout<<"for x^"<<i<<": ";
		cin>>v1[i];
	}

	cout<<"Enter the coefficients for 2nd polynomial :\n";

	for(int i=n-1;i>=0;i--)
	{
		cout<<" for x^"<<i<<": ";
		cin>>v2[i];
	}

	/*cout<<"Addition\n";

	add_poly(v1,v2,n);

	cout<<"\nSubtraction\n";

	sub_poly(v1,v2,n);

	cout<<"\nMultiplication\n";

	mul_poly(v1,v2,n);*/


	//div_poly(v1,v2,n);

	cout<<"gcd of the polynomial : ";

	gcd_poly(v1,v2,n);




}