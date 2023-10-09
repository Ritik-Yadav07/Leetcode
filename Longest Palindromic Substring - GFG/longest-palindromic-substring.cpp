//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here
        
        int n = S.length();
        int a,b;
        int left,right;
        int maxiLength = 0;
        
        for(int i=0;i<n;i++)
        {
            //for odd length 
            
            left = i;
            right = i;
            while(left>=0 && right < n && S[left]==S[right])
            {
               //right-left+1 is the curr palindromic substring length
               if((right-left+1)>maxiLength)
               {
                   a = left;
                   b = right;
                   maxiLength = right-left+1;
               }
               else if((right-left+1)==maxiLength)
               {
                   //for conflict we have to return least starting index substring
                   if(left<a)
                   {
                       a = left;
                       b = right;
                   }
               }
               
               left--;
               right++;
               
            }
            
            
            //for even length
            
            left = i;
            right = i+1;
            
            while(left>=0 && right < n && S[left]==S[right])
            {
               //right-left+1 is the curr palindromic substring length
               if((right-left+1)>maxiLength)
               {
                   a = left;
                   b = right;
                   maxiLength = right-left+1;
               }
               else if((right-left+1)==maxiLength)
               {
                   //for conflict we have to return least starting index substring
                   if(left<a)
                   {
                       a = left;
                       b = right;
                   }
               }
               
               left--;
               right++;
            }
            
        }
        
        
        string ans = "";
        for(int i=a;i<=b;i++){
            ans+=S[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends