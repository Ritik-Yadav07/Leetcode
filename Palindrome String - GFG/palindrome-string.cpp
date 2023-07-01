//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int low = 0;
	    int high = S.length()-1;
	    
	    while(low<=high)
	    {
	        if(S[low]!=S[high])
	        {
	            //Not matched
	            return 0;
	        }
	        
	        //else it is matched so keep scanning
	        low++;
	        high--;
	    }
	    
	    //whole string is matched
	    return 1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends