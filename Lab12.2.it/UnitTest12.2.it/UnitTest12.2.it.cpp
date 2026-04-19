#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.2.it/Lab12.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
	{
	public:
		TEST_METHOD(TestRemoveAfterValue)
		{
			Elem* first = new Elem;
			Elem* v2 = new Elem;
			Elem* v3 = new Elem;

			first->info = 10;
			v2->info = 20;
			v3->info = 30;

			first->link = v2;
			v2->link = v3;
			v3->link = NULL;

			removeAfterValue(first, 10);

			Assert::AreEqual(10, first->info);
			Assert::AreEqual(30, first->link->info);
			Assert::IsNull(first->link->link);

			clear(first);
		}

		TEST_METHOD(TestRemoveAtEnd)
		{
			Elem* first = new Elem;
			Elem* v2 = new Elem;
			first->info = 10;
			v2->info = 20;
			first->link = v2;
			v2->link = NULL;

			removeAfterValue(first, 20);

			Assert::AreEqual(20, first->link->info);
			Assert::IsNull(first->link->link);

			clear(first);
		}
	};
}