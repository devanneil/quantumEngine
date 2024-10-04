#include "triangle_mesh.h"
float angle = 0;
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
#include <cmath> // For sin and cos

void rotateVertices(qMat<float>& vertices, float angle) {
    // Convert angle to radians
    float radians = angle * (M_PI / 180.0f); // Assuming angle is in degrees

    // Create rotation matrix around the Z-axis
    qMat<float> rotationMatrix({
        {cos(radians), -sin(radians), 0, 0, 0, 0},
        {sin(radians), cos(radians), 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, cos(radians), -sin(radians), 0},
        {0, 0, 0, sin(radians), cos(radians), 0},
        {0, 0, 0, 0, 0, 1}
    });

    // Multiply each vertex by the rotation matrix
    for (int i = 0; i < vertices.getnSize(); i++) {
        //NOTE This code causes double free error on linux system, needs further investigation
        // qVec<float> vertex = vertices[i]; // Assuming getRows() returns the number of rows
        // qVec<float> rotatedVertex = vectorMultiply(vertex, rotationMatrix); // Implement this multiplication
        // vertices[i] = rotatedVertex; // Store the rotated vertex back
        //Working Linux code
        vertices[i] = vectorMultiply(vertices[i], rotationMatrix);
    }
}
void TriangleMesh::draw() {
    rotateVertices(*vertices, angle);
    angle += 0.001;
    
    float* data = vertices->toArray();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * 6 * sizeof(float), data);
    
    // Draw the triangles
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);

    // Free the data array after updating the buffer
    delete[] data;
    data = nullptr;
}

TriangleMesh::~TriangleMesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}