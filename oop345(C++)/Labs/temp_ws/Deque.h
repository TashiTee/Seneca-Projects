/*************************************************************************
// template workshop
// File: Deque.h
// Version: 1.0
// Date: 03/14/2019
// Author: Tashi Tsering
// Description: convert the Deque class to a template to work with any type
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

// convert the Deque class to a template to work with any type
// after done test you work and make sure it works with differenct types.
// When completed move your template file (Deque.h) and your tester to 
// matrix and make sure it works properly 
// To submit your workshop run the following command
// ~fardad.soleimanloo/submit 345_tw<ENTER>


#include <utility>
#include <iostream>

#ifndef SICT_QUEUE_H__
#define SICT_QUEUE_H__

template <typename T>
class Deque;

template <typename T>
class Qnode {
	T m_data;
	Qnode* m_next;
	Qnode* m_prev;
	Qnode(const T& data = {}, Qnode* prev = nullptr, Qnode* next = nullptr);
	friend class Deque<T>;
};


template <typename T>
class Deque {

	Qnode<T>* m_head = nullptr;
	Qnode<T>* m_tail = nullptr;
	unsigned int m_size = 0;
	static unsigned int m_serial;


public: 
  Deque();
  Deque(unsigned int size); 

  Deque(unsigned int size, const T& data); // deque(int n, const T& d)
  Deque(const Deque& Q);
  Deque(Deque&& Q);
  ~Deque();
  Deque& operator=(const Deque& Q);
  Deque& operator=(Deque&& Q);
  unsigned int size()const;
  bool empty()const;
  T& operator[](unsigned int index); // T& operator[](size_t i)
  const T& operator[](unsigned int index)const;  //const T& operator[](size_t i) const
  T& front();    // T& front();
  const T& front()const; //const T& front() const
  T& back();  // T& back();
  const T& back()const; // const T& back()const;
  void push_back(const T& data);   // void push_back(const T& data)
  void push_front(const T& data); // void push_front(const T& data)
  void pop_back();
  void pop_front();
  void clear();
  static unsigned int serial();
};

/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& Q) {
	for (unsigned int i = 0; i < Q.size(); i++) {
		os << Q[i] << " ";
	}
	return os;
}
*/ 

// deque.cpp 
template <typename T>
unsigned int Deque<T>::m_serial = 0;

template<typename T>
unsigned int Deque<T>::serial() {
	return m_serial;
}

template <typename T>
Qnode<T>::Qnode(const T& data, Qnode* prev, Qnode* next) :
	m_data(data), m_next(next), m_prev(prev) {}

template<typename T>
Deque<T>::Deque() {
	m_serial++;
}
template<typename T>
Deque<T>::Deque(unsigned int size) : Deque(size, {}) {
	m_serial++;
}

template<typename T>
Deque<T>::Deque(unsigned int size, const T& data) {
	while (size--) {
		(push_back(data));
	}
	m_serial++;
}

template<typename T>

Deque<T>::Deque(const Deque& Q) {
	operator=(Q);
	m_serial++;

}

template<typename T>
Deque<T>::Deque(Deque&& Q) {
	operator=(std::move(Q));
	m_serial++;
}

template<typename T>
Deque<T>::~Deque() {
	clear();
	m_serial--;
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& Q) {
	clear();
	for (unsigned int i = {}; i < Q.size(); push_back(Q[i++]));
	return *this;
}

template<typename T>
Deque<T>& Deque<T>::operator=(Deque&& Q) {
	clear();
	m_head = Q.m_head;
	m_tail = Q.m_tail;
	m_size = Q.m_size;
	Q.m_head = Q.m_tail = nullptr;
	Q.m_size = 0;
	return *this;
}

template <typename T>
unsigned int Deque<T>::size()const {
	return m_size;
}

template <typename T>
bool Deque<T>::empty()const {
	return m_head == nullptr;
}

template <typename T>
T& Deque<T>::operator[](unsigned int index) {
	if (empty())push_back({});
	index %= size();
	Qnode<T>* cur = m_head;
	for (unsigned int i = 0; i < index; i++, cur = cur->m_next);
	return cur->m_data;
}

template <typename T>
const T& Deque<T>::operator[](unsigned int index)const {
	index %= size();
	Qnode<T>* cur = m_head;
	for (unsigned int i = 0; i < index; i++, cur = cur->m_next);
	return cur->m_data;
}

template <typename T>
T& Deque<T>::front() {
	return m_head->m_data;
}

template <typename T>
const T& Deque<T>::front()const {
	return m_head->m_data;
}

template <typename T>
T& Deque<T>::back() {
	return m_tail->m_data;
}

template <typename T>
const T& Deque<T>::back()const {
	return m_tail->m_data;
}

template <typename T>
void Deque<T>::push_back(const T& data) {
	Qnode<T>* new_tail = new Qnode<T>(data, m_tail);
	if (m_head)  // not empty, at least one
		m_tail = m_tail->m_next = new_tail;
	else
		m_head = m_tail = new_tail;

	m_size++;
}

template <typename T>
void Deque<T>::push_front(const T& data) {
	Qnode<T>* new_head = new Qnode<T>(data, nullptr, m_head);
	if (m_tail)
		m_head = m_head->m_prev = new_head;
	else
		m_tail = m_head = new_head;
	m_size++;
}

template <class T>
void Deque<T>::pop_back() {
	if (m_tail) { // if (!empty()){
		if (m_tail == m_head) m_head = nullptr;
		Qnode<T>* toDelete = m_tail;
		m_tail = m_tail->m_prev;
		m_tail->m_next = nullptr;
		delete toDelete;
		m_size--;
	}
}
template <class T>
void Deque<T>::pop_front() {
	if (m_head) { // if (!empty()){
		if (m_tail == m_head) m_tail = nullptr;
		Qnode<T>* toDelete = m_head;
		m_head = m_head->m_next;
		m_head->m_prev = nullptr;
		delete toDelete;
		m_size--;
	}
}

template <class T>
void Deque<T>::clear() {
	Qnode<T>* toDel = m_head;
	while (toDel) {
		m_head = m_head->m_next;
		delete toDel;
		toDel = m_head;
	}
	m_size = 0;
}


#endif
