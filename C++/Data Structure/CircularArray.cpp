#include <iostream>
///////////////////////
//#include "CircularArray.h"
///////////////////////
#pragma once
#include <optional>

template<typename _Ty, uint32_t Capacity>
class CircularArray
{
private:
	_Ty m_Array[Capacity];
	uint16_t m_Size = 0;
	uint16_t m_Head = 0;
public:
	CircularArray () = default;

	_Ty &operator[](uint16_t position) { return m_Array[(m_Head + position)%Capacity]; }
	const _Ty &operator[](uint16_t position) const { return m_Array[(m_Head + position)%Capacity]; }

	std::optional<_Ty &> at (uint16_t position)
	{
		if (position < m_Size) return { m_Array[(m_Head + position)%Capacity] };
		else { return {}; }
	}
	std::optional<const _Ty &> at (uint16_t position) const
	{
		if (position<m_Size) return { m_Array[(m_Head + position)%Capacity] };
		else return {};
	}

	// TODO: due to m_Head being uint16_t (m_Head - 1)%Capacity cannot be used, but why is ((int)m_Head - 1) % capacity is not working ??(is it due to bitshifting when calculating %)
	void push_front (const _Ty &in)
	{
		if (m_Size < Capacity) {
			m_Head = (m_Head - 1 + Capacity) % Capacity;
			m_Array[m_Head] = in, m_Size++;
		} else {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
	}

	void pop_front ()
	{
		if (m_Size < 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		m_Head = (m_Head + 1) % Capacity;
		m_Size--;
	}

	void push_back (const _Ty &in)
	{
		if (m_Size < Capacity) {
			m_Array[(m_Head + m_Size) % Capacity] = in;
			m_Size++;
		} else {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
	}

	void pop_back ()
	{
		if (m_Size < 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		m_Size--;
	}

	void push_at (const _Ty &in, uint16_t position)
	{
		if (position > m_Size) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}

		if (m_Size < Capacity) {
			if (position > m_Size/2) { // Condition: position Value in upper Half
				for (uint16_t i = m_Size; i > position; i--) {
					m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i - 1) % Capacity];
				}
			} else { // Condition: position Value in lower Half
				m_Head = (m_Head - 1 + Capacity) % Capacity;
				for (uint16_t i = 0; i < position + 1; i++) {
					m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i + 1) % Capacity];
				}
			}
			m_Array[(m_Head + position) % Capacity] = in;
			m_Size++;
		} else {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
	}

	void pop_at (uint16_t position)
	{
		if (position > m_Size - 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}

		if (position > m_Size/2) {
			for (uint16_t i = position; i < m_Size; i++) {
				m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i + 1) % Capacity];
			}
		} else {
			for (uint16_t i = position; i > 0; i--) {
				m_Array[(m_Head + i) % Capacity] = m_Array[(m_Head + i - 1) % Capacity];
			}
			m_Head = (m_Head + 1)%Capacity;
		}
		m_Size--;
	}

	const uint16_t size () const { return m_Size; }
	uint16_t capacity () { return Capacity; }
	bool full () const { return m_Size == Capacity; }
	bool empty () const { return m_Size < 1; }
};
template<typename _Ty>
class CircularBuffer
{
private:
	_Ty *m_Array;
	uint16_t m_Size = 0;
	uint16_t m_Head = 0;
	uint16_t m_Capacity = 0;
public:
	CircularBuffer () = default;
	CircularBuffer (uint16_t StartCapacity)
		: m_Capacity (StartCapacity)
	{
		m_Array = new _Ty[m_Capacity];
	}
	~CircularBuffer () { delete[] m_Array; m_Capacity = 0; }

	void re_reserve (uint16_t newCapacity)
	{
		if (newCapacity < m_Capacity) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		_Ty *newArray = new _Ty[newCapacity];
		uint16_t newHead = 1;
		for (uint16_t i = 0; i < m_Size; i++)
			newArray[(newHead + i)%newCapacity] = m_Array[(m_Head + i)%m_Capacity];

		delete[] m_Array;

		m_Array = newArray;
		m_Head = newHead;
		m_Capacity = newCapacity;
		// size is unchanged
	}
private:
	void re_reserve_with (uint16_t newCapacity, uint16_t insrtPosition, const _Ty &in)
	{
		constexpr uint16_t numOfNewElemnt = 1;
		if (newCapacity < m_Capacity + numOfNewElemnt) { // adding 1 more element
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		_Ty *newArray = new _Ty[newCapacity];
		uint16_t newHead = 1;

		for (uint16_t i = 0; i < m_Size + numOfNewElemnt; i++) {
			if (i < insrtPosition) {
				//_Ty val = m_Array[(m_Head + i)%m_Capacity];
				newArray[(newHead + i)%newCapacity] = m_Array[(m_Head + i)%m_Capacity];
			} else if (i > insrtPosition + numOfNewElemnt - 1) {
				//_Ty val = m_Array[(m_Head + i - numOfNewElemnt)%m_Capacity];
				newArray[(newHead + i)%newCapacity] = m_Array[(m_Head + i - numOfNewElemnt)%m_Capacity];
			} else {// (i >= insrtPosition && i < numOfNewElemnt)
				//_Ty val = in;//in[i - insrtPosition];
				newArray[(newHead + i)%newCapacity] = in;
			}
		}
		delete[] m_Array;

		m_Array = newArray;
		m_Head = newHead;
		m_Capacity = newCapacity;
		m_Size += numOfNewElemnt;
	}

public:
	_Ty &operator[](uint16_t position) { return m_Array[(m_Head + position)%m_Capacity]; }
	const _Ty &operator[](uint16_t position) const { return m_Array[(m_Head + position)%m_Capacity]; }

	std::optional<_Ty &> at (uint16_t position)
	{
		if (position < m_Size) return { m_Array[(m_Head + position)%m_Capacity] };
		else { return {}; }
	}
	std::optional<const _Ty &> at (uint16_t position) const
	{
		if (position<m_Size) return { m_Array[(m_Head + position)%m_Capacity] };
		else return {};
	}

	// TODO: due to m_Head being uint16_t (m_Head - 1)%Capacity cannot be used, but why is ((int)m_Head - 1) % capacity is not working ??(is it due to bitshifting when calculating %)
	void push_front (const _Ty &in)
	{
		if (m_Size < m_Capacity) {
			m_Head = (m_Head - 1 + m_Capacity) % m_Capacity;
			m_Array[m_Head] = in, m_Size++;
		} else {
			re_reserve_with (m_Capacity + 2, 0, in);
			return;
		}
	}

	void pop_front ()
	{
		if (m_Size < 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		m_Head = (m_Head + 1) % m_Capacity;
		m_Size--;
	}

	void push_back (const _Ty &in)
	{
		if (m_Size < m_Capacity) {
			m_Array[(m_Head + m_Size) % m_Capacity] = in;
			m_Size++;
		} else {
			re_reserve_with (m_Capacity + 2, m_Size, in);
			return;
		}
	}

	void pop_back ()
	{
		if (m_Size < 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		m_Size--;
	}

	void push_at (const _Ty &in, uint16_t position)
	{
		if (position > m_Size) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}
		if (m_Size < m_Capacity) {
			if (position > m_Size/2) { // Condition: position Value in upper Half
				for (uint16_t i = m_Size; i > position; i--) {
					m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i - 1) % m_Capacity];
				}
			} else { // Condition: position Value in lower Half
				m_Head = (m_Head - 1 + m_Capacity) % m_Capacity;
				for (uint16_t i = 0; i < position + 1; i++) {
					m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i + 1) % m_Capacity];
				}
			}
			m_Array[(m_Head + position) % m_Capacity] = in;
			m_Size++;
		} else {
			re_reserve_with (m_Capacity + 2, position, in);
			return;
		}
	}

	void pop_at (uint16_t position)
	{
		if (position > m_Size - 1) {
			// HZ_ERROR ("Error: at {0} in {1}", __LINE__, __FUNCTION__);
			return;
		}

		if (position > m_Size/2) {
			for (uint16_t i = position; i < m_Size; i++) {
				m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i + 1) % m_Capacity];
			}
		} else {
			for (uint16_t i = position; i > 0; i--) {
				m_Array[(m_Head + i) % m_Capacity] = m_Array[(m_Head + i - 1) % m_Capacity];
			}
			m_Head = (m_Head + 1)%m_Capacity;
		}
		m_Size--;
	}

	const uint16_t size () const { return m_Size; }
	const uint16_t capacity () const { return m_Capacity; }
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

// Sorts in Ascending Order
template<typename _Ty, uint32_t Capacity>
class AutoSortQueue
{
private:
	CircularArray<_Ty, Capacity> m_Queue;
public:
	AutoSortQueue () = default;

	std::optional<const _Ty &> at (uint16_t position) const { return m_Queue.at (position); }
	const _Ty &operator[](uint16_t position) const { return m_Queue[position]; }
	_Ty &operator[](uint16_t position) { return m_Queue[position]; }

	// TODO: reduce code size
	// TODO: change it into analog Binary search
	void push (const _Ty &in)
	{
		// For Ascending Order
		/*void(*add_front)(const _Ty &in) = m_Queue.push_front;
		void(*add_back)(const _Ty &in) = m_Queue.push_back;
		void(*add)(const _Ty &in,uint16_t) = m_Queue.push_between;*/
	#define add_front(x) m_Queue.push_front(x);
	#define add_back(x)  m_Queue.push_back(x);
	#define add(x,y)     m_Queue.push_at(x,y);

		// Edge cases
		_Ty *MinInQueue;
		_Ty *MaxInQueue;
		if (m_Queue.size ()) {
			MinInQueue = &m_Queue[0]; // Front
			MaxInQueue = &m_Queue[m_Queue.size () - 1]; // Back
			if (in > *MaxInQueue) {
				add_back (in);
				return;
			} else if (in < *MinInQueue) {
				add_front (in);
				return;
			} else {
				uint16_t start_index = 0;
				uint16_t end_index = m_Queue.size () - 1;
				while (start_index < end_index + 1) {
					uint16_t middle = start_index + (end_index - start_index)/2;// *((float)(*MinInQueue - in) / (*MinInQueue - *MaxInQueue))
					if (m_Queue[middle] == in) {
						return;
					}
					if (m_Queue[middle] > in) {
						if (m_Queue[middle - 1] < in) {
							add (in, middle);
							return;
						} else {
							end_index = middle - 1;
						}
					} else {//if (m_Queue[middle] < in) {
						start_index = middle + 1;
					}

				}
			}
		} else add_back (in); // Empty so add at end
	}
	void pop_min ()
	{
		m_Queue.pop_front ();
	}
	void pop_max ()
	{
		m_Queue.pop_back ();
	}
	void pop_at (uint16_t position)
	{
		m_Queue.pop_at (position);
	}
	void print (const char *label)
	{
		std::cout<<"\n"<<label<< m_Queue;
	}

	uint16_t size () { return m_Queue.size (); }
	uint16_t capacity () { return Capacity; }
};

// Sorts in Ascending Order
template<typename _Ty>
class AutoSortBuffer
{
private:
	CircularBuffer<_Ty> m_Buffer;
public:
	AutoSortBuffer (uint16_t startCapacity)
		: m_Buffer (startCapacity)
	{}

	std::optional<const _Ty &> at (uint16_t position) const { return m_Buffer.at (position); }
	const _Ty &operator[](uint16_t position) const { return m_Buffer[position]; }
	_Ty &operator[](uint16_t position) { return m_Buffer[position]; }

	// TODO: reduce code size
	// TODO: change it into analog Binary search
	void push (const _Ty &in)
	{
		// For Ascending Order
		/*void(*add_front)(const _Ty &in) = m_Buffer.push_front;
		void(*add_back)(const _Ty &in) = m_Buffer.push_back;
		void(*add)(const _Ty &in,uint16_t) = m_Buffer.push_between;*/
	#define add_front(x) m_Buffer.push_front(x);
	#define add_back(x)  m_Buffer.push_back(x);
	#define add(x,y)     m_Buffer.push_at(x,y);

		// Edge cases
		_Ty *MinInQueue;
		_Ty *MaxInQueue;
		if (m_Buffer.size ()) {
			MinInQueue = &m_Buffer[0]; // Front
			MaxInQueue = &m_Buffer[m_Buffer.size () - 1]; // Back
			if (in > *MaxInQueue) {
				add_back (in);
				return;
			} else if (in < *MinInQueue) {
				add_front (in);
				return;
			} else {
				uint16_t start_index = 0;
				uint16_t end_index = m_Buffer.size () - 1;
				while (start_index < end_index + 1) {
					uint16_t middle = start_index + (end_index - start_index)/2;// *((float)(m_Buffer[start_index] - in) / (m_Buffer[start_index] - m_Buffer[end_index]))
					if (m_Buffer[middle] == in) {
						return;
					}
					if (m_Buffer[middle] > in) {
						if (m_Buffer[middle - 1] < in) {
							add (in, middle);
							return;
						} else {
							end_index = middle - 1;
						}
					} else {//if (m_Buffer[middle] < in) {
						start_index = middle + 1;
					}

				}
			}
		} else add_back (in); // Empty so add at end
	}
	void pop_min ()
	{
		m_Buffer.pop_front ();
	}
	void pop_max ()
	{
		m_Buffer.pop_back ();
	}
	void pop_at (uint16_t position)
	{
		m_Buffer.pop_at (position);
	}
	void print (const char *label)
	{
		std::cout<<"\n"<<label<< m_Buffer;
	}

	uint16_t size () { return m_Buffer.size (); }
	uint16_t capacity () { return m_Buffer.capacity (); }
	uint16_t empty () { return m_Buffer.empty (); }
};
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
