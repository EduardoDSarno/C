// Alice and Bob are playing a game. Initially, Alice has a string word = "a".

// You are given a positive integer k.

// Now Bob will ask Alice to perform the following operation forever:

// Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
// For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

// Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

 

// Example 1:

// Input: k = 5

// Output: "b"

// Explanation:

// Initially, word = "a". We need to do the operation three times:

// Generated string is "b", word becomes "ab".
// Generated string is "bc", word becomes "abbc".
// Generated string is "bccd", word becomes "abbcbccd".
// Example 2:

// Input: k = 10

// Output: "c"


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char kthCharacter(int k);

int main(void){
    printf("%c", kthCharacter(10));
}

char kthCharacter(int k) {
    
    char *word = malloc(k * 2 + 1);
    word[0] = 'a';
    word[1] = '\0';
    char *copy = malloc(k * 2 + 1);

    
    
    while (strlen(word) < k) {
        // for each char in s
        for (int i = 0; word[i] != '\0'; i++) {
            copy[i] = (word[i] == 'z') ? 'a' : (word[i] + 1);
        }

        //printf("copy: %s\n", copy);
        size_t old_length = strlen(word);
        copy[old_length] = '\0';
        // append the copy to the end
        for (int i = 0; copy[i] != '\0'; i++) {
            word[old_length + i] = copy[i];
        }

        word[old_length + strlen(copy)] = '\0';
        //printf("word: %s\n", word);
    }
    return word[k - 1]; // adjusting to index
}