//
// Created by Zhenqi Song on 2020/5/17.
//

#include "segment.h"
#include "Utils.h"
#include <time.h>

namespace segment{
    void test(char* argv[]){
        auto dic = loadDictionary(argv[1]);

        std::cout << "完全切分:" << endl;
        println(fully_segment("商品和服务", dic));
        std::cout << endl;

        std::vector<std::string> texts{"项目的研究", "商品和服务", "研究生命起源",
                                       "当下雨天地面积水", "结婚的和尚未结婚的", "欢迎新老师生前来就餐"};
        std::cout << "正向最长 | 逆向最长 | 双向最长" << endl;
        std::cout << "-------------------------" << endl;
        for (const auto& text : texts){
            print(forwardSegment(text, dic));
            std::cout << " | ";
            print(backwardSegment(text, dic));
            std::cout << " | ";
            println(bidirectionalSegment(text, dic));
        }

        evaluateSpeed(dic);
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
    std::vector<std::string> forwardSegment(const std::string &text, const Dict &dic) {
        std::vector<std::string> wordList;
        for (int i = 0; i< text.size(); ){
            std::string longestWord;
            for (int j =i; j <= text.size(); ++j){
                auto word = text.substr(i, j-i);
                if (dic.find(word) != dic.end() && word.size() > longestWord.size()){
                        longestWord = word;
                }
            }
            i += longestWord.size();
            wordList.push_back(longestWord);
        }

        return wordList;
    }

    /**
     * 逆向最长匹配
     */
    std::vector<std::string> backwardSegment(const std::string &text, const Dict &dict){
        std::vector<std::string> wordList;

        for (auto i = text.size(); i > 0;){
            string longestWord;
            for (int j=0; j <= i; ++j){
                auto word = text.substr(j, i-j); // 注意这里第二个参数是长度，而不是结束位置
                if (dict.find(word) != dict.end() && word.size() > longestWord.size()){
                    longestWord = word;
                    break;
                }
            }
            i -= longestWord.size();
            wordList.insert(wordList.begin(), longestWord); // 由于是逆序，所以要将新的词插入到头部
        }
        return wordList;
    }

    /**
     * 双向最大匹配
     * 根据正向和反向的结果，选择分词较少的，如果数量一样，则选择单个字较少的
     */
    std::vector<std::string> bidirectionalSegment(const std::string &text, const Dict &dict) {
        auto f = forwardSegment(text, dict);
        auto b = forwardSegment(text, dict);
        if (f.size() != b.size())
            return f.size() < b.size() ? f : b;
        else
            return countSingleChar(f) < countSingleChar(b)? f : b;
    }

    int countSingleChar(const std::vector<std::string> &words) {
        int sum = 0;
        for (auto& x : words){
            if (x.size() == 3) // 每个汉字的长度是3
                ++sum;
        }
        return sum;
    }

    void evaluateSpeed(const Dict &dict) {
        string text("江西鄱阳湖干枯，中国最大淡水湖编程大草原");
        clock_t start;
        double costTime;
        static int pressure = 10000;

        start = clock();
        for (int i = 0; i<pressure; i++){
            forwardSegment(text, dict);
        }
        costTime = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("%.2f 万字/秒\n", text.size() * pressure / 30000/ costTime);

        start = clock();
        for (int i = 0; i<pressure; i++){
            backwardSegment(text, dict);
        }
        costTime = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("%.2f 万字/秒\n", text.size() * pressure / 30000/ costTime);

        start = clock();
        for (int i = 0; i<pressure; i++){
            bidirectionalSegment(text, dict);
        }
        costTime = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("%.2f 万字/秒\n", text.size() * pressure / 30000/ costTime);
    }
}

