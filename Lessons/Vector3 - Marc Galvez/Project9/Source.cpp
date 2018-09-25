#include <iostream>

using namespace std;

template <class VECT>
class Vector3 {
public:
	
	VECT x, y, z;

	Vector3(){}
	Vector3(const VECT &x, const VECT &y, const VECT &z): x(x), y(y), z(z) {}

	Vector3(const Vector3 &vec): x(vec.x), y(vec.y), z(vec.z){}

	Vector3 operator+(const Vector3 &vec) const {
		return Vector3(x + vec.x, y + vec.y, z - vec.z);
	}

	Vector3 operator-(const Vector3 &vec) const {
		return Vector3(x - vec.x, y - vec.y, z - vec.z);
	}

	Vector3 operator+=(const Vector3 &vec) {
		x += vec.x; y += vec.y; z += vec.z;
		return *this;
	}

	Vector3 operator-=(const Vector3 &vec) {
		x -= vec.x; y -= vec.y; z -= vec.z;
		return *this;
	}

	Vector3 operator=(const Vector3 &vec) {
		x = vec.x; y = vec.y; z = vec.z;
		return *this;
	}

	bool operator==(const Vector3 &vec) const {
		return(x == vec.x && y == vec.y && z == vec.z);
	}

	Vector3 is_normalized() const { //Te devuelve un vector, y con él puedes hacer cosas
		VECT root = (sqrt(x*x) + (y*y) + (z*z));
		return Vector3(x / root, y / root,  z / root);
	}

	Vector3 normalize() { //Normaliza al vector;
		VECT root = (sqrt(x*x) + (y*y) + (z*z));
		x = x / root; y = y / root; z = z / root;
		return * this;
	}

	Vector3 zero() {
		x = y = z = 0.0f;
		return *this;
	}

	bool is_zero() const {
		return (x == 0.0f && y == 0.0f && z == 0.0f);
	}
	VECT distance_to(const Vector3 &vec) const {
		return sqrt((x-vect.x) * (x-vec.x) + ((y - vect.y) * (y - vect.y)) + ((z - vect.z) * (z - vect.z)));
	}

};


int main()
{
	Vector3<int> v1(5, 2, 5);
	Vector3<int> v2(9, 9, 2);

	v1.is_zero();
	v1.is_zero();
	system("pause");
}
