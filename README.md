# so_long

Small 2D game with basic gameplay

## How it works

1. The player’s goal is to collect all collectibles present on the map then escape with
minimal movement without being caught by the enemies.

2. The player is able to move up (press W), down (press S), left (press A) and right (press D). Player can close the game by pressing ESC.

3. The map is constructed with 5 components:
   - Player - 'P'
   - Exit - 'E'
   - Wall - '1'
   - Free space - '0'
   - Enemy - 'B'

4. Some map examples are stored in `/maps` folder. Feel free to change them (`.ber` format is required)!

## How to launch the game

1. Game is suitable for MacOS.

2. To start the game open `Terminal`, `git clone` repo, checkout to the source folder and type:

   ```sh
   $ ./so_long [path_to_valid_map]
   ```

3. Use `MakeFile` to make changes to the sources files and compile a new program. To compile a new program checkout to the source folder and type:

   ```sh
   $ make
   ```

   or

   ```sh
   $ make re
   ```

## Screenshots

- Game simulation:
  <br>
  <br>
  <img src="./examples/simulation.gif" width="600" alt="map_simulation">
