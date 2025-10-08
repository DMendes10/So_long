# So Long

`so_long` is a small 2D game built with the **MiniLibX** graphical library.
The goal is simple: collect all the items, and reach the exit.

---

## 🧠 Project Overview

This project introduces you to **graphics programming** in C using **MiniLibX**.
You’ll learn how to render images, handle player movement, manage a simple game loop, and detect collisions — all while following the 42 Norm.

---

## ⚙️ Game Objective

Your program displays a window with a **map** read from a `.ber` file.
The player must:

1. Collect all collectibles (`C`).
2. Reach the exit (`E`) once everything is collected.
3. Avoid invalid maps and walls (`1`).

---

## 🕹️ Controls

| Key   | Action        |
| ----- | ------------- |
| W / ↑ | Move up       |
| A / ← | Move left     |
| S / ↓ | Move down     |
| D / → | Move right    |
| ESC   | Quit the game |

Each movement increments the **step counter**, printed in the terminal.

---

## 📄 Map Format

The game map is provided as a `.ber` file and must respect specific rules.

### Example (`map.ber`)

```
111111
1P0C01
1000E1
111111
```

### Legend

| Symbol | Meaning               |
| ------ | --------------------- |
| `1`    | Wall                  |
| `0`    | Empty space           |
| `P`    | Player start position |
| `C`    | Collectible           |
| `E`    | Exit                  |

### Map Requirements

* Must be rectangular.
* Surrounded by walls (`1`).
* Contains exactly **1 player**, at least **1 exit**, and **1 collectible**.
* Only valid characters (`0`, `1`, `C`, `E`, `P`) are allowed.
* The map should have a valid path (every collectible and exit should be reachable).

---

## 🧰 Installation & Usage

### 1. Clone and compile

```bash
git clone https://github.com/DMendes10/So_long.git
cd so_long
make download_minilibx
make 
```

### 2. Run the game

```bash
./so_long maps/map.ber
```

---


## 🧮 Error Handling

Your program should handle:

* Invalid or missing maps.
* Non-rectangular maps.
* Missing player, exit, or collectible.
* File errors (nonexistent, wrong extension).
* Memory leaks and invalid paths.

Error messages are descriptive.

---

## 🌟 Bonus Part

Seen as I really enjoyed this project I spent some extra time doing a bonus:

* 🔊 **Animation** The player character has a different sprite for each orientation.

---

## 🧠 Learning Goals

* Reading, parsing and validating map data from files.
* Handling graphics and keyboard input with MiniLibX.
* Managing memory, assets, and the game loop.
* Designing a simple and robust architecture in C.

---

## 👤 Author

* **Name:** Diogo Mendes
* **42 Login:** Diomende

---

🕹️ *Try and catch'em all*
