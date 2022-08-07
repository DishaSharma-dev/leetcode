class Solution {
public:
    unordered_map<string, bool> umap;
    bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3){
        if(p3 == len3){
            if(p1 == len1 && p2 == len2) return true;
            else return false;
        }
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if(umap.find(key) != umap.end()) return umap[key];
        if(p1 == len1){
            if(s2[p2] == s3[p3]){
                return umap[key] = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
            }
            else return false;
        }
        if(p2 == len2){
            if(s1[p1] == s3[p3]){
                return umap[key] = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
            }
            else return false;
        }
        bool op1 = false, op2 = false;
        if(s1[p1] == s3[p3]){
            op1 = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
        }
        if(s2[p2] == s3[p3]){
            op2 = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
        }
        return umap[key] = op1 or op2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3) return false;
        return check(s1, s2, s3, len1, len2, len3, 0, 0, 0);
    }
};