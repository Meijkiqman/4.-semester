#ifndef DISC_H
#define DISC_H
#include "visualobject.h"

class Disc : public VisualObject
{
public:
	Disc();
	Disc(std::string fileName);
	~Disc() override;
	void readFile(std::string fileName);
	void writeFile(std::string fileName);
	void init(GLint matrixUniform) override;
	void draw() override;
	void construct();
	void move(float dt) override;
	void move(float dx, float dy, float dz) override;
protected:
	std::vector<GLuint> mIndices;   	// Til indeksering
	GLuint mIBO{ 0 };                 		// for glDrawElements()
	float mRadius{ 0.5 };			// 
};

#endif // DISC_H
