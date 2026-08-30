class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while(true){
            slow=nums[slow];  //1step move karan
            fast=nums[nums[fast]]; //2 step move karna
            if(slow==fast){
                break;
            }
        }
        int slow2=0;
        while(true){
            slow=nums[slow];
            slow2=nums[slow2];
            if(slow==slow2){
                return slow2;
            }
        }
        return 0;
    }
};
