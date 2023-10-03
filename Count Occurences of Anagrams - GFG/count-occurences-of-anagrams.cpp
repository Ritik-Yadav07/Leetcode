//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int n = txt.size();
	    int k = pat.size();
	    
	    vector<int>hash1(26,0);
	    vector<int>hash2(26,0);
	    
	    for(auto ch : pat){
	        hash1[ch-'a']++;
	    }
	    
	    int tail = 0;
	    int head = 0;
	    
	    int count=0;
	    
	    for(head=0;head<n;head++)
	    {
	        hash2[txt[head]-'a']++;
	        
	        if((head-tail+1)==k){
	            if(hash1==hash2){
	                count++;
	            }
	            hash2[txt[tail]-'a']--;
	            tail++;
	        }
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