class StockSpanner {
public:
    // stack<int>st,temp;
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // st.push(price);
        // int c=0;
        // while(!st.empty()&&st.top()<=price){
        //     temp.push(st.top());
        //     st.pop();
        //     c++;
        // }
        // while(!temp.empty()){
        //     st.push(temp.top());
        //     temp.pop();
        // }
        // return c;
        int c=1;
        while(!st.empty()&&st.top().first<=price){
            c+=st.top().second;
            st.pop();
        }
        st.push({price,c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */