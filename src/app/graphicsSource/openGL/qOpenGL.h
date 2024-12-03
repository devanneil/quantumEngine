#include <qMat.h>
#include <qVec.h>
#include <qLinMat.hpp>
#include <qMesh.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#ifdef QOPENGL
#ifndef QOPENGL_H
#define QOPENGL_H
    void qMesh::loadData() {
        unsigned int vertexCount = faces.getmSize() * faces.getnSize();
        float* data = faces.toArray();

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), data, GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        //Remove color attribute if not needed
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);

        glEnable(GL_CULL_FACE);
    }

    void qMesh::draw() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, faces.getnSize() * 3); // Ensure correct vertex count
    }
#endif
#endif