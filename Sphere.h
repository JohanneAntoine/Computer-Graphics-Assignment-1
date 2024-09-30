#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
	Sphere() {};
	~Sphere() {};

	OBJ_TYPE getType() {
		return SHAPE_SPHERE;
	}

	void draw() {

		float angleLongitude = 2 * PI / m_segmentsX;
		float angleLatitude = PI / m_segmentsY;

		float xOffset = 1.0f / m_segmentsX;
		float yOffset = 1.0f / m_segmentsY;
		float radius = 0.5f;

		glBegin(GL_TRIANGLES);

		for (int j = 0; j < m_segmentsY; j++) {
			for (int i = 0; i < m_segmentsX; i++) {
                float theta1 = i * angleLongitude;
                float theta2 = (i + 1) * angleLongitude;
                float phi1 = j * angleLatitude;
                float phi2 = (j + 1) * angleLatitude;

				// triangle 1
				draw_side(0.5 * (sin(phi2) * cos(theta1)), 0.5 * (cos(phi2)), 0.5 * (sin(phi2) * sin(theta1)));
				draw_side((0.5*sin(phi1) * cos(theta1)), 0.5f * (cos(phi1)), 0.5f * (sin(phi1) * sin(theta1)));
				draw_side(0.5 * (sin(phi1) * cos(theta2)), 0.5 * (cos(phi1)), 0.5 * (sin(phi1) * sin(theta2)));
				

				draw_side(0.5 * (sin(phi2) * cos(theta2)), 0.5 * (cos(phi2)), 0.5 * (sin(phi2) * sin(theta2)));
				draw_side(0.5 * (sin(phi2) * cos(theta1)), 0.5 * (cos(phi2)), 0.5 * (sin(phi2) * sin(theta1)));
				draw_side(0.5 * (sin(phi1) * cos(theta2)), 0.5 * (cos(phi1)), 0.5 * (sin(phi1) * sin(theta2)));
				

			}
		}

		glEnd();
	};

	void drawNormal() {
		float angleLongitude = 2 * PI / m_segmentsX;
		float angleLatitude = PI / m_segmentsY;
		glBegin(GL_LINES);
		glColor3f(1.0f, 0, 0);
		for (int j = 0; j < m_segmentsY; j++) {
			for (int  i = 0; i < m_segmentsX; i++)
			{
				float theta1 = i * angleLongitude;
                float theta2 = (i + 1) * angleLongitude;
                float phi1 = j * angleLatitude;
                float phi2 = (j + 1) * angleLatitude;

				glm::vec3 vector(0.5 * (sin(phi1) * cos(theta1)), 0.5 * (cos(phi1)), 0.5 * (sin(phi1) * sin(theta1)));
				glm::vec3 normal = glm::normalize(vector);
				
				glVertex3f(0.5 * (sin(phi1) * cos(theta1)), 0.5 * (cos(phi1)), 0.5 * (sin(phi1) * sin(theta1)));
				glVertex3f(0.6 * (sin(phi1) * cos(theta1)), 0.6 * (cos(phi1)), 0.6 * (sin(phi1) * sin(theta1)));

				glVertex3f(0.5 * (sin(phi1) * cos(theta2)), 0.5 * (cos(phi1)), 0.5 * (sin(phi1) * sin(theta2)));
				glVertex3f(0.6 * (sin(phi1) * cos(theta2)), 0.6 * (cos(phi1)), 0.6 * (sin(phi1) * sin(theta2)));

				glVertex3f(0.5 * (sin(phi2) * cos(theta1)), 0.5 * (cos(phi2)), 0.5 * (sin(phi2) * sin(theta1)));
				glVertex3f(0.6 * (sin(phi2) * cos(theta1)), 0.6 * (cos(phi2)), 0.6 * (sin(phi2) * sin(theta1)));

			}
			
		}
		glEnd();
	};

private:
	void draw_side(float x, float y, float z) {
		glm::vec3 vector(x,y,z);
		glm::vec3 normal = glm::normalize(vector);
		glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(x,y,z);
	}
};

#endif