#pragma once

#include <memory>
namespace SWRD
{
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> Create(Args&& ... args) 
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

#define BIT(x) 1 << x

	enum class OSPlatform
	{
		None = 0,
		Windows = 1,
		Linux = 2,
		Mac = 3
	};

#ifdef PLATFORM_WINDOWS
	static OSPlatform Platform = OSPlatform::Windows;
#endif // PLATFORM_WINDOWS

#ifdef PLATFORM_LINUX
	static OSPlatform Platform = OSPlatform::Linux;
#endif // PLATFORM_LINUX

#ifdef PLATFORM_MAC
	static OSPlatform Platform = OSPlatform::Mac;
#endif // PLATFORM_MAC


#ifdef USE_ASSERT
	#define RD_CORE_ASSERT(x, ...) {if(!x) {__debugbreak();}} 
	#define RD_USER_ASSERT(x, ...) {if(!x) {__debugbreak();}} 

#else 
	#define RD_CORE_ASSERT(x, ...) 
	#define RD_USER_ASSERT(x, ...) 
#endif // USE_ASSERT



}