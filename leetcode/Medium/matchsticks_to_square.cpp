class Solution {
public:
    
    static bool comp(int a, int b){
        return a > b;
    }
    int len;
    bool solve(vector<int> &matchsticks, int index, int s1, int s2, int s3, int s4){
        if(index == matchsticks.size()) return (len == s1 && len == s2 && len == s3 && len == s4);
        int curr = matchsticks[index];
        if(s1+curr <= len && solve(matchsticks, index + 1, s1+curr, s2, s3, s4)) return true;
        if(s2+curr <= len && solve(matchsticks, index + 1, s1, s2+curr, s3, s4)) return true;
        if(s3+curr <= len && solve(matchsticks, index + 1, s1, s2, s3+curr, s4)) return true;
        if(s4+curr <= len && solve(matchsticks, index + 1, s1, s2, s3, s4+curr)) return true;
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i = 0; i < matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        if(sum % 4 != 0) return false;
        len = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), comp);
        return solve(matchsticks, 0, 0, 0, 0, 0);
    }
};