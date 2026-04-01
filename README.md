🐉 Asciimon: Terminal-Based RPG

A lightweight, terminal-based monster battling RPG written entirely in C. This project was built to demonstrate core computer science concepts, memory management, and modular software architecture.
✨ Technical Features & Architecture

    Custom Data Structures: Utilizes struct and typedef to bundle complex entity data (health, stats, XP) and enum to enforce strict elemental typing (Fire, Water, Grass, etc.).

    Memory Management & Pointers: Implements Call-by-Reference using pointers (* and &) to directly update game states in memory, avoiding inefficient data cloning during the combat loop.

    Matrix Lookups & Game Logic: Features a dynamic 2D Array (float type_chart[][]) serving as a lookup table for elemental damage multipliers, efficiently calculating super-effective and non-effective attacks.

    Modular Codebase: Strictly separates declarations from definitions across multiple .h and .c files (e.g., system.h, battling.c, game.c). Properly manages the extern keyword to prevent linker conflicts and maintain scope.

    Procedural RNG: Leverages <stdlib.h> and <time.h> to seed system time for unpredictable wild encounters and critical hit mechanics.

    Persistent State (File I/O) - TODO: Uses standard C file handling (fopen, fprintf) to save player progress and monster stats locally to the hard drive.

📂 Project Structure
🚀 How to Compile and Run

To play Asciimon locally, you will need a C compiler (like gcc) installed on your system.

    Clone this repository: git clone https://github.com/Sparkening/ASCIImon.git

    Navigate to the project directory:

    Compile the source code: gcc main.c menu.c game.c testing.c system.c battling.c -o asciimon

    Run the game: ./asciimon

🎮 Gameplay

    Explore the 2D terminal map.

    Trigger wild encounters and battle using a turn-based menu.

    Utilize elemental advantages (Water beats Fire) to deal massive damage! - TODO
