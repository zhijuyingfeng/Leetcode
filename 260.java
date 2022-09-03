class Solution {

//    Let a and b be the two unique numbers
//    XORing all numbers gets you (a xor b)
//    (a xor b) must be non-zero otherwise they are equal
//    If bit_i in (a xor b) is 1, bit_i at a and b are different.
//    Find bit_i using the low bit formula m & -m
//    Partition the numbers into two groups: one group with bit_i == 1 and the other group with bit_i == 0.
//    a is in one group and b is in the other.
//    a is the only single number in its group.
//    b is also the only single number in its group.
//    XORing all numbers in a's group to get a
//    XORing all numbers in b's group to get b
//    Alternatively, XOR (a xor b) with a gets you b.

    public int[] singleNumber(int[] nums) {
        int ans[] = new int[2];
        int aXorB = 0;
        for (int num : nums) aXorB ^= num;
        aXorB &= -aXorB;
        for (int num : nums) {
            if ((aXorB & num) == 0) {
                ans[0] ^= num; 
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
}
