class FreqStack {
public:
    map<int, int> umap1;
    map<int, stack<int>> umap2;
    int maxfreq= 0;
    FreqStack() {
    }
    
    void push(int val) {
        int freq = umap1[val] + 1;
        umap1[val] = freq;
        if(maxfreq < freq)maxfreq = freq;
        umap2[freq].push(val);
    }
    
    int pop() {
        int top = umap2[maxfreq].top();
        umap2[maxfreq].pop();
        if(umap2[maxfreq].size() == 0) maxfreq--;
        umap1[top]--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */