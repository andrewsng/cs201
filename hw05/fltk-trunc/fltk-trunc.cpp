/*
	fltk-trunc.cpp
	Andrew Ng
	November 3 2019
	Truncate program using FLTK for hw5
*/


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include <string>
#include <sstream>
#include <iostream>
#include "truncstruct.hpp"

#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")


struct Model
{
	std::string inputStr;
	size_t inputInt = 0;
};


struct View {
	Fl_Input* inputStr = nullptr;
	Fl_Input* inputInt = nullptr;
	Fl_Output* output = nullptr;
};


Model model;
View view;


void stringChanged(Fl_Widget* w, void* userdata);
void intChanged(Fl_Widget* w, void* userdata);
void truncateClicked(Fl_Widget* w, void* userdata);
void quitClicked(Fl_Widget* w, void* userdata);
Fl_Window* CreateWindow();


void stringChanged(Fl_Widget* w, void* userdata) {
	// checks if view.inputStr hasn't changed (is still nullptr)
	if (!view.inputStr) {
		return;
	}

	// sets model's string to value from string input box
	model.inputStr = view.inputStr->value();
}


void intChanged(Fl_Widget* w, void* userdata) {
	// checks if view.inputInt hasn't changed (is still nullptr)
	if (!view.inputInt) {
		return;
	}

	// puts string value from integer input box into istringstream,
	// inputs istringstream into a size_t integer,
	// sets model's integer to that size_t int
	std::istringstream inputNum(view.inputInt->value());
	size_t newLen;
	inputNum >> newLen;
	model.inputInt = newLen;
}


void truncateClicked(Fl_Widget* w, void* userdata) {
	// checks if view.output hasn't changed (is still nullptr)
	if (!view.output) {
		return;
	}

	// makes a StringInfo struct using values in model struct,
	// gets new string by calling trunc with created StringInfo,
	// sets string value in output box to that new string
	StringInfo truncInfo{ model.inputStr, model.inputInt };
	std::string truncated = trunc(truncInfo).str;
	view.output->value(truncated.c_str());
}


void quitClicked(Fl_Widget* w, void* userdata) {
	// checks if given pointer, window, is nullptr
	if (!userdata) {
		return;
	}

	// casts given void pointer to a Fl_Window pointer
	// calls hide() function on Fl_Window* window to close it
	Fl_Window* window = (Fl_Window*)userdata;
	window->hide();
}


Fl_Window* CreateWindow() {
	// makes window of given size
	Fl_Window* window = new Fl_Window(720, 400);

	// makes box for the title
	Fl_Box* box = new Fl_Box(150, 20, 420, 80, "Truncate Your String!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);

	// makes box for the instruction sentence
	Fl_Box* Instructions = new Fl_Box(80, 80, 560, 80,
		"Enter a string and a number of characters "
		"greater than 0 to truncate the string.");
	Instructions->labelsize(18);

	// reused variables for spacing of boxes
	int x = 160;
	int y = 160;
	const int w = 200;
	const int h = 25;
	const int Spacing = 10;

	// making input/output boxes, and truncate/quit buttons
	view.inputStr = new Fl_Input(x, y, 2 * w, h, "Input String");
	y += h + Spacing;
	view.inputInt = new Fl_Input(x, y, 2 * w, h, "Input Number");
	view.inputInt->input_type(2);
	view.inputInt->redraw();
	y += h + Spacing;
	view.output = new Fl_Output(x, y, 2 * w, h, "Result");
	y += h + Spacing;
	x += 140;
	Fl_Button* truncButton = new Fl_Button(x, y, w / 2, h, "Truncate");
	y += h + Spacing * 3;
	Fl_Button* quitButton = new Fl_Button(x, y, w / 2, h, "Quit");

	// callback functions
	view.inputStr->callback(stringChanged, nullptr);
	view.inputInt->callback(intChanged, nullptr);
	truncButton->callback(truncateClicked, nullptr);
	quitButton->callback(quitClicked, (void*)window);

	// marks end of current window group
	window->end();
	return window;
}


int main(int argc, char** argv) {
	Fl_Window* window = CreateWindow();
	window->show(argc, argv);
	return Fl::run();
}