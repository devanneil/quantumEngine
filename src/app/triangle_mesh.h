#include<vector>
#include<qOpenGL.h>

class TriangleMesh {
public:
TriangleMesh();
void draw();
~TriangleMesh();

private:
unsigned int VBO, VAO, vertex_count;
};