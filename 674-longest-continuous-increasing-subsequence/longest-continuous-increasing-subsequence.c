int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}