class Solution {
private:
    int func(int n){
        long long sum=0;
        while(n>0){
            int digit=(n%10);
            sum+=(digit*digit);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(st.find(n)==st.end()){
            st.insert(n);
            n=func(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
};
