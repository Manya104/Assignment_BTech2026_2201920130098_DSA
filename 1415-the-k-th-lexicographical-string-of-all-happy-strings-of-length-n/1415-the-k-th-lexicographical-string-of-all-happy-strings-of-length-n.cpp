class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> sequences;

        findSequences(sequences, "", n, k);

        if(k>sequences.size()) return "";
        else return sequences[k-1];
    }

    void findSequences(vector<string> &sequences, string curr, int n, int k) {
        if(sequences.size()==k) return;

        if(curr.size()==n) {
            sequences.push_back(curr);
            return;
        }

        for(int i=0; i<=2; i++) {
            char charToAdd = 'a'+i;
            if(curr.empty() || charToAdd != curr.back()) {
                curr += charToAdd;
                findSequences(sequences, curr, n, k);
                curr.pop_back();
            }
        }
    }
};