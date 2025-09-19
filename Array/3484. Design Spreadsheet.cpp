// 2D Array Solution
class Spreadsheet {
public:
    vector<vector<int>> store;
    Spreadsheet(int rows) {
        store.resize(rows + 1, vector<int>(26));
    }
    
    auto getint(string s) {
        string number = "";
        for(auto &ch : s)
            if(isdigit(ch)) number += ch;
        return stoi(number);
    }

    void setCell(string cell, int value) {
        int row = getint(cell),  col = cell[0] - 'A';
        store[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = getint(cell), col = cell[0] - 'A';
        store[row][col] = 0;
    }
    
    int getValue(string formula) {
        int index = formula.find('+');
        string cell1 = formula.substr(1, index - 1);
        string cell2 = formula.substr(index + 1);
        
        int val1 = 0, val2 = 0;
        try {
            val1 = stoi(cell1);
        }
        catch(const exception &e) {
            int row = getint(cell1), col = cell1[0] - 'A';
            val1 = store[row][col];
        }
        
        try {
            val2 = stoi(cell2);
        }
        catch(const exception &e) {
            int row = getint(cell2), col = cell2[0] - 'A';
            val2 = store[row][col];
        }
        return val1 + val2;
    }
};



// Hash Table Solution
class Spreadsheet {
public:
    unordered_map<int, unordered_map<char, int>> store;
    Spreadsheet(int rows) {
    }

    auto getint(string s) {
        string number = "";
        for(auto &ch : s)
            if(isdigit(ch)) number += ch;
        return stoi(number);
    }

    void setCell(string cell, int value) {
        int col = cell[0], row = getint(cell);
        store[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = cell[0], col = getint(cell);
        swap(row, col);
        store[row][col] = 0;
    }
    
    int getValue(string formula) {
        int index = formula.find('+');
        string cell1 = formula.substr(1, index - 1);
        string cell2 = formula.substr(index + 1);
        
        int val1 = 0, val2 = 0;
        try {
            val1 = stoi(cell1);
        }
        catch(const exception &e) {
            int col = cell1[0], row = getint(cell1);
            val1 = store[row][col];
        }
        
        try {
            val2 = stoi(cell2);
        }
        catch(const exception &e) {
            int col = cell2[0], row = getint(cell2);
            val2 = store[row][col]; 
        }
        return val1 + val2;
    }
};