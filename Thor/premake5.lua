project "Thor"
    kind ("SharedLib")
    language ("C")
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {"**.h", "**.c"}
    links {
        "glfw3",
        "cglm",
        "glad",
        "Cocoa.framework",
        "OpenGL.framework",
        "IOKit.framework",
        "stb_image"
     }
     libdirs {
        "%{wks.location}/vendor/glfw/lib-%{cfg.architecture}"
     }
     includedirs {
         "%{wks.location}",
         "%{wks.location}/vendor/glfw/include",
         "%{wks.location}/vendor/glad/include",
         "%{wks.location}/vendor/stb_image"
     }