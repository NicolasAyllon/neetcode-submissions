class Solution {
public:
        // If the characters in a string are sorted, then
        // they appear in alphabetical order with each character appearing
        // the same number of times. The sorted string is unique
        // for each frequency of characters that could be in the string.
        // Furthermore we can tell if two strings are anagrams if they have
        // the same sorted form.
        // e.g. (stop, pots, tops) -SORT-> (opst)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Result will be a vector of vector of string, where each is a group of anagrams.
        std::vector<std::vector<std::string>> groups;
        // Hashmap that associates a sorted string to a group (vector<string>)
        std::unordered_map<std::string, std::vector<std::string>> sorted_to_group;

        // Iterrate through all the strings (str is a copy of each string in strs)
        for (const std::string& str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            // If there is already a group for this sorted string, add this string to the group
            if (sorted_to_group.count(sorted)) {
                sorted_to_group[sorted].push_back(str);
            } 
            // Otherwise create a new group.
            else {
                sorted_to_group[sorted] = {str};
            }
        }

        // Add all the groups to the result
        for (const auto& [sorted, group] : sorted_to_group) {
            groups.push_back(group);
        }

        return groups;
    }
};
