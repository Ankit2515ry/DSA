class MedianFinder {
public:
    priority_queue<int>inc;
    priority_queue<int,vector<int>,greater<int>>dec;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(inc.empty()||inc.top()>num)inc.push(num);
        else dec.push(num);
        if(inc.size()>dec.size()+1){
            int v=inc.top();
            inc.pop();
            dec.push(v);
        }
        if(dec.size()>inc.size()){
            int v=dec.top();
            dec.pop();
            inc.push(v);
        }
    }
    
    double findMedian() {
        int n=inc.size();
        int m=dec.size();
        if((n+m)%2==1)return (double)(inc.top());
        double a=(double)inc.top();
        double b=(double)dec.top();
        return (a+b)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */