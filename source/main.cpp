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
	Entity *e;
	
	e = new Entity();
	e->pos = vec2(-4, -5);
	e->vel = vec2(1, 2);
	world.add(e);
	
	e = new Entity();
	e->pos = vec2(4, 4);
	e->vel = vec2(-2, -1);
	world.add(e);
	
	QApplication app(argc, argv);
	
	Window window(world);
	window.show();
	
	window.scene.start();

	std::thread thread([&world](){world.run();});

	int rs = app.exec();

	world.done = true;
	thread.join();
	
	window.scene.stop();
	
	return rs;
}
