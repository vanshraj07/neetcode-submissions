class KthLargest {
    priority_queue<int>pq;
    int Kth;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        Kth=k;
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int>ptq=pq;
        int temp=Kth;
        temp--;
        while(!ptq.empty() && temp>0){
            temp--;
            ptq.pop();
        }
        return ptq.top();
    }
};
