class MinStack {
    stack<long long>st;
    long long mini=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                st.push(1LL*2*val-mini);
                mini=val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        if(st.top()<mini){
            mini=1LL*2*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        if(st.top()<mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};
