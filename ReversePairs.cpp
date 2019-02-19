class Solution {
    int lowerBound(int num, const vector<int>& nums, int l, int h){
        while(l<h){
            int mid = (l+h)/2;
            if(2.0*nums[mid] < num) l = mid + 1;
            else h = mid;
        }
        return l;
    }
    
    int countInv(vector<int>& nums, int l, int r){
        if(l==r) return 0;
        
        int inv = 0;
        int mid = (l+r)/2;
        inv += countInv(nums,l,mid);
        inv += countInv(nums,mid+1,r);
        
        for(int k=l;k<=mid;++k) inv += lowerBound(nums[k],nums,mid+1,r+1) - (mid+1);
        
        vector<int> temp(r-l+1);
        int i=l,j=mid+1;
        for(int k=0;k<=r-l;++k){
            if(j==r+1 || (i != mid+1 && nums[i]<nums[j])) {
                temp[k] = nums[i];
                ++i;
            }
            else{
                temp[k] = nums[j];
                ++j;
            }
        }
        
        for(int k=0;k<=r-l;++k) nums[l+k] = temp[k];
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return countInv(nums,0,nums.size()-1);
    }
};