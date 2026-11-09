#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include "../8.1 char/8.1 char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test81char
{
	TEST_CLASS(test81char)
	{
	public:

		TEST_METHOD(TestExist_OGO)
		{
			char s[101] = "xOGOy";
			Assert::IsTrue(Exist(s));
		}

		TEST_METHOD(TestExist_AGA)
		{
			char s[101] = "zAGAz";
			Assert::IsTrue(Exist(s));
		}

		TEST_METHOD(TestExist_None)
		{
			char s[101] = "OGAGO";
			Assert::IsFalse(Exist(s));
		}

		TEST_METHOD(TestChange_One)
		{
			char s[101] = "xOGOy";
			char* result = Change(s);
			Assert::AreEqual(0, strcmp(s, "x**y"));
			Assert::AreEqual(0, strcmp(result, "x**y"));
			delete[] result;
		}

		TEST_METHOD(TestChange_Both)
		{
			char s[101] = "AGAOGO";
			char* result = Change(s);
			Assert::AreEqual(0, strcmp(s, "****"));
			delete[] result;
		}

		TEST_METHOD(TestChange_NoTriple)
		{
			char s[101] = "hello";
			char* result = Change(s);
			Assert::AreEqual(0, strcmp(s, "hello"));
			delete[] result;
		}
	};
}