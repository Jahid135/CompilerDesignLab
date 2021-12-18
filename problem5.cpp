#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len,i,j,cnt=0,temp,temp2;
    string s;
    cout<<"Enter a string:"<<endl;
    cin>>s;
    len=s.length();
    if(s[0]=='*'||s[0]=='/'||s[len-1]=='+'||s[len-1]=='-'||s[len-1]=='*'||s[len-1]=='/'||s[len-1]=='(')
    {
        cout<<"Invalid"<<endl;
        return 0;
    }
    for(i=0;i<len;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/')
            {
                cout<<"Invalid"<<endl;
                return 0;

            }
        }
        if(s[i]==')')
        {
            temp=i;
        }
        else if(s[i]=='('&&i+2<len)
        { temp2=i;
          if(s[i+1]==')')
              {
              cout<<"Invalid"<<endl;
              return 0;

              }
          else if(s[i+1]=='*'||s[i+1]=='/')
        {
            if(s[i+2]=='+'||s[i+2]=='-'||s[i+2]=='*'||s[i+2]=='/'||s[i+2]==')')
            {
                cout<<"Invalid"<<endl;
                return 0;

            }
            else
            {
                cout<<"Invalid"<<endl;
                return 0;

            }
        }
        else{
            for(j=i;j<len;j++)
            {
                if(s[j]==')')
                {
                    cnt++;
                }
            }
            if(cnt==0)
            {
                cout<<"Invalid"<<endl;
                return 0;

            }
        }

        }
    }
    if(temp<temp2)
    {
        cout<<"Invalid"<<endl;
        return 0;
    }
    cout<<"valid"<<endl;
    return 0;


}
