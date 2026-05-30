class Solution {
public:
    int trap(vector<int>& height) {
        //O(n) time and space complexity using stack
        // int n=height.size();
        // stack<int>st;
        // int res=0;
        // for(int i=0;i<n;i++){
        //     while(!st.empty()&&height[i]>height[st.top()]){
        //         int b=st.top();
        //         st.pop();
        //         if(st.empty())break;
        //         int l=st.top();
        //         int w=i-l-1;
        //         int h=min(height[i],height[l])-height[b];
        //         res+=w*h;
        //     }
        //     st.push(i);
        // }
        // return res;

        //O(n) time and space complexity using prefix and suffix array 
        // int n=height.size();
        // vector<int>pre(n);
        // vector<int>suf(n);
        // pre[0]=height[0];
        // for(int i=1;i<n;i++){
        //     pre[i]=max(pre[i-1],height[i]);
        // }
        // suf[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suf[i]=max(suf[i+1],height[i]);
        // }
        // int res=0;
        // for(int i=0;i<n;i++){
        //     res+=min(pre[i],suf[i])-height[i];
        // }
        // return res;

        //O(n) time complexity
        int n=height.size();
        int l=0;
        int r=n-1;
        int lm=0;
        int rm=0;
        int res=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lm){
                    lm=max(lm,height[l]);
                }else{
                    res+=lm-height[l];
                }
                l++;
            }else{
                if(height[r]>=rm){
                    rm=max(rm,height[r]);
                }else{
                    res+=rm-height[r];
                }
                r--;
            }
        }
        return res;
    }
};