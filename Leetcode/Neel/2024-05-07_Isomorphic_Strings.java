/*

ISOMORPHIC STRINGS - https://leetcode.com/problems/isomorphic-strings/

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

*/

public class Solution {
    public boolean isIsomorphic(String s, String t) {

        int sLen = s.length(), tLen = t.length();
        if (sLen != tLen)
            return false;

        HashMap<Character, Character> mapS2T = new HashMap<>();
        HashMap<Character, Character> mapT2S = new HashMap<>();
        for (int i = 0; i < sLen; i++) {
            char charS = s.charAt(i);
            char charT = t.charAt(i);
            if (mapS2T.containsKey(charS)) {
                if (mapS2T.get(charS) != charT)
                    return false;
            } else {
                if (mapT2S.containsKey(charT))
                    return false;
                mapS2T.put(charS, charT);
                mapT2S.put(charT, charS);
            }
        }
        return true;
    }
}