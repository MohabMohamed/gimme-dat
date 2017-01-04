#include "trie.h"


void Trie::build(const QVector <QString> & words) {
  for (int i=0; i<words.size(); ++i) {
    insert(words[i],i);

  }
}

void Trie::insert(const QString &word,int idx) {
  QMap<QChar, TrieNode> * current_tree = &head.child;
  QMap<QChar, TrieNode>::iterator it;

  for (int i=0; i<word.length(); i++) {
    QChar ch = word[i];
it =  current_tree->find(ch);
    if (it != current_tree->end()) {
      current_tree = & it.value().child;
      if(i==word.length()-1)(*current_tree)[ch].occ.push_back(idx);
      continue;
    }

    if (it == current_tree->end()) {


      TrieNode  new_node;
      new_node.ch = ch;
      (*current_tree)[ch] = new_node;
if(i==word.length()-1)(*current_tree)[ch].occ.push_back(idx);
      // For continuous inserting a word
      current_tree = &new_node.child;


    }

  }
}
QMap<QChar, TrieNode> * Trie::search(QString & word,QMap<QChar, TrieNode> * current_tree ) {
  QMap<QChar, TrieNode>::iterator it;

  for (int i=0; i<word.length(); ++i) {
      it = current_tree->find(word[i]);
    if (it == current_tree->end()) {

      return NULL;
    }

    current_tree = &it.value().child;
  }


  return current_tree;
}
vector <int> Trie::trav(QMap<QChar, TrieNode>::iterator it){
if(it.value().occ.size()!=0){

    for (QMap<QChar, TrieNode>::iterator tmp=it.value().child.begin(); tmp!=it.value().child.end(); tmp++)
    trav(tmp);

}
return it.value().occ;
}

QVector<vector<int> >  Trie::matches(QString word, bool &result){
    QMap<QChar, TrieNode> * current_tree = search(word,&head.child);
    QVector<vector<int> > pos;
    if(current_tree==NULL){result=0; return pos;}

        for( QMap<QChar, TrieNode>::iterator it=  current_tree->begin();it!=current_tree->end();it++){
            pos.push_back(trav(it));
}
return pos;
}
