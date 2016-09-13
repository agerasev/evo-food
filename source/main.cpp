#include <QApplication>
#include <QWidget>

class Window : public QWidget {
public:
	Window() : QWidget() {
		resize(1280, 720);
		setWindowTitle("EvoFood");
	}
};


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	Window window;
	window.show();

	int rs = app.exec();

	return rs;
}
