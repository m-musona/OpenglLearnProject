#ifndef MESH_H
#define MESH_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Renderer.h"

#include <string>
#include <vector>

#define MAX_BONE_INFLUENCE 4

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;

};

struct ModelTexture {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh {
public:
	// Mesh Data
	std::vector<Vertex> m_Vertices;
	std::vector<unsigned int> m_Indices;
	std::vector<ModelTexture> m_Textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<ModelTexture> textures);
	void Draw(Shader& shader);
private:
	// render data
	unsigned int VAO, VBO, IBO;
	void setupMesh();
};

#endif // !MESH_H

