class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> m;
    int max_freq;
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        max_freq = max(max_freq, ++freq[x]);
        m[freq[x]].push(x);
    }
    
    int pop() {
        int ret = m[max_freq].top();
        m[max_freq].pop();
        freq[ret]--;
        if(!m[max_freq].size()) max_freq--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */