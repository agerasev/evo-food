#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>

#include <world/world.hpp>

#include <world/scene.hpp>
#include <world/view.hpp>


class Window : public QWidget {
public:
	World &world;
	
	Scene scene;
	View view;
	
	QHBoxLayout layout;
	
	Window(World &w) : QWidget(), 
		world(w), scene(w), view(scene)
	{
		resize(1280, 720);
		setWindowTitle("EvoFood");
		
		layout.addWidget(&view, 1);
		
		setLayout(&layout);
	}
};


int main(int argc, char *argv[]) {
	World world(vec2(10, 10));
	world.add(new Entity());
	
	QApplication app(argc, argv);
	
	Window window(world);
	window.show();
	
	window.scene.sync();
	window.scene.update();

	int rs = app.exec();

	return rs;
}
