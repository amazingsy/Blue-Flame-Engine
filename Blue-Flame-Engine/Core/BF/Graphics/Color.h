#pragma once
#include <iostream>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API Color
		{
			public:
				float r, g, b, a;

				Color();
				Color(float value);
				Color(float r, float g, float b, float a);
				~Color();

				Color Normalize() const;

				friend BFE_API Color operator+(const Color& left, const Color& right);
				friend BFE_API Color operator-(const Color& left, const Color& right);
				friend BFE_API Color operator*(const Color& left, const Color& right);
				friend BFE_API Color operator/(const Color& left, const Color& right);

				Color& operator+=(const Color& right);
				Color& operator-=(const Color& right);
				Color& operator*=(const Color& right);
				Color& operator/=(const Color& right);

				bool operator>(const Color& right);
				bool operator>=(const Color& right);
				bool operator<(const Color& right);
				bool operator<=(const Color& right);

				bool operator==(const Color& right);
				bool operator!=(const Color& right);

				#include"PredefinedColors.h"

				friend BFE_API std::ostream& operator<<(std::ostream& os, const Color& color);
		};
	}
}