class MyQueue {
public:
    void move(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
    }
    // stack<int>st;
    stack<int>in,out;
    MyQueue() {
        
    }
    
    void push(int x) {
        // st.push(x);
        in.push(x);
    }
    
    int pop() {
        // stack<int>temp;
        // while(st.size()>1){
        //     int v=st.top();
        //     st.pop();
        //     temp.push(v);
        // }
        // int res=st.top();
        // st.pop();
        // while(!temp.empty()){
        //     int v=temp.top();
        //     temp.pop();
        //     st.push(v);
        // }
        // return res;
        move();
        int v=out.top();
        out.pop();
        return v;
    }
    
    int peek() {
        // stack<int>temp;
        // while(st.size()>1){
        //     int v=st.top();
        //     st.pop();
        //     temp.push(v);
        // }
        // int res=st.top();
        // st.pop();
        // temp.push(res);
        // while(!temp.empty()){
        //     int v=temp.top();
        //     temp.pop();
        //     st.push(v);
        // }
        // return res;
        move();
        return out.top();
    }
    
    bool empty() {
        // return st.empty();
        return (in.empty()&&out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */