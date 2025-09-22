# Rewritten CMakeLists.txt
#
# those are the static libs that TU2 uses, i got those using `XexTool -l`
#Static Libraries
#0) XAPILIB        v2.0.21119.0
#1) D3D9           v2.0.21119.0
#2) XGRAPHC        v2.0.21119.0
#3) XBOXKRNL       v2.0.21119.0
#4) XNET           v2.0.21119.0
#5) XAUDIO2        v2.0.21119.0
#6) XAPOBA         v2.0.21119.0
#7) XACT3          v2.0.21119.0
#8) X3DAUD         v2.0.21119.0
#9) XMCORE         v2.0.21119.0
#0) LIBCPMT        v2.0.11886.0
#1) XUIRUN         v2.0.21119.0
#2) XUIRNDR        v2.0.21119.0
#3) XUIHTM         v2.0.21119.0
#4) XONLINE        v2.0.21119.0
#5) QNETXA2        v2.0.21119.0
#6) XRNSS          v2.0.21119.0
#7) XRNMS          v2.0.21119.0
#8) XSOCPST        v2.0.21119.0
#9) XPARTY         v2.0.21119.0
#0) NUI            v2.0.21119.0
#1) ST             v2.0.21119.0
#2) D3DX9          v2.0.21119.0
#3) XHV2           v2.0.21119.0
#4) LINK           v10.0.11886.0
#5) C2             v16.0.11886.0
#6) C1             v16.0.11886.0

 
cmake_minimum_required(VERSION 3.29)

project(Rewritten)

include(Compiler/XMsvc.cmake)
message(STATUS "COMPILER: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

# some libs have shortened names to fit the character limit i guess
set(TU2_LIBS 
	xapilib.lib
	D3D9.lib
	xgraphics.lib # XGRAOHC is short for xgraphics
	XBOXKRNL.lib
	XNET.lib
	XAUDIO2.lib
	XAPOBase.lib # XAPOBA is short for XAPOBase
	XACT3.lib
	x3daudio.lib # X3DAUD is short for X3DAudio
	XMCORE.lib
	LIBCPMT.lib
	XUIRUN.lib
	xuirender.lib # XUIRNDR is short for XUIRender
	xuihtmld.lib	# XUIHTM is short for XUIHtml
	XONLINE.lib
	qnetxaudio2.lib	# QNETXA2 is short for qnetxaudio2
	#XRNSS.lib		not sure, i can't find this oneq
	XRNMS.lib
	xsocialpost.lib	# XSOCPST is short for xsocialpost
	XPARTY.lib
	nuiapi.lib	# NUI, i guess it is nuiapi
	ST.lib
	D3DX9.lib
	XHV2.lib
)


set(SRC
	src/main.cpp
	src/globals.h
)



add_executable(Rewritten test.cpp test2.c)

target_link_libraries(Rewritten PRIVATE ${TU2_LIBS})
