#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

class Cylinder : public Shape {
public:
	Cylinder() {};
	~Cylinder() {};

	OBJ_TYPE getType() {
		return SHAPE_CYLINDER;
	}


	void draw() {
		float angleToRotate = 2 * PI / m_segmentsX;

		glBegin(GL_TRIANGLES);

		segmentHeight = 1.0f / m_segmentsY;
		for (int i = 0; i < m_segmentsX; i++)
		{
			float angle1 = i * angleToRotate;
				float angle2 = (i + 1) * angleToRotate;

			// bottom base
				glNormal3f(0.0f, -1.0f, 0.0f);

				glVertex3f(0.0f, -0.5f, 0.0f);
				glVertex3f(0.5f * cos(angle1), -0.5f, 0.5f * sin(angle1));
				glVertex3f(0.5f * cos(angle2), -0.5f, 0.5f * sin(angle2));

				// Top Base
				glNormal3f(0.0f, 1.0f, 0.0f);

				if (i == 0) {
					glNormal3f(0.0f, 1.0f, 0.0f);
					glVertex3f(0.5f, 0.5f, 0.0f);
				}
				else {
					glNormal3f(0.0f, 1.0f, 0.0f);
					glVertex3f(0.5f * cos(angle1), 0.5f, 0.5f * -sin(angle1));
				}
	
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.5f * cos(angle2), 0.5f, 0.5f * -sin(angle2));
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.0f, 0.5f, 0.0f);

			for (int j = 0; j < m_segmentsY; j++) {
				float y1 = -0.5f + j * segmentHeight;
				float y2 = -0.5f + (j + 1) * segmentHeight;

				float angle1 = i * angleToRotate;
				float angle2 = (i + 1) * angleToRotate;

				


				// body

				glNormal3f(cos(angle1), 0.0f, sin(angle1));
				glVertex3f(0.5f * cos(angle1), y1, 0.5f * sin(angle1));
				glNormal3f(cos(angle2), 0.0f, sin(angle2));
				glVertex3f(0.5f * cos(angle2), y2, 0.5f * sin(angle2));
				glNormal3f(cos(angle2), 0.0f, sin(angle2));
				glVertex3f(0.5f * cos(angle2), y1, 0.5f * sin(angle2));
				

				glNormal3f(cos(angle1), 0.0f, sin(angle1));
				glVertex3f(0.5f * cos(angle1), y1, 0.5f * sin(angle1));
				glNormal3f(cos(angle1), 0.0f, sin(angle1));
				glVertex3f(0.5f * cos(angle1), y2, 0.5f * sin(angle1));
				glNormal3f(cos(angle2), 0.0f, sin(angle2));
				glVertex3f(0.5f * cos(angle2), y2, 0.5f * sin(angle2));
				
			}
		}
		

		

		glEnd();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		//set color 
		glColor3f(1.0f, 0.0f, 0.0f);
		segmentHeight = 1.0/m_segmentsY;
		angleToRotate = 2 * M_PI / m_segmentsX;
		// bottom base
		for (int i = 0; i < m_segmentsX; i++) {
			float angle1 = i * angleToRotate;
			float angle2 = (i + 1) * angleToRotate;

			glVertex3f(0.0f, -0.5f, 0.0f);
			glVertex3f(0.0f, -0.6f, 0.0f);

			glVertex3f(0.5f * cos(angle1), -0.5f, 0.5f * sin(angle1));
			glVertex3f(0.5f * cos(angle1), -0.6f, 0.5f * sin(angle1));

			glVertex3f(0.5f * cos(angle2), -0.6f, 0.5f * sin(angle2));
			glVertex3f(0.5f * cos(angle2), -0.6f, 0.5f * sin(angle2));

			//top base
			glVertex3f(0.0f, 0.5f, 0.0f);
			glVertex3f(0.0f, 0.6f, 0.0f);

			glVertex3f(0.5f * cos(angle1), 0.5f, 0.5f * sin(angle1));
			glVertex3f(0.5f * cos(angle1), 0.6f, 0.5f * sin(angle1));

			glVertex3f(0.5f * cos(angle2), 0.6f, 0.5f * sin(angle2));
			glVertex3f(0.5f * cos(angle2), 0.6f, 0.5f * sin(angle2));

			// normals along the height
			for (int j = 0; j < m_segmentsY; j++) {
				yOffset = j * segmentHeight;
				glVertex3f(0.5f * cos(angle1), -0.5+yOffset, 0.5f * sin(angle1));
				glVertex3f(0.6f * cos(angle1), -0.5+yOffset, 0.6f * sin(angle1));
			}

		}
		glEnd();

	};


private:
	float angleToRotate;
	float yOffset;
	float segmentHeight;
};

#endif