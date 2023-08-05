//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string>st;
        string temp = "";
        
        for(int i=0;i<S.length();i++){
            
            if(S[i]!='.'){
                temp+=S[i];
            }
            if(S[i]=='.'){
                st.push(temp);
                temp = "";
            }
        }
        st.push(temp);
        
        string ans = "";
        
        while(!st.empty()){
            string str = st.top();
            st.pop();
            ans+=str+".";
        }
        
        ans.pop_back();
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends