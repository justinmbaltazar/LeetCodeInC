#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
    int len = 0;
    int i = 0;
    int j = 0;
    int max = 0;
    int hash[256] = {0};
    while(s[i] != '\0'){
        if(hash[s[i]] == 0){
            len++;
            hash[s[i]] = 1;
        }
        else{
            if(len > max){
                max = len;
            }
            while(s[j] != s[i]){
                hash[s[j]] = 0;
                j++;
            }
            j++;
            len = i - j + 1;
        }
        i++;
    }
    if(len > max){
        max = len;
    }
    return max;
}