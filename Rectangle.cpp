#include "Rectangle.h"

//Function definitions for the class

void Rectangle::animate()
{
	int directR, directC; //for motion direction
	int officialColor = color;	//color for output
	color = 0;	// any drawings in this color will erase the shape
	digitalDraw();

	// get the new shape position. We will add a step in the correct
	//direction to what the current position is
	getDirection(directR, directC);
	rowP += directR;
	colP += directC;

	//draw the new shape
	color = officialColor;
	digitalDraw();
}

void SpecialRectangle::digitalDraw() 
{
	int rowP, colP;
	COORD pos;

	//set the color attribute for the rectangle
	SetConsoleTextAttribute(outHandle, getColor());
	getPos(rowP, colP);
	pos.X = colP;
	pos.Y = rowP;

	//draw the box
	for (int r = 0; r < length; r++)
	{
		SetConsoleCursorPosition(outHandle, pos);
		for (int c = 0; c < width; c++)
		{
			cout << "#";
		}
		cout << endl;
		pos.Y++;
	}
	//return the text attribute back to normal
	SetConsoleTextAttribute(outHandle, 7);

}

//set the information for the rectangle
SpecialRectangle::SpecialRectangle(int rowP, int colP, int width, int length)
{
	setColor(5);
	setPos(rowP, colP);
	this->width = width;
	this->length = length;
	digitalDraw();
}

