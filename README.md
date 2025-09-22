# Minecraft-Xbox-360-Decompilation


## What Is This Project?

Formally referred to as **LCE Rewritten or simply Rewritten**

This is a **Functional** Decompilation of the Xbox 360 edition of Minecraft Legacy (Title Update 2), also known as **Legacy Console Edition (LCE) or just Legacy.**

A Function Decomp aims to recreate a compilable equivalent of the original source that is not necessary byte matching with the original binary but functionally equivalent.

## What Is Minecraft Legacy Console Edition?
Minecraft for legacy consoles was a version of Minecraft ported to consoles by [4J Studios][4j].

This version of the game was discontinued around 2019 and was replaced by the **Bedrock Edition.**

## How Do I Help?
This project was abbandoned by me a while ago, i'm reving it up again, i don't know for how long i'll keep it again, so i wont promise anything, it's just a side project i'd say.

Theres a Discord Server it is inactive tho, but if you wanna join here it is

Link: [https://discord.com/invite/mm3PsUYvsg](https://discord.com/invite/mm3PsUYvsg)


## How to Build
So, to build the project you will need some [stuff][Stuff You Need], like the XDK version v2.0.21119, from that you will need the libs, headers, and the compiler + linker.
Copy: **XDK/include**-**XDK/lib**-**XDK/bin** into ./Compiler folder, there are other headers, it's kinda weird maybe i'll write some script to extract later (i'm the only one who is compiling it so i don't care for now :} )
A CMake Toolchain has been made to be able to use the compiler with CMake, so that's nice :}.
you need Windows to run the compiler, if you want to build it on Linux or Mac you will need a way to run the tools, like Wine, i can't help with that for now.

- TODO, add the steps here lol

## Stuff You Need
Some of the stuff are not strictly needed, but if you want to contribute you will need them.

- The game. With Title Update 2, to get the assets
- Ghidra, or IDA Pro with xex loader plugins
- for those i need a Patched .xex of the TU2 (so XexTool baseGame.xex tu2.xexp)
- The XDK v2.0.21119
- CMake (i guess that's obvious)


[4j]: https://www.4jstudios.com
[Todo]: https://github.com/AleBello7276/MC-LCE-Rewritten#to-do-list
