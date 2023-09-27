//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  bool isAnagram(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        if(n!=m) return false;

        vector<int>hash(26,0);
        for(int i = 0;i<n;i++)
        {
            hash[s1[i]-'a']++;
            hash[s2[i]-'a']--;

        }

        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0) return false;
        }
        return true;
    }
    vector<vector<string> > Anagrams(vector<string>& strs) {
        //code here
        vector<vector<string>>res;
        int n = strs.size();
        vector<int>vis(n,0);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                string curr_str = strs[i];
                vector<string>temp;
                temp.push_back(curr_str);
                for(int j = i+1;j<n;j++)
                {
                    if(isAnagram(curr_str,strs[j])==true){
                        temp.push_back(strs[j]);
                        vis[j]=1;
                    }
                }

                res.push_back(temp);
            }
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends