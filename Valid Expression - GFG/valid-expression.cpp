//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool match(char a,char b)
{
    if(a=='(' && b==')') return true;
    else if(a=='[' && b==']') return true;
    else if(a=='{' && b=='}') return true;
    
    else return false;
}

bool valid(string s)
{
    // code here
    
    int n = s.length();
    stack<char>st;
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='[' ||s[i]=='{')
        {
            //any open bracket
            st.push(s[i]);
        }
        else{
            //i.e. we encountered closed bracket
            if(st.empty()) return false;
            else if(match(st.top(),s[i])==false) return false;
            else{
                st.pop();
            }
        }
    }
    return st.empty()==true;
}