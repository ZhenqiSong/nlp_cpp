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
#include <algorithm>

using namespace std;
#define DIC_PATH "/Users/zhenqisong/develop/project/CPlus/nlp_cpp/data/CoreNatureDictionary.mini.txt"

std::set<string> loadDictionary(const string& path=DIC_PATH);

template <typename T>
void print(std::vector<T> data, const string& sep=" "){
    for (auto& x : data)
        std::cout << x << sep;
}

template <typename T>
void println(std::vector<T> data, const string& sep=" "){
    print(data, sep);
    std::cout << endl;
}

#endif //NLP_CPP_UTILS_H
