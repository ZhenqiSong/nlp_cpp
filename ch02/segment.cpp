//
// Created by Zhenqi Song on 2020/5/17.
//

#include "segment.h"

/**
 * 完全切分
 * @param text
 * @param dic
 * @return
 */
std::vector<std::string> fully_segment(const std::string& text, const std::set<std::string>& dic){
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