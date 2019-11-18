#include <iostream>
#include <cmath>

template <typename T>
class Tuple
{
private:
	TupleData<T>* _data;
public:
	Tuple(int n);
	Tuple(T x[], int n);
	template <typename T>
	Tuple(Tuple<T> a);
	~Tuple();
	int size();
	double magnitude();
	Tuple<T> operator+(Tuple<T> x);
	Tuple<T> operator+=(Tuple<T> x);
	Tuple<T> operator*(Tuple<T> x);
	Tuple<T> operator*(int x);
	Tuple<T> operator*=(int x);
	Tuple<T> operator=(Tuple<T> x);
	bool operator==(Tuple<T> x);
	bool operator!=(Tuple<T> x);
};

template <typename T>
Tuple::Tuple(int n){
	_data = new TupleData(n);
}
template <typename T>
Tuple::Tuple(T x[], int n){
	_data = new TupleData(x, n);
}
template <typename T>
Tuple::Tuple(Tuple<T> a){
	_data = a;
}
template <typename T>
Tuple::~Tuple(){
	delete [] _data;
}
template <typename T>
int Tuple::size(){
	return _data->size();
}
template <typename T>
double Tuple::magnitude(){
	return _data->magnitude();
}
template <typename T>
T Tuple::operator+(T x){

}
template <typename T>
T Tuple::operator+=(T x){

}
template <typename T>
T Tuple::operator*(T x){

}
template <typename T>
T Tuple::operator*=(T x){

}
template <typename T>
T Tuple::operator=(T x){

}
template <typename T>
T Tuple::operator==(T x){

}
template <typename T>
T Tuple::operator!=(T x){

}












template <typename T>
class TupleData
{
private:
	int _owners, _indices;
	T * _dataArr;
public:
	TupleData(int n);
	TupleData(T* a, int n);
	~TupleData();
	int size() const;
	int useCount() const;
	void setCount(int a);
	double magnitude();
	T& operator[](int a);
};

template <typename T>
TupleData::TupleData(int n) {
	_dataArr = new T[n];
	for (int i = 0; i < n; ++i){
		_dataArr = 0;
	}
	_indices = n;
	_owners = 1;
}
template <typename T>
TupleData::TupleData(T* a, int n) {
	_dataArr = new T[n];
	for (int i = 0; i < n; ++i){
		_dataArr[i] = a[i];
	}
	_indices = n;
	_owners = 1;
}
TupleData::~TupleData() {
	delete[] _dataArr;
}
template <typename T>
int TupleData::size() const {
	return _indices;
}
template <typename T>
int TupleData::useCount() const {
	return _owners;
}
template <typename T>
int TupleData::setCount(int a){
	_owners = a;
}
template <typename T>
double TupleData::magnitude(){
	double x = 0;
	for (int i = 0; i < _indices; ++i){
		x += _dataArr[i]*_dataArr[i];
	}
	return sqrt(x);
}
template <typename T>
T& TupleData::operator[](int a) {
	return &_dataArr[a];
}






