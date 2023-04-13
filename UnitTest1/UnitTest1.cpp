#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Politekh\AP\12.2(rek)\12.2(rek)\12.2(rek).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int k = main();
			Assert::AreEqual(k, 0);
		}
	};
}