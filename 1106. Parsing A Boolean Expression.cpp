class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char>st;
        for(auto ch:expression)
        {
            if(ch == ')')
            {
                char flag = 't';
                unordered_set<char>ust;
                while(st.top() != '(')
                {
                    if(ust.size() <= 2) 
                        ust.insert(st.top());
                    st.pop();
                }

                st.pop(); // poped '('
                if(st.top() == '&')
                {
                    if(ust.count('f')) 
                        flag = 'f';
                }
                else if(st.top() == '|')
                {
                    if(not ust.count('t')) 
                        flag = 'f';
                }
                else if(st.top() == '!')
                {
                    if(ust.count('t')) 
                        flag = 'f';
                }
                st.pop(); // poped '&' or '|' or '!'
                st.push(flag); // flag = 't' or 'f'
            }
            else st.push(ch);
        }
        return (st.top() == 't' ? true : false);
    }
};