/*
	fltk-bulls-and-cows.cpp
	Andrew Ng
	November 3 2019
	Bulls and cows guessing game
	program using FLTK for hw5
*/


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")


struct Model
{
	std::vector<int> input;
};


struct View {
	Fl_Input* input = nullptr;
	Fl_Output* outputBulls = nullptr;
	Fl_Output* outputCows = nullptr;
};


std::vector<int> answer{ 3, 4, 6, 1 };
Model model;
View view;


int bulls(const std::vector<int>& answer, const std::vector<int>& guess);
int cows(const std::vector<int>& answer, const std::vector<int>& guess);
void inputChanged(Fl_Widget* w, void* userdata);
void checkClicked(Fl_Widget* w, void* userdata);
void quitClicked(Fl_Widget* w, void* userdata);
Fl_Window* CreateWindow();


int bulls(const std::vector<int>& answer, const std::vector<int>& guess)
{
	// Checks if number is right and in the correct spot
	int numBulls = 0;
	for (int i = 0; i < 4; ++i) {
		if (guess[i] == answer[i]) {
			numBulls++;
		}
	}
	return numBulls;
}


int cows(const std::vector<int>& answer, const std::vector<int>& guess)
{
	// Checks if number is right but in the wrong spot
	int numCows = 0;
	if (guess[0] == answer[1] || guess[0] == answer[2] || guess[0] == answer[3]) {
		numCows++;
	}
	if (guess[1] == answer[0] || guess[1] == answer[2] || guess[1] == answer[3]) {
		numCows++;
	}
	if (guess[2] == answer[0] || guess[2] == answer[1] || guess[2] == answer[3]) {
		numCows++;
	}
	if (guess[3] == answer[0] || guess[3] == answer[1] || guess[3] == answer[2]) {
		numCows++;
	}
	return numCows;
}


void inputChanged(Fl_Widget* w, void* userdata) {
	// checks if view.input hasn't changed (is still nullptr)
	if (!view.input) {
		return;
	}

	// gets input line as string,
	// pushed individual digits into vector of ints
	std::string number = view.input->value();
	std::vector<int> guess;
	for (int i = 0; i < number.size(); ++i) {
		if (number[i] < '0' || number[i] > '9' || number.size() != 4) {
			guess.clear();
			break;
		}
		int pushed;
		std::string digit(1, number[i]);
		std::istringstream instream(digit);
		instream >> pushed;
		guess.push_back(pushed);
	}
	model.input = guess;
}


void checkClicked(Fl_Widget* w, void* userdata) {
	// checks if outputs haven't changed (is still nullptr)
	if (!view.outputBulls || !view.outputCows) {
		return;
	}

	//checks if stored vector isn't the right size
	if (model.input.size() != 4) {
		return;
	}

	// calls evaluation of bull and cow values
	// pushes strings of those values to the output lines
	int b = bulls(answer, model.input);
	int c = cows(answer, model.input);
	std::string bullsLine = std::to_string(b);
	std::string cowsLine = std::to_string(c);

	// win condition
	if (b == 4) {
		bullsLine += "    FOUR BULLS: YOU WIN!";
	}
	view.outputBulls->value(bullsLine.c_str());
	view.outputCows->value(cowsLine.c_str());
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
	Fl_Window* window = new Fl_Window(720, 540);

	// makes box for the title
	Fl_Box* box = new Fl_Box(180, 40, 360, 80, "Guessing Game!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);

	// makes box for the instruction sentence
	Fl_Box* Instructions = new Fl_Box(80, 120, 560, 160,
		"Guess a number of 4 different digits!\n"
		"A bull means a digit is right and in the correct position.\n"
		"A cow means a digit is right but in the wrong position.\n");
	Instructions->labelsize(18);

	// reused variables for spacing of boxes
	int x = 260;
	int y = 280;
	const int w = 100;
	const int h = 25;
	const int Spacing = 10;

	// making input/output boxes, and check/quit buttons
	view.input = new Fl_Input(x, y, 2 * w, h, "Input Guess");
	view.input->input_type(2);
	view.input->redraw();
	y += h + Spacing;
	view.outputBulls = new Fl_Output(x, y, 2 * w, h, "Bulls");
	y += h + Spacing;
	view.outputCows = new Fl_Output(x, y, 2 * w, h, "Cows");
	y += h + Spacing;
	x += 40;
	Fl_Button* truncButton = new Fl_Button(x, y, w, h, "Check Guess");
	y += h + Spacing * 3;
	Fl_Button* quitButton = new Fl_Button(x, y, w, h, "Quit");

	// callback functions
	view.input->callback(inputChanged, nullptr);
	truncButton->callback(checkClicked, nullptr);
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