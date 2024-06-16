#include <iostream>
#include <random>
#include <ctime>
#include <unistd.h>
#include <conio.h> // For _kbhit and _getch

using namespace std;

class Cell
{
public:
    bool isAlive;
    bool wasAlive;

    Cell(bool isAlive = rand() % 2) : isAlive(isAlive), wasAlive(isAlive) {}

    // function return the new stat in the next generation, depend on set of rules .
    bool rules(int neighborsCount)
    {
        /* [RULES]
             1- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
             2- Any live cell with two or three live neighbours lives on to the next generation.
             3- Any live cell with more than three live neighbours dies, as if by overpopulation.
             4- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
        */
        return ((this->isAlive && neighborsCount >= 2 && neighborsCount <= 3) || (!this->isAlive && neighborsCount == 3));
    }
};

// I use Template in case u have position index and position in real world , like in console we use int , int SDL ,or a game engine use float
// [NOTE] is u wanna use this code in real world position , u need to do many and many changes
class Life
{
    int width;
    int height;

    int CountCellCeighbors(int ypos, int xpos)
    {
        int count = 0;
        for (int i = ypos - 1; i <= ypos + 1; ++i)
        {
            for (int j = xpos - 1; j <= xpos + 1; ++j)
            {
                if (!(i == ypos && j == xpos)) // Skip the cell itself
                {
                    int ni = (i + height) % height; // Wrap around vertically
                    int nj = (j + width) % width;   // Wrap around horizontally
                    if (Grid[ni][nj].wasAlive)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }

public:
    Cell **Grid;

    // by default the init of Cell stat will be random, u can update it and control it as you like or , by passing a matrice have all stat u like to us.[NOTE] the matrice you like to use as a sugggestion use Life([bool/int] *mat,width,height){...}
    Life(int height, int width) : height(height), width(width)
    {
        // Seed the random number generator once
        srand(static_cast<unsigned>(time(0)));

        // Allocate the grid
        Grid = new Cell *[height];
        for (int i = 0; i < height; ++i)
        {
            Grid[i] = new Cell[width];
            for (int j = 0; j < width; ++j)
            {
                Grid[i][j] = Cell();
            }
        }
    }

    Life(int size) : height(size), width(size)
    {
        srand(time(0));

        Grid = new Cell *[height];
        for (int i = 0; i < height; ++i)
        {
            Grid[i] = new Cell[width];
            for (int j = 0; j < width; ++j)
            {
                Grid[i][j] = Cell();
            }
        }
    }

    // # main function of this class . [NOTE] is not really importent cause we are not using a game engine u can midife this part as you like
    // Function init all the elment depend on what you want
    void Start()
    {
        // the constructer in console is the start , but in the next and advance "game of life" when we add variables ect ect ...
    }

    // function do the update needed , change attri ect ...
    void Update()
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (Grid[i][j].isAlive != Grid[i][j].wasAlive)
                    Grid[i][j].wasAlive = Grid[i][j].isAlive;
                Grid[i][j].isAlive = Grid[i][j].rules(this->CountCellCeighbors(i, j));
            }
        }
    }

    // function that will render our scene
    void Render()
    {
        for (int i = 0; i < width + 2; ++i)
            cout << "-";
        cout << endl;
        for (int i = 0; i < height; ++i)
        {
            cout << "|";
            for (int j = 0; j < width; ++j)
            {
                cout << ((Grid[i][j].isAlive) ? "#" : " ");
            }
            cout << "|" << endl;
        }
        for (int i = 0; i < width + 2; ++i)
            cout << "-";
        cout << endl;
    }

    ~Life()
    {
        for (int i = 0; i < height; ++i)
        {
            delete[] Grid[i];
        }
        delete[] Grid;
    }
};

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
        // // Check if 'q' is pressed to exit the loop
        // if (_kbhit())
        // {                        // Check if a key is pressed
        //     char key = _getch(); // Get the pressed key
        //     if (key == 'q')
        //     {
        //         break; // Exit the loop if 'q' is pressed
        //     }
        // }
        myGameLife.Render();
        myGameLife.Update();

        // Sleep for 500 milliseconds
        // sleep(500);
        system("cls"); // Clear screen for Windows
    }

    return 0;
}