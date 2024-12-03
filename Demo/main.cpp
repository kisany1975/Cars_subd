#include <iostream>
#include "../Demo_main/Car.h"

using namespace car;

int main() {
	try {
		car::Car c1("Toyota", "Camry", "1234VIN", "2023");
        std::cout << "Бренд автомобиля: " << c1.GetBrand() << std::endl;
        std::cout << "Марка автомобиля: " << c1.GetModel() << std::endl;
        std::cout << "VIN номер автомобиля: " << c1.GetVIN() << std::endl;
        std::cout << "Год выпуска автомобиля: " << c1.GetYearRelease() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}