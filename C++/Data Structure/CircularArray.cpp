#include <iostream>
///////////////////////
//#include "CircularArray.h"
///////////////////////
#include <optional>

template<typename _Ty, uint32_t Capacity>
class CircularArray
{
private:
	_Ty m_Array[Capacity];
	uint32_t m_Size = 0; // more than enough, as its a stack allocated object
	uint32_t m_Head = 0; // more than enough, as its a stack allocated object
public:
	CircularArray () = default;

	_Ty &operator[](uint32_t position) { return m_Array[(m_Head + position)%Capacity]; }
	const _Ty &operator[](uint32_t position) const { return m_Array[(m_Head + position)%Capacity]; }

	std::optional<_Ty &> at (uint32_t position)
	{
		if (position < m_Size) return { m_Array[(m_Head + position)%Capacity] };
		else { return {}; }
	}
	std::optional<const _Ty &> at (uint32_t position) const
	{
		if (position<m_Size) return { m_Array[(m_Head + position)%Capacity] };
		else return {};
	}

	bool push_front (const _Ty &in)
	{
		if (m_Size < Capacity) {
			m_Head = (m_Head - 1 + Capacity) % Capacity;
			m_Array[m_Head] = in, m_Size++;
		} else {
			return false;
		}
		return true;
	}

	bool pop_front ()
	{
		if (m_Size < 1) {
			m_Head = (m_Head + 1) % Capacity;
			m_Size--;
		} else return false;
		return true;
	}

	bool push_back (const _Ty &in)
	{
		if (m_Size < Capacity) {
			m_Array[(m_Head + m_Size) % Capacity] = in;
			m_Size++;
		} else return false;

		return true;
	}

	bool pop_back ()
	{
		if (m_Size > 0)
			m_Size--;
		else return false;

		return true;
	}

	bool push_at (const _Ty &in, uint32_t position)
	{
		if (position < m_Size &&m_Size < Capacity) {
			if (position > m_Size/2) { // Condition: position Value in upper Half
				for (uint32_t i = m_Size; i > position; i--) {
					m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i - 1) % Capacity];
				}
			} else { // Condition: position Value in lower Half
				m_Head = (m_Head - 1 + Capacity) % Capacity;
				for (uint32_t i = 0; i < position + 1; i++) {
					m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i + 1) % Capacity];
				}
			}
			m_Array[(m_Head + position) % Capacity] = in;
			m_Size++;

		} else return false;

		return true;
	}

	bool pop_at (uint32_t position)
	{
		if (position < m_Size) {

			if (position > m_Size/2) {
				for (uint32_t i = position; i < m_Size; i++) {
					m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i + 1) % Capacity];
				}
			} else {
				for (uint32_t i = position; i > 0; i--) {
					m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i - 1) % Capacity];
				}
				m_Head = (m_Head + 1)%Capacity;
			}
			m_Size--;

		} else return false;
	}

	const uint32_t size () const { return m_Size; }
	uint32_t capacity () { return Capacity; }
	bool full () const { return m_Size == Capacity; }
	bool empty () const { return m_Size < 1; }
};
template<typename _Ty>
class CircularBuffer
{
private:
	_Ty *m_Array = nullptr;
	uint64_t m_Size = 0;
	uint64_t m_Head = 0;
	uint64_t m_Capacity = 0;
public:
	CircularBuffer () = default;
	CircularBuffer (uint64_t startCapacity)
		: m_Capacity (startCapacity)
	{
		m_Array = new _Ty[m_Capacity];
	}
	~CircularBuffer () { delete[] m_Array; m_Capacity = 0; }

	bool resize (uint64_t newCapacity)
	{
		if (newCapacity < m_Capacity) {
			return false;
		}
		_Ty *newArray = new _Ty[newCapacity];
		uint64_t newHead = 1;
		for (uint64_t i = 0; i < m_Size; i++)
			newArray[(newHead + i)%newCapacity] = std::move (m_Array[(m_Head + i)%m_Capacity]);

		delete[] m_Array;

		m_Array = newArray;
		m_Head = newHead;
		m_Capacity = newCapacity;
		return true;
	}
private:
	bool re_reserve_with (uint64_t newCapacity, uint64_t insrtPosition, const _Ty &in)
	{
		constexpr uint64_t numOfNewElemnt = 1;
		if (newCapacity < m_Capacity + numOfNewElemnt) { // adding 1 more element
			return false;
		}
		_Ty *newArray = new _Ty[newCapacity];
		uint64_t newHead = 1;

		const uint64_t newSize = m_Size + numOfNewElemnt;
		{// no branching
			for (uint64_t i = 0; i < insrtPosition; i++)
				newArray[(newHead + i)%newCapacity] = m_Array[(m_Head + i)%m_Capacity];

			for (uint64_t i = 0; i < numOfNewElemnt; i++)
				newArray[(newHead + insrtPosition + i)%newCapacity] = in;

			for (uint64_t i = insrtPosition + numOfNewElemnt; i < newSize; i++)
				newArray[(newHead + i)%newCapacity] = m_Array[(m_Head + i - numOfNewElemnt)%m_Capacity];

		}
		delete[] m_Array;

		m_Array = newArray;
		m_Head = newHead;
		m_Capacity = newCapacity;
		m_Size = newSize;
		return true;
	}

public:
	_Ty &operator[](uint64_t position) { return m_Array[(m_Head + position)%m_Capacity]; }
	const _Ty &operator[](uint64_t position) const { return m_Array[(m_Head + position)%m_Capacity]; }

	std::optional<_Ty &> at (uint64_t position)
	{
		if (position < m_Size)
			return { m_Array[(m_Head + position)%m_Capacity] };
		else return {};
	}
	std::optional<const _Ty &> at (uint64_t position) const
	{
		if (position<m_Size)
			return { m_Array[(m_Head + position)%m_Capacity] };
		else return {};
	}

	bool push_front (const _Ty &in)
	{
		if (m_Size < m_Capacity) {
			m_Head = (m_Head - 1 + m_Capacity) % m_Capacity;
			m_Array[m_Head] = in, m_Size++;
		} else {
			return re_reserve_with (m_Capacity + 2, 0, in);
		}
		return true;
	}

	bool pop_front ()
	{
		if (m_Size > 0) {
			m_Head = (m_Head + 1) % m_Capacity;
			m_Size--;
		} else return false;
		return true;
	}

	bool push_back (const _Ty &in)
	{
		if (m_Size < m_Capacity) {
			m_Array[(m_Head + m_Size) % m_Capacity] = in;
			m_Size++;
		} else {
			return re_reserve_with (m_Capacity + 2, m_Size, in);
		}
		return true;
	}

	bool pop_back ()
	{
		if (m_Size < 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		m_Size--;
	}

	bool push_at (const _Ty &in, uint64_t position)
	{
		if (position < m_Size) {
			if (m_Size < m_Capacity) {
				if (position > m_Size/2) { // Condition: position Value in upper Half
					for (uint64_t i = m_Size; i > position; i--) {
						m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i - 1) % m_Capacity];
					}
				} else { // Condition: position Value in lower Half
					m_Head = (m_Head - 1 + m_Capacity) % m_Capacity;
					for (uint64_t i = 0; i < position + 1; i++) {
						m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i + 1) % m_Capacity];
					}
				}
				m_Array[(m_Head + position) % m_Capacity] = in;
				m_Size++;
			} else {
				return re_reserve_with (m_Capacity + 2, position, in);
			}
		} else return false;
	}

	bool pop_at (uint64_t position)
	{
		if (position > m_Size - 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return false;
		}

		if (position > m_Size/2) {
			for (uint64_t i = position; i < m_Size; i++) {
				m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i + 1) % m_Capacity];
			}
		} else {
			for (uint64_t i = position; i > 0; i--) {
				m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i - 1) % m_Capacity];
			}
			m_Head = (m_Head + 1)%m_Capacity;
		}
		m_Size--;
		return true;
	}

	const uint64_t size () const { return m_Size; }
	const uint64_t capacity () const { return m_Capacity; }
	const bool full () const { return m_Size == m_Capacity; }
	const bool empty () const { return m_Size < 1; }
};

template<typename _Ty, uint32_t Capacity>
inline std::ostream &operator<<(std::ostream &os, const CircularArray<_Ty, Capacity> &e)
{
	os<<" { ";
	const uint16_t size = e.size ();
	for (uint16_t i = 0; i < size; i++, os<<", ")
		os << e[i];

	return os << "}\n";
}
template<typename _Ty>
inline std::ostream &operator<<(std::ostream &os, const CircularBuffer<_Ty> &e)
{
	os<<" { ";
	const uint16_t size = e.size ();
	for (uint16_t i = 0; i < size; i++, os<<", ")
		os << e[i];

	return os << "}\n";
}
///////////////////
/// source.cpp
///////////////////
int main ()
{
	using namespace std;
	{
		CircularArray<int,20> my_queue;
		std::cout <<"q: "<< my_queue << '\n';
		my_queue.push_back (100);
		my_queue.push_back (200);
		my_queue.push_back (300);
		my_queue.push_back (400);
		std::cout <<"q: "<< my_queue << '\n';
		my_queue.push_front (100);
		my_queue.push_front (200);
		my_queue.push_front (300);
		my_queue.push_front (400);
		std::cout <<"q: "<< my_queue << '\n';
		my_queue.pop_at (3);
		my_queue.pop_at (3);
		my_queue.pop_at (3);
		std::cout <<"q: "<< my_queue << '\n';
		my_queue.push_at (700,3);
		my_queue.push_at (800,3);
		my_queue.push_at (900,3);
		std::cout <<"q: "<< my_queue << '\n';
	}
	std::cout << '\n' << '\n' << '\n';
	{
	}
	return 0;
};
