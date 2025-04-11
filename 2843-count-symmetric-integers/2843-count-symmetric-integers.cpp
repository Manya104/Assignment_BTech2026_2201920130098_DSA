class Solution {
public:
    bool checkevendigits_and_halfsum(int num) {
        int temp = num;
        int digitCount = 0;
        while (temp > 0) {
            temp /= 10;
            digitCount++;
        }

        if (digitCount % 2 != 0) {
            return false;
        }

        int halfCount = digitCount / 2;
        int leftSum = 0;
        int rightSum = 0;
        int powerOf10 = 1;
        for (int i = 0; i < halfCount; ++i) {
            powerOf10 *= 10;
        }

        // Calculate sum of the first half
        int firstHalf = num / powerOf10;
        for (int i = 0; i < halfCount; ++i) {
            leftSum += firstHalf % 10;
            firstHalf /= 10;
        }

        // Calculate sum of the second half
        int secondHalf = num % powerOf10;
        for (int i = 0; i < halfCount; ++i) {
            rightSum += secondHalf % 10;
            secondHalf /= 10;
        }

        return leftSum == rightSum;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            if (checkevendigits_and_halfsum(i)) {
                ans++;
            }
        }
        return ans;
    }
};