#include "disc.h"
Disc::Disc()
{
    construct();
}
Disc::Disc(std::string fileName)
{
    readFile(fileName);
}
Disc::~Disc()
{
}
void Disc::readFile(std::string fileName)
{
    std::ifstream inn;
    inn.open(fileName.c_str());

    if (inn.is_open()) {
        int ni, nv, indeks;
        inn >> ni;
        mIndices.reserve(ni);
        inn >> nv;
        mVertices.reserve(nv);

        for (int i = 0; i < ni; i++) { inn >> indeks; mIndices.push_back(indeks); }
        Vertex vertex;
        for (int i = 0; i < nv; i++) { inn >> vertex; mVertices.push_back(vertex); }

        inn.close();
    }
}
void Disc::writeFile(std::string fileName)
{
    //Write the current trianglesurface to a file
    std::ofstream file(fileName);

    if (file.is_open()) {
        //Amount of indices
        file << mIndices.size() << "\n";
        //Writes amount of lines
        file << mVertices.size() << "\n";

        //Prints indices data to line
        for (auto i = 0; i < mIndices.size(); i++) {
            file << mIndices[i] << "\n";
        }

        //Prints the vertdata to a line
        for (auto i = 0; i < mVertices.size(); i++) {
            file << mVertices[i] << "\n";
        }

        file.close();
    }
}
void Disc::init(GLint matrixUniform)
{
    ///
    mMatrixUniform = matrixUniform;
    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<const void*>(0));
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<const void*>(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );
    glGenBuffers(1, &mIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(GLuint), mIndices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);

}

void Disc::draw()
{
    initializeOpenGLFunctions();
    glBindVertexArray(mVAO);
    // GL_FALSE for QMatrix4x4
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
    glDrawElements(GL_TRIANGLE_FAN, mVertices.size(), GL_UNSIGNED_INT, reinterpret_cast<const void*>(0));//mVertices.size());
}

// Konstruerer for TRIANGLE_FAN her
// Hardkodet sektorstørrelse og antall
void Disc::construct()
{
    mVertices.push_back(Vertex{ 0,0,0,1,1,1 });
    for (int i = 0; i < 13; i++)
    {
        double angle = 30 * i * M_PI / 180;
        qDebug() << "angle = " << angle;
        float x = cos(angle);
        float y = sin(angle);
        float z = 0.0f;
        float r = i % 2;
        float g = 0.f;
        float b = 0.5f;
        mVertices.push_back(Vertex{ x,y,z,r,g,b });
    }
    for (GLuint i = 0; i < 14; i++) mIndices.push_back(i);

    writeFile("Disc.txt");
}
void Disc::move(float dt)
{

    float degrees = (180 * dt) / M_PI;
    mRotation.rotate(degrees, 0, 0, 1);

    //Slide
    QVector3D ds = mVelocity * dt;

    // mPosition = mPosition + ds;		// hvis mPosisjon er Vector3d
    mPosition.translate(ds.x(), ds.y(), ds.z());	// hvis mPosisjon er Matrix4x4

    // normalen kan generelt være en parameter inn
    QVector3D normal = QVector3D{ 0.0f, 1.0f, 0.0f };

    // bruker kryssprodukt for å finne rotasjonsvektor
    QVector3D rotation = QVector3D::crossProduct(normal, mVelocity);
    rotation.normalize();


    mMatrix = mPosition * mRotation;		// hvis mPosition og mRotation er Matrix4x4
}


void Disc::move(float dx, float dy, float dz)
{
    pos.mX += dx;
    pos.mY += dy;
    pos.mZ += dz;
    mPosition.translate(dx, dy, dz);
    mMatrix = mPosition * mRotation;
}