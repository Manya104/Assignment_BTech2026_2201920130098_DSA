class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        int pos1 = 0;

        for (int i = 0; i < t.size(); i++) {
            if ((t[i] == '0') || (t[i] == '1')) {
                continue;
            } else {
                pos1 = i;
                break;
            }
        }

        if (pos1 != t.size()) {
            
            char b = t[pos1];
            if (pos1 == 0) {
                replace(t.begin(), t.end(), b, '1');
            } else {
                replace(t.begin(), t.end(), b, '0');
            }

        }
        cout << stoi(s) << " " << stoi(t);
        // char b = t[0];
        // replace(t.begin(), t.end(), b, '0');

        return stoi(s) - stoi(t);
    }
};