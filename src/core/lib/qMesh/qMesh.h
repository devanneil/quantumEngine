#include <qVec.h>
#include <qMat.h>
#include <vector>
#ifndef QMESH_H
#define QMESH_H
class qMesh {
    public:
    qMat<float> vertexes;
    qMat<float> faces;
    qMat<float> UVs;
    qMat<float> normals;
    //Values for loading data
#ifdef QOPENGL //OpenGL Module
    unsigned int VBO, VAO, vertex_count;
#endif
    public:
    qMesh() {
        vertexes = qMat<float>();
        faces = qMat<float>();
        UVs = qMat<float>();
        normals = qMat<float>();
    }
    qMesh(char* filePath);
    qMesh(int size);
    ~qMesh() {
        
    };
    void setFace(int ind, qVec<float> v1, qVec<float> v2, qVec<float> v3);

    void draw();
    void loadData();
};
#endif