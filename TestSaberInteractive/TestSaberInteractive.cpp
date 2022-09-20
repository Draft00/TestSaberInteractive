#include "BinaryRepresentation.hpp"
#include "RemoveDups.h"

#include <iostream>
#include <climits>

int main()
{
    constexpr long long runTestRandomList = std::numeric_limits<long long>::min();
    BinaryRepresentation<long long>::printBinaryRepresentation(runTestRandomList); //-9'223'372'036'854'775'808
    std::cout << std::endl;

    char test_ch[] = "AAA BB AAA";
    RemoveDups::removeDups(test_ch);

    std::cout << test_ch << std::endl;
}
