#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    map<pair<string, int>, string> mp; // Declare a map with a key of pair<string, int> and a value of string. This map will store the time-based key-value pairs.

    TimeMap() {} // Default constructor for the TimeMap class.

    void set(string key, string val, int tt)
    {
        mp[{key, tt}] = val; // Set the value 'val' at the key [{key, tt}] in the map.
    }

    string get(string key, int tt)
    {
        auto it = mp.lower_bound({key, tt}); // Find the iterator pointing to the first element in the map whose key is not considered to go before [{key, tt}] (or is equal to it).
        if (it != mp.end())
        { // If the iterator is not pointing to the end of the map (i.e., a valid element is found)
            if ((*it).first.first == key && (*it).first.second <= tt)
            {
                return (*it).second; // If the key matches 'key' and the timestamp is less than or equal to 'tt', return the corresponding value.
            }
            it--; // If the above condition is not satisfied, move the iterator to the previous element in the map.
        }
        if ((*it).first.first == key && (*it).first.second <= tt)
        {
            return (*it).second; // Check if the key matches 'key' and the timestamp is less than or equal to 'tt' for the previous element. If so, return the corresponding value.
        }
        return ""; // If no valid value is found, return an empty string.
    }
};

int main()
{
    // Example usage of the TimeMap class
    TimeMap tm;

    tm.set("key1", "value1", 5);
    tm.set("key1", "value2", 10);
    tm.set("key2", "value3", 7);

    cout << tm.get("key1", 3) << endl;  // Output: ""
    cout << tm.get("key1", 8) << endl;  // Output: "value1"
    cout << tm.get("key2", 9) << endl;  // Output: ""
    cout << tm.get("key2", 12) << endl; // Output: "value3"

    return 0;
}