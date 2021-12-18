#include<bits/stdc++.h>
using namespace std;

int presedence(char c) {
    if(c == '^')
        return 4;
    else if(c == '/' || c=='*')
        return 3;
    else if(c == '+' || c == '-')
        return 2;
    else
        return 1;
}
void Postfix(string s) {

    stack <char>stck;
    string result;

    for(int i = 0; i < s.length(); i++) {

        if((s[i]>= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            result +=s[i] ;
        else if(s[i] == '(')
            stck.push('(');
        else if(s[i] == ')') {
            while(stck.top() != '(')
            {
                result += stck.top();
                stck.pop();
            }
            stck.pop();
        }
        else {
               while(!stck.empty() && presedence(s[i]) <= presedence(stck.top())) {
                result += stck.top();
                stck.pop();
            }
            stck.push(s[i]);
        }
    }
    while(!stck.empty()) {
        result += stck.top();
        stck.pop();
    }
    cout<<"The expected  postfix expression is:"<<endl;
    cout << result << endl;
}
int main() {
    cout<<"Enter a infix expression"<<endl;
    string expression;
    cin>>expression;
    Postfix(expression);
    return 0;
}
