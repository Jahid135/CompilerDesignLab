#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len,i,j,cnt=0,temp,temp2,brs=0,bre=0;
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
        else if(s[i]=='(')
        {
          if(s[i+1]==')')
              {
              cout<<"Invalid"<<endl;
              return 0;

              }
          else if(s[i+1]=='*'||s[i+1]=='/')
        {
                cout<<"Invalid"<<endl;
                return 0;

         }
        else{
            for(j=i+1;j<len;j++)
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
    for(i=0;i<len;i++)
    {
        if(s[i]==')')
        {
            temp=i;
            bre++;
        }
        if(s[i]=='(')
        {
            temp2=i;
            brs++;
        }
    }
    if(temp<temp2||(brs!=bre))
    {
        cout<<"Invalid"<<endl;
        return 0;
    }
    cout<<"valid"<<endl;
    return 0;


}
