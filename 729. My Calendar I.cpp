class MyCalendar
{
public:
    MyCalendar() {}

    map<int, int> mp;
    bool book(int start, int end)
    {
        mp[start] += 1;
        mp[end] -= 1;
        int ActiveCount = 0;
        for (auto [value, count] : mp)
        {
            ActiveCount += count;
            if (ActiveCount > 1)
            {
                mp[start] -= 1;
                mp[end] += 1;
                return false;
            }
        }
        return true;
    }
};