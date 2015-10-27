#ifndef STACK_H_
#define STACK_H_

#define DEFAULT_CAPACITY 3
typedef int Rank;

template <typename T>
class Stack
{
private:
	T *_elem;
	Rank _size;
	Rank _capacity;
public:
	Stack(int n = 0,T ele = 0){
		_elem = new T[_capacity = DEFAULT_CAPACITY << 1];
		for(_size = 0;_size < n;_size++)
			_elem[_size] = ele;
		expand();
	};

	~Stack(){delete [] _elem;};

	void expand();
	void shrink();
	bool empty(){return (_size == 0);}
	Rank size(){return _size;}
	void push(T const&e);
	T pop();
	T & top();

};


template <typename T>
void Stack<T>::expand(){
	if(_size < _capacity) return;
	if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	T *oldelem = _elem;
	_elem = new T[_capacity <<= 1];
	for(int i = 0;i < _size; ++i){
		_elem[i] = oldelem[i];
	}
	delete [] oldelem;
}

template <typename T>
void Stack<T>::shrink(){
	if(_capacity < DEFAULT_CAPACITY << 1) return;
	if(_size << 2 > _capacity) return;
	T *oldelem = _elem;
	_elem = new T[_capacity >>= 1];
	for(int i = 0;i < _size; ++i){
		_elem[i] = oldelem[i];
	}
	delete [] oldelem;

}

template <typename T>
void Stack<T>::push(T const&e){
	expand();
	_elem[_size++] = e;
}

template <typename T>
T Stack<T>::pop(){
	shrink();
	return _elem[_size-- - 1];
}

template <typename T>
T & Stack<T>::top(){
	return _elem[_size - 1];
}

#endif
