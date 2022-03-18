#include "trianglesurface.h"
#include <fstream>
#include <iostream>
#include <string>
#include "cube.h"
TriangleSurface::TriangleSurface() : VisualObject()
{
}
TriangleSurface::~TriangleSurface()
{
}
void TriangleSurface::init(GLint matrixUniform) {

    VisualObject::init(matrixUniform);
}

TriangleSurface::TriangleSurface(std::string fileName) : VisualObject()
{
    mMatrix.setToIdentity();
    construct();
    //Read the data and add the vertices to mVertices
    //readFile(fileName);
    //Write trianglesurface data to the file
    //writeFile(fileName);
    CalculateNumerical();
}

void TriangleSurface::readFile(std::string fileName) {
    std::ifstream file(fileName);
    if(file.is_open()){
        //Stores amount of lines
        int amount = 0;
        //Gets the amount, use stoi maybe
        file >> amount;
        //Holder for the vertex data
        Vertex vert;
        mVertices.reserve(amount);
        for(int i = 0; i < amount; i++){
            file >> vert;
            mVertices.push_back(vert);
        }
        file.close();
    }else{
        construct();
    }
}

void TriangleSurface::writeFile(std::string fileName){
    //Write the current trianglesurface to a file
    std::ofstream file(fileName);

    if(file.is_open()){
        //Writes amount of lines
        file << mVertices.size() << "\n";
        //Prints the vertdata to a line
        for(auto i = 0; i < mVertices.size(); i++){
            file << mVertices[i] << "\n";
        }

        file.close();
    }

}

void TriangleSurface::draw()
{
    VisualObject::draw();
    //glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void TriangleSurface::CalculateNumerical(){
    std::ofstream file;

    file.open("b.txt");

        if(file.is_open())
        {
        float xmin= -1.0f, xmax = 1.0f, ymin = 0.0f, ymax  = 1.0f,h = 0.25f, result = 0;
            for(int i = 0; i < 4; i++)
            {
                for(auto x = xmin; x < xmax; x+=h)
                {
                    for(auto y = ymin; y < ymax; y+= h)
                    {
                        float z = func(x, y);
                        result += z;
                    }
                }
            h = h / 2;
            file << result << "\n";
            }
        }
        else
        {
            std::cout << "Failed to write to file.\n";
        }
        file.close();

    //Write to file

}

void TriangleSurface::construct(){
    float xmin=-2.0f, xmax=2.0f, ymin=-2.0f, ymax=2.0f, h=0.1f;
        for (auto x=xmin; x<xmax; x+=h)
        {
           for (auto y=ymin; y<ymax; y+=h)
           {
               float z = func(x, y);
               
               mVertices.push_back(Vertex{x,y,z,x,y,z});
               z = func(x+h,y);
               mVertices.push_back(Vertex{x+h,y,z,x,y,z});
               z = func(x,y+h);
               mVertices.push_back(Vertex{x,y+h,z,x,y,z});
               mVertices.push_back(Vertex{x,y+h,z,x,y,z});
               z = func(x+h,y);
               mVertices.push_back(Vertex{x+h,y,z,x,y,z});
               z = func(x+h,y+h);
               mVertices.push_back(Vertex{x+h,y+h,z,x,y,z});
           }
        }
}
