31. Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
My code:
class Solution {
public:
	int bsearch(vector<int>& nums,int l,int r,int val)
	{	int index=-1;
		while(l<=r)
		{
			int mid=l+(r-l)/2;

			if(nums[mid]<=val)
				r=mid-1;
			else
			{
				l=mid+1;
				if(index==-1||nums[index]>=nums[mid])
					index=mid;
			}
		}
		return index;
	}
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return;
        int i=n-2;
        while(i>=0&&nums[i]>=nums[i+1])
        	i--;
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int index=bsearch(nums,i+1,n-1,nums[i]);
        swap(nums[i],nums[index]);
        reverse(nums.begin()+i+1,nums.end());
    }
};
