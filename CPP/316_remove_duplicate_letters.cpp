#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool occurrence[26];
        for (int i = 0; i < 26; i++) {
            occurrence[i] = false;
        }
        int count = 0;
        // cout << "s.size()= " << s.size() << endl;
        for (int i = 0; i < s.size(); i++) {
            if (occurrence[s[i] - 'a'] == false) {
                occurrence[s[i] - 'a'] = true;
                count = count + 1;
            }
        }

        // cout << "count = " << count << endl;

        string result = "";
        int start_index = 0;
        while (count != 0) {
            bool temp_occurrence[26];
            for (int i = 0; i < 26; i++)
                temp_occurrence[i] = false;
            int temp_count = 0;
            char candidate = 'z' + 1;
            int temp_index;
            for (int i = s.size() - 1; i >= start_index; i--) {
                if (!temp_occurrence[s[i] - 'a'] &&
                    occurrence[s[i] - 'a']) {
                    temp_occurrence[s[i] - 'a'] = true;
                    temp_count = temp_count + 1;
                }

                if (occurrence[s[i] - 'a'] && temp_count == count &&
                    s[i] <= candidate) {
                    temp_index = i;
                    candidate = s[i];
                }
            }
            // find the candidate
            result = result + candidate;
            start_index = temp_index + 1;
            occurrence[s[temp_index] - 'a'] = false;
            count = count - 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s;
    string result;
    // s = "bcabc";
    // result = solution.removeDuplicateLetters(s);
    // cout << result << endl;
    // s = "cbacdcbc";
    // result = solution.removeDuplicateLetters(s);
    // cout << result << endl;
    s = "abacb";
    result = solution.removeDuplicateLetters(s);
    cout << result << endl;
    // s = "bddbccd";
    // result = solution.removeDuplicateLetters(s);
    // cout << result << endl;
    // s = "mitnlruhznjfyzmtmfnstsxwktxlboxutbic";
    // result = solution.removeDuplicateLetters(s);
    // cout << result << endl;
    s = "cbacdcbc";
    result = solution.removeDuplicateLetters(s);
    cout << result << endl;
    s = "";
    result = solution.removeDuplicateLetters(s);
    cout << result << endl;
    return 0;
}