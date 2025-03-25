/*             Object-Oriented Programming, Final exam (2023-2, CSE103-02)                       */
// Write your answers in Korean or English(����� �ѱ��� �Ǵ� ����� �ۼ��Ͻÿ�).

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// �а�:				, �й�:				, ����:        
/////////// ��� ����
class A {
private:
	double x;
public:
	A(double x = 0) : x(x) {}

	const double& Get() const {
		return x;
	}
};

class B {
private:
	double x;
public:
	B(double x = 0) : x(x) {}

	double& Get() {
		return x;
	}

	const double& Get() const {
		return x;
	}
};

class C {
private:
	double x;
public:
	C(double x = 0) : x(x) {}

	const double& Get() const {
		return x;
	}

	C operator+ (const C& other) const {
		return C(x + other.Get());
	}
};

std::ostream& operator<< (std::ostream& os, const C& target) {
	os << target.Get();
	return os;
}

class E {
private:
	int x;
public:
	E(int x = 0) : x(x) {}

	const int Get() const {
		return x;
	}
};

class F : public E {
private:
	int y;
public:
	F(int a = 0, int b = 1) : E(a), y(b) {}

	const int Get() const {
		return y;
	}
};

class G {
private:
	int x;
public:
	G(int x = 0) : x(x) {}

	virtual const int Get() const {
		return x;
	}
};

class H : public G {
private:
	int y;
public:
	H(int a = 0, int b = 0) : G(a), y(b) {}

	const int Get() const override {
		return G::Get() + y;
	}
};

template<typename T>
class K {
private:
	std::vector<T> data;
public:
	K(size_t n, T value = T()) : data(n, value) {}

	void Print() const {
		for (const T& elem : data) { std::cout << elem << ", "; }
		std::cout << std::endl;
	}
};

template<typename Iterator>
void Print(Iterator start, Iterator end) {
	std::for_each(start, end, [](const auto& elem) { std::cout << elem << ", "; });
	std::cout << std::endl;
}

template<typename Container>
void Fn(Container& container) {
	container.erase(std::remove_if(container.begin(), container.end(), [](int x) {return x < 0 || x > 100; }), container.end());
}
/////////// ��� ��

int main() {

	// ���� ���� ��� ����
	// ä�� ����:		1. �־��� ���� ������ �����ϸ� 0�� ó��
	//				2. ����(main �Լ��� ����)�� �����ϸ� 0�� ó��
	//				3. �Ϲ����� ������ �Ұ����� ��� 0�� ó�� �Ǵ� ����(�Ϲ����� �Է¿� ���� ó�� ��)
	//				4. �������� ����� ����Ȯ�� ��� ����(��, &&�� ����� ��ġ�� &�� ��� ��)
	//				5. �ʿ���� �Ķ���ͳ� ��ȯ�� ������ ����
	//				6. ������� �ڵ� ���ۿ� ���� ������ ������ 0�� ó��

	std::cout << "\n### 1 ###" << std::endl;
	// 1. �Ʒ��� ���� �����ϴ� A Ŭ������ �����϶�. 
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	A a1, a2(1.2);
//	const A a3(2.5);
//	std::cout << a1.Get() << ", " << a2.Get() << ", " << a3.Get() << std::endl;		// ���: 0, 1.2, 2.5

	std::cout << "\n### 2 ###" << std::endl;
	// 2. �Ʒ��� ���� �����ϴ� B Ŭ������ �����϶�. 
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	B b1, b2(1.2);
//	const B b3(2.5);
//	b1.Get() += 1.5;
//	b2.Get() += 2.9;
//	std::cout << b1.Get() << ", " << b2.Get() << ", " << b3.Get() << std::endl;		// ���: 1.5, 4.1, 2.5

	std::cout << "\n### 3 ###" << std::endl;
	// 3. �Ʒ��� ���� �����ϴ� C Ŭ������ �����϶�. << �����ڴ� ����, + �����ڴ� ����� ����
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	C c1;
//	const C c2(1.2), c3(2.5);

//	std::cout << c1 << ", " << c2 << ", " << c3 << std::endl;		// ���: 0, 1.2, 2.5
//	C c4 = c3 + c2;
//	std::cout << c4 << std::endl; // ���: 3.7

	std::cout << "\n### 4 ###" << std::endl;
	// 4. �Ʒ��� ���� �����ϴ� E�� F Ŭ������ �����϶�. 
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ, 4) friend ���� ����
//	F f1, f2(3);
//	const F f3(4, 5);
//	std::cout << f1.E::Get() << ", " << f1.Get() << std::endl; // ���: 0, 1
//	std::cout << f2.E::Get() << ", " << f2.Get() << std::endl; // ���: 3, 1
//	std::cout << f3.E::Get() << ", " << f3.Get() << std::endl; // ���: 4, 5

	std::cout << "\n### 5 ###" << std::endl;
	// 5. �Ʒ��� ���� �����ϴ� G�� H Ŭ������ �����϶�. (g1.Get()�� ����� 2, g2.Get()�� ����� 2+4)
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ, 4) friend ���� ����
//	const H h1(2, 4);
//	G g1 = h1; 
//	const G& g2 = h1;
//	std::cout << g1.Get() << ", " << g2.Get() << std::endl;	// ��� : 2, 6

	std::cout << "\n### 6 ###" << std::endl;
	// 6. �Ʒ��� ���� �����ϴ� K Ŭ���� ���ø��� �����϶�. (k1�� ũ�Ⱑ 5�� int�� ����(std::vector)�� ��� 0���� �ʱ�ȭ, k2�� ũ�Ⱑ 10��  char�� ����(std::vector)�� ��� '*'���� �ʱ�ȭ)
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	K<int> k1(5);
//	K<char> k2(10, '*');
//	k1.Print(); // ���: 0, 0, 0, 0, 0,
//	k2.Print(); // ���: *, *, *, *, *, *, *, *, *, *,

	std::cout << "\n### 7 ###" << std::endl;
	// 7. �Ʒ��� ���� �����ϴ� Print��  Fn �Լ� ���ø��� �����϶�. (Print�� iterator ������ ����ϰ�, Fn�� ��Ұ� [0, 100] ������ �ƴϸ� �����Ѵ�.)
	// 1) �Լ��� overloading���� ����, 2) Fn �Լ��� ����(lambda) �Լ��� �̿��Ͽ� �ִ��� ����ȭ�Ͽ� �ۼ�
	srand((unsigned)time(0));
	std::vector<int> r;
	std::list<int> l;

	for (int i = 0; i < 10; ++i) {
		r.push_back(rand() % 300 - 100);
		l.push_back(rand() % 300 - 100);
	}

	//	Print(r.begin(), r.end()); // ��� ��: 5, 197, 77, 97, -55, -39, -23, 192, 64, 33,
	//	Fn(r);
	//	Print(r.begin(), r.end()); // ��� ��: 5, 77, 97, 64, 33,
	//	std::cout << std::endl;
	//	Print(l.begin(), l.end());	// ��� ��: 2, -38, -37, 87, -88, 126, 185, 122, 89, -88,
	//	Fn(l);
	//	Print(l.begin(), l.end());	// ��� ��: 2, 87, 89,
}