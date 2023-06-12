//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr,arr+N);
      int lastSmaller = INT_MIN;
      int longest = 1;
      int cnt = 0; //current selected sequence length
      
      for(int i=0;i<N;i++)
      {   
         if(arr[i]==lastSmaller+1) // part of sequence
         {
             cnt++;
             lastSmaller = arr[i];
         }
         else if(arr[i]==lastSmaller) continue;  //skipp duplicate
         else{
             // this num is not part of seq,it is different
             cnt = 1;
             lastSmaller = arr[i];
         }
         
         longest = max(longest,cnt);
      }
     
     return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends