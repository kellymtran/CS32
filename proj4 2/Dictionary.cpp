#include "Dictionary.h"
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

const int MAX_BUCKETS = 50000;
void removeNonLetters(string& s);

class DictionaryImpl
{
public:
    DictionaryImpl(int maxBuckets) : m_buckets(maxBuckets) {}
    ~DictionaryImpl() {}
    void insert(string word);
    void lookup(string letters, void callback(string)) const;

private:
    vector<list<pair<string, string>>> m_buckets;
};

void DictionaryImpl::insert(string word)
{
    
    if (!word.empty()) {
        string temp = word;
        
        removeNonLetters(word);
        removeNonLetters(temp);
        
        sort(temp.begin(), temp.end());
        
        hash<string>hash;
        size_t hashV = hash(temp) % MAX_BUCKETS;
        
        m_buckets[hashV].push_back(make_pair(temp, word));
    }
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    if (callback == nullptr)
        return;

    removeNonLetters(letters);
    if (letters.empty())
        return;

    sort(letters.begin(), letters.end());
    hash<string> hash;
    size_t hashV = hash(letters) % MAX_BUCKETS;
    
    for (const auto& entry : m_buckets[hashV]) {
        if (entry.first == letters)
            callback(entry.second);
    }
}

void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());
}

Dictionary::Dictionary(int maxBuckets)
{
    m_impl = new DictionaryImpl(maxBuckets);
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters, callback);
}
