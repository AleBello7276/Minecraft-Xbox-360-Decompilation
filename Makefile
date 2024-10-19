# ------------in short---------------

# - make sure to set "XEDK" environment variable to the root folder of the XDK

# - we compile with cl.exe every .cpp into .obj
# - after that we link with link.exe the .obj into a EXE
# - then imagexex.exe create a xex image that the xbox 360 can run
# - all the output files are in build/ :}
# - also add to Vs Code the xdks headers for intellisense


# ------------XDK stuff---------------
XDKPATH := $(subst \,/,$(XEDK))

# Path for XDK Linker, Compiler and ImageXex, libs and header include 
CC := "$(XDKPATH)/bin/win32/cl.exe"
LINKER := "$(XDKPATH)/bin/win32/link.exe"
IX := "$(XDKPATH)/bin/win32/imagexex.exe"
XLIB_DIR := "$(XDKPATH)/lib/xbox"
XINC_DIR := "$(XDKPATH)/include/xbox"
XLIBS := xapilib.lib d3d9ltcg.lib d3dx9.lib xgraphics.lib xboxkrnl.lib xnet.lib xaudio2.lib xact3ltcg.lib x3daudioltcg.lib xmcoreltcg.lib vcomp.lib
# -------------------------------------




# "config" and stuff
PROJECT_NAME := "MinecraftX360"
SRC_DIR := src
OUTPUT_DIR := build
EXE_NAME := $(OUTPUT_DIR)/$(PROJECT_NAME).exe

# generated stuff for make file (grabs all .cpp files and all .obj files)
SOURCES := \
    src/Game.cpp \
    src/Timer.cpp \
    src/Minecraft.cpp \
    src/World/Entity/Entity.cpp \
    src/World/Map/MapColor.cpp \
    src/World/WorldInfo.cpp \
    src/phys/AxisAlignedBB.cpp \
    src/Util/MathHelper.cpp \
    src/Util/Vec3D.cpp \
    src/World/Block/Block.cpp \
    src/World/Block/Material/Material.cpp \
    src/Model/ModelBiped.cpp \
    src/Renderer/ModelRenderer.cpp \
    src/Network/Packet.cpp \
    


OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OUTPUT_DIR)/%.obj)


# FLAGS :}
CFLAGS := /c /Zi /nologo /W3 /WX- /Ox /Os /GL /D NDEBUG /D _XBOX /D LTCG /GF /Gm- /MT /GS- /Gy /fp:fast /fp:except- /I$(XINC_DIR) /Zc:wchar_t /Zc:forScope /GR- /openmp- /Fd"$(BUILD_DIR)/vc100.pdb" 
LFLAGS := /ERRORREPORT:PROMPT /INCREMENTAL:NO /NOLOGO /LIBPATH:$(XLIB_DIR) $(XLIBS) /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /DEBUG /STACK:262144,262144 /OPT:REF /OPT:ICF /LTCG /TLBID:1 /RELEASE /IMPLIB:$(BUILD_DIR)/$(PROJECT_NAME).lib /XEX:NO /OUT:$(EXE_NAME)
IXFLAGS:= /out:$(OUTPUT_DIR)/$(PROJECT_NAME).xex $(EXE_NAME)



$(EXE_NAME): $(OBJECTS)
	$(LINKER) $(OBJECTS) $(LFLAGS) /OUT:$(EXE_NAME)
	$(IX) $(IXFLAGS)


$(OUTPUT_DIR)/%.obj: $(SRC_DIR)/%.cpp | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) /c $< /Fo$@


# --------------create_dirs and remove_dirs_dirs---------------
# this create and clean the folders for obj files inside of build/ for the linker
# I'm sure there's a simpler and better way to automate everything also for $SOURCES too (cmake I guess lol) but I've banged my head enough with this file so, if it works, it works
MCDIRS := \
    build/World/Entity/ \
    build/phys/ \
    build/Util/ \
    build/World/ \
    build/World/Chunk/ \
    build/World/Map/ \
    build/World/Nbt/ \
    build/World/Biome/ \
    build/World/Block/ \
    build/World/Block/Material/ \
    build/Model/ \
    build/Renderer/ \
    build/Java/Math \
    build/Network \
    

.PHONY: create_dirs
create_dirs:
	@for %%d in ($(MCDIRS)) do ( \
		if not exist "%%d" ( \
			mkdir "%%d" && echo Created directory %%d \
		) else ( \
			echo Directory %%d already exists. \
		) \
	)

.PHONY: remove_dirs
remove_dirs:
	@for %%d in ($(MCDIRS)) do ( \
		if exist "%%d" ( \
			rmdir /s /q "%%d" && echo Removed directory %%d \
		) else ( \
			echo Directory %%d does not exist. \
		) \
	)
# --------------create_dirs and remove_dirs_dirs---------------

.PHONY: clean
clean:
	del /F /Q $(OUTPUT_DIR)
    

# Default target
all: clean remove_dirs create_dirs