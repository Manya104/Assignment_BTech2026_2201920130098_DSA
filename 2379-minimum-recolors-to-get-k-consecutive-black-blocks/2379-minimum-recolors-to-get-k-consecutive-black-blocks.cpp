class Solution {
public:
    int minimumRecolors(string blocks, int k) {int l = 0, fw = 0;

        for (int r = 0; r < k; r++) {
            if (blocks[r] == 'W') fw++;
        }
        int mini = fw;

        for (int r = k; r < blocks.length(); r++, l++) {
            if (blocks[r] == 'W') fw++;
            if (blocks[l] == 'W') fw--;
            if (fw < mini) mini = fw;
        }

        return mini;
    }
};