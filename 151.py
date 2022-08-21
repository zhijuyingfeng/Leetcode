class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        words.reverse()

        ans = ""
        for word in words:
            if len(word) > 0:
                ans += " " + word
        return ans.strip()
