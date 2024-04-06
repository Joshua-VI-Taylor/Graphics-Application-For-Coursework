#pragma once
#include "Resource.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "GraphicsEngine.h"
#include "VertexMesh.h"
#include <vector>
#include "Vector3D.h"
struct MaterialSlot {

	size_t start_index = 0;

	size_t num_indices;

	size_t material_id;

};



class Mesh:public Resource
{
public:
	Mesh(const wchar_t* full_path);
	~Mesh();
	const VertexBufferPtr& getVertexBuffer();
	const IndexBufferPtr& getIndexBuffer();
	const MaterialSlot& getMaterialSlot(unsigned int slot);
	size_t getNumMaterialSlots();
private:
	VertexBufferPtr m_vertex_buffer;
	IndexBufferPtr m_index_buffer;
	std::vector<MaterialSlot> m_material_slots;
	void calculateTangents(const Vector3D& v0, const Vector3D& v1, const Vector3D& v2,const Vector2D& t0, const Vector2D& t1, const Vector2D& t2,Vector3D& tangent, Vector3D& binormal);
private:
	friend class DeviceContext;
};

