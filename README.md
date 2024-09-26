# Minecraft-Xbox-360-Decompilation


## What Is This Project?

Formally referred to as **LCE Rewritten or simply Rewritten**

This is a **Rewrite** (or Decompilation idk lol) of the Xbox 360 edition of Minecraft Legacy, also known as **Legacy Console Edition (LCE) or just Legacy.**



The Decomp will first aim to be as close **as possible** to the original source code but mainly the game behaviors.


## What Is Minecraft Legacy Console Edition?
Minecraft for legacy consoles was a version of Minecraft ported to consoles by [4J Studios][4j].

This version of the game was discontinued around 2019 and was replaced by the **Bedrock Edition.**

## Progress
<p align="center">
  <img src="https://github.com/AleBello7276/Minecraft-Xbox-360-Decompilation/blob/main/img/Bar-V1.png" width="50%" >
</p>


This is the **current Goal**.
## How Do I Help?
You can join the Official Discord Server!

Link: [https://discord.com/invite/mm3PsUYvsg](https://discord.com/invite/mm3PsUYvsg)


## How to Build
This is a oversimplified guide to build the project.
on windows it works 100% since that's what I'm using, on linux and MacOs I don't know, if someone can run the Compiler and Linker EXEs on maybe Wine I think it can still work but I don't know

- First make sure to have a copy of the Xbox 360 XDK downloaded on your machine (I won't provide any guide on how to install it! you'll have to figure it out yourself)
- at the moment we'll just need the folders: bin/ lib/ and include/ also the documentation can be useful, the rest will not be used
- You need to set an Enviroment Varialble called "XEDK" which will be the root folder of the xdk (basically the folder where bin/ lib/ and include/ are located)
- Then just run ``make`` to build the project
- I recommend including the headers found in include/xbox in the IDE you are using, so intellisense will work with those, it will help a lot

## Tools Used
To compare Minecraft's Java beta 1.6.6 code to decompilation, I used:
* [RetroMCP][rmcp]: RetroMCP is a modification of the Minecraft Coder Pack.

---

For reverse engineering the game binaries's, I used: 
* [Ghidra][ghi]: Ghidra is a software reverse engineering (SRE) framework created by the National Security Agency.

---

For loading the .xex along with Ghidra, I used: 
* [XEXLoaderWV][xel]: XEXLoaderWV is a .xex file loader for Ghidra.


[rmcp]: https://github.com/MCPHackers/RetroMCP-Java
[ghi]: https://github.com/NationalSecurityAgency/ghidra
[xel]: https://github.com/zeroKilo/XEXLoaderWV
[4j]: https://www.4jstudios.com
[Todo]: https://github.com/AleBello7276/MC-LCE-Rewritten#to-do-list
