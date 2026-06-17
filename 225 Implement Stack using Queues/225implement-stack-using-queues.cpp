class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        // q.push(x);
        q.push(x);
        int n=q.size();
        for(int i=1;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // queue<int>temp;
        // while(q.size()>1){
        //     int v=q.front();
        //     q.pop();
        //     temp.push(v);
        // }
        // int res=q.front();
        // q.pop();
        // while(!temp.empty()){
        //     int v=temp.front();
        //     temp.pop();
        //     q.push(v);
        // }
        // return res;
        int v=q.front();
        q.pop();
        return v;
    }
    
    int top() {
        // queue<int>temp;
        // while(q.size()>1){
        //     int v=q.front();
        //     q.pop();
        //     temp.push(v);
        // }
        // int res=q.front();
        // q.pop();
        // temp.push(res);
        // while(!temp.empty()){
        //     int v=temp.front();
        //     temp.pop();
        //     q.push(v);
        // }
        // return res;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */