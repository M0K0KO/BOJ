/*             Object-Oriented Programming, Final exam (2023-2, CSE103-00)                       */
// Write your answers in Korean or English(답안은 한국어 또는 영어로 작성하시오).

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric> 
#include <exception>
#include <cstdlib>
#include <ctime>


// 학과:				, 학번:				, 성명:        

/////////// 답안 시작
class X1 {
private:
	double x;
public:
	X1(double x = 0) : x(x) {}

	double GetX() const {
		return x;
	}
};

std::ostream& operator<< (std::ostream& os, const X1& target) {
	os << target.GetX();
	return os;
}

class B2 {
public:
	double x = 0;
};

class D2 : public B2 {
public:
	double x = 0;

	D2(double b2value = 0, double d2value = 0) {
		B2::x = b2value;
		x = d2value;
	}
};

class B31 {
private:
	int x;

public:
	B31(int val = 0) : x(val) {}

	virtual void Print() const { 
		std::cout << x;
	}

	virtual ~B31() = default;
};

class B32 {
private:
	int y;

public:
	B32(int val = 0) : y(val) {}

	virtual void Print() const {
		std::cout << y;
	}

	virtual ~B32() = default;
};

class D3 : public B31, public B32 {
public:
	D3(int b31Val, int b32Val) : B31(b31Val), B32(b32Val) {}

	void Print() const override {
		B31::Print(); 
		std::cout << ", ";
		B32::Print();
		std::cout << ", ";
	}

	~D3() override = default;
};

class V4 {
private:
	int x = 0;
public:
	virtual void Print() const {}
};

class W4 : public V4 {
private:
	int a, b;
public:
	W4(int a = 0, int b = 0) : a(a), b(b) {}

	W4 operator+ (const W4& other)  const {
		return W4(a + other.a, b + other.b);
	}

	void Print() const override {
		std::cout << a << ", " << b << std::endl;
	}
};

template<typename T, std::size_t N>
class X5 {
private:
	std::vector<T> data;
public:
	X5(T value = T()) : data(std::vector<T>(N, value)) {}

	void Set(T newValue, int index) {
		if (N <= index) { throw(std::out_of_range("index exception")); }
		else {
			data[index] = newValue;
		}
	}

	void Print() const {
		std::for_each(data.begin(), data.end(), [](const auto& elem) { std::cout << elem << ", "; });
		std::cout << std::endl;
	}
};

template <typename F1, typename F2>
auto Fn6(F1 f1, F2 f2) {
	return [f1, f2](double x1, double x2) {return f1(x1, x2) * f2(x1, x2); };
}

/////////////////////////////////////////
struct Line {
	int Start, End;
	Line(int s = 0, int e = 0) : Start(s), End(e) {}
};
/////////////////////////////////////////

std::ostream& operator <<(std::ostream& os, const Line& target) {
	os << "(" << target.Start << ", " << target.End << ")";
	return os;
}

void EraseInvalid(std::vector<Line>& lines) {
	lines.erase(std::remove_if(lines.begin(), lines.end(), [](const Line& x) {return x.Start > x.End; }), lines.end());
}

Line UnionLines(std::vector<Line>& lines) {
	return lines.empty() ? Line() : std::accumulate(lines.begin(), lines.end(), Line(INT_MAX, INT_MIN),
		[](const Line& acc, const Line& line) {return Line(std::min(acc.Start, line.Start), std::max(acc.End, line.End)); });
}
/////////// 답안 끝

int main() {
	// 전역 변수 사용 금지
	// 채점 기준:		1. 주어진 제한 조건을 위반하면 감점
	//				2. 문제(main 함수의 내용)를 수정하면 감점 
	//				3. 일반적인 동작이 불가능한 경우 0점 처리 또는 감점(일반적인 입력에 대한 처리 등)
	//				4. 연산자의 사용이 부정확한 경우 감점(예, &&를 사용할 위치에 &를 사용 등)
	//				5. 필요없는 파라메터나 반환이 있으면 감점
	//				6. 답안지에 코드 동작에 대한 설명이 없으면 0점 처리
	//				7. 주석 부분은 채점하지 않음(main의 동작도 주석으로 실행되지 않으면 채점하기 않음)



	std::cout << "\n### 1 ###" << std::endl;
	// 1. 아래와 같이 동작하는 X1 클래스를 정의하고, << 연산자(non member)를 overloading하라.
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) friend 선언 사용 금지, 4) 함수, 변수 및 수식의 사용을 최소화
//	X1 x1, x2(5.3);
//	const X1 x3(7.2);
//	std::cout << x1 << ", " << x2 << ", " << x3 << std::endl;		// 출력: 0, 5.3, 7.2, 


	std::cout << "\n### 2 ###" << std::endl;
	// 2. 아래와 같이 동작하는 B2, D2 클래스를 정의하라. 
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 public 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화
//	D2 d1, d2(2.5, 3.2);
//	std::cout << d1.B2::x << ", " << d1.x << ", " << d2.B2::x << ", " << d2.x << std::endl; // 출력: 0, 0, 2.5, 3.2

	std::cout << "\n### 3 ###" << std::endl;
	// 3. 아래와 같이 동작하는 B31, B32, D3 클래스를 정의하라.
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) friend 선언 사용 금지, 4) 함수, 변수 및 수식의 사용을 최소화
//	B31* pB31 = new D3(1, 0);
//	B32* pB32 = new D3(3, 2);
//	static_cast<B31>(*pB31).Print();	// 출력: 1
//	static_cast<B32>(*pB32).Print();	// 출력: 2
//	pB31->Print();	// 출력: 1, 0,
//	pB32->Print();	// 출력: 3, 2, 
	std::cout << std::endl;
	//	delete pB31;		// 정상적으로 동작해야 함
	//	delete pB32;		// 정상적으로 동작해야 함

	std::cout << "\n### 4 ###" << std::endl;
	// 4. 아래와 같이 동작하는 V4, W4 클래스를 정의하라.(+ 연산자는 멤버로 정의)
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) friend 선언 사용 금지, 4) 함수, 변수 및 수식의 사용을 최소화
	// dynamic_cast를 위해서는 Base 클래스는 한 개 이상의 virtual method를 가져야 함
//	W4 w0(1, 2), w1(3, 4), w2;
//	V4& v0 = w0;
//	V4& v1 = w1;
//	V4 v2 = w2;
//	w2.Print(); // 출력: 0, 0

	try {
		//		W4 w3 = dynamic_cast<W4&>(v0) + dynamic_cast<W4&>(v1); // {1+3, 2+4}
		//		w3.Print();	// 출력: 4, 6

		//		W4 w4 = dynamic_cast<W4&>(v0) + dynamic_cast<W4&>(v2); // catch로 Bad dynamic_cast!(Windows)나 std::bad_cast(Mac) 출력
		//		w4.Print();
	}

	catch (std::exception& e) {
		std::cout << e.what() << std::endl;;
	}

	std::cout << "\n### 5 ###" << std::endl;
	//5. 아래와 같이 동작하는 X5 클래스 템플릿을 정의하라. (t1은 크기가 5인 int형 벡터(std::vector)로 모두 0으로 초기화, t2는 크기가 10인  char형 벡터(std::vector)로 모두 '*'으로 초기화)
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화
//	X5<int, 5> t1;
//	X5<char, 10> t2('*');
//	t1.Print(); // 출력: 0, 0, 0, 0, 0,
//	t2.Print(); // 출력: *, *, *, *, *, *, *, *, *, *,
	try {
		//		t1.Set(10, 2);	// 2번 index를 10으로 수정
		//		t2.Set('?', 9);	// 9번 index를 '?'로 수정
		//		t2.Set('+', 10);	// 10번 index의 요소는 없으므로, catch로 "index exception" 출력, at 메소드 사용불가
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl; // "index exception" 출력
	}
	//	t1.Print(); // 출력: 0, 0, 10, 0, 0,
	//	t2.Print(); // 출력: *, *, *, *, *, *, *, *, *, ?,


	std::cout << "\n### 6 ###" << std::endl;
	//6. 아래와 같이 두 함수(f1, f2와 같은 프로토타입(prototype))의 곱셈을 수행하는 함수를 반환하는 Fn6 함수를 정의하라.
	// 1) 함수, 변수 및 수식의 사용을 최소화
	auto f1 = [](double x1, double x2) { return (x1 + x2) / 2.; };
	auto f2 = [](double x1, double x2) { return x1 > x2 ? x1 : x2; };
	//	auto f = Fn6(f1, f2);	// ((x1 + x2)/2.)*(x1 > x2 ? x1 : x2)를 반환하는 함수
	//	std::cout << f(2, 5) << std::endl; // 출력: 17.5

	std::cout << "\n### 7 ###" << std::endl;
	// 7. 위에 정의된 struct Line으로 아래와 같이 동작하는 operator <<, EraseInvalid(Start<End가 아니면 제거)와  UnionLines(Start는 작은 값, End는 큰 값으로 누적)를 정의하라.
	// 1) EraseInvalid 함수는 최대한 간소화하여 작성(Lambda 함수가 포함된 한 개의 문장), 2) UnionLines 함수는 최대한 간소화하여 작성(크기가 0인 경우를 확인하는 코드와 Lambda 함수가 포함된 한 개의 리턴)
	// 3) EraseInvalid, UnionLines는 조건문, 반복문의 사용을 최소화하여 표준 함수를 사용할 것
	srand((unsigned)time(0));
	std::vector<Line> lines;
	//	std::cout << Line(3, 5) << std::endl; // 출력: (3, 5)

	for (int i = 0; i < 10; ++i) {
		lines.push_back(Line(rand() % 100, rand() % 100));
	}

	//	for (auto e : lines) std::cout << e << ", "; // 출력 예: (77, 26), (1, 4), (96, 1), (57, 80), (61, 33), (76, 51), (37, 57), (22, 25), (27, 61), (66, 57),
	std::cout << std::endl;
	//	EraseInvalid(lines);
	//	for (auto e : lines) std::cout << e << ", "; // 출력 예: (1, 4), (57, 80), (37, 57), (22, 25), (27, 61),
	std::cout << std::endl;
	//	Line l = UnionLines(lines);
	//	std::cout << l << std::endl;	// 출력 예: (1, 80)
}