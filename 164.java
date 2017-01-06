package Hard.p164;

import Nodes.Interval;

import java.util.*;

/**
 * Created by Krossing on 1/1/17.
 */
//Bucket Sort
//public class Solution {
//    public int maximumGap(int[] nums) {
//        if (nums == null || nums.length < 2)
//            return 0;
//        int min = Integer.MAX_VALUE;
//        int max = Integer.MIN_VALUE;
//
//        for (int n : nums) {
//            min = Math.min(min, n);
//            max = Math.max(max, n);
//        }
//        int bucketSize = Math.max(1, (max - min) / (nums.length - 1));
//        int num = (max - min) / bucketSize + 1;
//        if (num <= 1)
//            return max - min;
//
//        int[] minBuckets = new int[num];
//        int[] maxBuckets = new int[num];
//        Arrays.fill(minBuckets, Integer.MAX_VALUE);
//        Arrays.fill(maxBuckets, Integer.MIN_VALUE);
//
//        for (int n : nums) {
//            int pos = (n - min) / bucketSize;
//            minBuckets[pos] = Math.min(minBuckets[pos], n);
//            maxBuckets[pos] = Math.max(maxBuckets[pos], n);
//        }
//        int res = -1;
//        int pre = maxBuckets[0];
//        for (int i = 1; i < num; ++i) {
//            if (minBuckets[i] != Integer.MAX_VALUE)
//                res = Math.max(res, minBuckets[i] - pre);
//            if (maxBuckets[i] != Integer.MIN_VALUE)
//                pre = maxBuckets[i];
//        }
//        return res;
//    }
//}

//Radix Sort
public class Solution {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2)
            return 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        for (int n : nums) {
            max = Math.max(max, n);
        }
        int base = 1;
        int[] sorted = new int[nums.length];
        while (max != 0) {
            int[] count = new int[10];
            for (int n : nums)
                count[(n / base) % 10]++;
            for (int i = 1; i < 10; ++i)
                count[i] += count[i - 1];
            for (int i = nums.length - 1; i >= 0; --i) {
                sorted[--(count[(nums[i] / base) % 10])] = nums[i];
            }
            nums = sorted.clone();
            base *= 10;
            max /= 10;
        }
        int res = -1;
        for (int i = 1; i < nums.length; ++i) {
            res = Math.max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
}