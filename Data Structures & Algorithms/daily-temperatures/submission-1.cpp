class Solution {
private:
    vector<int>nge(vector<int>& temperatures){
        int n=temperatures.size();
        vector<int>next(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()) next[i]=st.top();
            st.push(i);
        }
        return next;
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        vector<int>next;
        next=nge(temperatures);
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                ans[i]=0;
            }
            else{
                ans[i]=next[i]-i;
            }
        }
        return ans;
    }
};
