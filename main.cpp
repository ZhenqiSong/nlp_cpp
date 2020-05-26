#include <iostream>

#include "ch02/segment.h"

int main(int argc, char* argv[]) {
    system("chcp 65001 > nul"); // 解决输出乱码的问题
    segment::test(argv);
    return 0;
}
