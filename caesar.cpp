#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cout<<"Enter a string : ";
	cin>>s;

	for(int i=0;i<s.length();i++)
	{
		s[i]=(s[i]-'a'+3)%26 + 'a';
	}

	cout<<"Converted string : "<<s<<endl;
}