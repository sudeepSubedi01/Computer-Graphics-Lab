# Computer Graphics Lab - II/II Code <br> 
- Software used: **Dev-Cpp 5.11 TDM-GCC 4.9.2** <br>
- Tutorial for setup: https://www.youtube.com/watch?v=TEMhWt9WwTA
- Compiler used: **TDM-GCC 4.9.2 32-bit Release**

# How to code program?
1. In Dev-Cpp, choose compiler **TDM-GCC 4.9.2 32-bit Release**
2. Create a new project: **Console Graphics Application**
3. Save the project with `.dev`
4. Use **graphics.h** in program code
5. Build and run the program

# C++ Features used in the Code

### 1. **`int gdriver = DETECT, gm;`**
- **Purpose**:
  - `gdriver` (graphics driver): Specifies the graphics driver to be used. By setting it to `DETECT`, the compiler automatically detects the best graphics driver available on the system.
  - `gm` (graphics mode): Holds the graphics mode that is used for drawing. The actual mode is set by the `initgraph` function.
- **What `DETECT` does:**
  - A predefined constant in the graphics library (`graphics.h`) that directs the library to determine the appropriate driver and mode during runtime.

---

### 2. **`initgraph(&gdriver, &gm, NULL);`**
- **Purpose:** Initializes the graphics mode and prepares the screen for graphical output.
- **Parameters:**
  - `&gdriver`: Pointer to the graphics driver variable (`gdriver`) that specifies the driver to be used.
  - `&gm`: Pointer to the graphics mode variable (`gm`) that specifies the mode to be used.
  - `NULL`: This is the path to a BGI (Borland Graphics Interface) driver file. Using `NULL` tells the program to search for the driver in the default directory.
- **How it works:**
  - Automatically selects the best graphics driver and mode (if `gdriver` is `DETECT`).
  - Sets up the screen for drawing.
- **Example Output:**
  - A new graphics window opens, ready for rendering.

---

### 3. **`putpixel(x, y, color);`**
- **Purpose:** Plots a pixel at the specified coordinates (`x`, `y`) with the given color.
- **Parameters:**
  - `x`: X-coordinate of the pixel.
  - `y`: Y-coordinate of the pixel.
  - `color`: Color constant (e.g., `WHITE`, `RED`), provided by `graphics.h`.

---

### 4. **`delay(milliseconds);`**
- **Purpose:** Pauses the program for a specified time in milliseconds.
- **Use Case in Code:**
  - Adds a delay between plotting consecutive points in the DDA algorithm to visually render the line incrementally.

---

### 5. **`getch();`**
- **Purpose:** Waits for the user to press a key before continuing the program.
- **Use Case in Code:**
  - Keeps the graphics window open after the algorithm finishes so that the user can view the final output. The program only proceeds to `closegraph()` after a key is pressed.

---

### 6. **`closegraph();`**
- **Purpose:** Closes the graphics window and deallocates the memory used by the graphics system.
- **Use Case:**
  - Ensures the program exits cleanly, releasing resources tied to the graphics system.

---

### Flow of Graphics Initialization and Termination
1. **Start Graphics Mode:**
   - `int gdriver = DETECT, gm;`
   - `initgraph(&gdriver, &gm, NULL);`

2. **Perform Drawing:**
   - Use graphics functions like `putpixel()`.

3. **End Graphics Mode:**
   - `getch();`
   - `closegraph();`

---