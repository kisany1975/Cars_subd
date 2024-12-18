#include "pch.h" 
#include "CppUnitTest.h"
#include "../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(StackTest)
    {
    public:

        TEST_METHOD(Stack_Empty_OnCreation_IsEmpty)
        {
            Stack s;
            Assert::IsTrue(s.empty(), L"����� ���� ������ ���� ������.");
            Assert::AreEqual((size_t)0, s.size(), L"������ ������� ����� ������ ���� 0.");
        }

        TEST_METHOD(Stack_Push_WhenOneElementPushed_SizeIsOne)
        {
            Stack s;
            s.push(10);
            Assert::AreEqual((size_t)1, s.size(), L"����� ���������� ������ �������� ������ ������ ���� 1.");
            Assert::IsFalse(s.empty(), L"���� �� ������ ���� ������ ����� ���������� ��������.");
        }

        TEST_METHOD(Stack_Push_WhenMultipleElementsPushed_TopIsLastElement)
        {
            Stack s;
            s.push(10);
            s.push(20);
            s.push(30);
            Assert::AreEqual(30, s.top(), L"top() ������ ���������� ��������� ����������� ������� (30).");
        }

        TEST_METHOD(Stack_Pop_WhenCalledOnNonEmptyStack_ReturnsLastPushedElement)
        {
            Stack s;
            s.push(10);
            s.push(20);
            int popped = s.pop();
            Assert::AreEqual(20, popped, L"pop() ������ ������� ��������� ����������� ������� (20).");
            Assert::AreEqual((size_t)1, s.size(), L"����� pop ������ ������ ����������� �� 1.");
        }

        TEST_METHOD(Stack_Pop_WhenCalledOnEmptyStack_ThrowsOutOfRange)
        {
            Stack s;
            bool exceptionThrown = false;
            try {
                s.pop();
            }
            catch (const std::out_of_range&) {
                exceptionThrown = true;
            }
            Assert::IsTrue(exceptionThrown, L"pop() ������ ������� ���������� ��� ������ �� ������ �����.");
        }

        TEST_METHOD(Stack_Top_WhenCalledOnEmptyStack_ThrowsOutOfRange)
        {
            Stack s;
            bool exceptionThrown = false;
            try {
                int value = s.top(); // ����������, ����� �������� warning � �������������� ����������
                (void)value;
            }
            catch (const std::out_of_range&) {
                exceptionThrown = true;
            }
            Assert::IsTrue(exceptionThrown, L"top() ������ ������� ���������� ��� ������ �� ������ �����.");
        }

        TEST_METHOD(Stack_Contains_WhenElementIsPresent_ReturnsTrue)
        {
            Stack s;
            s.push(10);
            s.push(20);
            Assert::IsTrue(s.contains(10), L"contains(10) ������ ������� true, ���� 10 ������������ � �����.");
            Assert::IsTrue(s.contains(20), L"contains(20) ������ ������� true, ���� 20 ������������ � �����.");
        }

        TEST_METHOD(Stack_Contains_WhenElementIsNotPresent_ReturnsFalse)
        {
            Stack s;
            s.push(10);
            Assert::IsFalse(s.contains(30), L"contains(30) ������ ������� false, ���� 30 ����������� � �����.");
        }

        TEST_METHOD(Stack_ToString_WhenMultipleElements_ReturnsCorrectFormat)
        {
            Stack s;
            s.push(5);
            s.push(10);
            Assert::AreEqual(std::string("[5, 10]"), s.toString(), L"toString() ������ ������� \"[5, 10]\".");
        }

    };
}
