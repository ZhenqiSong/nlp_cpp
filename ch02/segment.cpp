//
// Created by Zhenqi Song on 2020/5/17.
//

#include "segment.h"
#include "Utils.h"

namespace segment{
    void test(char* argv[]){
        auto dic = loadDictionary(argv[1]);
        println(fully_segment("商品和服务", dic));
        println(segmentForForwardLongest("就读北京大学", dic));
    }

    /**
     * 完全切分
     * @return
     */
    std::vector<std::string> fully_segment(const std::string& text, const Dict &dic){
        std::vector<std::string> word_list;
        for(int i = 0; i < text.size(); ++i){
            for (int j = i+1; j<(text.size()+1); ++j){
                auto word = text.substr(i, j-i);
                if (dic.find(word) != dic.end()){
                    word_list.push_back(word);
                }
            }
        }
        return word_list;
    }

    /**
     * 正向最长匹配
     */
    std::vector<std::string> segmentForForwardLongest(const std::string &text, const Dict &dic) {
        std::vector<std::string> wordList;
        for (int i = 0; i< text.size(); ){
            std::string longestWord;
            for (int j =i; j <= text.size(); ++j){
                auto word = text.substr(i, j);
                if (dic.find(word) != dic.end()){
                    if (word.size() > longestWord.size())
                        longestWord = word;
                }
            }
            i += longestWord.size();
            wordList.push_back(longestWord);
        }

        return wordList;
    }
}

