/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

/*

    Time Complexity : O(NlogN + MlogM), Sorting the String(s and t) costs O(NlogN + MlogM). Where N is the size
    of the String(s) and M is the size of the String(t).

    Space Complexity : O(1), Constant Space.

    Solved using String + Sorting.

*/

bool isAnagram(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t){
        return true;  
    }
    return false;
}

/*

    Time Complexity : O(N), as we iterate the string to count the frequency of every character where N is the
    length of the string.

    Space Complexity : O(1), Constant space. As we are using  26 size-frequency array to store the frequency of
    every character which is constant.

    Solved using String + Hash Table.

*/

bool isAnagram(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    int arr[26] = {0};
    for(int i=0; i<s.length(); i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }
    for(int i=0; i<26; i++){
        if(arr[i] != 0){
            return false;
        }
    }
    return true;
}

