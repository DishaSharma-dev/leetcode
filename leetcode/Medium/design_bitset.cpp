class Bitset {
private:
    vector<int> arr;
    int cnt;
    int cntflip;
public:
    Bitset(int size) {
        arr.resize(size, 0);
        cnt = 0;
        cntflip = 0;
    }
    
    void fix(int idx) {
        if((arr[idx] + cntflip) % 2 == 0){
            arr[idx]++;
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if((arr[idx] + cntflip) % 2 != 0){
            arr[idx]--;
            cnt--;
        }
    }
    
    void flip() {
        cnt = arr.size() - cnt;
        cntflip++;
    }
    
    bool all() {
        if(arr.size() != cnt) return false;
        return true;
    }
    
    bool one() {
        if(cnt >= 1) return true;
        return false;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string str = "";
        for(int i = 0; i < arr.size(); i++){
            if((arr[i] + cntflip) % 2 == 0) str += "0";
            else str += "1";
        }
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */