#ifndef utilities_h
#define utilities_h

#include <iostream>
#include <string>
#include "Point.h"

// This file contains different "small" classes that simplify the code

class PointData {
	public:
		std::string city;
		int population;
		PointData();
};

class Boundary {
	public:
		Point upperleft;
		Point bottomright;

		Boundary() {
			throw "Cannot initialize Boundary without given Points";
		}

		Boundary(Point ul, Point br) {
			if (ul.x > br.x || ul.y > br.y)
				throw "Cannot create Boundary, upperLeft Point must be lower than lowerRight Point";
			
			this->upperleft = ul;
			this->bottomright = br;
		}

		bool isInBounds(Point p) {
			if (p.x < upperleft.x || p.y < upperleft.y)
				return false;

			if (bottomright.x < p.x || bottomright.y < p.y)
				return false;

			return true;
		}

		void print() {
			std::cout << "Upper Left bound: ";
			upperleft.print();
			std::cout << std::endl << "Lower Right bound: ";
			bottomright.print();
			std::cout << std::endl;
		}
};

#endif