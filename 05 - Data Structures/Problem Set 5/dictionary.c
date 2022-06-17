// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// Defines struct for a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];

// Hashes the word (hash function posted on reddit by delipity)
// The word you want to hash is contained within new node, arrow, word.
// Hashing that will give you the index. Then you insert word into linked list.
int hash_index(char *hash_this)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hash_this); i < n; i++)
    {
        hash = (hash << 2) ^ hash_this[i];
    }
    return hash % HASHTABLE_SIZE;
}

// Initializes counter for words in dictionary
int word_count = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Opens dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Scans dictionary word by word (populating hash table with nodes containing words found in dictionary)
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Mallocs a node for each new word (i.e., creates node pointers)
        node *new_node = malloc(sizeof(node));
        // Checks if malloc succeeded, returns false if not
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        strcpy(new_node->word, word);

        int h = hash_index(new_node->word);

        node *head = hashtable[h];

        if (head == NULL)
        {
            hashtable[h] = new_node;
            word_count++;
        }
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
            word_count++;
        }
    }
    fclose(file);
    return true;
}

bool check(const char *word)
{
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[n] = '\0';
    int h = hash_index(word_copy);
    node *cursor = hashtable[h];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    node *head = NULL;
    node *cursor = head;
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}