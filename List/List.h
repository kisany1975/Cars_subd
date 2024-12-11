#include "Node.h"
#include <iostream>
/*
 * ЛОС (Линейный односвязный список).
 * @tparam T - тип данных элементов, хранимых в списке.
 */
template <typename T>
class List
{
private:
	Node<T>* head;
	size_t size;
public:
	List();
	List(const List<T>& ll);
	List(List<T>&& ll);
	~List();

	List<T>& operator=(List<T> const& ll);
	List<T>& operator=(List<T>&& ll);

	/*
	* @brief получение указателя на первый элемент в списке.
	* @return указатель на первый элемент в списке.
	*/
	Node<T>* getHead() const;

	/*
	* @brief получить количество элементов в списке.
	* @return количество элементов в списке.
	*/
	size_t getSize() const;

	/*
	* @brief вывод списка в поток.
	* @param out поток для вывода.
	*/
	void display(std::ostream& out = std::cout) const;


	/*
	* @brief добавление элемента в конец списка.
	* @param data  информация об элементе.
	*/
	void push_back(T data);

	/*
	* @brief добавление элемента в начало списка.
	* @param data информация об элементе.
	*/
	void push_front(T data);

	/*
	* @brief добавление элемента на заданную позицию.
	* @param data информация об элементе.
	* @param index позиция элемента.
	*/
	void push(T data, size_t index);

	/*
	* @brief удаление первого элемента в списке.
	*/
	void pop_front();

	/*
	* @brief удаление последнего элемента в списке.
	*/
	void pop_back();

	/*
	* @brief получение элемента на заданной позиции.
	* @param index позиция элемента.
	* @return указатель на найденый элемент в списке или nullptr.
	*/
	Node<T>* get_by_index(size_t index);

	/*
	* @brief перегузка оператора вывода в поток.
	*/
	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const List<U>& ll);
};


#include "List.cpp"