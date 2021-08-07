#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
  vector<string> result;

  auto word_begin = begin(s);

  while (true) {
    auto word_end = find(word_begin, end(s), ' ');

    result.push_back({word_begin, word_end});

    if (word_end == end(s)) {
      break;
    }

    word_begin = word_end + 1;
  }

  return result;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
