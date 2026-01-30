#include "vect2.hpp"
#include <limits>

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int x, int y) : _x(x), _y(y) {}

vect2::vect2(const vect2 &other) : _x(other._x), _y(other._y) {}

vect2 &vect2::operator=(const vect2 &other){
	if (this != &other){
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

vect2::~vect2() {}

int &vect2::operator[](unsigned int index){
	if (index == 0)
		return _x;
	else if (index == 1)
		return _y;
	else
		throw std::out_of_range("Index out of bounds");
}

vect2 vect2::operator+(const vect2 &other) const{
  return vect2(_x + other._x, _y + other._y);
}

vect2 vect2::operator-(const vect2 &other) const{
  return vect2(_x - other._x, _y - other._y);
}

vect2 vect2::operator*(int nb) const{
  return vect2(_x * nb, _y * nb);
}
vect2 operator*(int nb, const vect2& v) {
    return v * nb;
}

bool vect2::operator==(const vect2 &other) const{
	if (this->_x == other._x && this->_y == other._y)
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, vect2 &fixed){
	os << "[" << fixed[0] << ", " << fixed[1] << "]" << std::endl;
	return os;
}
