#ifndef CONE_H
#define CONE_H

#include <cmath>
#include "Shape.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Cone : public Shape {
public:
	Cone() {};
	~Cone() {};

	OBJ_TYPE getType() {
		return SHAPE_CONE;
	}

	void draw() {
		float angleToRotate = 2 * M_PI / m_segmentsX;

		glBegin(GL_TRIANGLES);

		for (int i = 0; i < m_segmentsX; i++) {

            float angle1 = i * angleToRotate;
            float angle2 = (i + 1) * angleToRotate;

            glNormal3f(0.0f, -1.0f, 0.0f);
            glVertex3f(0.0f, -0.5f, 0.0f);

            if (i == 0) {
                glNormal3f(0.0f, -1.0f, 0.0f);
                glVertex3f(0.5f, -0.5f, 0.0f);
            }
            else {
                glNormal3f(0.0f, -1.0f, 0.0f);
                glVertex3f(0.5f * cos(angle1), -0.5f, 0.5f * sin(angle1));
            }

            glNormal3f(0.0f, -1.0f, 0.0f);
            glVertex3f(0.5f * cos(angle2), -0.5f, 0.5f * sin(angle2));
		}

		glEnd();
	};

	void drawNormal() {

	};

private:
};

#endif