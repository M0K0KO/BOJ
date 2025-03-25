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
	// Print: 1, 0, 3
	*****/



	// 2. 아래 코드에서 주석과 같이 출력되도록 B 클래스를 정의하라.
	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자와 << 연산자를 overloding 없이 한 개씩 정의한다. 
	// << 연산자는 비멤버로 정의하며, 추가적인 멤버 함수를 1개 더 사용할 수 있다.
	std::cout << "\n### 2 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	B b1(1), b2;
	const B b3(3);
	std::cout << b1 << ", " << b2 << ", " << b3 << std::endl;
	// Print: 1, 0, 3
	*****/

	// 3. 아래 코드에서 주석과 같이 출력되도록 C 클래스를 정의하라.
	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자, GetX와 + 연산자만 overloding 없이 한 개씩만 정의한다. 
	// + 연산자는 멤버로 정의한다.
	std::cout << "\n### 3 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	const C c1(10);
	C c2(5), c3;
	c3 = c2 + c1;
	std::cout << c1.GetX() << ", " << c3.GetX() << std::endl;
	// Print: 10, 15
	*****/



	// 4. 아래 코드에서 주석과 같이 출력되도록 Base와 Derived 클래스를 정의하라.
	// 두 개의 클래스는 상속 관계이며, 각각 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자와 Print 함수만 overloading 없이 정의한다.
	std::cout << "\n### 4 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	const Derived derived(2, 3);
	derived.Print();	// Print: 2, 3
	std::cout << std::endl;
	const Base& base = derived;
	base.Print();		// Print: 2
	std::cout << std::endl;
	*****/


	// 5. 아래 코드에서 주석과 같이 출력되도록 Super와 Sub 클래스를 정의하라.
	// 두 개의 클래스는 상속 관계이며, 각각 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// 생성자, Print 함수만 overloading 없이 정의한다.
	std::cout << "\n### 5 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	Sub sub(1, 2);
	Super& super = sub;
	super.Print();
	std::cout << std::endl;		// Print: 1, 2
	*****/


	// 6. 아래 코드에서 주석과 같이 출력되도록 Data 클래스 템플릿을 정의하라.
	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).
	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.
	// Print 멤버 함수는 데이터 멤버의 값을 출력하며, bool 타입은 true이면 "positive"를 false이면 "negative"를 출력한다.
	std::cout << "\n### 6 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
	/*****
	Data<int> data1(10.2);
	Data<double> data2(10.2);
	Data<bool> data3(true), data4;
	data1.Print();	// Print: 10
	data2.Print();	// Print: 10.2
	data3.Print();	// Print: positive
	data4.Print();	// Print: negative
	*****/


	// 7. 아래의 코드에서 주석과 간이 출력되도록, 
	// 매개변수가 한 개의 double이고 반환 타입이 double인 두 개의 함수를 파라메터로 가지며,
	// 두 함수 결과의 평균을 반환하는 함수를 생성하는 Function7 함수를 정의하라.
	// Function7은 생성된 함수를 반환하며, 
	// 반환은 lamba function으로 작성하고, 함수의 body는 return 문장으로만 작성한다. 
	std::cout << "\n### 7 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)
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