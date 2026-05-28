# OpenGL 2D Engine

A small 2D rendering engine built with OpenGL and C++17, featuring a Snake game demonstration. This project showcases sprite rendering, animations, and basic 2D game mechanics.

## Features

The engine provides a lightweight framework for 2D rendering with:
* Sprite rendering and sprite sheet support
* Sprite sheet animations
* Camera system for 2D scenes
* Material and shader management
* Input handling
* Tick-based update system

### Snake Game (WIP)

A classic Snake game implementation demonstrating the engine's capabilities. The game is currently under development.

<img width="1015" height="788" alt="image" src="https://github.com/user-attachments/assets/1b9a8a6f-f680-45b9-9f99-cc4b41f15894" />

---

## Prerequisites & Dependencies

To compile and run this project on Linux, you will need a C++17 compliant compiler (`gcc` or `clang`), `cmake`, and the following development libraries:

* **OpenGL** (Core Graphics Drivers)
* **GLEW** (Extension Wrangler)
* **GLFW** (Windowing & Input)
* **FreeGLUT** (Utility Toolkit)
* **FreeImage** (Image Loading)
* **GLM** (OpenGL Mathematics)

### Dependency Installation

#### CachyOS / Arch Linux
Most libraries are available via the standard package manager (`pacman`). Note that `freeimage` must be installed via the Arch User Repository (AUR) using an AUR helper like `paru` or `yay`.

```bash
# Install core build tools and standard repositories libraries
sudo pacman -S base-devel cmake glew glfw freeglut glm

# Install FreeImage from the AUR (Do NOT run with sudo)
paru -S freeimage
# OR:
yay -S freeimage
```

#### Ubuntu / Debian

If setting up on a Debian-based distribution, use `apt`:

```bash
sudo apt update
sudo apt install build-essential cmake libglew-dev libglfw3-dev freeglut3-dev libfreeimage-dev libglm-dev
```

---

## Building the Project

You can build the project either directly through the terminal or by using Visual Studio Code.

### Method 1: Via Terminal (Standard CMake)

From the project root directory, run the following commands to configure and compile:

```bash
# Create and enter the build directory
mkdir build && cd build

# Configure the project using native Linux compilers
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Compile the executable
make
```

### Method 2: Via VS Code (Recommended)

1. Open the project folder in VS Code.

2. Install the following extensions:
   - **C/C++** (by Microsoft)
   - **CMake Tools** (by Microsoft)

3. Open the Command Palette (`Ctrl + Shift + P`) and run **CMake: Select a Kit**. Choose your native host compiler (e.g., GCC or Clang). Do **NOT** select `clang-cl`.

4. Run **CMake: Configure**.

5. Click the **Build** button on the bottom blue status bar (or press `F7`).

---

## Running the Application

There are two critical platform constraints to keep in mind when running this application on modern Linux systems:

1. **Working Directory**: The application loads assets (Shaders, Textures) using relative paths. It must be executed with the project root folder as the working directory.

2. **Wayland Display Server**: If you are running a Wayland-based desktop (default on CachyOS), GLEW requires an X11 context to initialize properly (`No GLX display` error). You must pass the `GLFW_PLATFORM=x11` environment variable to force XWayland compatibility.

### Running via Terminal

Always run the executable from the project root directory (not from inside the `build` folder):

```bash
# Ensure you are in the project root folder
cd /path/to/OpenGL-2D

# Launch the app forcing X11 context compatibility
GLFW_PLATFORM=x11 ./build/OpenGL_2D
```

### Running via VS Code (Automated Setup)

To make clicking the Play **[▷]** button in VS Code work seamlessly without errors, the project is configured with `.vscode/settings.json` to automatically:
- Set the working directory to the project root
- Force X11 context compatibility for GLFW

Once configured, clicking **Launch / Play** on the bottom status bar will properly route the assets paths and handle display window contexts automatically.

---

## Project Structure

```
OpenGL-2D/
├── Source/
│   ├── Core/          # Engine core systems
│   │   ├── Buffers/   # OpenGL buffer management
│   │   ├── Includes/  # Common headers
│   │   └── Utils/     # Utility functions
│   └── Game/          # Game implementations
│       ├── Examples/  # Example projects
│       └── Snake/     # Snake game (WIP)
├── Resources/
│   ├── Shaders/       # GLSL shader files
│   ├── Textures/      # Texture assets
│   └── Settings/      # Configuration files
└── build/             # Build output directory
```

---

## Dependencies

[freeglut](http://freeglut.sourceforge.net/) | [glew](http://glew.sourceforge.net/) | [GLFW](http://www.glfw.org/) | [FreeImage](http://freeimage.sourceforge.net/)
