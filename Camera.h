#pragma once

class CameraDraw{
public:
	static int x, y;
	static int Graph(int, int, int, int);
	static int Box(int, int, int, int, int, int);
	static int Circle(int, int, int, int, int);
	static int Line(int, int, int, int, int, int);
	static void setCameraTargetPosition(int x, int y);
};