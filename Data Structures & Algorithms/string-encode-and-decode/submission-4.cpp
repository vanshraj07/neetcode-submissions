class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string s="";
        for(int i=0;i<n;i++){
            s+=to_string(strs[i].size());
            s+="#";
            s+=strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        int n=s.size();
        vector<string>ans;
        int i=0;
        while(i<n){
            int hashPos=s.find('#',i);
            int len=stoi(s.substr(i,hashPos-i));
            ans.push_back(s.substr(hashPos+1,len));
            i=hashPos+len+1;
        }
        return ans;
    }
};
