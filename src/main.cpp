#include <iostream>
#include <cmath>
#include <numbers>

class Robot
{
private:
    float posX, posY;   // represented in meters
    float heading;      // represented in radians
    float goalX, goalY; // represented in meters
    float tolerence;

public:
    void setGoal(float x, float y)
    {
        goalX = x;
        goalY = y;
    }

    float getGoalX()
    {
        return goalX;
    }

    float getGoalY()
    {
        return goalY;
    }

    void moveForward(float distance)
    {
        posX = posX + (distance * std::cos(heading));
        posY = posY + (distance * std::sin(heading));
    }

    float getPosX()
    {
        return posX;
    }

    float getPosY()
    {
        return posY;
    }

    void setHeading(float newHeading)
    {
        heading = newHeading;
    }

    void navigateToGoal()
    {
        if (isGoalReached())
        {
            std::cout << "Goal position achieved";
            return;
        }

        float deltaX = goalX - posX;

        if (std::abs(deltaX) <= tolerence)
            std::cout << "X coordinate already within tolerance" << std::endl;
        else
        {
            if (deltaX < 0)
            {
                setHeading(std::numbers::pi);
                moveForward(std::abs(deltaX));
            }
            else if (deltaX > 0)
            {
                setHeading(0);
                moveForward(std::abs(deltaX));
            }
        }

        float deltaY = goalY - posY;

        if (std::abs(deltaY) <= tolerence)
            std::cout << "Y coordinate already within tolerance" << std::endl;
        else
        {
            if (deltaY < 0)
            {
                setHeading(std::numbers::pi * 3.0 / 2.0);
                moveForward(std::abs(deltaY));
            }
            else if (deltaY > 0)
            {
                setHeading(std::numbers::pi / 2.0);
                moveForward(std::abs(deltaY));
            } 
        }
    }

    float getGoalDistance()
    {
        float deltaX = goalX - posX;
        float deltaY = goalY - posY;
        float distance = std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
        return distance;
    }

    bool isGoalReached()
    {
        float distance = getGoalDistance();
        return (distance <= tolerence);
    }

    Robot()
    {
        posX = 0.0;
        posY = 0.0;
        heading = std::numbers::pi / 2.0;
        goalX = 0.0;
        goalY = 0.0;
        tolerence = 0.035;
    }
};

int main()
{
    Robot rob1;

    rob1.setGoal(0.04, 0.04);

    std::cout << "Goal X: " << rob1.getGoalX() << std::endl;
    std::cout << "Goal Y: " << rob1.getGoalY() << std::endl;

    rob1.navigateToGoal();

    std::cout << "Final position: ("
              << rob1.getPosX() << ", "
              << rob1.getPosY() << ")" << std::endl;

    std::cout << "Goal reached: "
              << std::boolalpha
              << rob1.isGoalReached()
              << std::endl;

    return 0;
}