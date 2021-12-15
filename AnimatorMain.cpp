#include "Rectangle.h"

//main implementation file

int main()
{
	//declare the shape position of each rectangle
	SpecialRectangle rect1(5, 0, 13, 4);
	SpecialRectangle rect2(5, 70, 13, 4);

	//directions of movement
	int forward = 1;
	int backward = -1;

	//point of middle intersection
	int middlePos = 0;

	//draw the rectangles
	rect1.digitalDraw();
	rect2.digitalDraw();
	
	//counter for middle meets
	int totalMiddleMeets = 1;

	while (middlePos < 20) 
	{
		//set the motion
		forward = -forward;
		backward = -backward;

		rect1.setDirection(0, backward);	//backwards and forward reverse order
		rect2.setDirection(0, forward);

		for (int i = 0; i < 29; i++) //exact meeting point
		{
			Sleep(75);
			rect1.animate();
			rect2.animate();
		}
		middlePos++; //increment for the while loop
		COORD pos;
		pos.X = 4;		
		pos.Y = 13;

		//change cursor position
		SetConsoleCursorPosition(outHandle, pos);
		totalMiddleMeets++;

		cout << " Middle Meet #: " << totalMiddleMeets/2 << endl;
	}
	return 0;
} //end of main
