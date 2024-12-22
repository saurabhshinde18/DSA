#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(TrieNode* root, const char* word) {
    TrieNode* node = root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
        word++;
    }
    node->is_end_of_word = 1;
}

void searchWords(TrieNode* node, char* pattern, int index, char* result, int resultIndex, int wordLength) {
    if (index == wordLength) {
        if (node->is_end_of_word) {
            result[resultIndex] = '\0';
            printf("%s\n", result);
        }
        return;
    }

    char currentChar = pattern[index];
    if (currentChar == '?') {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                result[resultIndex] = 'a' + i;
                searchWords(node->children[i], pattern, index + 1, result, resultIndex + 1, wordLength);
            }
        }
    } else {
        int charIndex = currentChar - 'a';
        if (node->children[charIndex]) {
            result[resultIndex] = currentChar;
            searchWords(node->children[charIndex], pattern, index + 1, result, resultIndex + 1, wordLength);
        }
    }
}

int main() {
    TrieNode* root = createNode();
    char* dictionary[] = {"frost", "foist", "first", "feast", "feist", "faust"};
    int dictSize = 6;
    char pattern[100];
    int wordLength;

    for (int i = 0; i < dictSize; i++) {
        insert(root, dictionary[i]);
    }

    printf("Enter the word length: ");
    scanf("%d", &wordLength);
    printf("Enter the pattern (use '?' for unknown letters): ");
    scanf("%s", pattern);

    if (strlen(pattern) != wordLength) {
        printf("Error: Pattern length does not match the specified word length.\n");
        return 1;
    }

    char result[wordLength + 1];
    printf("Matching words:\n");
    searchWords(root, pattern, 0, result, 0, wordLength);

    return 0;
}
