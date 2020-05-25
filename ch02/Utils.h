//
// Created by Zhenqi Song on 2020/5/17.
//

#ifndef NLP_CPP_UTILS_H
#define NLP_CPP_UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
#define DIC_PATH "/Users/zhenqisong/develop/project/CPlus/nlp_cpp/data/CoreNatureDictionary.mini.txt"

std::set<string> loadDictionary(const string& path=DIC_PATH);

#endif //NLP_CPP_UTILS_H
