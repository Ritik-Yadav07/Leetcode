//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    int count=0;
	    vector<int>Hash(26,0); //for string pat
	    vector<int>tempHash(26,0); //for string text while scanning

	    for(int i=0;i<pat.size();i++)
	    {
	        Hash[pat[i]-'a']++;
	    }
	    
	    	    
	    int head = 0;
	    int tail=0;
	    
	    for(head=0;head<txt.size();head++)
	    {
	        tempHash[txt[head]-'a']++;
	        
	        while((head-tail+1)>pat.size())
	        {
	            tempHash[txt[tail]-'a']--;
	            tail++;
	        }
	        
	        if(tempHash==Hash) count++;
	    }
	    
	    return count;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends