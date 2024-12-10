#include "pch.h"
#include "CppUnitTest.h"
#include "../Demo_main/Car.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(CarTest)
    {
    public:

        // Тестирование создания автомобиля
        TEST_METHOD(TestCreateCar)
        {
            car::Car c("Honda", "Accord", "123GDD", "2012");
            Assert::AreEqual(std::string("Honda"), c.GetBrand());
            Assert::AreEqual(std::string("Accord"), c.GetModel());
            Assert::AreEqual(std::string("123GDD"), c.GetVIN());
            Assert::AreEqual(std::string("2012"), c.GetYearRelease());
        }

        // Тестирование установки Марки
        TEST_METHOD(TestSetBrand)
        {
            car::Car c("Ferrari", "F430", "321EEE", "2012");
            c.SetBrand("Ferrari");
            Assert::AreEqual(std::string("Ferrari"), c.GetBrand());
        }

        // Тестирование установки Модели
        TEST_METHOD(TestSetModel)
        {
            car::Car c("Ferrari", "F430", "321EEE", "2012");
            c.SetModel("F430");
            Assert::AreEqual(std::string("F430"), c.GetModel());
        }

        // Тестирование установки VIN номера
        TEST_METHOD(TestSetVIN)
        {
            car::Car c("Ferrari", "F430", "321EEE", "2012");
            c.SetVIN("321EEE");
            Assert::AreEqual(std::string("321EEE"), c.GetVIN());
        }

        // Тестирование установки Года выпуска
        TEST_METHOD(TestSetYearRelease)
        {
            car::Car c("Ferrari", "F430", "321EEE", "2012");
            c.SetYearRelease("2012");
            Assert::AreEqual(std::string("2012"), c.GetYearRelease());
        }

        // Тестирование исключения для пустого имени
        TEST_METHOD(TestEmptyNameException)
        {
            Assert::ExpectException<std::invalid_argument>(
                [] { car::Car c("Ferrari", "F430", "321EEE", "2012"); });
        }

        // Тестирование исключения для неверного формата даты рождения
        TEST_METHOD(TestInvalid)
        {
            Assert::ExpectException<std::invalid_argument>(
                [] { car::Car c("Ferrari", "F430", "321EEE", "06.2012"); });
        }
    };
}