#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.3.rec/Lab12.3.rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest123it
{
    TEST_CLASS(UnitTest123it)
    {
    public:
        TEST_METHOD(TestContained)
        {
            Node* L1_h = nullptr; Node* L1_t = nullptr;
            Node* L2_h = nullptr; Node* L2_t = nullptr;

            // ТЕПЕР ТУТ 4 АРГУМЕНТИ:
            pushBack(L2_h, nullptr, 1, L2_t);
            pushBack(L2_h, nullptr, 2, L2_t);
            pushBack(L1_h, nullptr, 2, L1_t);
            pushBack(L1_h, nullptr, 1, L1_t);

            Assert::IsTrue(areAllElementsContained(L1_h, L2_h));

            freeList(L1_h, L1_t);
            freeList(L2_h, L2_t);
        }

        TEST_METHOD(TestNotContained)
        {
            Node* L1_h = nullptr; Node* L1_t = nullptr;
            Node* L2_h = nullptr; Node* L2_t = nullptr;

            pushBack(L2_h, nullptr, 100, L2_t);
            pushBack(L1_h, nullptr, 200, L1_t); // 200 немає в L2

            Assert::IsFalse(areAllElementsContained(L1_h, L2_h));

            freeList(L1_h, L1_t);
            freeList(L2_h, L2_t);
        }
    };
}