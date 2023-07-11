//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    unordered_map<char,int>mp;
    string ans  ="";
    for(auto &c : s)
    {
        mp[c]++;
        if(mp[c]>1){
            ans+=c;
            break;
        }
    }
    if(ans.size()==0) return "-1";
    return ans;
}