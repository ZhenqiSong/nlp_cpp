#include <iostream>
#include "ch02/Utils.h"
#include "ch02/segment.h"

int main() {
    auto dic = loadDictionary();
    auto word_list = fully_segment("商品和服务", dic);
    for (const auto& word : word_list){
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
