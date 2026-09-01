class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end());
        int gadha=freq[25]-1;
        int idlespots=gadha*n;
        for(int i=24;i>=0;i--){
            idlespots-=min(freq[i],gadha);
        }
        return tasks.size()+max(0,idlespots);
    }
};
