#include <iostream>
#include <random>
#include <ctime>

using namespace std;

template <typename T>
class vector2
{
public:
    T x, y;

    vector2(T x = 0) : x(x), y(x) {}
    vector2(T x = T(), T y = T()) : x(x), y(y) {}
    vector2(const vector2<T> &pos) : x(pos.x), y(pos.y) {}
};

template <typename T>
class Cell
{
public:
    bool isAlive;
    vector2<T> curentPos;
    vector2<T> OldPos;

    Cell() : isAlive(false), curentPos(0, 0), OldPos(0, 0) {}
    Cell(int i, int j) : isAlive(rand() % 2), curentPos(i, j), OldPos(i, j) {}
    Cell(bool isAlive, vector2<T> pos) : isAlive(isAlive), curentPos(pos), OldPos(pos) {}
    Cell(bool isAlive, vector2<T> curentPos, vector2<T> OldPos) : isAlive(isAlive), curentPos(curentPos), OldPos(OldPos) {}

    // Change the current position to the next position
    void NextPosition(vector2<T> newPos)
    {
        OldPos = curentPos;
        curentPos = newPos;
    }
};

// I use Template in case u have position index and position in real world , like in console we use int , int SDL ,or a game engine use float
// [NOTE] is u wanna use this code in real world position , u need to do many and many changes
template <typename T>
class Life
{
    int width;
    int height;

public:
    Cell<T> **Grid;

    // by default the init of Cell stat will be random, u can update it and control it as you like or , by passing a matrice have all stat u like to us.[NOTE] the matrice you like to use as a sugggestion use Life([bool/int] *mat,width,height){...}
    Life(int height, int width) : height(height), width(width)
    {
        // Seed the random number generator once
        srand(static_cast<unsigned>(time(0)));

        // Allocate the grid
        Grid = new Cell<T> *[height];
        for (int i = 0; i < height; ++i)
        {
            Grid[i] = new Cell<T>[width];
            for (int j = 0; j < width; ++j)
            {
                Grid[i][j] = Cell<T>(i, j); // Properly initialize each Cell
            }
        }
    }

    Life(int size) : height(size), width(size)
    {
        srand(time(0));

        Grid = new Cell<T> *[height];
        for (int i = 0; i < height; ++i)
        {
            Grid[i] = new Cell<T>[width];
            for (int j = 0; j < width; ++j)
            {
                Grid[i][j] = Cell<T>(i, j);
            }
        }
    }

    // # main function of this class . [NOTE] is not really importent cause we are not using a game engine u can midife this part as you like
    // Function init all the elment depend on what you want
    void Start()
    {
    }

    // function do the update needed , change attri ect ...
    void Update()
    {
    }

    // function that will render our scene
    void Render()
    {
        for (int i = 0; i < height + 2; ++i)
            cout << "-";
        cout << endl;
        for (int i = 0; i < height; ++i)
        {
            cout << "|";
            for (int j = 0; j < width; ++j)
            {
                cout << ((Grid[i][j].isAlive)? "*" : " ");
            }
            cout << "|" << endl;
        }
        for (int i = 0; i < height +2; ++i)
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
    Life<int> myGameLife(10, 10); // Use a smaller grid for demonstration
    myGameLife.Render();
    return 0;
}