#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *link[26];
    bool end = false;

    bool containkey(char ch)
    {
        return (link[ch - 'a']) != NULL;
    }

    void ref(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void setEnd()
    {
        end = true;
    }

    bool isEnd()
    {
        return end;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                node->ref(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.size(); ++i)
        {
            if (!node->containkey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main()
{
    Trie trie;

    // Insert words into the trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("cat");
    trie.insert("car");

    // Search for words in the trie
    cout << "Search Results:" << endl;
    cout << "apple: " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "banana: " << (trie.search("banana") ? "Found" : "Not Found") << endl;
    cout << "cat: " << (trie.search("cat") ? "Found" : "Not Found") << endl;
    cout << "car: " << (trie.search("car") ? "Found" : "Not Found") << endl;
    cout << "dog: " << (trie.search("dog") ? "Found" : "Not Found") << endl;

    // Check if prefixes exist in the trie
    cout << "Prefix Check:" << endl;
    cout << "ap: " << (trie.startsWith("ap") ? "Prefix exists" : "Prefix does not exist") << endl;
    cout << "ban: " << (trie.startsWith("ban") ? "Prefix exists" : "Prefix does not exist") << endl;
    cout << "c: " << (trie.startsWith("c") ? "Prefix exists" : "Prefix does not exist") << endl;
    cout << "ca: " << (trie.startsWith("ca") ? "Prefix exists" : "Prefix does not exist") << endl;
    cout << "z: " << (trie.startsWith("z") ? "Prefix exists" : "Prefix does not exist") << endl;

    return 0;
}

// TC-O(N)
// SC-O(N)
