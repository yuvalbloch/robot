#pragma once
#include "button.h"
#include <iostream>
class instractionWindow

{
private:
	button exit;
public:
	instractionWindow();
	void init();
	void display();
	void setUp();
	int mouseFunc(int button , int state , int x, int y);
};

