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
		draw_face(stepX, stepY, 0.5f, 0, 0, 1.0f);

		// back face
		draw_face(stepX, stepY, -0.5f, 0, 0, -1.0f);

		// right face
		draw_face(stepX, stepY, 0.5f, 1.0f, 0, 0);

		// left face
		draw_face(stepX, stepY, -0.5f, -1.0f, 0, 0);

		// top face
		draw_face(stepX, stepY, 0.5f, 0, 1.0f, 0);

		// bottom face
		draw_face(stepX, stepY, -0.5f, 0, -1.0f, 0);

	};


	void drawNormal() {
		float stepX = 1.0f / m_segmentsX;
		float stepY = 1.0f / m_segmentsY;

		// front face
		draw_normal_face(stepX, stepY, 0.5f, 0, 0, 1.0f);

		// back face
		draw_normal_face(stepX, stepY, -0.5f, 0, 0, -1.0f);

		// right face
		draw_normal_face(stepX, stepY, 0.5f, 1.0f, 0, 0);

		// left face
		draw_normal_face(stepX, stepY, -0.5f, -1.0f, 0, 0);

		// top face
		draw_normal_face(stepX, stepY, 0.5f, 0, 1.0f, 0);

		// bottom face
		draw_normal_face(stepX, stepY, -0.5f, 0, -1.0f, 0);

	};

private:
	void draw_face(float stepX, float stepY, float fixedCoordinate, float normalX, float normalY, float normalZ) {

		glBegin(GL_TRIANGLES);

		glNormal3f(normalX, normalY, normalZ);

		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				float v0 = -0.5f + i * stepX;
				float v1 = -0.5f + (i + 1) * stepX;
				float w0 = -0.5f + j * stepY;
				float w1 = -0.5f + (j + 1) * stepY;

				// right or left
				if (normalX == -1.0f) {
					glVertex3f(fixedCoordinate, w0, v1);
					glVertex3f(fixedCoordinate, w1, v1);
					glVertex3f(fixedCoordinate, w1, v0);

					glVertex3f(fixedCoordinate, w0, v1);
					glVertex3f(fixedCoordinate, w1, v0);
					glVertex3f(fixedCoordinate, w0, v0);
				}
				else if (normalX == 1.0f) {
					glVertex3f(fixedCoordinate, w0, v0);
					glVertex3f(fixedCoordinate, w1, v0);
					glVertex3f(fixedCoordinate, w1, v1);

					glVertex3f(fixedCoordinate, w0, v0);
					glVertex3f(fixedCoordinate, w1, v1);
					glVertex3f(fixedCoordinate, w0, v1);
				}

				// top or bottom
				if (normalY == 1.0f) {
					glVertex3f(v1, fixedCoordinate, w0);
					glVertex3f(v0, fixedCoordinate, w0);
					glVertex3f(v0, fixedCoordinate, w1);

					glVertex3f(v1, fixedCoordinate, w0);
					glVertex3f(v0, fixedCoordinate, w1);
					glVertex3f(v1, fixedCoordinate, w1);
				}
				else if (normalY == -1.0f) {
					glVertex3f(v0, fixedCoordinate, w0);
					glVertex3f(v1, fixedCoordinate, w0);
					glVertex3f(v1, fixedCoordinate, w1);

					glVertex3f(v0, fixedCoordinate, w0);
					glVertex3f(v1, fixedCoordinate, w1);
					glVertex3f(v0, fixedCoordinate, w1);
				}

				// front or back
				if (normalZ == -1.0f) {
					glVertex3f(v1, w0, fixedCoordinate);
					glVertex3f(v0, w0, fixedCoordinate);
					glVertex3f(v0, w1, fixedCoordinate);

					glVertex3f(v1, w0, fixedCoordinate);
					glVertex3f(v0, w1, fixedCoordinate);
					glVertex3f(v1, w1, fixedCoordinate);
				}
				else if (normalZ == 1.0f) {
					glVertex3f(v0, w0, fixedCoordinate);
					glVertex3f(v1, w0, fixedCoordinate);
					glVertex3f(v1, w1, fixedCoordinate);

					glVertex3f(v0, w0, fixedCoordinate);
					glVertex3f(v1, w1, fixedCoordinate);
					glVertex3f(v0, w1, fixedCoordinate);
				}
			}
		}

		glEnd();
	}

	void draw_normal_face(float stepX, float stepY, float fixedCoordinate, float normalX, float normalY, float normalZ) {
		float halfsize = 0.5f;
		float normalLineLength = 0.5f;

		glColor3f(0.0f, 1.0f, 0.0f);

		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				float v0 = -halfsize + i * stepX;
				float v1 = -halfsize + (i + 1) * stepX;
				float w0 = -halfsize + j * stepY;
				float w1 = -halfsize + (j + 1) * stepY;

				glBegin(GL_LINES);

				// right or left
				if (normalX == 1.0f || normalX == -1.0f) {
					glVertex3f(fixedCoordinate, w0, v0);
					glVertex3f(fixedCoordinate + normalX * normalLineLength, w0, v0);

					glVertex3f(fixedCoordinate, w1, v0);
					glVertex3f(fixedCoordinate + normalX * normalLineLength, w1, v0);

					glVertex3f(fixedCoordinate, w1, v1);
					glVertex3f(fixedCoordinate + normalX * normalLineLength, w1, v1);

					glVertex3f(fixedCoordinate, w0, v1);
					glVertex3f(fixedCoordinate + normalX * normalLineLength, w0, v1);
				}

				// top or bottom
				else if (normalY == 1.0f || normalY == -1.0f) {
					glVertex3f(v0, fixedCoordinate, w0);
					glVertex3f(v0, fixedCoordinate + normalY * normalLineLength, w0);

					glVertex3f(v1, fixedCoordinate, w0);
					glVertex3f(v1, fixedCoordinate + normalY * normalLineLength, w0);

					glVertex3f(v1, fixedCoordinate, w1);
					glVertex3f(v1, fixedCoordinate + normalY * normalLineLength, w1);

					glVertex3f(v0, fixedCoordinate, w1);
					glVertex3f(v0, fixedCoordinate + normalY * normalLineLength, w1);
				}

				// front or back
				else if (normalZ == 1.0f || normalZ == -1.0f) {
					glVertex3f(v0, w0, fixedCoordinate);
					glVertex3f(v0, w0, fixedCoordinate + normalZ * normalLineLength);

					glVertex3f(v1, w0, fixedCoordinate);
					glVertex3f(v1, w0, fixedCoordinate + normalZ * normalLineLength);

					glVertex3f(v1, w1, fixedCoordinate);
					glVertex3f(v1, w1, fixedCoordinate + normalZ * normalLineLength);

					glVertex3f(v0, w1, fixedCoordinate);
					glVertex3f(v0, w1, fixedCoordinate + normalZ * normalLineLength);
				}

				glEnd();
			}
		}
	}
};

#endif