#include "triangle_mesh.h"

TriangleMesh::TriangleMesh() {
    
    vertices = new qMat<float>({
        {-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f},
        {0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f}
    });
    vertex_count = 3;
    float* data = vertices->toArray();

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 3 * 6 * sizeof(float), data, GL_STATIC_DRAW);

    //position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
    glEnableVertexAttribArray(0);

    //color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)12);
    glEnableVertexAttribArray(1);

    delete[] data;
    data = nullptr;
}
void TriangleMesh::draw() {        
    // Draw the triangles
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}

TriangleMesh::~TriangleMesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}