#include <iostream>

using namespace std;

template <typename T>
class vector2
{
public:
    T x, y;

    vector2(T x , T y){}

    void operator=(vector2 &curentPos)
    {
        this->x = curentPos.x;
        this->y = curentPos.y;
    }
};

template <typename T>
class Cell
{
    void NextPosition(vector2<T> newPos)
    {
        OldPos = curentPos;
        curentPos = newPos;
    }

public:
    bool isAlive;
    vector2<T> curentPos;
    vector2<T> OldPos;

    Cell(bool isAlive, vector2<T> curentPos, vector2<T> OldPos) : isAlive(isAlive), curentPos(curentPos), OldPos(OldPos) {}
};

int main()
{
    int Old;
    return 0;
}