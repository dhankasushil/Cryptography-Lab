#include<bits/stdc++.h>
using namespace std;
int main()
{
 //All the text which ever entered is converted to upper and without spaces

   int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];

   string str,key,cipher;

   cout<<"Enter a string text to encrypt\n";
   cin>>str;

   for(i=0,j=0;i<str.length();i++)
   {
    if(str[i]!=' ')
    {
     str[j]=toupper(str[i]);
     j++;
    }
   }

   str[j]='\0';

 //obtaining numerical plain text ex A-0,B-1,C-2

    for(i=0;i<str.length();i++)
    {
     numstr[i]=str[i]-'A';
    }

    cout<<"Enter key string of random text\n";
    cin>>key;




   for(i=0,j=0;i<key.length();i++)
   {
    if(key[i]!=' ')
    {
     key[j]=toupper(key[i]);
     j++;
    }
   }

 //obtaining numerical one time pad(OTP) or key

    for(i=0;i<key.length();i++)
    {
      numkey[i]=key[i]-'A';
    }

    for(i=0;i<str.length();i++)
    {
      numcipher[i]=numstr[i]+numkey[i];
    }

    //To loop the number within 25 i.e if addition of numstr and numkey is 27 then numcipher should be 1

    for(i=0;i<str.length();i++)
    {
     if(numcipher[i]>25)
     {
      numcipher[i]=numcipher[i]-26;
     }
    }

    cout<<"One Time Pad Cipher text is\n";

    for(i=0;i<str.length();i++)
    {
      printf("%c",(numcipher[i]+'A'));
    }

    cout<<endl;

}
