#include "pch.h"
#include "CppUnitTest.h"
#pragma warning(disable : 4996)
#include "C:\Users\Arseniy\Desktop\Project6\Laba8.1.char.C\Laba8.1.char.C\Laba8.1.char.C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:

		TEST_METHOD(ChangeTest)
		{
			char str1[101] = "abSQcdQSef";
			char* result1 = Change(str1);
			Assert::AreEqual("ab***cd***ef", result1);
			delete[] result1;

			char str2[101] = "abcdef";
			char* result2 = Change(str2);
			Assert::AreEqual("abcdef", result2);
			delete[] result2;

			char str3[101] = "aSQbSSQQc";
			char* result3 = Change(str3);
			Assert::AreEqual("a***bS***Qc", result3);
			delete[] result3;
		}
	};
}