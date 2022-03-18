#ifndef VISUALPOINT_H
#define VISUALPOINT_H
#include "visualobject.h"
class VisualPoint : public VisualObject
{
public:
	VisualPoint();
	VisualPoint(const std::vector<Vertex>& v);
	~VisualPoint() override;
	void init(GLint matrixUniform);
	void draw() override;
protected:
	std::vector<std::vector<float>> createMatrix(const int& rows, const int& columns);
	std::vector<std::vector<float>> multiplyMatrixes(const std::vector<std::vector<float>>& a,
		const std::vector<std::vector<float>>& b);
	std::vector<std::vector<float>> transposeMatrix(const std::vector<std::vector<float>>& a);
};
#endif // VISUALPOINT_H
