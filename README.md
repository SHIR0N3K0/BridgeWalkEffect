⚠️ Requirements
Unreal Engine 5.6
C++ project (this plugin is not compatible with Blueprint-only projects)

This project focuses on recreating — with a custom implementation — a dynamic traversal mechanic inspired by various games.

It simulates a fragmented structure (road, bridge, or stairs) that behaves as follows:

- When the player approaches, scattered fragments reassemble into their original positions, forming a usable path.
- When the player moves away, the structure deconstructs, and fragments return to a floating state.

This system creates a responsive and visually dynamic environment driven by player proximity.
________________________________________________________________________________________________________________________________________
Development Time

~7 hours

Key focus areas:

- Learning and experimenting with Chaos Physics
- Adapting Chaos to support a controlled reconstruction system (first-time usage)

________________________________________________________________________________________________________________________________________
[![Watch the video](https://github.com/user-attachments/assets/7adaa623-2a8a-426c-8ba1-9fa20e304b70)](https://github.com/user-attachments/assets/356ae664-c7e5-42e5-b274-644a1fc416a3)
________________________________________________________________________________________________________________________________________

## 📥 Download

Download Project 
👉 [Here](https://github.com/SHIR0N3K0/BridgeWalkEffect/releases)

________________________________________________________________________________________________________________________________________

## 🛠️ Setup Guide

1. Import or create a mesh.
2. Place it in the level.
3. Open **Fracture Mode**.
<br><img width="223" height="213" alt="Show_FractureMode" src="https://github.com/user-attachments/assets/442f1e75-fa09-41c6-b242-6578b1e3fa65" /> 
4. Click on **New** while your **mesh is still selected** and save it wherever you want.
<br><img width="237" height="83" alt="Show_NewGC" src="https://github.com/user-attachments/assets/c87a7ce0-8db3-47e1-96bd-7454f6f8fe04" />
5. Now that you have your Geometry Collection(GC) you can choose the king of fracture you want, here either **Uniform** or **Cluster**.
<br><img width="234" height="104" alt="Capture d&#39;écran 2026-03-27 101836" src="https://github.com/user-attachments/assets/b14f0104-e06a-472a-8868-a1dabaff4c18" />
<br><img width="403" height="55" alt="Capture d&#39;écran 2026-03-27 101844" src="https://github.com/user-attachments/assets/4563cba1-dea8-4e8b-852e-36cc6d6930bc" />
6. You now need to get the parts as mesh, for that you need to select all the parts in the **Fracture Hierarchy Window**, then click on **ToMesh** and **Convert**, you
can now choose the destination folder. (You can delete all the part created on the map just keep the GC)
<br>![Show_SelectPart](https://github.com/user-attachments/assets/d478f3ae-e226-4a72-bbe2-401dac5ac0e2)
<br><img width="678" height="262" alt="Show_ConvertToMesh" src="https://github.com/user-attachments/assets/9a2a36f9-105a-4f9f-9bbe-8478680b873f" />
7. Now That you have your meshes go to **/All/Plugins/Plugin_WalkingRebuilding/PluginBP** and Open the Data Table **"DT_Meshes"**
<br><img width="836" height="236" alt="Capture d&#39;écran 2026-03-27 110051" src="https://github.com/user-attachments/assets/4cc7cfdb-7211-439e-aaf9-88c6c0819e42" />
8. After opening the Data table **click Add** after adding the new row **Select all mesh part** and drop them in the new Row **Chunk** Variable (Don't forget to
rename Row)
<br><img width="644" height="38" alt="Show_AddRow" src="https://github.com/user-attachments/assets/a96c50d7-c1ab-475c-a8c0-72b3443a7c8c" />
<br>![Show_AddPartsToRow](https://github.com/user-attachments/assets/b958d961-348a-4740-a094-021ad5b6454f)
9. Now in **/All/Plugins/Plugin_WalkingRebuilding/PluginBP** take the **Bp_RoadChunckManager** and drop it on the map
10. After dropping it, go to it's **Detail** and in the **Default Section** select your GC (appear only if the GC is on the Map)
<br><img width="536" height="162" alt="Show_GCVariable" src="https://github.com/user-attachments/assets/2866de61-37c1-49c1-9b1e-2c0bc0edf374" />
<br><img width="564" height="490" alt="Show_GConMap" src="https://github.com/user-attachments/assets/97aea11e-5e15-406c-925e-16c5ea21b706" />
11. Now still in the **Default Section** of the **Bp_RoadChunckManager** you should have a Variable Named **Data Table Row** There you need to give the name
of the Row you added to the Data Table
<br><img width="325" height="27" alt="Capture d&#39;écran 2026-03-27 114141" src="https://github.com/user-attachments/assets/91c9054e-d9ef-43ac-ac95-0ec37d32b1e8" />

Result: You now have a mesh wich rebuilt itself as you Walk over it
