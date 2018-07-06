#include "Vec2f.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

void test() {
	const float value = 2.0;
	const float nvalue = -2.0;
	const float zero = 0.0;
	const float infinity = 1.0/0.0;
	const float ninfinity = -1.0/0.0;
	const float notanumber = nanf("");
	const float nnotanumber = -nanf("");

	std::cout << "value = " << value << std::endl;
	std::cout << "nvalue = " << nvalue << std::endl;
	std::cout << "zero = " << zero << std::endl;
	std::cout << "infinity = " << infinity << std::endl;
	std::cout << "ninfinity = " << ninfinity << std::endl;
	std::cout << "notanumber = " << notanumber << std::endl;

	int line = 0;
	for (int xp=0; xp < 7; xp++) {
		for (int yp=0; yp<7; yp++) {
			float x, y;

			switch (xp) {
				case 0: x = value; break;
				case 1: x = nvalue; break;
				case 2: x = zero; break;
				case 3: x = infinity; break;
				case 4: x = ninfinity; break;
				case 5: x = notanumber; break;
				case 6: x = nnotanumber; break;
			} 

			switch (yp) {
				case 0: y = value; break;
				case 1: y = nvalue; break;
				case 2: y = zero; break;
				case 3: y = infinity; break;
				case 4: y = ninfinity; break;
				case 5: y = notanumber; break;
				case 6: y = nnotanumber; break;
			}

			Vec2f v(x, y);
			Vec2f n = v.normal();

			std::cout << "(" << v.x << ", "<< v.y << ")\t";
			std::cout << "(" << n.x << ", "<< n.y << ")\n";
			//std::cout << length  << std::endl;
		}
	}
}


int main() {
	test();
	return 0;
}
