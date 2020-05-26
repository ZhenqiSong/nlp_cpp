//
// Created by Zhenqi Song on 2020/5/17.
//

#ifndef NLP_CPP_SEGMENT_H
#define NLP_CPP_SEGMENT_H

#include <vector>
#include <iostream>
#include <string>
#include <set>
namespace segment{
    using Dict = std::set<std::string>;

    // 完全切分
    std::vector<std::string> fully_segment(const std::string& text, const Dict& dic);

    // 正向最大切分
    std::vector<std::string> segmentForForwardLongest(const std::string& text, const Dict& dic);

    // 反向最长匹配
    std::vector<std::string> backwardSegment(const std::string& text, const Dict& dic);

    void test(char* argv[]);
}

#endif //NLP_CPP_SEGMENT_H
