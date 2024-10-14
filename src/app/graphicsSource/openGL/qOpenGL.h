#include <qMat.h>
#include <qVec.h>
#include <qLinMat.hpp>
#include <qMesh.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#ifndef QOPENGL_H
#define QOPENGL_H
class glMesh : public qMesh {
    public:
    glMesh(char* filepath) : qMesh(filepath) {
        unsigned int vertexCount = faces.getmSize() * faces.getnSize();
        float* data = faces.toArray();

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(float), data, GL_STATIC_DRAW);

        //position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void*)0);
        glEnableVertexAttribArray(0);

        //color
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 12, (void*)0);
        glEnableVertexAttribArray(1);

        glEnable(GL_CULL_FACE);
    }

    void draw() override {
        // Bind the VAO
        glBindVertexArray(VAO);
        
        // Draw the vertices as triangles
        glDrawArrays(GL_TRIANGLES, 0, faces.getmSize() * sizeof(float)); // Ensure this count matches your vertex data
    }

};
#endif