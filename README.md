# Roby the Robot — OpenGL Lab

An interactive 3D robot simulation built with C++ and OpenGL/FreeGLUT: a robot standing in a lab
room that you can drive around, watch through a free camera, or see through the robot's own eyes.
This was my first C++ project, coming from a C/Java background.

## What it does

Two windows open side by side:

- **Lab window** — the robot in a room with mixed copper and glass surfaces, lit and rendered in real time
- **Instructions window** — a help panel listing the active control scheme, with clickable UI buttons (lighting toggle, quit, help)

Everything — the robot, its arm/head/body parts, the room, the camera, and the UI widgets — is
its own C++ object, composed hierarchically and driven by keyboard/mouse events routed through a
central `world` object.

### Control modes

Press a number key to switch modes:

| Key | Mode |
|---|---|
| `1` | Drive the robot directly, viewed from a free camera |
| `2` | Move the camera itself, independent of the robot |
| `3` | First-person view through the robot's own eyes |

Once in a mode, the keyboard drives whichever object is active (robot or camera) — see the
in-app **Instructions** window for the full key list for each mode.

## Building & running

This is a Visual Studio C++ project (`ConsoleApplication5.sln`) targeting Windows, using
[FreeGLUT](http://freeglut.sourceforge.net/) for windowing/OpenGL.

1. Install FreeGLUT (e.g. via [vcpkg](https://vcpkg.io): `vcpkg install freeglut`) and make sure
   Visual Studio can find its headers/libs.
2. Open `ConsoleApplication5.sln` in Visual Studio.
3. Build and run (`F5`) — the lab and instructions windows should open automatically.

## Project layout

| File(s) | Role |
|---|---|
| `world.h/.cpp` | Top-level state machine — owns the robot, room, and camera; routes input by mode |
| `robot.h/.cpp`, `robotPart.h/.cpp` | The robot and its composable parts |
| `arm.h/.cpp`, `arm_part.h/.cpp`, `head.h/.cpp`, `body.h/.cpp` | Individual robot components |
| `camra.h/.cpp` | Free/first-person camera |
| `room.h/.cpp` | The lab environment (surfaces, lighting) |
| `instractionWindow.h/.cpp`, `button.h/.cpp`, `colorButton.h/.cpp`, `powerButton.h/.cpp`, `text.h/.cpp` | The instructions/UI window and its widgets |
| `matrialList.h/.cpp`, `utility.h/.cpp` | Shared materials and helpers |
| `robotProject.cpp` | Entry point — wires up both GLUT windows and their callbacks |

## License

MIT — see [LICENSE](LICENSE).
