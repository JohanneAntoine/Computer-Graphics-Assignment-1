#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"

class Cube : public Shape {
public:
	Cube() {};
	~Cube() {};

	OBJ_TYPE getType() {
		return SHAPE_CUBE;
	}

	void draw() {

		float stepX = 1.0f / m_segmentsX;
		float stepY = 1.0f / m_segmentsY;

		// front face
		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				float x0 = -0.5f + i * stepX;
				float x1 = -0.5f + (i + 1) * stepX;
				float y0 = -0.5f + j * stepY;
				float y1 = -0.5f + (j + 1) * stepY;

				glBegin(GL_TRIANGLES);

				glNormal3f(0.0f, 0.0f, 1.0f);

				glVertex3f(x0, y0, 0.5f);
				glVertex3f(x1, y0, 0.5f);
				glVertex3f(x1, y1, 0.5f);

				glVertex3f(x0, y0, 0.5f);
				glVertex3f(x1, y1, 0.5f);
				glVertex3f(x0, y1, 0.5f);

				glEnd();
			}
		}

		// back face
		for (int k = 0; k < m_segmentsX; k++) {
			for (int l = 0; l < m_segmentsY; l++) {
				float x0 = -0.5f + k * stepX;
				float x1 = -0.5f + (k + 1) * stepX;
				float y0 = -0.5f + l * stepY;
				float y1 = -0.5f + (l + 1) * stepY;

				glBegin(GL_TRIANGLES);

				glNormal3f(0.0f, 0.0f, -1.0f);

				glVertex3f(x0, y0, -0.5f);
				glVertex3f(x1, y0, -0.5f);
				glVertex3f(x1, y1, -0.5f);

				glVertex3f(x0, y0, -0.5f);
				glVertex3f(x1, y1, -0.5f);
				glVertex3f(x0, y1, -0.5f);

				glEnd();
			}
		}

		// right face
		for (int m = 0; m < m_segmentsX; m++) {
			for (int n = 0; n < m_segmentsY; n++) {
				float y0 = -0.5f + m * stepX;
				float y1 = -0.5f + (m + 1) * stepX;
				float z0 = -0.5f + n * stepY;
				float z1 = -0.5f + (n + 1) * stepY;

				glBegin(GL_TRIANGLES);

				glNormal3f(1.0f, 0.0f, 0.0f);

				glVertex3f(0.5f, y0, z0);
				glVertex3f(0.5f, y1, z0);
				glVertex3f(0.5f, y1, z1);

				glVertex3f(0.5f, y0, z0);
				glVertex3f(0.5f, y1, z1);
				glVertex3f(0.5f, y0, z1);

				glEnd();
			}
		}

		// left face
		for (int o = 0; o < m_segmentsX; o++) {
			for (int p = 0; p < m_segmentsY; p++) {
				float y0 = -0.5f + o * stepX;
				float y1 = -0.5f + (o + 1) * stepX;
				float z0 = -0.5f + p * stepY;
				float z1 = -0.5f + (p + 1) * stepY;

				glBegin(GL_TRIANGLES);

				glNormal3f(-1.0f, 0.0f, 0.0f);

				glVertex3f(-0.5f, y0, z0);
				glVertex3f(-0.5f, y1, z0);
				glVertex3f(-0.5f, y1, z1);

				glVertex3f(-0.5f, y0, z0);
				glVertex3f(-0.5f, y1, z1);
				glVertex3f(-0.5f, y0, z1);

				glEnd();
			}
		}

		// top face
		for (int q = 0; q < m_segmentsX; q++) {
			for (int r = 0; r < m_segmentsY; r++) {
				float x0 = -0.5f + q * stepX;
				float x1 = -0.5f + (q + 1) * stepX;
				float z0 = -0.5f + r * stepY;
				float z1 = -0.5f + (r + 1) * stepY;

				glBegin(GL_TRIANGLES);

				glNormal3f(0.0f, 1.0f, 0.0f);

				glVertex3f(x0, 0.5f, z0);
				glVertex3f(x1, 0.5f, z0);
				glVertex3f(x1, 0.5f, z1);

				glVertex3f(x0, 0.5f, z0);
				glVertex3f(x1, 0.5f, z1);
				glVertex3f(x0, 0.5f, z1);

				glEnd();
			}
		}

		// bottom face
		for (int s = 0; s < m_segmentsX; s++) {
			for (int t = 0; t < m_segmentsY; t++) {
				float x0 = -0.5f + s * stepX;
				float x1 = -0.5f + (s + 1) * stepX;
				float z0 = -0.5f + t * stepY;
				float z1 = -0.5f + (t + 1) * stepY;

				glBegin(GL_TRIANGLES);

				glNormal3f(0.0f, -1.0f, 0.0f);

				glVertex3f(x0, -0.5f, z0);
				glVertex3f(x1, -0.5f, z0);
				glVertex3f(x1, -0.5f, z1);

				glVertex3f(x0, -0.5f, z0);
				glVertex3f(x1, -0.5f, z1);
				glVertex3f(x0, -0.5f, z1);

				glEnd();
			}
		}

	};


	void drawNormal() {

	};

private:
};

#endif