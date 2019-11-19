#include<bits/stdc++.h>
using namespace std;
char aa[5][5];
int vst[26];
map<char,pair<int,int> > mp;

char get_different(char ch){
  for(char a='x';a<'z'+1;a++)
    if(a!=ch) return a;
  return ch;
}

void buildmat(string key){
  memset(vst,0,sizeof(vst));
  memset(aa,0,sizeof(aa));
  mp.clear();
  int cnt=0;
  vst['j'-'a']=1;
  for(int i=0;i<key.length();i++){
    aa[cnt/5][cnt%5]=key[i];
    mp[key[i]]=make_pair(cnt/5,cnt%5);
    if(key[i]=='j') key[i]='i';
    vst[key[i]-'a']=1;
    cnt++;
  }
  for(int i=0;i<26;i++)
  {
    if(vst[i]==0){
      aa[cnt/5][cnt%5]='a'+i;
      mp['a'+i]=make_pair(cnt/5,cnt%5);
      cnt++;
    }
  }
  cout<<"Matrix\n";
  for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 5; j++) {
        cout<<aa[i][j]<<" ";
      }
      cout<<endl;
  }
}
void cipher(string &s){
  string nx="";
  for (size_t i = 0; i < s.length(); i+=2) {
    char x,y;
    if(i+1==s.length()){
        x=s[i-1];
        y=s[i];
    }
    else{
        x=s[i];
        y=s[i+1];
    }
    if(x==y){
      y = get_different(y);
      i--;
    }
    char x1,y1;
    if(mp[x].first==mp[y].first){
      x1=aa[mp[x].first][(mp[x].second+1)%5];
      y1=aa[mp[y].first][(mp[y].second+1)%5];
    }
    else if(mp[x].second==mp[y].second){
      x1=aa[(mp[x].first+1)%5][mp[x].second];
      y1=aa[(mp[y].first+1)%5][mp[y].second];
    }
    else{
      x1=aa[mp[x].first][mp[y].second];
      y1=aa[mp[y].first][mp[x].second];
    }
    nx+=x1;
    nx+=y1;
  }
  cout<<"Playfair cipher: "<<nx<<endl;
}
int main(int argc, char const *argv[]) {
  string s,key;
  key="monarchy";
  buildmat(key);
  cout<<"Enter string :";
  cin>>s;
  cipher(s);
}
