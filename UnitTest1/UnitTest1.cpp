#include "pch.h"
#include "CppUnitTest.h"

#include <fstream>

#include "../TestSaberInteractive/List.h"
#include "../TestSaberInteractive/List.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(RandomList)
		{
            List testListSer;
            for (int i = 0; i < 10; ++i) {
                testListSer.push_back(std::to_string(i) + " " + std::to_string(i));
            }
            testListSer.setRandNode();

            std::ofstream outFile("Serialize.txt", std::ios::binary);
            testListSer.Serialize(outFile);
            outFile.close();

            List testListDeser;
            std::ifstream inFile("Serialize.txt", std::ios::binary);
            testListDeser.Deserialize(inFile);
            inFile.close();

            Assert::IsTrue(testListSer == testListDeser);
		}
	};
}
