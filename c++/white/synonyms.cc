#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
  map<string, set<string>> synonyms;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string op;

    cin >> op;

    if (op == "ADD") {
      string word1, word2;

      cin >> word1 >> word2;

      synonyms[word1].insert(word2);
      synonyms[word2].insert(word1);
    }

    if (op == "COUNT") {
      string word;

      cin >> word;

      cout << synonyms[word].size() << endl;
    }

    if (op == "CHECK") {
      string word1, word2;

      cin >> word1 >> word2;

      if (synonyms[word1].count(word2)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}