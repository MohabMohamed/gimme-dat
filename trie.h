#ifndef TRIE_H
#define TRIE_H
#include <QString>
#include <QVector>
#include "trienode.h"
using namespace std;
class Trie
{
public:
    TrieNode head;

    Trie(){ head.ch = -1; }
    ~Trie();
    void build(const QVector<QString> & words);
   void insert(const QString & word,int);
  QVector<vector<int> > matches(QString word, bool &result);

QMap<QChar, TrieNode> * search(QString & word,QMap<QChar, TrieNode> * current_tree);
vector <int> trav(QMap<QChar, TrieNode>::iterator it);

};

#endif // TRIE_H
