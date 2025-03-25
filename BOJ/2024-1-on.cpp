/*             Object-Oriented Programming, Final exam (2024-1, CSE103-01)                       */
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric> 
#include <exception>
#include <memory>
#include <iterator>

// �а�:						�й�:						�̸�:
// ��� �ڵ� (�Լ� �� Ŭ����) �ۼ� ����
class A {
private:
	double x;
public:
	A(double x = 0) : x(x) {}

	const double& GetX() const {
		return x;
	}
};

class B {
private:
	int x;
public:
	B(int x = 0) : x(x) {}

	const double& GetX() const {
		return x;
	}
};

std::ostream& operator<< (std::ostream& os, const B& other) {
	os << other.GetX();
	return os;
}

class C {
private:
	int x;
public:
	C(int x = 0) : x(x) {}

	const int GetX() const {
		return x;
	}

	C operator+ (const C& other) {
		return C(x + other.x);
	}
};

class Base {
private:
	int x;
public:
	Base(int x = 0) : x(x) {}

	void Print() const {
		std::cout << x;
	}
};

class Derived : public Base {
private:
	int y;
public:
	Derived(int a = 0, int b = 0) : Base(a), y(b) {}

	void Print() const {
		Base::Print();
		std::cout << ", " << y;
	}
};

class Super {
private:
	int x;
public:
	Super(int x = 0) : x(x) {}

	virtual void Print() const {
		std::cout << x;
	}
};

class Sub : public Super {
private:
	int y;
public:
	Sub(int a = 0, int b = 0) : Super(a), y(b) {}

	void Print() const override {
		Super::Print();
		std::cout << ", " << y;
	}
};

template<typename T>
class Data {
private:
	T value;
public:
	Data(T value = T()) : value(value) {}

	void Print() const {
		if (std::is_same_v<T, bool>) {
			std::cout << (value ? "positive" : "negative") << std::endl;
		}
		else {
			std::cout << value << std::endl;
		}
	}
};

template<typename F1, typename F2>
std::function<double(double)> Function7(F1 f1, F2 f2) {
	return [f1, f2](double x) -> double { return (f1(x) + f2(x)) / 2.; };
}


int main() {
	// ���� ���� �� static ���� ��� ����
	// ä�� ����:		1. ������� ������ 0�� ó��
	//				2. �־��� ���� ������ �����ϸ� 0�� ó��
	//				3. ����(main �Լ��� ����)�� �����ϸ� 0�� ó��
	//				4. �Ϲ����� ������ �Ұ����� ��� 0�� ó�� �Ǵ� ����(�Ϲ����� �Է¿� ���� ó�� ��)
	//				5. �������� ����� ����Ȯ�� ��� ����(��, &&�� ����� ��ġ�� &�� ��� ��)
	//				6. �ʿ���� �Ķ���ͳ� ��ȯ�� ������ ����
	//				7. ������� �ڵ� ���ۿ� ���� ������ ������ 0�� ó��

	/**********
	1. ��� �������� friend ������ �� �� ����
	2. ��� �������� ������ ����� private�� �����Ѵ�.
	3. ��� �������� auto Ÿ���� ����� �� ����.
	**********/

	// 1. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� A Ŭ������ �����϶�.
	// �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// �����ڿ� GetX�� overloding ���� �� ������ �����Ѵ�. 
	std::cout << "\n### 1 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	A a1(1.5), a2;
	const A a3(3.2);
	std::cout << a1.GetX() << ", " << a2.GetX() << ", " << a3.GetX() << std::endl;
	// Print: 1, 0, 3
	*****/



	// 2. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� B Ŭ������ �����϶�.
	// �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// �����ڿ� << �����ڸ� overloding ���� �� ���� �����Ѵ�. 
	// << �����ڴ� ������ �����ϸ�, �߰����� ��� �Լ��� 1�� �� ����� �� �ִ�.
	std::cout << "\n### 2 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	B b1(1), b2;
	const B b3(3);
	std::cout << b1 << ", " << b2 << ", " << b3 << std::endl;
	// Print: 1, 0, 3
	*****/

	// 3. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� C Ŭ������ �����϶�.
	// �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// ������, GetX�� + �����ڸ� overloding ���� �� ������ �����Ѵ�. 
	// + �����ڴ� ����� �����Ѵ�.
	std::cout << "\n### 3 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	const C c1(10);
	C c2(5), c3;
	c3 = c2 + c1;
	std::cout << c1.GetX() << ", " << c3.GetX() << std::endl;
	// Print: 10, 15
	*****/



	// 4. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� Base�� Derived Ŭ������ �����϶�.
	// �� ���� Ŭ������ ��� �����̸�, ���� �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// �����ڿ� Print �Լ��� overloading ���� �����Ѵ�.
	std::cout << "\n### 4 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	const Derived derived(2, 3);
	derived.Print();	// Print: 2, 3
	std::cout << std::endl;
	const Base& base = derived;
	base.Print();		// Print: 2
	std::cout << std::endl;
	*****/


	// 5. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� Super�� Sub Ŭ������ �����϶�.
	// �� ���� Ŭ������ ��� �����̸�, ���� �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// ������, Print �Լ��� overloading ���� �����Ѵ�.
	std::cout << "\n### 5 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	Sub sub(1, 2);
	Super& super = sub;
	super.Print();
	std::cout << std::endl;		// Print: 1, 2
	*****/


	// 6. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� Data Ŭ���� ���ø��� �����϶�.
	// �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// Print ��� �Լ��� ������ ����� ���� ����ϸ�, bool Ÿ���� true�̸� "positive"�� false�̸� "negative"�� ����Ѵ�.
	std::cout << "\n### 6 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	Data<int> data1(10.2);
	Data<double> data2(10.2);
	Data<bool> data3(true), data4;
	data1.Print();	// Print: 10
	data2.Print();	// Print: 10.2
	data3.Print();	// Print: positive
	data4.Print();	// Print: negative
	*****/


	// 7. �Ʒ��� �ڵ忡�� �ּ��� ���� ��µǵ���, 
	// �Ű������� �� ���� double�̰� ��ȯ Ÿ���� double�� �� ���� �Լ��� �Ķ���ͷ� ������,
	// �� �Լ� ����� ����� ��ȯ�ϴ� �Լ��� �����ϴ� Function7 �Լ��� �����϶�.
	// Function7�� ������ �Լ��� ��ȯ�ϸ�, 
	// ��ȯ�� lamba function���� �ۼ��ϰ�, �Լ��� body�� return �������θ� �ۼ��Ѵ�. 
	std::cout << "\n### 7 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	std::function<double(double)> F1 = [](double x) {
		return 2. * x * x + 3. * x + 2.;
	};
	std::function<double(double)> F2 = [](double x) {
		return 5. * x + 1.;
	};

	std::function<double(double)> F3 = Function7(F1, F2);
	double x = -0.86;
	std::cout << x << ", " << F3(x) << ", " << (F1(x) + F2(x)) / 2. << std::endl;
	// Print: -0.86, -1.2004, -1.2004
	x = 10.5;
	std::cout << x << ", " << F3(x) << ", " << (F1(x) + F2(x)) / 2. << std::endl;
	// Print: 10.5, 153.75, 153.75
	*****/

}