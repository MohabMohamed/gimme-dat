# gimme dat #
a lite search engine.
the program predicts the complete query (typically a word or phrase) 
that the user intends to type and auto correct the spell mistakes.


## Dependencies ##
This project is based on the wonderful Qt framework.

If you're on Windows download and install it here: https://www.qt.io/download-open-source/
If you're on Linux use your package manager.
### Ubuntu
`sudo apt install sudo apt-get install qt5-default qttools5-dev-tools mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev`
### Fedora
`sudo dnf install qt5-qt*`
### Arch
I don't know! If you have arch send a pull request to let the world know what commands to do!


## Data structures and algorithims used: ##
1. Prefix seach: Trie
2. Substring search: Suffix tree 
3. Auto correct: Levenshtein distance