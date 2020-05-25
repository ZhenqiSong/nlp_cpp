//
// Created by Zhenqi Song on 2020/5/17.
//

#include "Utils.h"

/**使用反向迭代器，擦除左侧空格
 *
 * @s 需要处理的字符串
*/
static inline void lstrip(std::string &s){
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch){
        return !std::isspace(ch);
    }));
}

/**使用反向迭代器，擦除右侧空格
 *
 * @s 需要处理的字符串
*/
static inline void rstrip(std::string &s){
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch){
        return !std::isspace(ch);
    }).base(), s.end());
}

/**
 * 删除两侧的空格
 *
 * @s 需要处理的字符串
*/
static inline void strip(std::string &s){
    lstrip(s);
    rstrip(s);
}

std::vector<string> split(const string& str, std::string sep=" "){
    std::vector<string> subStrs;
    if (str.empty())
        return subStrs;

    std::string tmp;
    // 找到第一个不是sep的位置，相当于过滤了
    std::size_t pos_begin = str.find_first_not_of(sep);
    std::size_t comma_pos = 0;
    while (pos_begin != std::string::npos){
        // 找到sep的位置
        comma_pos = str.find(sep, pos_begin);
        if (comma_pos!= std::string::npos){
            // 找到一个sep，截取它之前的字串，并经begin位置移动到该seq之后
            tmp = str.substr(pos_begin, comma_pos-pos_begin);
            pos_begin = comma_pos+sep.length();
        }else{
            tmp = str.substr(pos_begin);
            pos_begin = comma_pos;
        }

        if (!tmp.empty()){
//            strip(tmp);
            subStrs.push_back(tmp);
            tmp.clear();
        }
    }
    return subStrs;
}

/**
 * 加载字典，字典以set的形式保存
 * @param path 字典的路径
 * @return
 */
std::set<string> loadDictionary(const string& path){
    ifstream in(path);
    string str;
    set<std::string> dic;
    while (getline(in, str)){
        auto split_strs = split(str, "\t");
        dic.insert(split_strs[0]);
    }
    return dic;
}