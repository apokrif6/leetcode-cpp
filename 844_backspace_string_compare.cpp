//Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

//Note that after backspacing an empty text, the text will continue empty.

//Example 1:
//Input: s = "ab#c", t = "ad#c"
//Output: true
//Explanation: Both s and t become "ac".

//Example 2:
//Input: s = "ab##", t = "c#d#"
//Output: true
//Explanation: Both s and t become "".

//Example 3:
//Input: s = "a#c", t = "b"
//Output: false
//Explanation: s becomes "c" while t becomes "b".

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;

        for (auto c : s)
        {
            if (c == '#' && !a.empty())
                a.pop_back();
            else
                a += c;
        }

        for (auto c : t)
        {
            if (c == '#' && !b.empty())
                b.pop_back();
            else
                b += c;
        }

        a.erase(remove(a.begin(), a.end(), '#'), a.end());
        b.erase(remove(b.begin(), b.end(), '#'), b.end());

        return a == b;
    }
};
