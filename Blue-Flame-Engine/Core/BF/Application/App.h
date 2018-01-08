#pragma once
#ifdef BF_PLATFORM_WINDOWS
#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined(BF_PLATFORM_LINUX)
#include "BF/Platform/Linux/LXEngineEntryPoint.h"
#elif defined(BF_PLATFORM_WEB)
#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined(BF_PLATFORM_ANDROID)
#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/Application/Layers/LayerManager.h"
#include "BF/Application/SceneManager.h"
#include "BF/Graphics/API/Context.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API App
		{
			friend class BF::Engine;

#ifdef BF_PLATFORM_WINDOWS
			friend class BF::Platform::Windows::WINEngineEntryPoint;
#elif defined(BF_PLATFORM_LINUX)
			friend class BF::Platform::Linux::LXEngineEntryPoint;
#elif defined(BF_PLATFORM_WEB)
			friend class BF::Platform::Web::WEBEngineEntryPoint;
#elif defined(BF_PLATFORM_ANDROID)
			friend class BF::Platform::Android::ANDEngineEntryPoint;
#endif

		private:
			SceneManager sceneManager;
			BF::Application::Layers::LayerManager layerManager;

			BF::System::Timer frameTimer;
			BF::System::Timer fixedUpdateTimer;
			BF::System::Timer frameRateTimer;

			bool initialized;
			bool loaded;
			int fixedUpdateTicks;

		public:
			App();
			~App();

			virtual void Initialize();
			virtual void Load();
			virtual void Update();
			virtual void Render();

			inline SceneManager& GetSceneManager() { return sceneManager; }
			inline BF::Application::Layers::LayerManager& GetLayerManager() { return layerManager; }
		};
	}
}