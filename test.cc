#include <iostream>
#include "cjk-tokenizer.h"

using namespace std;
using namespace cjk;

int main() {
  char text[] =
    "美女遊戲等你挑戰周蕙最新鈴搶先下載茄子醬耍可愛一流"
    "华沙是波兰的首都，也是其最大的城市。"
    "납치 여중생 공포에 떠는데'…경찰 200m 거리 25분만에 출동"
    "寛永通宝の一。京都方広寺の大仏をこわして1668年（寛文8）から鋳造した銅銭。"
    "ㄅㄆㄇㄈㄉㄊㄋㄌㄧㄨㄩ"
    "Giant Microwave Turns Plastic Back to Oil";
  string text_str = string(text);

  tokenizer tknzr;
  vector<pair<string, unsigned> > token_list;
  vector<pair<string, unsigned> >::iterator token_iter;

  token_list.clear();
  tknzr.ngram_size = 1;       // Unigram
  tknzr.max_token_count = 0;
  tknzr.tokenize(text_str, token_list);
  cout << "Original string: " << text_str << endl;
  cout << "Tokenized result: ";
  for (token_iter = token_list.begin();
       token_iter != token_list.end(); ++token_iter) {
    cout << "[" << token_iter->first << "] ";
  }
  cout << endl << endl;

  return 0;
}
