#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

using namespace Graph_lib;

/*
g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/

int main(){

	Point t1{300, 50};
	Simple_window win {t1, 1000, 800, "Window"};
	win.wait_for_button();
	
	
	Lines grid;
	int x_size = 800;
	int y_size = 800;
	
	for(int i = 100; i <= x_size; i += 100){
		grid.add(Point(i, 0), Point(i, y_size));
		grid.add(Point(0, i), Point(x_size, i));
	}
	win.attach(grid);
	win.set_label("Lines");
	win.wait_for_button();
	
	
	Vector_ref<Rectangle> v;
	for(int i = 0; i < 8; ++i){
		v.push_back(new Rectangle{Point(i*100, i*100), 100, 100});
		v[i].set_fill_color(Color::red);
		win.attach(v[i]); 
		}
	
	
	win.set_label("Red rectangles");
	win.wait_for_button();
	
	
	Image img1{Point(200,0),"badge.jpg"};
	Image img2{Point(400,200),"badge.jpg"};
	Image img3{Point(600,400),"badge.jpg"};
	img1.set_mask(Point(100, 100), 200, 200);
	img2.set_mask(Point(100, 100), 200, 200);
	img3.set_mask(Point(100, 100), 200, 200);
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);
	win.set_label("Images");
	win.wait_for_button();
	
	
	for(int i = 0; i < 701; i += 100){
		for(int j = 0; j < 701; j += 100){
			Image ii{Point{j, i}, "badge.jpg"};
			ii.set_mask(Point(150, 150), 100, 100);
			win.attach(ii);
			win.set_label("Moving image");
			win.wait_for_button();
		}
	}
	

}
