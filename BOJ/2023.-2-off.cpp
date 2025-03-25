/*             Object-Oriented Programming, Final exam (2023-2, CSE103-00)                       */
// Write your answers in Korean or English(����� �ѱ��� �Ǵ� ����� �ۼ��Ͻÿ�).

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


// �а�:				, �й�:				, ����:        

/////////// ��� ����
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
/////////// ��� ��

int main() {
	// ���� ���� ��� ����
	// ä�� ����:		1. �־��� ���� ������ �����ϸ� ����
	//				2. ����(main �Լ��� ����)�� �����ϸ� ���� 
	//				3. �Ϲ����� ������ �Ұ����� ��� 0�� ó�� �Ǵ� ����(�Ϲ����� �Է¿� ���� ó�� ��)
	//				4. �������� ����� ����Ȯ�� ��� ����(��, &&�� ����� ��ġ�� &�� ��� ��)
	//				5. �ʿ���� �Ķ���ͳ� ��ȯ�� ������ ����
	//				6. ������� �ڵ� ���ۿ� ���� ������ ������ 0�� ó��
	//				7. �ּ� �κ��� ä������ ����(main�� ���۵� �ּ����� ������� ������ ä���ϱ� ����)



	std::cout << "\n### 1 ###" << std::endl;
	// 1. �Ʒ��� ���� �����ϴ� X1 Ŭ������ �����ϰ�, << ������(non member)�� overloading�϶�.
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) friend ���� ��� ����, 4) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	X1 x1, x2(5.3);
//	const X1 x3(7.2);
//	std::cout << x1 << ", " << x2 << ", " << x3 << std::endl;		// ���: 0, 5.3, 7.2, 


	std::cout << "\n### 2 ###" << std::endl;
	// 2. �Ʒ��� ���� �����ϴ� B2, D2 Ŭ������ �����϶�. 
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� public ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	D2 d1, d2(2.5, 3.2);
//	std::cout << d1.B2::x << ", " << d1.x << ", " << d2.B2::x << ", " << d2.x << std::endl; // ���: 0, 0, 2.5, 3.2

	std::cout << "\n### 3 ###" << std::endl;
	// 3. �Ʒ��� ���� �����ϴ� B31, B32, D3 Ŭ������ �����϶�.
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) friend ���� ��� ����, 4) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	B31* pB31 = new D3(1, 0);
//	B32* pB32 = new D3(3, 2);
//	static_cast<B31>(*pB31).Print();	// ���: 1
//	static_cast<B32>(*pB32).Print();	// ���: 2
//	pB31->Print();	// ���: 1, 0,
//	pB32->Print();	// ���: 3, 2, 
	std::cout << std::endl;
	//	delete pB31;		// ���������� �����ؾ� ��
	//	delete pB32;		// ���������� �����ؾ� ��

	std::cout << "\n### 4 ###" << std::endl;
	// 4. �Ʒ��� ���� �����ϴ� V4, W4 Ŭ������ �����϶�.(+ �����ڴ� ����� ����)
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) friend ���� ��� ����, 4) �Լ�, ���� �� ������ ����� �ּ�ȭ
	// dynamic_cast�� ���ؼ��� Base Ŭ������ �� �� �̻��� virtual method�� ������ ��
//	W4 w0(1, 2), w1(3, 4), w2;
//	V4& v0 = w0;
//	V4& v1 = w1;
//	V4 v2 = w2;
//	w2.Print(); // ���: 0, 0

	try {
		//		W4 w3 = dynamic_cast<W4&>(v0) + dynamic_cast<W4&>(v1); // {1+3, 2+4}
		//		w3.Print();	// ���: 4, 6

		//		W4 w4 = dynamic_cast<W4&>(v0) + dynamic_cast<W4&>(v2); // catch�� Bad dynamic_cast!(Windows)�� std::bad_cast(Mac) ���
		//		w4.Print();
	}

	catch (std::exception& e) {
		std::cout << e.what() << std::endl;;
	}

	std::cout << "\n### 5 ###" << std::endl;
	//5. �Ʒ��� ���� �����ϴ� X5 Ŭ���� ���ø��� �����϶�. (t1�� ũ�Ⱑ 5�� int�� ����(std::vector)�� ��� 0���� �ʱ�ȭ, t2�� ũ�Ⱑ 10��  char�� ����(std::vector)�� ��� '*'���� �ʱ�ȭ)
	// 1) �����ڸ� overloading���� ����, 2) ������ ����� private ���� ����, 3) �Լ�, ���� �� ������ ����� �ּ�ȭ
//	X5<int, 5> t1;
//	X5<char, 10> t2('*');
//	t1.Print(); // ���: 0, 0, 0, 0, 0,
//	t2.Print(); // ���: *, *, *, *, *, *, *, *, *, *,
	try {
		//		t1.Set(10, 2);	// 2�� index�� 10���� ����
		//		t2.Set('?', 9);	// 9�� index�� '?'�� ����
		//		t2.Set('+', 10);	// 10�� index�� ��Ҵ� �����Ƿ�, catch�� "index exception" ���, at �޼ҵ� ���Ұ�
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl; // "index exception" ���
	}
	//	t1.Print(); // ���: 0, 0, 10, 0, 0,
	//	t2.Print(); // ���: *, *, *, *, *, *, *, *, *, ?,


	std::cout << "\n### 6 ###" << std::endl;
	//6. �Ʒ��� ���� �� �Լ�(f1, f2�� ���� ������Ÿ��(prototype))�� ������ �����ϴ� �Լ��� ��ȯ�ϴ� Fn6 �Լ��� �����϶�.
	// 1) �Լ�, ���� �� ������ ����� �ּ�ȭ
	auto f1 = [](double x1, double x2) { return (x1 + x2) / 2.; };
	auto f2 = [](double x1, double x2) { return x1 > x2 ? x1 : x2; };
	//	auto f = Fn6(f1, f2);	// ((x1 + x2)/2.)*(x1 > x2 ? x1 : x2)�� ��ȯ�ϴ� �Լ�
	//	std::cout << f(2, 5) << std::endl; // ���: 17.5

	std::cout << "\n### 7 ###" << std::endl;
	// 7. ���� ���ǵ� struct Line���� �Ʒ��� ���� �����ϴ� operator <<, EraseInvalid(Start<End�� �ƴϸ� ����)��  UnionLines(Start�� ���� ��, End�� ū ������ ����)�� �����϶�.
	// 1) EraseInvalid �Լ��� �ִ��� ����ȭ�Ͽ� �ۼ�(Lambda �Լ��� ���Ե� �� ���� ����), 2) UnionLines �Լ��� �ִ��� ����ȭ�Ͽ� �ۼ�(ũ�Ⱑ 0�� ��츦 Ȯ���ϴ� �ڵ�� Lambda �Լ��� ���Ե� �� ���� ����)
	// 3) EraseInvalid, UnionLines�� ���ǹ�, �ݺ����� ����� �ּ�ȭ�Ͽ� ǥ�� �Լ��� ����� ��
	srand((unsigned)time(0));
	std::vector<Line> lines;
	//	std::cout << Line(3, 5) << std::endl; // ���: (3, 5)

	for (int i = 0; i < 10; ++i) {
		lines.push_back(Line(rand() % 100, rand() % 100));
	}

	//	for (auto e : lines) std::cout << e << ", "; // ��� ��: (77, 26), (1, 4), (96, 1), (57, 80), (61, 33), (76, 51), (37, 57), (22, 25), (27, 61), (66, 57),
	std::cout << std::endl;
	//	EraseInvalid(lines);
	//	for (auto e : lines) std::cout << e << ", "; // ��� ��: (1, 4), (57, 80), (37, 57), (22, 25), (27, 61),
	std::cout << std::endl;
	//	Line l = UnionLines(lines);
	//	std::cout << l << std::endl;	// ��� ��: (1, 80)
}