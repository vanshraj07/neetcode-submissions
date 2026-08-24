class Solution {
private:
    vector<int>nse(vector<int>&heights){
        int n=heights.size();
        vector<int>next(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) next[i]=st.top();
            st.push(i);
        }
        return next;
    }
    vector<int>pse(vector<int>&heights){
        int n=heights.size();
        vector<int>prev(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(!st.empty()) prev[i]=st.top();
            st.push(i);
        }
        return prev;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        vector<int>next;
        vector<int>prev;
        next=nse(heights);
        prev=pse(heights);
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(next[i]-prev[i]-1));
        }
        return maxi;
    }
};
