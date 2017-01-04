#ifndef TRIENODE_H
#define TRIENODE_H
#include <QChar>
#include <QString>
#include <QMap>
#include <vector>
using namespace std;
class TrieNode
{   
public:
    TrieNode();
    bool isleaf;
    QChar ch;
  QMap  <QChar,TrieNode> child;
    vector <int> occ;

};

#endif // TRIENODE_H
