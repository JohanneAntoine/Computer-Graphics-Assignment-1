#ifndef HOURGLASS_H
#define HOURGLASS_H


#include <cmath>
#include "Shape.h"



class Hourglass : public Shape {
    public:
    Hourglass() {};
    ~Hourglass() {};

    OBJ_TYPE getType() {
		return SHAPE_SPECIAL1;
	}

    void draw() {
        float angleToRotate = 2 * M_PI / m_segmentsX;
		draw_base(angleToRotate);
        float yOffset = 0.5/m_segmentsY;
        glBegin(GL_TRIANGLES);
		for (int j = 0; j < m_segmentsY; j++) {
			float lat1 = j * yOffset;
			float lat2 = (j+1) * yOffset;
			//printf("%f \n", yOffset);
			for (int i = 0; i < m_segmentsX; i++) {
				// set the angles
				float angle1 = i * angleToRotate;
				float angle2 = (i+1) * angleToRotate;
				// first normal
				glNormal3f(cos(angle1), 0.5f, sin(angle1));
				//vertex along height
				glVertex3f(0.5f * cos(angle1) * (1-lat1), -0.5f + lat1, 0.5f * sin(angle1) * (1-lat1));
				glVertex3f(0.5f * cos(angle1) * (1-lat2), -0.5f + lat2, 0.5f * sin(angle1) * (1-lat2));
				glNormal3f(cos(angle2), 0.5f, sin(angle2));
				//third vertex
				glVertex3f(0.5f * cos(angle2) * (1-lat1), -0.5f + lat1, 0.5f * sin(angle2) * (1-lat1));

				// 2nd triangle
				//reset normal
				glNormal3f(cos(angle2), 0.5f, sin(angle2));
				glVertex3f(0.5f * cos(angle2)* (1-lat1), -0.5f + lat1, 0.5f * sin(angle2) * (1-lat1));
				glNormal3f(cos(angle1), 0.5f, sin(angle1));
				glVertex3f(0.5f * cos(angle1) * (1-lat2), -0.5f + lat2, 0.5f * sin(angle1) * (1-lat2));
				glNormal3f(cos(angle2), 0.5f, sin(angle2));
				glVertex3f(0.5f * cos(angle2) * (1-lat2), -0.5f + lat2, 0.5f * sin(angle2) * (1-lat2));



                // top half
                glNormal3f(cos(angle1), -0.5f, sin(angle1));
				//vertex along height
				glVertex3f(0.5f * cos(angle1) * (1-lat1), 0.5f - lat1, 0.5f * sin(angle1) * (1-lat1));
				glVertex3f(0.5f * cos(angle1) * (1-lat2), 0.5f - lat2, 0.5f * sin(angle1) * (1-lat2));
				glNormal3f(cos(angle2), -0.5f, sin(angle2));
				//third vertex
				glVertex3f(0.5f * cos(angle2) * (1-lat1), 0.5f - lat1, 0.5f * sin(angle2) * (1-lat1));

				// 2nd triangle
				//reset normal
				glNormal3f(cos(angle2), -0.5f, sin(angle2));
				glVertex3f(0.5f * cos(angle2)* (1-lat1), 0.5f - lat1, 0.5f * sin(angle2) * (1-lat1));
				glNormal3f(cos(angle1), -0.5f, sin(angle1));
				glVertex3f(0.5f * cos(angle1) * (1-lat2), 0.5f - lat2, 0.5f * sin(angle1) * (1-lat2));
				glNormal3f(cos(angle2),- 0.5f, sin(angle2));
				glVertex3f(0.5f * cos(angle2) * (1-lat2), 0.5f - lat2, 0.5f * sin(angle2) * (1-lat2));

			}


		}
        glEnd();

    };

private:
    void draw_base(float angle) {



		glBegin(GL_TRIANGLES);
        // bottom base
		for (int i = 0; i < m_segmentsX; i++) {

            float angle1 = i * angle;
            float angle2 = (i + 1) * angle;

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

            // top base
            glNormal3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, 0.5f, 0.0f);

            if (i == 0) {
                glNormal3f(0.0f, 1.0f, 0.0f);
                glVertex3f(0.5f, 0.5f, 0.0f);
            }
            else {
                glNormal3f(0.0f, 1.0f, 0.0f);
                glVertex3f(0.5f * cos(angle1), 0.5f, 0.5f * sin(angle1));
            }

            glNormal3f(0.0f, -1.0f, 0.0f);
            glVertex3f(0.5f * cos(angle2), 0.5f, 0.5f * sin(angle2));
		}

		glEnd();

	}
};
#endif