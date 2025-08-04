#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include<stdlib.h>

char* extractWordAtIndex(const char*, int);
char* extractWordAtIndex(const char* sentence, int position) {
    char* copy = strdup(sentence);
    char* token;
    int count = 0;
    char* result = NULL;

    token = strtok(copy, " ");
    while (token != NULL) {
        if (count == position) {
            result = strdup(token);
            break;
        }
        count++;
        token = strtok(NULL, " ");
    }
    free(copy);
    return result;
}
int hash[26];

int charToNumber(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else {
        return -1;
    }
}

int countWords(const char *s) {
    int count = 0;
    int inWord = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}


bool wordPattern(char* pattern, char* s) {
    for(int i=0;i<26;i++){
        hash[i] = -1;
    }
    if(strlen(pattern)!=countWords(s)) return false;
    for(int i =0;i<strlen(pattern);i++){
        int n = charToNumber(pattern[i]);
        if(hash[n] != -1){
            if(strcmp(extractWordAtIndex(s,i),extractWordAtIndex(s,hash[n])) != 0) return false;
        }else{
            for(int j = 0;j<26;j++){
                if(j==n) continue;
                if(hash[j]!= -1){
                    if(strcmp(extractWordAtIndex(s,hash[j]),extractWordAtIndex(s,i)) == 0 ) return false;
                }
            }
            hash[n]=i;
        }
    }
    return  true;
}

int main() {
    char pattern[] = "aaaa";
    char s[] = "dog dog dog dog dog";

    bool result = wordPattern(pattern, s);
    printf("%s\n", result ? "true" : "false");

    return 0;
}
