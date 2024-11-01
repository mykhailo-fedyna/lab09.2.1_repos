#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestFormula1)
		{
			// Тест для calculateWFormula1
			double x = 5.0, y = 2.0, z = 4.0;
			double expected = MIN(SQUARE(x - z), x - y);  // Розрахунок очікуваного значення вручну
			Assert::AreEqual(expected, calculateWFormula1(x, y, z), 0.001);
		}

		TEST_METHOD(TestFormula2)
		{
			// Тест для calculateWFormula2
			double x = 3.0, y = 4.0, z = 2.0;
			double expected = MAX(x * y, y * z) + MIN(z * x, y * z);  // Розрахунок очікуваного значення вручну
			Assert::AreEqual(expected, calculateWFormula2(x, y, z), 0.001);
		}

		TEST_METHOD(TestCalculateW_Formula1)
		{
			// Тест для calculateW з використанням Formula1 (z > 3)
			double x = 5.0, y = 2.0, z = 4.0;
#define USE_FORMULA1
			double expected = calculateWFormula1(x, y, z);
			Assert::AreEqual(18, calculateW(x, y, z), 0.001);
#undef USE_FORMULA1
		}

		TEST_METHOD(TestCalculateW_Formula2)
		{
			// Тест для calculateW з використанням Formula2 (z <= 3)
			double x = 3.0, y = 4.0, z = 3.0;
			double expected = calculateWFormula2(x, y, z);
			Assert::AreEqual(expected, calculateW(x, y, z), 0.001);
		}
	};
}
