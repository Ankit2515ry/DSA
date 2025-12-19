class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>st;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(exp[i]==',')continue;
            else if(exp[i]==')'){
                int t=0;
                int f=0;
                while(st.top()!='('){
                    if(st.top()=='t')t++;
                    else f++;
                    st.pop();
                }
                st.pop();
                if(st.top()=='|'){
                    if(t>0){
                        st.pop();
                        st.push('t');
                    }else{
                        st.pop();
                        st.push('f');
                    }
                    continue;
                }else if(st.top()=='&'){
                    if(f>0){
                        st.pop();
                        st.push('f');
                    }else{
                        st.pop();
                        st.push('t');
                    }
                    continue;
                }else if(st.top()=='!'){
                    if(t>0){
                        st.pop();
                        st.push('f');
                    }else{
                        st.pop();
                        st.push('t');
                    }
                    continue;
                }
            }else{
                st.push(exp[i]);
            }
        }
        if(st.top()=='t')return true;
        return false;
    }
};