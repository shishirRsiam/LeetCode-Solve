class Solution {
public:
    vector<string>number_words = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
    "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "thirty",
    "thirty one", "thirty two", "thirty three", "thirty four", "thirty five", "thirty six", "thirty seven", "thirty eight", "thirty nine", "forty",
    "forty one", "forty two", "forty three", "forty four", "forty five", "forty six", "forty seven", "forty eight", "forty nine", "fifty",
    "fifty one", "fifty two", "fifty three", "fifty four", "fifty five", "fifty six", "fifty seven", "fifty eight", "fifty nine", "sixty",
    "sixty one", "sixty two", "sixty three", "sixty four", "sixty five", "sixty six", "sixty seven", "sixty eight", "sixty nine", "seventy",
    "seventy one", "seventy two", "seventy three", "seventy four", "seventy five", "seventy six", "seventy seven", "seventy eight", "seventy nine", "eighty",
    "eighty one", "eighty two", "eighty three", "eighty four", "eighty five", "eighty six", "eighty seven", "eighty eight", "eighty nine", "ninety",
    "ninety one", "ninety two", "ninety three", "ninety four", "ninety five", "ninety six", "ninety seven", "ninety eight", "ninety nine", "one hundred"};
    string words(int num)
    {
        int cnt = 0;
        while(100 <= num) cnt++, num -= 100;
        string ans;
        if(cnt) 
        {
            ans += number_words[cnt];
            ans += " Hundred ";
        } 
        return ans + number_words[num];
    }
    string numberToWords(int num) 
    {
        if(num == 0) return "Zero";

        int bilion = 0, milion = 0, thousand = 0;
        while(num >= 1000000) milion++, num -= 1000000;
        while(num >= 1000) thousand++, num -= 1000;
        while(milion >= 1000) bilion++, milion -= 1000;

        string ans;
        if(bilion)
        {
            ans += words(bilion);
            if(ans.back() != ' ') ans += ' ';
            ans += "Billion ";
        }
        if(milion)
        {
            ans += words(milion);
            if(ans.back() != ' ') ans += ' ';
            ans += "million ";
        }
        if(thousand)
        {
            ans += words(thousand);
            if(ans.back() != ' ') ans += ' ';
            ans += "thousand ";
        }
        if(num) ans += words(num);

        bool flag = true;
        for(auto &ch:ans)
        {
            if(flag) ch = toupper(ch), flag = false;
            if(ch == ' ') flag = true;
        }
        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};