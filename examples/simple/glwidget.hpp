
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>

class GLWidget : public QOpenGLWidget {
public:
	GLWidget(QWidget *parent = 0);
    ~GLWidget();

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
};
