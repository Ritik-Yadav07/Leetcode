class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Naive(O(N^2))
        // vector<int>result;
        // int n=nums.size();

        // for(int i=0;i<n;++i){
        //     int val=target-nums[i];
        //     for(int j=i+1;j<n;j++){
        //       if(val==nums[j]){
        //           result.push_back(i);
        //           result.push_back(j);
        //           return result;
        //       }
        //     }
        // }
        // return result;

        unordered_map<int,int>mp;  //val - index
        int n = nums.size();
        vector<int>result;

       mp[nums[0]]=0;
         
        for(int i=1;i<n;i++){
             int val=target-nums[i];
             auto it = mp.find(val);
             if(it!=mp.end()){
                 //ie we found
                 result.push_back(i);
                 result.push_back(it->second);
                 return result;
             }else{
                 mp[nums[i]]=i;
             }
        }

        return result;
        


    }
};