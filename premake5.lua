workspace "softwareRenderer"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"        
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "softwareRenderer/vendor/GLFW/include"
IncludeDir["Glad"] = "softwareRenderer/vendor/Glad/include"
IncludeDir["spdlog"] = "softwareRenderer/vendor/spdlog/include"

group "Dependencies"
    include "softwareRenderer/vendor/GLFW"
    include "softwareRenderer/vendor/Glad"
group ""


project "softwareRenderer"
    location "softwareRenderer"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    --项目所含文件（属于项目的内容，而非第三方库）
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    --include路径
    includedirs
    {
        "softwareRenderer/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.spdlog}"
    }

    links
    {
        "GLFW",
        "Glad",        
        "opengl32.lib"
    }


    filter "system:windows"
        systemversion "10.0"
        defines
        {
            "PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE",
            "_CRT_SECURE_NO_WARNINGS"
        }

    filter "configurations:Debug"
		defines "RENDERER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RENDERER_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "RENDERER_DIST"
		runtime "Release"
		symbols "on"

project "testDemo"
    location "testDemo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "softwareRenderer/src",
        "%{IncludeDir.spdlog}"
    }

    links
    {
        "softwareRenderer"
    }

    filter "system:windows"
        systemversion "10.0"
        defines
        {
            "PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
		defines "RENDERER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RENDERER_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "RENDERER_DIST"
		runtime "Release"
		symbols "on"
