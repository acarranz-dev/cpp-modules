#ifndef vect2_HPP
#define vect2_HPP

#include <iostream>

class vect2 {
private:
	int _x;
	int _y;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2 &other);
	vect2 &operator=(const vect2 &other);
	~vect2();

	int &operator[](unsigned int index);
	vect2 operator+(const vect2 &other) const;
	vect2 operator-(const vect2 &other) const;
	vect2 operator*(int nb) const;
	friend vect2 operator*(int nb, const vect2& v);
	bool operator==(const vect2& other) const;

};

std::ostream &operator<<(std::ostream &os, vect2 &fixed);

#endif
