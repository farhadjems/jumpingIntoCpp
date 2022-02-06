#include <iostream>

using namespace std;

struct spaceShip
{
    int x; // x-location
    int y; // y-location
    int u; // x-direction velocity
    int v; // y-direction velocity
    string name; // space ship name
    bool screenCond;  // this variable holds true if the space ship is on the screen or false if its off the screen
};

spaceShip getSpaceShipData(); // this function gets the space ship info from user and returns it
spaceShip updateLocation(spaceShip spaceship); // this function updates the location of space ship for each 1 second
bool isSpaceShipOnTheScreen(spaceShip spaceship, int screenX, int screenY, int time); // this function checks if the space ship is in the screen or not!!


int main()
{
    const int numberOfSpaceShips = 3;
    spaceShip spaceship[numberOfSpaceShips];
    for (size_t i = 0; i < numberOfSpaceShips; i++)
    {
        spaceship[i] = getSpaceShipData();
    }
    
    int screenX = 1024; // x-screen resolution
    int screenY =  768; // y-screen resolution

    int time = 0;
    bool isAllSpaceShipsOffTheScreen = false;
    while (!isAllSpaceShipsOffTheScreen)
    {
        isAllSpaceShipsOffTheScreen = true;
        for (int i = 0; i < numberOfSpaceShips; i++)
        {
            spaceship[i] = updateLocation(spaceship[i]);
            if (isSpaceShipOnTheScreen(spaceship[i], screenX, screenY, time))
            {
                isAllSpaceShipsOffTheScreen = false;
            }
        }
        time ++;
    }
    


}

spaceShip getSpaceShipData()
{
    spaceShip spaceship;
    cout << "enter the name of space ship: ";
    cin >> spaceship.name;
    cout << "enter the initial x-location: ";
    cin >> spaceship.x;
    cout << "enter the initial y-location: ";
    cin >> spaceship.y;
    cout << " enter the x-direction velocity: ";
    cin >> spaceship.u;
    cout << " enter the y-direction velocity: ";
    cin >> spaceship.v;
    return spaceship;
}

spaceShip updateLocation(spaceShip spaceship)
{
    spaceship.x += spaceship.u;
    spaceship.y += spaceship.v;
    return spaceship;
}

bool isSpaceShipOnTheScreen(spaceShip spaceship, int screenX, int screenY, int time)
{
    cout << " at time: " << time << '\t';
    if (spaceship.x > screenX || spaceship.x < 0 || spaceship.y > screenY || spaceship.y < 0)
    {
        cout << "space ship " << spaceship.name << " is off the screen!\n";
        return false;
    }
    else
    {
        cout << "space ship " << spaceship.name << " is on the screen!\n";
        return true;
    }
}














