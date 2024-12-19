#include "qMesh.h"
#include <cstring>
#include <iostream>
#ifndef QMESH
#define QMESH
qMesh::qMesh(char* filepath) {
    std::vector<qVec<float>*> temp_vertices, temp_uvs, temp_normals;
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    FILE * file = fopen(filepath, "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
    }
    while( 1 ){
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF) break; // EOF = End Of File. Quit the loop.
        float v1 = 0, v2 = 0, v3 = 0;
        if ( strcmp( lineHeader, "v" ) == 0 ){
            fscanf(file, "%f %f %f\n", &v1, &v2, &v3);
            temp_vertices.push_back(new qVec<float> {v1, v2, v3});
        }else if ( strcmp( lineHeader, "vt" ) == 0 ){
            qVec<float> uv = qVec<float>(2);
            fscanf(file, "%f %f\n", &v1, &v2 );
            temp_uvs.push_back(new qVec<float> {v1, v2});
        }else if ( strcmp( lineHeader, "vn" ) == 0 ){
            fscanf(file, "%f %f %f\n", &v1, &v2, &v3);
            temp_normals.push_back(new qVec<float> {v1, v2, v3});
        }else if ( strcmp( lineHeader, "f" ) == 0 ){
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }
    if(vertexIndices.size() % 3 != 0) {
        printf("Invalid face");
    }
    this->vertexes = qMat<float>(temp_vertices.size(), 3);
    this->faces = qMat<float>((int)(vertexIndices.size() / 3), 9);
    this->UVs = qMat<float>(temp_uvs.size(), 2);
    this->normals = qMat<float>(3, temp_normals.size());
    for (unsigned int i = 0; i < vertexIndices.size(); i += 3) {
        for (int j = 0; j < 3; j++) { // Loop over the three vertices of each face
            unsigned int vertexIndex = vertexIndices[i + j] - 1; // Get the correct vertex index (1-based to 0-based)
            // Set the x, y, z components for this face's j-th vertex
            this->faces[i / 3][3 * j + 0] = temp_vertices[vertexIndex]->getValue(0); // x component
            this->faces[i / 3][3 * j + 1] = temp_vertices[vertexIndex]->getValue(1); // y component
            this->faces[i / 3][3 * j + 2] = temp_vertices[vertexIndex]->getValue(2); // z component
        }
    }
    for(qVec<float>* v : temp_vertices) delete(v);
    loadData();
}
qMesh::qMesh(int size) {
    vertexes = qMat<float>(3, size);
    faces = qMat<float>(9, size);
    UVs = qMat<float>(2, size);
    normals = qMat<float>(3, size);
}
void qMesh::setFace(int ind, qVec<float> v1, qVec<float> v2, qVec<float> v3) {
    if(ind > faces.getnSize() || ind < 0) {
        throw std::out_of_range("Index out of bournds!");
    }
    qVec<float> row = qVec<float>(9);
    row[0] = v1[0];
    row[1] = v1[1];
    row[2] = v1[2];
    row[3] = v2[0];
    row[4] = v2[1];
    row[5] = v2[2];
    row[6] = v3[0];
    row[7] = v3[1];
    row[8] = v3[2];
    faces.set(ind, row);
    loadData();
}
#endif