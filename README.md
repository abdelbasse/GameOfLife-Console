# GameOfLife-Console
### Documentation for the Game of Life Simulation

#### Purpose
The Game of Life simulation aims to demonstrate cellular automaton behavior according to specified rules. It uses a grid of cells that evolve from generation to generation based on their neighbors' states. This documentation explains the `Cell` and `Life` classes implemented in C++ for this purpose.

#### `Cell` Class
The `Cell` class represents an individual cell in the Game of Life grid. Each cell can either be alive (`isAlive = true`) or dead (`isAlive = false`). The class also tracks the previous state of the cell (`wasAlive`) to facilitate rule evaluation during updates.

##### Attributes
- `bool isAlive`: Represents the current state of the cell.
- `bool wasAlive`: Tracks the previous state of the cell.

##### Methods
- `Cell(bool isAlive = rand() % 2)`: Constructor that initializes the cell's state randomly if not provided explicitly.
- `bool rules(int neighborsCount)`: Method that applies the rules of the Game of Life to determine the cell's state in the next generation based on the count of its live neighbors.

#### `Life` Class
The `Life` class manages the entire simulation, including the grid of cells and methods for updating and rendering the simulation.

##### Attributes
- `int width, height`: Dimensions of the grid.
- `Cell** Grid`: 2D array representing the grid of cells.

##### Constructors
- `Life(int height, int width)`: Initializes a grid of cells with dimensions `height` and `width`. Each cell is initialized with a random state.
- `Life(int size)`: Overloaded constructor that creates a square grid (`size x size`) with cells initialized randomly.

##### Methods
- `void Start()`: Placeholder method that could initialize additional game variables or settings.
- `void Update()`: Iterates through each cell in the grid, applies the Game of Life rules using `Cell::rules()` to determine the next generation's state, and updates the `Grid`.
- `void Render()`: Renders the current state of the grid to the console, displaying live cells as `#` and dead cells as spaces (` `).
- `~Life()`: Destructor that frees dynamically allocated memory for the grid.

##### Private Method
- `int CountCellNeighbors(int ypos, int xpos)`: Counts the number of live neighbors surrounding a cell at position `(ypos, xpos)` on the grid, taking care to wrap around the edges to simulate an infinite grid.

#### Example Usage

```cpp
int main()
{
    int width, height;

    // User input for width and height
    std::cout << "Enter width of the matrix: ";
    std::cin >> width;
    std::cout << "Enter height of the matrix: ";
    std::cin >> height;

    Life myGameLife(height, width);

    while (true)
    {
        myGameLife.Render(); // Display the current state of the grid
        myGameLife.Update(); // Update the grid based on Game of Life rules

        // Implement your own exit condition logic if needed
        // e.g., exit loop if 'q' key is pressed
        /*
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'q')
                break;
        }
        */

        // Optional: Pause execution for a short time before next iteration
        // sleep(500); // Uncomment this line if using Unix/Linux
        
        // Clear the console screen before rendering the next frame
        system("cls"); // For Windows
        // system("clear"); // For Unix/Linux
    }

    return 0;
}
```

#### Example Rendering

Below is an example rendering of the Game of Life grid in the console:

```
-------------
| # #       |
|     #     |
| #   #     |
|           |
|           |
-------------
```

In this rendering:
- `#` represents live cells.
- Spaces (` `) represent dead cells.

#### Conclusion
This documentation outlines the implementation and usage of the Game of Life simulation in C++, focusing on the `Cell` and `Life` classes. It provides an overview of their purpose, attributes, methods, example usage, and a sample rendering output. Adjustments and enhancements can be made based on specific requirements or additional features desired for the simulation.