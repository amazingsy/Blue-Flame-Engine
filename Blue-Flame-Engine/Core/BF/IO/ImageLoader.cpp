#include "BF/System/Log.h"
#include "ImageLoader.h"
#include "BF/Graphics/API/Texture.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics::API;

		bool ImageLoader::initialised = false;

		Texture::TextureData* ImageLoader::Load(const string& filename)
		{
			if (!initialised)
			{
				FreeImage_Initialise();
				initialised = true;
			}

			FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

			FIBITMAP* dib = nullptr;

			fif = FreeImage_GetFileType(filename.c_str(), 0);

			if (fif == FIF_UNKNOWN)
				fif = FreeImage_GetFIFFromFilename(filename.c_str());

			if (fif == FIF_UNKNOWN)
				BF_LOG_ERROR("FIF_UNKNOWN");

			if (FreeImage_FIFSupportsReading(fif))
				dib = FreeImage_Load(fif, filename.c_str());

			if (!dib)
				BF_LOG_ERROR("file not found");

			if (!FreeImage_FlipVertical(dib))
				BF_LOG_ERROR("failed to flip image");

			FIBITMAP* bitmap = nullptr;
			bitmap = FreeImage_ConvertTo32Bits(dib);

			Texture::TextureData* textureData = new Texture::TextureData();
			textureData->freeImage_bitmap = bitmap;
			textureData->buffer = FreeImage_GetBits(bitmap);
			textureData->width = FreeImage_GetWidth(bitmap);
			textureData->height = FreeImage_GetHeight(bitmap);

			if ((textureData->buffer == 0) || (textureData->width == 0) || (textureData->height == 0))
				BF_LOG_ERROR("file courrpted");

			if (FreeImage_GetRedMask(bitmap) == 0xff0000)
				FreeImage_SwapRedBlue32(bitmap);

			FreeImage_Unload(dib);
			return textureData;
		}

		void ImageLoader::Unload(Texture::TextureData* textureData)
		{
			FreeImage_Unload(reinterpret_cast<FIBITMAP*>(textureData->freeImage_bitmap));
		}

		void ImageLoader::DeInitialise()
		{
			if (initialised)
				FreeImage_DeInitialise();
		}
	}
}