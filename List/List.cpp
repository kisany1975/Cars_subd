namespace list {

	#include "List.h"

	template<typename T>
	List<T>::List() : head(nullptr), size(0) {}

	template<typename T>
	List<T>::List(const List<T>& ll) : head(nullptr), size(0)
	{
		Node<T>* head = ll.getHead();
		while (head != nullptr) {
			push_back(head->data);
			head = head->next;
		}
	}

	template<typename T>
	List<T>::List(List<T>&& ll) : List()
	{

		head = ll.getHead();
		ll.head = nullptr;
		size = ll.getSize();
		ll.size = 0;

	}

	template<typename T>
	List<T>& List<T>::operator=(List<T> const& ll)
	{
		if (this == &ll)
			return *this;

		List<T> tmp(ll);

		size = tmp.getSize();

		head = tmp.getHead();
		tmp.head = nullptr;

		return *this;
	}

	template<typename T>
	List<T>& List<T>::operator=(List<T>&& ll)
	{
		if (this != &ll)
			return *this;

		head = std::move(ll.head);
		size = std::move(ll.size);

		return *this;
	}

	template<typename T>
	List<T>::~List()
	{
		Node<T>* tmp = nullptr;
		while (head)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		head = nullptr;
	}

	template<typename T>
	Node<T>* List<T>::getHead() const
	{
		return head;
	}

	template<typename T>
	size_t List<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	void List<T>::display(std::ostream& out) const
	{
		Node<T>* node = head;
		while (node != nullptr)
		{
			out << node->data << " ";
			node = node->next;
		}
	}

	template<typename T>
	void List<T>::push_back(T data)
	{
		Node<T>* t = new Node<T>(data);
		Node<T>* tmp = head;
		if (tmp == nullptr)
		{
			head = t;
		}
		else
		{
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = t;
		}
		size++;
	}

	template<typename T>
	void List<T>::push_front(T data)
	{
		Node<T>* t = new Node<T>(data);
		if (head == nullptr)
		{
			head = t;
		}
		else
		{
			t->next = head;
			head = t;
		}
		size++;
	}

	template<typename T>
	void List<T>::push(T data, size_t index)
	{
		Node<T>* cur = head;
		Node<T>* prev = nullptr;
		size_t cur_index = 0;
		while (cur_index != index && cur != nullptr)
		{
			prev = cur;
			cur = cur->next;
			++cur_index;
		}
		if (cur_index == index)
		{
			Node<T>* t = new Node<T>(data);
			if (prev != nullptr) prev->next = t;
			else head = t;
			t->next = cur;
			size++;
		}
	}

	template<typename T>
	Node<T>* List<T>::get_by_index(size_t index)
	{
		Node<T>* cur = head;
		size_t cur_index = 0;
		while (cur_index != index && cur != nullptr)
		{
			cur = cur->next;
			++cur_index;
		}
		if (cur_index == index)
		{
			return cur;
		}

		return nullptr;
	}

	template<typename T>
	void List<T>::pop_front()
	{
		Node<T>* tmp = head;
		if (tmp != nullptr)
		{
			head = head->next;
			delete tmp;
			size--;
		}
	}

	template<typename T>
	void List<T>::pop_back()
	{
		Node<T>* tmp = head;
		Node<T>* prev = nullptr;
		if (tmp != nullptr)
		{
			while (tmp->next != nullptr)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			if (prev != nullptr)
			{
				prev->next = nullptr;
			}
			else
			{
				head = nullptr;
			}
			delete tmp;
			size--;
		}
	}

	template<typename U>
	std::ostream& operator<<(std::ostream& os, const List<U>& ll)
	{
		ll.display(os);
		return os;
	}
}
