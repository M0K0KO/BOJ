/*             Object-Oriented Programming, Final exam (2024-1, CSE103-00)                       */
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

	void SetX(int y) {
		x = y;
	}

	const int& GetX() const {
		return x;
	}
};

std::ostream& operator<< (std::ostream& os, const B& b) {
	os << b.GetX();
	return os;
}

class C {
private:
	int x;
public:
	C(int x = 0) : x(x) {}

	int GetX() const {
		return x;
	}

	C& operator+= (const C& other) {
		x += other.GetX();
		return *this;
	}
};

class Super {
private:
	int super;
public:
	Super(int super = 0) : super(super) {
		std::cout << "Super";
	}
	virtual ~Super() { std::cout << "~Super" << std::endl; }

	virtual void Print() const {
		std::cout << super;
	}
};

class Sub : public Super {
private:
	int sub;
public:
	Sub(int super = 0, int sub = 0) : Super(super), sub(sub) {
		std::cout << "Sub";
	}

	~Sub() override {
		std::cout << "~Sub" << std::endl;
	}

	void Print() const override {
		Super::Print();
		std::cout << ", " << sub;
	}
};

template <typename T>
class Data {
private:
	std::shared_ptr<T> value;
public:
	Data(T initValue = 0) : value(std::make_shared<T>(initValue)) {}

	T Get() const {
		return *value;
	}

	void Set(T newValue) {
		*value = newValue;
	}
};

template <typename Container, typename Target>
void Function6(Container& container, const Target& target) {
	container.erase(std::remove(container.begin(), container.end(), target), container.end());
}

std::function<std::vector<int>::iterator(std::vector<int>&)> Function7(int value) {
	return [value](std::vector<int>& container) -> std::vector<int>::iterator { return std::find(container.begin(), container.end(), value); };
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
	// Print: 1.5, 0, 3.2
	*****/

	// 2. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� B Ŭ������ �����϶�.
	// �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// ������, SetX�� << �����ڸ� overloding ���� �� ���� �����Ѵ�. 
	// << �����ڴ� ������ �����ϸ�, �߰����� ��� �Լ��� 1�� �� ����� �� �ִ�.
	std::cout << "\n### 2 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	B b1(1), b2;
	const B b3(3);
	b1.SetX(10);
	std::cout << b1 << ", " << b2 << ", " << b3 << std::endl;
	// Print: 10, 0, 3
	*****/

	// 3. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� C Ŭ������ �����϶�.
	// �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// ������, GetX�� += �����ڸ� overloding ���� �� ������ �����Ѵ�. 
	// += �����ڴ� ����� �����Ѵ�.
	std::cout << "\n### 3 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	const C c1(10);
	C c2(5), c3;
	c3 = c2 += c1;
	std::cout << c2.GetX() << ", " << c3.GetX() << std::endl;
	// Print: 15, 15
	*****/


	// 4. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� Super�� Sub Ŭ������ �����϶�.
	// �� ���� Ŭ������ ��� �����̸�, ���� �� ���� private ���� ������ ������ ����� ������(�߰����� ������ ��� ����).
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	// "Super"�� "~Super"�� ����� Super Ŭ�������� ����ϸ�, "Sub"�� "~Sub"�� ����� Sub Ŭ�������� ����Ѵ�.
	// ������, �Ҹ���, Print �Լ��� overloading ���� �����Ѵ�.
	std::cout << "\n### 4 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	Super* p1 = new Sub(1, 2);	// Print: "Super" "Sub"
	Sub* p2 = dynamic_cast<Sub*>(p1);
	p1->Print();				// Print: 1
	std::cout << std::endl;
	if (p2) p2->Print();			// Print: 1, 2
	std::cout << std::endl;
	delete p1;					// Print: "~Sub" "~Super"
	*****/

	// 5. �Ʒ� �ڵ忡�� �ּ��� ���� ��µǵ��� Data Ŭ���� ���ø��� �����϶�.
	// ������ ����� template type�� �ڷḦ �����ϴ� shared pointer�� ����Ѵ�(private ���� �����̸� �߰����� ������ ��� ����)
	// �����ڿ� �ʱⰪ�� ���� ��쿡�� 0�� �����Ѵ�.
	// Get�� Set�� ���� �����Ͱ� ����Ű�� ����� ���� ��ȯ�ϰ� �����Ѵ�.
	std::cout << "\n### 5 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	Data<int> data1(2), data2;
	Data<double> data3(10.5), data4;
	std::cout << data1.Get() << ", " << data2.Get() << std::endl;	// Print: 2, 0
	std::cout << data3.Get() << ", " << data4.Get() << std::endl;	// Print: 10.5, 0
	data2 = data1;
	data2.Set(3);
	data3 = data4;
	data4.Set(1.2);
	std::cout << data1.Get() << ", " << data2.Get() << std::endl;	// Print: 3, 3
	std::cout << data3.Get() << ", " << data4.Get() << std::endl;	// Print: 1.2, 1.2
	*****/

	// 6. �Ʒ� �ڵ忡�� ù ��° �Ű������� sequence container���� �� ��° �Ű������� ������ ��Ҹ� �����ϴ� Function6 ���ø� �Լ��� �����϶�.
	// �Լ��� body�� �� ���� �������� �ۼ��ϸ�, container�� �޼ҵ�� std::remove �Լ��� ����Ѵ�.
	// std::remove�� ������� �ʰ� ��ȿ�������� �ۼ��ϸ� 0�� ó��
	std::cout << "\n### 6 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	std::vector<int> v1{ 1, 9, 4, 7, 4, 6 };
	Function6(v1, 4);
	for (const int& x : v1) std::cout << x << ", ";	// Print: 1, 9, 7, 6,
	std::cout << std::endl;
	std::list<int> l1{ 8, 3, 4, 3, 3, 2 };
	Function6(l1, 3);
	for (const int& x : l1) std::cout << x << ", ";	// Print: 8, 4, 2,
	std::cout << std::endl;
	*****/

	// 7. �Ʒ��� �ڵ忡�� std::vector<int>���� ������ ���� ��Ҹ� ã�� Function7 �Լ��� �����϶�.
	// Function7�� ��ȯ�� �Լ��� return type�� std::vector<int>::iterator�̰� parameter type�� std::vector<int>& �̴�.
	// Fn1�� argument�� ���޵� v2���� 2�� ���� ������ ������ iterator�� ��ȯ�ϴ� �Լ��̰�,
	// Fn2�� argument�� ���޵� v2���� 5�� ���� ������ ������ iterator�� ��ȯ�ϴ� �Լ��̰�,
	// Fn2�� argument�� ���޵� v2���� 7�� ���� ������ ������ iterator�� ��ȯ�ϴ� �Լ��̴�(ã�� ���� ��Ұ� ������ end iterator�� ��ȯ�Ѵ�).
	// auto Ÿ���� ����� �� ������, container�� �޼ҵ�� std::find �Լ��� ����Ѵ�.
	// ��ȯ�� lamba function���� �ۼ��ϰ�, �Լ��� body�� return �������θ� �ۼ��Ѵ�.
	// std::find�� ������� �ʰ� ��ȿ�������� �ۼ��ϸ� 0�� ó��
	std::cout << "\n### 7 ###" << std::endl;
	// ����� �ۼ��Ǹ� �Ʒ��� /*****�� *****/�� �����϶�.(�������� ������ ä������ ����)
	/*****
	std::vector<int> v2{ 1, 2, 4, 5, 9 };
	std::vector<int>::iterator it;

	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn1 = Function7(2);
	it = Fn1(v2);
	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;
	else std::cout << std::distance(v2.begin(), it) << std::endl;
	// Print: 1, 2, 2

	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn2 = Function7(5);
	it = Fn2(v2);
	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;
	else std::cout << std::distance(v2.begin(), it) << std::endl;
	// Print: 3, 5, 5

	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn3 = Function7(7);
	it = Fn3(v2);
	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;
	else std::cout << std::distance(v2.begin(), it) << " = " << v2.size() << std::endl;
	// Print: 5 = 5
	*****/

}