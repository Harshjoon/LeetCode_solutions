class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        '''
            abcabcbbefghijk
                        r
                   l
        '''
        left = 0
        max_len = 0
        char_set = set()

        for right in range(len(s)):

            if s[right] not in char_set:
                char_set.add(s[right])
                max_len = max(max_len,right-left+1)
            else:
                while s[right] in char_set:
                    char_set.remove(s[left])
                    left += 1
                char_set.add(s[right])

        return max_len
        