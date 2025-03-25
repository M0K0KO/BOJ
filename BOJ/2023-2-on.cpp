/*             Object-Oriented Programming, Final exam (2023-2, CSE103-02)                       */
// Write your answers in Korean or English(답안은 한국어 또는 영어로 작성하시오).

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// 학과:				, 학번:				, 성명:        
/////////// 답안 시작
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
/////////// 답안 끝

int main() {

	// 전역 변수 사용 금지
	// 채점 기준:		1. 주어진 제한 조건을 위반하면 0점 처리
	//				2. 문제(main 함수의 내용)를 수정하면 0점 처리
	//				3. 일반적인 동작이 불가능한 경우 0점 처리 또는 감점(일반적인 입력에 대한 처리 등)
	//				4. 연산자의 사용이 부정확한 경우 감점(예, &&를 사용할 위치에 &를 사용 등)
	//				5. 필요없는 파라메터나 반환이 있으면 감점
	//				6. 답안지에 코드 동작에 대한 설명이 없으면 0점 처리

	std::cout << "\n### 1 ###" << std::endl;
	// 1. 아래와 같이 동작하는 A 클래스를 정의하라. 
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화
//	A a1, a2(1.2);
//	const A a3(2.5);
//	std::cout << a1.Get() << ", " << a2.Get() << ", " << a3.Get() << std::endl;		// 출력: 0, 1.2, 2.5

	std::cout << "\n### 2 ###" << std::endl;
	// 2. 아래와 같이 동작하는 B 클래스를 정의하라. 
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화
//	B b1, b2(1.2);
//	const B b3(2.5);
//	b1.Get() += 1.5;
//	b2.Get() += 2.9;
//	std::cout << b1.Get() << ", " << b2.Get() << ", " << b3.Get() << std::endl;		// 출력: 1.5, 4.1, 2.5

	std::cout << "\n### 3 ###" << std::endl;
	// 3. 아래와 같이 동작하는 C 클래스를 정의하라. << 연산자는 비멤버, + 연산자는 멤버로 정의
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화
//	C c1;
//	const C c2(1.2), c3(2.5);

//	std::cout << c1 << ", " << c2 << ", " << c3 << std::endl;		// 출력: 0, 1.2, 2.5
//	C c4 = c3 + c2;
//	std::cout << c4 << std::endl; // 출력: 3.7

	std::cout << "\n### 4 ###" << std::endl;
	// 4. 아래와 같이 동작하는 E와 F 클래스를 정의하라. 
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화, 4) friend 선언 없음
//	F f1, f2(3);
//	const F f3(4, 5);
//	std::cout << f1.E::Get() << ", " << f1.Get() << std::endl; // 출력: 0, 1
//	std::cout << f2.E::Get() << ", " << f2.Get() << std::endl; // 출력: 3, 1
//	std::cout << f3.E::Get() << ", " << f3.Get() << std::endl; // 출력: 4, 5

	std::cout << "\n### 5 ###" << std::endl;
	// 5. 아래와 같이 동작하는 G와 H 클래스를 정의하라. (g1.Get()의 결과는 2, g2.Get()의 결과는 2+4)
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화, 4) friend 선언 없음
//	const H h1(2, 4);
//	G g1 = h1; 
//	const G& g2 = h1;
//	std::cout << g1.Get() << ", " << g2.Get() << std::endl;	// 출력 : 2, 6

	std::cout << "\n### 6 ###" << std::endl;
	// 6. 아래와 같이 동작하는 K 클래스 템플릿을 정의하라. (k1은 크기가 5인 int형 벡터(std::vector)로 모두 0으로 초기화, k2는 크기가 10인  char형 벡터(std::vector)로 모두 '*'으로 초기화)
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화
//	K<int> k1(5);
//	K<char> k2(10, '*');
//	k1.Print(); // 출력: 0, 0, 0, 0, 0,
//	k2.Print(); // 출력: *, *, *, *, *, *, *, *, *, *,

	std::cout << "\n### 7 ###" << std::endl;
	// 7. 아래와 같이 동작하는 Print와  Fn 함수 템플릿을 정의하라. (Print는 iterator 범위를 출력하고, Fn은 요소가 [0, 100] 범위가 아니면 제거한다.)
	// 1) 함수를 overloading하지 않음, 2) Fn 함수는 람다(lambda) 함수를 이용하여 최대한 간소화하여 작성
	srand((unsigned)time(0));
	std::vector<int> r;
	std::list<int> l;

	for (int i = 0; i < 10; ++i) {
		r.push_back(rand() % 300 - 100);
		l.push_back(rand() % 300 - 100);
	}

	//	Print(r.begin(), r.end()); // 출력 예: 5, 197, 77, 97, -55, -39, -23, 192, 64, 33,
	//	Fn(r);
	//	Print(r.begin(), r.end()); // 출력 예: 5, 77, 97, 64, 33,
	//	std::cout << std::endl;
	//	Print(l.begin(), l.end());	// 출력 예: 2, -38, -37, 87, -88, 126, 185, 122, 89, -88,
	//	Fn(l);
	//	Print(l.begin(), l.end());	// 출력 예: 2, 87, 89,
}