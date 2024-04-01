
#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include "RenderSystem.h"
#include "TextureManager.h"
#include "MeshManager.h"
class GraphicsEngine
{
public:
	GraphicsEngine();
	//Initialize the GraphicsEngine and DirectX 11 Device

	
	~GraphicsEngine();
public:
	RenderSystem* getRenderSystem();
	TextureManager* getTextureManager();
	MeshManager* getMeshManager();
	void getVertexMeshLayoutShaderByCodeAndSize(void** byte_code,size_t*size);
public:
	static GraphicsEngine* get();
public:
	
	static void create();
	static void release();
private:
	RenderSystem* m_render_system = nullptr;
	static GraphicsEngine* m_engine;
	TextureManager* m_tex_manager=nullptr;
	MeshManager* m_mesh_manager = nullptr;
	unsigned char m_mesh_layout_byte_code[1024];
	size_t m_mesh_layout_size = 0;
};


