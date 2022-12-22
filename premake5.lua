workspace "Odyn"
   configurations { "Debug", "Release" }
   architecture ("ARM64")

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"  
      defines { "NDEBUG" }
      optimize "On"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "vendor/stb_image"
include "vendor/glad"
include "Thor"
include "Fernir"
