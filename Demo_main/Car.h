#pragma once
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <stdexcept>

namespace car {
	/**
	* @brief ����� ����������
	*/
	class Car
	{
	private:
		/**
		* @brief �����.
		*/
		std::string brand;
		/**
		* @brief ������ ����������.
		*/
		std::string model;
		/**
		* @brief VIN �����.
		*/
		std::string VIN;
		/**
		* @brief ��� �������.
		*/
		std::string yearRelease;
	public:
		/**
			* @brief �������������� ����� ������ ������ Car.
			*
			* @param VIN VIN �����. ������ ���� �������� 17 ��������.
			* @throws std::invalid_argument ���� ������ �� 17 ��������.
			*/
		Car(const std::string& b, const std::string& m, const std::string& V, const std::string& yR);
		/**
		* @brief ��������� ����� ����������.
		* @return ����� ����������.
		*/
		void SetBrand(const std::string& b);
		/**
		* @brief ��������� ������ ����������.
		* @return ������ ����������.
		*/
		void SetModel(const std::string& m);
		/**
		* @brief ��������� VIN ������ ����������.
		* @return VIN ����� ����������.
		*/
		void SetVIN(const std::string& V);
		/**
		* @brief ���������� ���� ������� ����������.
		* @return ��� ������� ����������.
		*/
		void SetYearRelease(const std::string& yR);
		/**
		* @brief ���������� ����� ����������.
		* @return ����� ����������.
		*/
		std::string GetBrand() const;
		/**
		* @brief ���������� ������ ����������.
		* @return ������ ����������.
		*/
		std::string GetModel() const;
		/**
		* @brief ���������� VIN ������ ����������.
		* @return VIN ����� ����������.
		*/
		std::string GetVIN() const;
		/**
		* @brief ���������� ���� ������� ����������.
		* @return ��� ������� ����������.
		*/
		std::string GetYearRelease() const;
	};
	/*
	* @brief ������� � ����� ���������� �� ����������
	* @param output ����� ������
	* @param object ����������
	*/
	std::ostream& operator<<(std::ostream& output, const Car& object);
}

#endif // CAR_H