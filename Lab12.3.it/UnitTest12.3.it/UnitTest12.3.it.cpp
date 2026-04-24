#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.3.it/Lab12.3.it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest123it
{
    TEST_CLASS(UnitTest123it)
    {
    public:

        TEST_METHOD(TestElementsExist)
        {
            Node* L1_h = nullptr; Node* L1_t = nullptr;
            Node* L2_h = nullptr; Node* L2_t = nullptr;

            // Списки: L2 = {1, 2, 3}, L1 = {3, 1}
            pushBack(L2_h, L2_t, 1);
            pushBack(L2_h, L2_t, 2);
            pushBack(L2_h, L2_t, 3);

            pushBack(L1_h, L1_t, 3);
            pushBack(L1_h, L1_t, 1);

            bool result = areAllElementsContained(L1_h, L2_h);

            Assert::IsTrue(result); // Має бути істина

            freeList(L1_h, L1_t);
            freeList(L2_h, L2_t);
        }

        TEST_METHOD(TestElementMissing)
        {
            Node* L1_h = nullptr; Node* L1_t = nullptr;
            Node* L2_h = nullptr; Node* L2_t = nullptr;

            // Списки: L2 = {10, 20}, L1 = {10, 30}
            pushBack(L2_h, L2_t, 10);
            pushBack(L2_h, L2_t, 20);

            pushBack(L1_h, L1_t, 10);
            pushBack(L1_h, L1_t, 30); // 30 немає в L2

            bool result = areAllElementsContained(L1_h, L2_h);

            Assert::IsFalse(result); // Має бути хиба

            freeList(L1_h, L1_t);
            freeList(L2_h, L2_t);
        }
    };
}