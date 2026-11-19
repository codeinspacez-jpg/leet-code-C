int findShortestSubArray(int* nums, int numsSize) {
    int freq[50001] = {0};
    int first[50001];
    int last[50001];

    for (int i = 0; i < 50001; i++) {
        first[i] = -1;
        last[i] = -1;
    }

    int degree = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        freq[x]++;

        if (first[x] == -1) {
            first[x] = i;
        }

        last[x] = i;

        if (freq[x] > degree) {
            degree = freq[x];
        }
    }

    int minLength = numsSize;

    for (int i = 0; i < 50001; i++) {
        if (freq[i] == degree) {
            int length = last[i] - first[i] + 1;

            if (length < minLength) {
                minLength = length;
            }
        }
    }

    return minLength;
}