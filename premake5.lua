workspace "Pong"
    architecture "x64"
    startproject "Pong"

    configurations{
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["GLFW"] = "vendor/GLFW/include"
    IncludeDir["glad"] = "vendor/glad/include"
    IncludeDir["glm"] = "vendor/glm"
    IncludeDir["spdlog"] = "vendor/spdlog/include"
    
group "Dependencies"
	include "vendor/GLFW"
	include "vendor/glad"
group ""
        
project "Pong"
	location "Pong"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"
	staticruntime "on"
    buildoptions { "/utf-8" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}"
	}

	links{ 
		"GLFW",
		"glad",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"
