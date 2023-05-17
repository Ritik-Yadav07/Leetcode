//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string ans="";
         stack<char>st;
        for(int i=0;i<s.size();i++)
        {   
            if(s[i]!='.')
            {
             st.push(s[i]);
            }
            else{
                 while(st.empty()==false){
                auto c = st.top();
                st.pop();
                ans+=c;
                
            }
            ans+='.';
            }
           
            
            
        }
        //for last word
        while(st.empty()==false){
                auto c = st.top();
                st.pop();
                ans+=c;
                
            }
       
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends