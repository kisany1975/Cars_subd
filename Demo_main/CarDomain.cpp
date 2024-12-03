#include <iostream>
#include "Car.h"
#include <cstring>
#include <regex>

namespace car {

	Car::Car(const std::string& b, const std::string& m, const std::string& V, const std::string& yR) : brand(b), model(m), VIN(V), yearRelease(yR) {
        if (brand.empty() || model.empty() || VIN.empty()) {
            throw std::invalid_argument("��� ���� �� ����� ���� �������!");
        }
        std::regex datePattern("\\d{4}");
        if (!std::regex_match(yearRelease, datePattern)) {
            throw std::invalid_argument("��� ������� ������ ���� � ������� ����.");
        }
	}
    std::string Car::GetBrand() const {
        return brand;
    }

    std::string Car::GetModel() const {
        return model;
    }

    std::string Car::GetVIN() const {
        return VIN;
    }

    std::string Car::GetYearRelease() const {
        return yearRelease;
    }

    void Car::SetBrand(const std::string& b) {
        if (b.empty()) {
            throw std::invalid_argument("����� �� ����� ���� ������.");
        }
        brand = b;
    }

    void Car::SetModel(const std::string& m) {
        if (m.empty()) {
            throw std::invalid_argument("������ �� ����� ���� ������.");
        }
        model = m;
    }

    void Car::SetVIN(const std::string& V) {
        if (V.empty()) {
            throw std::invalid_argument("VIN �� ����� ���� ������.");
        }
        VIN = V;
    }

    void Car::SetYearRelease(const std::string& yR) {
        std::regex datePattern("\\d{4}");
        if (!std::regex_match(yearRelease, datePattern)) {
            throw std::invalid_argument("��� ������� ������ ���� � ������� ����.");
        }
        yearRelease = yR;
    }
}