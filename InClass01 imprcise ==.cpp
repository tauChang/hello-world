#include<iostream>
#include<cmath>
using namespace std;

class MyVector
{
	private:  
		static double equalityGap;
		const int n;
		double* m;
	public:
		MyVector(); 
		MyVector(int n, double m[]);
		MyVector(const MyVector& v);
		//void print();
		void print() const;
		~MyVector();
		bool operator== (double d) const; 
		bool operator == (const MyVector& v) const;
		bool operator<(const MyVector& v) const;
		bool operator!=(const MyVector& v) const;
};

MyVector::MyVector()  : n(0), m(nullptr)
{
	//m = nullptr;
}
void MyVector::print() const
{
	cout << "(";
	for(int i = 0; i < n - 1;i++)
		cout << m[i] << ", ";
	cout << m[n - 1] << ")\n";
}
MyVector::~MyVector()
{
	delete [] m;
}
MyVector::MyVector(int n, double m[]) : n(n)  //member initializer
{
	this->m = new double[this->n];
	for(int i = 0; i < this->n; i++)
		this->m[i] = m[i];
}
MyVector::MyVector(const MyVector& v) : n(v.n)
{
	//n = v.n;
	m = new double[n];
	for(int i = 0; i < n; i++)
		m[i] = v.m[i];  //Deep copy
						//Shallow copy => m = v.m;
}
double MyVector::equalityGap = 0.00001;
bool MyVector::operator== (double d) const   //HERE!!! 
{
	for(int i = 0; i < n; i++)
	{
		if(abs(this->m[i] - d) > equalityGap)
		{
			cout << m[i] - d;
			return false;
		}
	}
	return true;
 } 
bool MyVector::operator == (const MyVector& v) const
{
	if(n != v.n)
		return false;
	for(int i = 0; i < n; i++)
		if(m[i] != v.m[i])
			return false;
	return true;
 } 
bool MyVector::operator<(const MyVector& v) const
{
	if(this->n != v.n)
		return false;
	for(int i = 0; i< n; i ++)
		if(this->m[i] >= v.m[i])
			return false;
	return true;
}

bool MyVector::operator!=(const MyVector& v) const
{
	if(*this == v)
		return false;
	return true;
	// return !(*this == v)
} 

int main()
{
	double d1[5] = {1.00001, 1.000002, 1.0000042, 0.99999, 0.9999993};
	MyVector a1(5, d1);
	cout << (a1 == 1 ? "YES, Equal" : "NO");
	//cout << (1.00001 - 1 > 0.00001);
	cout << "HEY";
}
