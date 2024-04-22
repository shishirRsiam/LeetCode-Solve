class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<int>count;
        vector<set<int>>value;
        int n = 9;
        for(int i=0;i<n;i++)
        {
            int digit = 0;
            set<int>st;
            for(int j=0;j<n;j++)
            {
                if(isdigit(board[i][j])) 
                {
                    digit++;
                    st.insert(board[i][j]);
                }                 
            }
            count.push_back(digit);
            value.push_back(st);
        }

        for(int i=0;i<n;i++)
        {
            if(count[i] != value[i].size()) return false;
            // cout<<count[i]<<" "<<value[i].size()<<endl;
        }

        count.clear(), value.clear();
        for(int i=0;i<n;i++)
        {
            int digit = 0;
            set<int>st;
            for(int j=0;j<n;j++)
            {
                if(isdigit(board[j][i])) 
                {
                    digit++;
                    st.insert(board[j][i]);
                    // cout<<board[j][i]<<" ";
                }                 
            }
            // cout<<endl;
            count.push_back(digit);
            value.push_back(st);
        }

        for(int i=0;i<n;i++)
        {
            if(count[i] != value[i].size()) return false;
            // cout<<count[i]<<" "<<value[i].size()<<endl;
        }

        count.clear(), value.clear();
        for(int k=0;k<n;k+=3)
        {
            for(int l=0;l<n;l+=3)
            {
                int digit = 0;
                set<int>st;
                for(int i=k;i<k+3;i++)
                {
                    for(int j=l;j<l+3;j++)
                    {
                        if(isdigit(board[j][i])) 
                        {
                            digit++;
                            st.insert(board[j][i]);
                            // cout<<board[j][i]<<" ";
                        }
                        //cout<<board[i][j]<<" ";
                    }
                    //cout<<endl;
                }
                count.push_back(digit);
                value.push_back(st);
                //cout<<endl;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(count[i] != value[i].size()) return false;
            // cout<<count[i]<<" "<<value[i].size()<<endl;
        }

        return true;
    }
};