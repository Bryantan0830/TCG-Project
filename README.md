# Pokemon Battle Arena: 3D Computer Graphics Project

A real-time, interactive **3D Pokemon Battle Arena** built in C++ using **OpenGL** and **GLUT**. This project was developed as part of the **TCG6223 Computer Graphics** course at the Faculty of Information Science and Technology (FIST), Multimedia University.

## 👥 Group Members
*   **Chong Jie Lun** (242UT243V4)
*   **Gan Zi Jin** (242UT243TY)
*   **Chong Tian Wei** (1231303630)

The simulation showcases complex 3D modeling, hierarchical transformations, dynamic animations, particle/lightning rendering techniques, and a interactive turn-based battle interface between two iconic Pokemon: **Magnemite (evolving to Magneton)** and **Umbreon**.

---

## 🎮 Features

### 1. Pokemon Modeling & Hierarchy
*   **Umbreon (Dark Type):**
    *   Constructed using multi-segmented hierarchical models (Head, Ears, Neck, Front/Back Body, Tail, Legs, and Feet).
    *   Smooth sitting-to-standing transition animations.
    *   Custom yellow ring patterns/tattoos and red eyes.
*   **Magnemite & Magneton (Electric/Steel Type):**
    *   Floating/hovering idle animation.
    *   Rotating horseshoe magnets and detailed screws.
    *   **Dynamic Evolution:** Evolves into **Magneton** (three linked Magnemites) when using powerful attacks (Thunderbolt) and devolves back to **Magnemite** for standard moves.

### 2. Interactive Turn-Based Battle System
*   **Turn Cycle:** Progresses dynamically through `PLAYER1_SELECTING` ➔ `PLAYER1_EXECUTING` ➔ `PLAYER2_SELECTING` ➔ `PLAYER2_EXECUTING`.
*   **Custom 2D GUI Overlay:**
    *   **HP Bars:** Dynamic coloring based on health level (Green for high, Yellow for medium, Red for low health).
    *   **Info Cards:** Displays level (Lv.100), gender symbols (♂/♀ rendered in vector graphics), and numerical health values (e.g., `100/100`).
    *   **Skill Selector:** Selection menu displaying available skills for the active Pokemon.
    *   **Status Ticker:** Interactive text box showing battle events, announcements, and match outcomes.
*   **Faint Animations:** When either Pokemon's HP reaches zero, they spin and fall to the ground, ending the game with a victory message.

### 3. Dynamic Skill Effects
*   **Thunder Shock (Electric):** Standard electric shock overlay effect.
*   **Thunderbolt (Electric):** Advanced procedural branching lightning bolts with custom width, segments, random jitter, and transparency.
*   **Feint Attack (Dark):** Dark energy explosion sphere expanding dynamically.
*   **Assurance (Dark):** Multi-layered dark shadow force effect.

---

## 🛠️ Controls

### Camera & World Manipulation
*   **Translation (Move):**
    *   `A` / `D` — Pan Left / Right
    *   `W` / `S` — Move Forward / Backward (Zoom)
    *   `Q` / `E` — Move Up / Down
*   **Rotation:**
    *   `Arrow Keys` — Rotate world view pitch/yaw
    *   `Left Mouse Click + Drag` — Rotate pitch/yaw dynamically
    *   `Right Mouse Click + Drag` — Rotate roll (Z-axis rotation)
*   **Reset:**
    *   `HOME` — Restore default camera settings and angles

### Rendering & Debug Controls
*   `F1` — Toggle shading mode (Solid Shaded / Wireframe)
*   `F2` — Toggle rendering of Coordinate Axes (Red = X, Green = Y, Blue = Z)
*   `F3` — Toggle OpenGL Lighting on / off
*   `ESC` — Exit program

### Battle Controls
*   `I` / `i` — Move Selection Up in the skill menu
*   `K` / `k` — Move Selection Down in the skill menu
*   `SPACEBAR` — Confirm skill selection / proceed

---

## 📋 Skill List

| Pokemon | Skill Name | Type | Damage | Effect / Animation |
| :--- | :--- | :--- | :---: | :--- |
| **Magnemite / Magneton** | Thunder Shock | Electric | 20 HP | Standard shock wave, devolves back to Magnemite. |
| | Thunderbolt | Electric | 35 HP | Advanced branching lightning bolts, evolves into Magneton. |
| **Umbreon** | Feint Attack | Dark | 25 HP | Jumps forward and triggers shadow explosion. |
| | Assurance | Dark | 55 HP | Unleashes a massive dark energy impact block. |

---

## 🚀 Compilation and Execution

### Prerequisites
Make sure your compiler environment has **OpenGL**, **GLU**, and **GLUT** configured:
1.  **MinGW / GCC compiler** (for Windows).
2.  `gl.h`, `glu.h`, and `glut.h` present in your compiler's include directories.
3.  `libopengl32.a`, `libglu32.a`, and `libglut32.a` in the library search path.
4.  `glut32.dll` (or equivalent) in your system path or placed in the same directory as the executable.

### Compilation
Open your terminal (PowerShell, Command Prompt, or Git Bash) inside the project folder and run:

```bash
g++ CGLabmain.cpp CGLabProject.cpp -o PokemonBattle.exe -lopengl32 -lglu32 -lglut32
```

### Execution
Run the compiled executable:

```bash
./PokemonBattle.exe
```

---

## 📁 Repository Structure

*   [CGLabmain.cpp](file:///d:/TCG%20Project/TCG-Project/CGLabmain.cpp) - Main driver program containing window management, input callbacks, display loops, and initialization.
*   [CGLabmain.hpp](file:///d:/TCG%20Project/TCG-Project/CGLabmain.hpp) - Header definitions for the main display and utility classes (Window, World, Viewer, Axis).
*   [CGLabProject.cpp](file:///d:/TCG%20Project/TCG-Project/CGLabProject.cpp) - Primary implementation file containing 3D mesh arrays, drawing functions, skill logic, UI, and animation states.
*   [CGLabProject.hpp](file:///d:/TCG%20Project/TCG-Project/CGLabProject.hpp) - Header declarations for the Pokemon, Skills, and Virtual World classes.
