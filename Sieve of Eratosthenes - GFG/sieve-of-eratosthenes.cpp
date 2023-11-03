//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int>sieve(N+1,1);
        sieve[0] = sieve[1] = 0;
        for(long long i = 2;i<=N;i++)
        {
            if(sieve[i]){
                for(long long j = i*i;j<=N;j+=i)
                {
                    sieve[j] = 0;
                }
            }
        }
        vector<int>primes;
        for(int i=0;i<=N;i++)
        {
            if(sieve[i])
            {
                primes.push_back(i);
            }
        }
        return primes;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends