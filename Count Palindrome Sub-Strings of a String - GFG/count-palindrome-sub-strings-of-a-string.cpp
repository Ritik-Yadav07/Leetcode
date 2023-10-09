//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char S[], int N)
{
    //code here
    //neetcode video must
    int count = 0;
    
    int left,right;
    
    for(int i=0;i<N;i++)
    {
        //for odd length 
        left = i;
        right = i;
        int res = 0;
        while(left>=0 && right<N && S[left] == S[right])
        {
            if((right-left+1)>=2) res++;
            left--;
            right++;
        }
        
        count+=res;
        //for even length
        left = i;
        right = i+1;
        res = 0;
        while(left>=0 && right<N && S[left] == S[right])
        {
            if((right-left+1)>=2) res++;
            left--;
            right++;
        }
        
        count+=res;
    }
    
    return count;
    
}