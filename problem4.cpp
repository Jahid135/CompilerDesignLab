#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len,i,j;
    string s,str;
    str='E';
    cin>>s;
    len=s.length();
    cout<<"E"<<endl;
    for(i=len-2;i>=0;i=i-2)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
           str=s[i]+str;
           str='E'+str;
           cout<<str<<endl;
        }
    }
    for(i=0;i<len;i=i+2)
    {
       str[i]=s[i];
       cout<<str<<endl;
    }
}
