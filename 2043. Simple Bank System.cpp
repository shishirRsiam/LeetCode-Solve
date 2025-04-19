class Bank {
public:
    vector<long long> bal;
    Bank(vector<long long>& balance) {
        bal = balance;
    }
    bool isValidAccount(int account) {
        return account and account <= bal.size();
    }
    bool availableMoney(int &account, long money) {
        return bal[account - 1] >= money;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(not isValidAccount(account1) or not isValidAccount(account2))
            return false;
        
        if(not availableMoney(account1, money)) 
            return false;
        
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }

    
    bool deposit(int account, long long money) {
        if(not isValidAccount(account))
            return false;
        bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(not isValidAccount(account))
            return false;
        if(not availableMoney(account, money)) 
            return false;

        bal[account - 1] -= money;
        return true;
    }
};