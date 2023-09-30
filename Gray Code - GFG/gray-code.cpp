//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        if(n==1){
            vector<string>temp;
            temp.push_back("0");
            temp.push_back("1");
            return temp;
        }
        
        vector<string>prevResult = graycode(n-1);
        vector<string>res;
        
        for(int i=0;i<prevResult.size();i++)
        {
            string s = prevResult[i];
            res.push_back("0"+s);
        }
        
        for(int i=prevResult.size()-1;i>=0;i--){
            string s = prevResult[i];
            res.push_back("1"+s);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}




// } Driver Code Ends