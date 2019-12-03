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
	Tuple(const Tuple<T> &a);
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
	_data = new TupleData<T>(n);
}
template <typename T>
Tuple::Tuple(T x[], int n){
	_data = new TupleData<T>(x, n);
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
	//points to the same pointer 
	// but keep an account for "deallocation of 5 ints, share 3 ints" / DIMENSION thing
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
	static T zero;
public:

	TupleData(int n);
	TupleData(T* a, int n);
	~TupleData();
	int size() const;
	int useCount() const;
	double magnitude();
	T& operator[](int a);
	const T& operator[](int a) const;
	void decOwners();
	void incOwners(){_owners++};
};

template <typename T>
static T TupleData::zero = 0;

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
double TupleData::magnitude(){
	double x = 0;
	for (int i = 0; i < _indices; ++i){
		x += _dataArr[i]*_dataArr[i];
	}
	return sqrt(x);
}
template <typename T>
T& TupleData::operator[](int a) {
	if(a >=0 && a <= _indices)
		return _dataArr[a];
	else{
		zero = 0;
		return zero;
	}
}
template <typename T>
const T& TupleData::operator[](int a) const {
	if(a >=0 && a <= _indices)
		return _dataArr[a];
	else{
		zero = 0;
		return zero;
	}
}
template <typename T>
void TupleData::decOwners(){
	if (_owners == 1)
		delete this;
	else
		_owners--;
}
