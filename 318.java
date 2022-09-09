class Solution {
    final static private int letterNumber = 26;
    private int charBit(String s) {
        int ans = 0;
        for (char ch : s.toCharArray()) ans |= (1 << (ch - 'a'));
        return ans;
    }
    public int maxProduct(String[] words) {
        int ans = 0;
        int cnt = words.length;
        int[] charBits = new int[cnt];
        for (int i = 0; i < cnt; i++) charBits[i] = charBit(words[i]);
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if ((charBits[i] & charBits[j]) == 0) {
                    ans = Integer.max(ans, words[i].length() * words[j].length());
                }
            }
        }
        
        return ans;
    }
}
