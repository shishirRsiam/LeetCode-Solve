class Solution {
public:
    string reformatDate(string date) 
    {
        unordered_map<string, string> store;
        store["Jan"] = "01";
        store["Feb"] = "02";
        store["Mar"] = "03";
        store["Apr"] = "04";
        store["May"] = "05";
        store["Jun"] = "06";
        store["Jul"] = "07";
        store["Aug"] = "08";
        store["Sep"] = "09";
        store["Oct"] = "10";
        store["Nov"] = "11";
        store["Dec"] = "12";

        int n = date.size();
        string year = date.substr(n - 4);
        string month = date.substr(n - 8, 3);
        string day = date.substr(0, n - 11);

        return year + "-" + store[month] + "-" + (day.size() == 1 ? "0" : "") + day;
    }
};