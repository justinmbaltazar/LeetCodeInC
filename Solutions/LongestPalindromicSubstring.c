#include <stdio.h>
#include <stdlib.h>

char *substr(char *s, int start, int end){
    int len = end - start;
    char *result = malloc(sizeof(char) * (len + 1));
    int i = 0;
    for(i = start; i < end; i++){
        result[i - start] = s[i];
    }
    result[len] = '\0';
    return result;
}
int expandFromCenter(char *s, int start, int end) {
    while (start >= 0 && end < strlen(s) && s[start] == s[end]) {
        start--;
        end++;
    }
    return end - start - 1;
}
char* longestPalindrome(char* s) {
    if (s == NULL || s == "") {
        return "";
    }
    int maxLen = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < strlen(s); i++) {
        int len1 = expandFromCenter(s, i, i);
        int len2 = expandFromCenter(s, i, i + 1);
        int len = len1 > len2 ? len1 : len2;
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return substr(s, start, end + 1);
}

