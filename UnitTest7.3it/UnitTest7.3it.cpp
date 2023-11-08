#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3it/lab7.3it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73it
{
	TEST_CLASS(UnitTest73it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 2;

			int** x = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				x[i] = new int[colCount];
			x[0][0] = 2;
			x[0][1] = 2;
			x[1][0] = 2;
			x[1][1] = 1;
			int columnWithMaxSeries = -1;
			findLongestSeriesColumn(x, rowCount, colCount, columnWithMaxSeries);
			Assert::AreEqual(columnWithMaxSeries, 0);
		}
	};
}
