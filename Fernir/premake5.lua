project "Fernir"
    kind ("ConsoleApp")
    language ("C++")
    cppdialect ("C++17")
	staticruntime ("off")
    
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {"**.h", "**.cpp"}
    links {
        "Thor"
     }
     includedirs {
        "%{wks.location}",
        "%{wks.location}/vendor/glfw/include",
        "%{wks.location}/vendor/glad/include",
        "%{wks.location}/vendor/stb_image"
     }