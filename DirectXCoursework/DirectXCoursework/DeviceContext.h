
#pragma once
#include "IndexBuffer.h"
#include <d3d11.h>
#include "Texture.h"
#include "Prerequisites.h"
class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* device_context, RenderSystem* system);
	void clearRenderTargetColor(const SwapChainPtr& swap_chain, float red, float green, float blue, float alpha);
	void clearDepthStencil(const SwapChainPtr& swap_chain);
	void clearDepthStencil(const TexturePtr& depth_stencil);

	void clearRenderTarget(const TexturePtr& render_target, float red, float green, float blue, float alpha);
	void setRenderTarget(const TexturePtr& render_target, const TexturePtr& depth_stencil);

	void setVertexBuffer(const VertexBufferPtr& vertex_buffer);
	void setIndexBuffer(const IndexBufferPtr& index_buffer);

	void setConstantBuffer(const VertexShaderPtr& vertex_shader,const ConstantBufferPtr& buffer);
	void setConstantBuffer(const PixelShaderPtr& pixel_shader, const ConstantBufferPtr& buffer);

	void drawTriangleList(UINT vertex_count, UINT start_vertex_index);
	void drawTriangleStrip(UINT vertex_count, UINT start_vertex_index);
	void drawIndexedTriangleList(UINT index_count, UINT start_vertex_index, UINT start_index_location);

	void setViewportSize(UINT width, UINT height);

	void setVertexShader(const VertexShaderPtr& vertex_shader);
	void setPixelShader(const PixelShaderPtr& pixel_shader);

	void setTexture(const VertexShaderPtr& vertex_shader, const TexturePtr* texture,unsigned int num_textures);
	void setTexture(const PixelShaderPtr& pixel_shader, const TexturePtr* texture, unsigned int num_textures);
	
	~DeviceContext();
	ID3D11DeviceContext* m_device_context;
private:
	RenderSystem* m_system = nullptr;
private:
	friend class ConstantBuffer;

	
};


