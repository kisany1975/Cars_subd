#pragma once
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <stdexcept>

namespace car {
	/**
	* @brief Класс автомобиль
	*/
	class Car
	{
	private:
		/**
		* @brief Марка.
		*/
		std::string brand;
		/**
		* @brief Модель автомобиля.
		*/
		std::string model;
		/**
		* @brief VIN номер.
		*/
		std::string VIN;
		/**
		* @brief год выпуска.
		*/
		std::string yearRelease;
	public:
		/**
			* @brief Инициализирует новый объект класса Car.
			*
			* @param VIN VIN номер. Должен быть размером 17 символов.
			* @throws std::invalid_argument Если размер не 17 символов.
			*/
		Car(const std::string& b, const std::string& m, const std::string& V, const std::string& yR);
		/**
		* @brief Установка марки автомобиля.
		* @return марку автомобиля.
		*/
		void SetBrand(const std::string& b);
		/**
		* @brief Установка модели автомобиля.
		* @return модель автомобиля.
		*/
		void SetModel(const std::string& m);
		/**
		* @brief Установка VIN номера автомобиля.
		* @return VIN номер автомобиля.
		*/
		void SetVIN(const std::string& V);
		/**
		* @brief Извлечение года выпуска автомобиля.
		* @return год выпуска автомобиля.
		*/
		void SetYearRelease(const std::string& yR);
		/**
		* @brief Извлечение марки автомобиля.
		* @return марку автомобиля.
		*/
		std::string GetBrand() const;
		/**
		* @brief Извлечение модели автомобиля.
		* @return модель автомобиля.
		*/
		std::string GetModel() const;
		/**
		* @brief Извлечение VIN номера автомобиля.
		* @return VIN номер автомобиля.
		*/
		std::string GetVIN() const;
		/**
		* @brief Извлечение года выпуска автомобиля.
		* @return год выпуска автомобиля.
		*/
		std::string GetYearRelease() const;
	};
	/*
	* @brief Выводит в поток информацию об автомобиле
	* @param output Поток вывода
	* @param object Автомобиль
	*/
	std::ostream& operator<<(std::ostream& output, const Car& object);
}

#endif // CAR_H