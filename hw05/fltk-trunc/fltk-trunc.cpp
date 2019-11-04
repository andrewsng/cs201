#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include <string>
#include <iostream>

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

}


void intChanged(Fl_Widget* w, void* userdata) {

}


void truncateClicked(Fl_Widget* w, void* userdata) {

}


void quitClicked(Fl_Widget* w, void* userdata) {

}


Fl_Window* CreateWindow() {
	Fl_Window* window = new Fl_Window(720, 400);

	Fl_Box* box = new Fl_Box(150, 20, 420, 80, "Truncate Your String!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);

	Fl_Box* Instructions = new Fl_Box(80, 80, 560, 80,
		"Enter a string and a number of characters greater than 0 to truncate the string.");
	Instructions->labelsize(18);

	int x = 160;
	int y = 160;
	const int w = 200;
	const int h = 25;
	const int Spacing = 10;

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

	view.inputStr->callback(stringChanged, nullptr);
	view.inputInt->callback(intChanged, nullptr);
	truncButton->callback(truncateClicked, nullptr);
	quitButton->callback(quitClicked, (void*)window);

	window->end();
	return window;
}


int main(int argc, char** argv) {
	Fl_Window* window = CreateWindow();
	window->show(argc, argv);
	return Fl::run();
}