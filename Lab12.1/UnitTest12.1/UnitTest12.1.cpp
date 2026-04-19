#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.1/Lab12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121
{
	TEST_CLASS(UnitTest121)
	{
	public:

		TEST_METHOD(TestStructureConnections)
		{
			Elem* v1 = new Elem;
			Elem* v2 = new Elem;
			Elem* v3 = new Elem;
			Elem* v4 = new Elem;

			v1->info = 1; v2->info = 2; v3->info = 3; v4->info = 4;

			v1->link1 = v2; v1->link2 = v4;
			v2->link1 = v1; v2->link2 = v3;
			v3->link1 = v2; v3->link2 = v4;
			v4->link1 = v2; v4->link2 = NULL;

			// Перевіряємо вузол 1
			Assert::AreEqual(v1->link1->info, 2); // має вести до v2
			Assert::AreEqual(v1->link2->info, 4); // має вести до v4

			// Перевіряємо вузол 2
			Assert::AreEqual(v2->link1->info, 1); // має вести до v1
			Assert::AreEqual(v2->link2->info, 3); // має вести до v3

			// Перевіряємо вузол 3
			Assert::AreEqual(v3->link1->info, 2); // має вести до v2
			Assert::AreEqual(v3->link2->info, 4); // має вести до v4

			// Перевіряємо вузол 4
			Assert::AreEqual(v4->link1->info, 2); // має вести до v2
			Assert::IsNull(v4->link2);            // має бути NULL (перекреслений блок)

			// Очищення пам'яті
			delete v1;
			delete v2;
			delete v3;
			delete v4;
		}
	};
}