class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<string>st;
        for(int i=n-1;i>=0;i--){
            st.push(tokens[i]);
        }
        vector<int>v;
        while(!st.empty()){
            string ch=st.top();
            st.pop();
            if(ch=="+"){
                int a=v.back();
                v.pop_back();
                int b=v.back();
                v.pop_back();
                v.push_back(b+a);
            }
            else if(ch=="-"){
                int a=v.back();
                v.pop_back();
                int b=v.back();
                v.pop_back();
                v.push_back(b-a);
            }
            else if(ch=="*"){
                int a=v.back();
                v.pop_back();
                int b=v.back();
                v.pop_back();
                v.push_back(b*a);
            }
            else if(ch=="/"){
                int a=v.back();
                v.pop_back();
                int b=v.back();
                v.pop_back();
                v.push_back(b/a);
            }
            else {
                int num=stoi(ch);
                v.push_back(num);
            }
        }
        return v[0];
    }
};
