#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1_B/Lab_9.1_B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLab91B
{
	TEST_CLASS(UTLab91B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* a = new Student[2];
			a[0].spec = –≤;
			a[1].spec =  Õ;
			a[0].fis = 4;
			a[0].math = 4;
			a[0].infor = 4;
			a[1].fis = 4;
			a[1].math = 5;
			a[1].methods = 3;
			int c = Count1(a, 2);
			Assert::AreEqual(c, 1);
		}
	};
}
