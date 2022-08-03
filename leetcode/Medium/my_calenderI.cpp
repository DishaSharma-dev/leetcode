class MyCalendar {
    private:
        map<int, int> umap;
public:
    MyCalendar() {
           
    }
    
    bool book(int start, int end) {
        umap[start]++;
        umap[end]--;
        int sum = 0;
        for(auto it : umap){
            sum += it.second;
            if(sum > 1){
                umap[start]--;
                umap[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */