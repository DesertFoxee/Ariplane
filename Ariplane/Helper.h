#pragma once
#ifndef HELPER_H
#define HELPER_H


#include <math.h>
#include <random>
#include <SFML/Graphics.hpp>

#define PI 3.141592654


namespace Convert {
	inline float convertToRadian(float degree ) {
		return float (degree *(PI/180) );
	}
	inline float convertToDegree(float radian) {
		return float(radian *(180 / PI));
	}
}

namespace Limit {
	template <typename T>
	inline void value(T&value, T min, T max) {
		if (std::is_same<int, T>::value || std::is_same<float, T>::value ||
			std::is_same<double, T>::value) {
			if (value < min) value = min;
			else if (value > max) value = max;
		}
	}

	template <typename T>
	inline void vector(T&value , T min , T max) {
		if (std::is_same<sf::Vector2i, T >::value || std::is_same<sf::Vector2f, T>
			|| std::is_same<sf::Vector2u, T>) {
			if (value.x < min.x) value.x = min.x;
			if (value.x > max.x) value.x = max.x;
			if (value.y < min.y) value.y = min.y;
			if (value.y < max.y) value.y = max.y;
		}
	}
}

namespace Random {
	inline float randomFloatUniform(float min , float max) {
		std::random_device dv;
		std::mt19937 rd(dv());
		std::uniform_real_distribution<float> dist(min, max);
		return dist(rd);
	}
	
	
	inline int randomIntUniform(int min, int max) {
		std::random_device dv;
		std::mt19937 rd(dv());
		std::uniform_int_distribution<> dis(min, max);
		return dis(rd);
	}

	template <typename T>
	inline T randomNormal(T min, T max) {
		if (std::is_same<int, T>::value || std::is_same<float, T>::value ||
			std::is_same<double, T>::value) {
			std::random_device dv;
			std::mt19937 rd(dv());
			std::normal_distribution<> dis((max + min) / 2, (max - min) / 2);
			return (T)dis(rd);
		}
		return (T)0;
	}


}

#endif // !HELPER_H
