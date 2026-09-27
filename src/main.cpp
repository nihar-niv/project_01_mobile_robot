#include <iostream>
#include <cmath>
#include <numbers>

class Robot
{
private:
    float posx, posy;
    float heading;
    float goalx, goaly;

public:
    void setGoal(float x, float y)
    {
        goalx = x;
        goaly = y;
    }

    float getGoalX()
    {
        return goalx;
    }

    float getGoalY()
    {
        return goaly;
    }

    void moveForward(float distance)
    {
        posx = posx + (distance * std::cos(heading));
        posy = posy + (distance * std::sin(heading));
    }

    float getPosX()
    {
        return posx;
    }

    float getPosY()
    {
        return posy;
    }

    Robot()
    {
        posx = 0.0;
        posy = 0.0;
        heading = std::numbers::pi / 2.0;
        goalx = 0.0;
        goaly = 0.0;
    }
};

int main()
{
    Robot rob1;

    rob1.setGoal(0.0, 1.0);

    std::cout << "Goal X: " << rob1.getGoalX() << std::endl;
    std::cout << "Goal Y: " << rob1.getGoalY() << std::endl;

    rob1.moveForward(1.0);

    std::cout << "Final position: (" << rob1.getPosX() << "," << rob1.getPosY() << ")" << std::endl;
    return 0;
}
