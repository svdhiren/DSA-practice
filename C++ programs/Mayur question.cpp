#include <bits/stdc++.h>
using namespace std;
#define CHILDREN 26
#define MAX 100


// Trie node
struct trie {
    trie* child[CHILDREN];
    // endOfWord is true if the node represents
    // end of a word
    bool endOfWord;
};

// Function will return the new node(initialized to NULLs)
trie* createNode()
{
    trie* temp = new trie();
    temp->endOfWord = false;
    for (int i = 0; i < CHILDREN; i++) {
        // Initialise all child to the null, initially
        temp->child[i] = NULL;
    }

    // Return newly created node
    return temp;
}
// Function will insert the string in a trie recursively
void insertRecursively(trie* itr, string str, int i)
{
    if (i < str.length()) {
        int index = str[i] - 'a';
        if (itr->child[index] == NULL) {
            // Assining a newly created node
            itr->child[index] = createNode();
        }
        // Recursive call for insertion
        // of a string in a trie
        insertRecursively(itr->child[index], str, i + 1);
    }
    else {
        // Make the endOfWord true which represents
        // the end of string
        itr->endOfWord = true;
    }
}
// Function call to insert a string
void insert(trie* itr, string str)
{
    // Function call with necessary arguments
    insertRecursively(itr, str, 0);
}
// Function to print traverse
// the tree in bottum to top manner
void printPattern(trie* itr)
{
    // Base condition
    if (itr == NULL)
        return;

    // Loop for printing t a value of character
    for (int i = 0; i < CHILDREN; i++) {

        // Recursive call for print pattern
        printPattern(itr->child[i]);
        if (itr->child[i] != NULL) {
            char ch = (i + 97);
            cout << ch << ", "; // Print character
        }
    }
}

// Driver code
int main()
{
    trie* root = createNode();

    // Function to insert a string
    insert(root, "their");
    insert(root, "there");
    insert(root, "answer");
    insert(root, "any");


    // Function call for printing a pattern
    printPattern(root);

    return 0;
}
