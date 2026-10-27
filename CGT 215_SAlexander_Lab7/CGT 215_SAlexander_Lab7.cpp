// Sophia Alexander
//CGT 215
//bouncy ball .exe lol


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>


using namespace std;
using namespace sf;
using namespace sfp;

//declare common variables here to make changing them later easier
int wallW = 625;
int wallH = 30;

int main()
{

	// Create our window and world with gravity 0,1
	RenderWindow window(VideoMode(800, 600), "Bounce");
	World world(Vector2f(0, 1));

	// Create the ball
	PhysicsCircle ball;
	
	//sets the center of the ball and starting location
	ball.setCenter(Vector2f(400, 300));
	//sets radius and therefore size (d = 40)
	ball.setRadius(20);
	//adds the ball to the world as an entity that has physics
	world.AddPhysicsBody(ball);

	// Create the floor
	PhysicsRectangle floor;
	//sets the size of the floor in length and height)
	floor.setSize(Vector2f(wallW, wallH));
	//sets where the floor STARTS not the center of it!
	floor.setCenter(Vector2f(90, 575));
	//makes the floor static so it doesnt move
	floor.setStatic(true);
	//adds the floor to the world as an entity that has physics
	world.AddPhysicsBody(floor);
	//sets the thud (hit) count to 1 to start
	int thudCount(1);

	// Create the left Wall
	PhysicsRectangle LWall;
	//sets the size of the left wall in length and height)
	LWall.setSize(Vector2f(wallH, wallW));
	//sets where the left wall STARTS not the center of it!
	LWall.setCenter(Vector2f(90, 120));
	//makes the left wall static so it doesnt move
	LWall.setStatic(true);
	//adds the left wall to the world as an entity that has physics
	world.AddPhysicsBody(LWall);

	// Create the right Wall
	PhysicsRectangle RWall;
	//sets the size of the left wall in length and height)
	RWall.setSize(Vector2f(wallH, wallW));
	//sets where the left wall STARTS not the center of it!
	RWall.setCenter(Vector2f(690, 120));
	//makes the left wall static so it doesnt move
	RWall.setStatic(true);
	//adds the left wall to the world as an entity that has physics
	world.AddPhysicsBody(RWall);

	//when the ball hits the floor, increase the thud count by 1.
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};

	Clock clock;
	Time lastTime(clock.getElapsedTime()); //keeps track of how long the program is running

	//this is the main game loop
	while (true) {
		// calculate Mili-Seconds since last frame
		Time currentTime(clock.getElapsedTime()); //gets the time thats passed since program start
		Time deltaTime(currentTime - lastTime); //subtracts time since start from time running
		//not sure why the above line is necessary- shouldnt they be the same??

		int deltaTimeMS(deltaTime.asMilliseconds());//
		if (deltaTimeMS > 0) {
			world.UpdatePhysics(deltaTimeMS);
			lastTime = currentTime;
		}

		window.clear(Color(0, 0, 0));
		window.draw(ball);
		window.draw(floor);
		window.draw(LWall);
		window.draw(RWall);
		window.display();
	}
}
