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

// 학과:						학번:						이름:
// 답안 코드 (함수 및 클래스) 작성 영역
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
	// 전역 변수 및 static 변수 사용 금지
	// 채점 기준:		1. 실행되지 않으면 0점 처리
	//				2. 주어진 제한 조건을 위반하면 0점 처리
	//				3. 문제(main 함수의 내용)를 수정하면 0점 처리
	//				4. 일반적인 동작이 불가능한 경우 0점 처리 또는 감점(일반적인 입력에 대한 처리 등)
	//				5. 연산자의 사용이 부정확한 경우 감점(예, &&를 사용할 위치에 &를 사용 등)
	//				6. 필요없는 파라메터나 반환이 있으면 감점
	//				7. 답안지에 코드 동작에 대한 설명이 없으면 0점 처리



	/**********
	1. 모든 문제에서 friend 설정을 할 수 없음
	2. 모든 문제에서 데이터 멤버는 private로 선언한다.
	3. 모든 문제에서 auto 타입을 사용할 수 없다.
	**********/


	// 1. 아래 코드에서 주석과 같이 출력되도록 A 클래스를 정의하라.
	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자와 GetX만 overloding 없이 한 개씩만 정의한다. 
	std::cout << "\n### 1 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	A a1(1.5), a2;
	const A a3(3.2);
	std::cout << a1.GetX() << ", " << a2.GetX() << ", " << a3.GetX() << std::endl;
	// Print: 1.5, 0, 3.2
	*****/

	// 2. 아래 코드에서 주석과 같이 출력되도록 B 클래스를 정의하라.
	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자, SetX과 << 연산자를 overloding 없이 한 개씩 정의한다. 
	// << 연산자는 비멤버로 정의하며, 추가적인 멤버 함수를 1개 더 사용할 수 있다.
	std::cout << "\n### 2 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	B b1(1), b2;
	const B b3(3);
	b1.SetX(10);
	std::cout << b1 << ", " << b2 << ", " << b3 << std::endl;
	// Print: 10, 0, 3
	*****/

	// 3. 아래 코드에서 주석과 같이 출력되도록 C 클래스를 정의하라.
	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자, GetX와 += 연산자만 overloding 없이 한 개씩만 정의한다. 
	// += 연산자는 멤버로 정의한다.
	std::cout << "\n### 3 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	const C c1(10);
	C c2(5), c3;
	c3 = c2 += c1;
	std::cout << c2.GetX() << ", " << c3.GetX() << std::endl;
	// Print: 15, 15
	*****/


	// 4. 아래 코드에서 주석과 같이 출력되도록 Super와 Sub 클래스를 정의하라.
	// 두 개의 클래스는 상속 관계이며, 각각 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// "Super"와 "~Super"의 출력은 Super 클래스에서 출력하며, "Sub"와 "~Sub"의 출력은 Sub 클래스에서 출력한다.
	// 생성자, 소멸자, Print 함수만 overloading 없이 정의한다.
	std::cout << "\n### 4 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	Super* p1 = new Sub(1, 2);	// Print: "Super" "Sub"
	Sub* p2 = dynamic_cast<Sub*>(p1);
	p1->Print();				// Print: 1
	std::cout << std::endl;
	if (p2) p2->Print();			// Print: 1, 2
	std::cout << std::endl;
	delete p1;					// Print: "~Sub" "~Super"
	*****/

	// 5. 아래 코드에서 주석과 같이 출력되도록 Data 클래스 템플릿을 정의하라.
	// 데이터 멤버는 template type의 자료를 저장하는 shared pointer를 사용한다(private 접근 권한이며 추가적인 데이터 멤버 없음)
	// 생성자에 초기값이 없는 경우에는 0을 저장한다.
	// Get과 Set은 각각 포인터가 가리키는 대상의 값을 반환하고 수정한다.
	std::cout << "\n### 5 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
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

	// 6. 아래 코드에서 첫 번째 매개변수인 sequence container에서 두 번째 매개변수와 동일한 요소를 제거하는 Function6 템플릿 함수를 정의하라.
	// 함수의 body는 한 개의 문장으로 작성하며, container의 메소드와 std::remove 함수만 사용한다.
	// std::remove를 사용하지 않고 비효율적으로 작성하면 0점 처리
	std::cout << "\n### 6 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
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

	// 7. 아래의 코드에서 std::vector<int>에서 지정된 값의 요소를 찾는 Function7 함수를 정의하라.
	// Function7로 반환된 함수는 return type이 std::vector<int>::iterator이고 parameter type은 std::vector<int>& 이다.
	// Fn1은 argument로 전달된 v2에서 2의 값을 가지는 최초의 iterator를 반환하는 함수이고,
	// Fn2은 argument로 전달된 v2에서 5의 값을 가지는 최초의 iterator를 반환하는 함수이고,
	// Fn2은 argument로 전달된 v2에서 7의 값을 가지는 최초의 iterator를 반환하는 함수이다(찾는 값의 요소가 없으면 end iterator를 반환한다).
	// auto 타입을 사용할 수 없으며, container의 메소드와 std::find 함수만 사용한다.
	// 반환은 lamba function으로 작성하고, 함수의 body는 return 문장으로만 작성한다.
	// std::find를 사용하지 않고 비효율적으로 작성하면 0점 처리
	std::cout << "\n### 7 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
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