//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isMatch(char a,char b)
    {
        if(a=='(' && b==')') return true;
        else if(a=='[' && b==']') return true;
        else if(a=='{' && b=='}') return true;
        else return false;
    }
    bool ispar(string x)
    {
        // Your code here
        int n = x.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(x[i]=='(' || x[i]=='[' || x[i]=='{')
            {
                st.push(x[i]);
            }
            else{
                if(st.empty()) return false;
                else if(isMatch(st.top(),x[i])==false) return false;
                else{
                    st.pop();
                }
            }
        }
        
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends