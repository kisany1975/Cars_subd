#include <iostream>
#include "../Demo_main/Car.h"

using namespace car;

int main() {
	try {
		car::Car c1("Toyota", "Camry", "1234VIN", "2023");
        std::cout << "����� ����������: " << c1.GetBrand() << std::endl;
        std::cout << "����� ����������: " << c1.GetModel() << std::endl;
        std::cout << "VIN ����� ����������: " << c1.GetVIN() << std::endl;
        std::cout << "��� ������� ����������: " << c1.GetYearRelease() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "������: " << ex.what() << std::endl;
    }

    return 0;
}