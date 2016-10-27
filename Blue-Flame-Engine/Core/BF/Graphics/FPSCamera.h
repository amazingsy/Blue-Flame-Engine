#pragma once
#include "Camera.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API FPSCamera : public Camera
		{
			private:
				float speed;

			public:
				FPSCamera(const Math::Matrix4& projectionMatrix);
				~FPSCamera();

				void Update();
		};
	}
}