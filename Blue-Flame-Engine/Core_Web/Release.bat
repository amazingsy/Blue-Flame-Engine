CALL mkdir ..\Output\Core\Web\Release\
CALL emcc ^
 -I "../Dependency/FreeImage/Source" ^
 "../Core/BF/Application/Window.cpp" ^
 "../Core/BF/Math/Matrix4.cpp" ^
 "../Core/BF/IO/FileReader.cpp" ^
 "../Core/BF/IO/ImageReader.cpp" ^
 "../Core/BF/Graphics/API/Context.cpp" ^
 "../Core/BF/Graphics/API/Shader.cpp" ^
 "../Core/BF/Graphics/API/VertexBuffer.cpp" ^
 "../Core/BF/Graphics/API/BufferLayout.cpp" ^
 "../Core/BF/Graphics/API/Texture2D.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLShader.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLVertexBuffer.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLTexture2D.cpp" ^
 "../Core/BF/Platform/API/OpenGL/Context/WEBGLContext.cpp" ^
 "../Core/BF/Platform/Web/WEBWindow.cpp" ^
 "../Dependency/FreeImage/Dist/em/Release/FreeImage.bc" ^
 -D BF_PLATFORM_WEB ^
 -std=c++11 ^
 -O0 ^
 -o ../Output/Core/WebGL/Release/Core.bc