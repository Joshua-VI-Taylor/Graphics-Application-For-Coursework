
#pragma once
#include <d3d11.h> 
#include <wrl.h>
#include <DX3D/Prerequisites.h>


class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* device_context, RenderSystem * system);

	void clearRenderTargetColor(const SwapChainPtr& swap_chain,float red, float green, float blue, float alpha);
	void clearDepthStencil(const SwapChainPtr& swap_chain);

	//void clearRenderTarget(const TexturePtr& render_target, float red, float green, float blue, float alpha);
	//void clearDepthStencil(const TexturePtr& depth_stencil);

	//void setRenderTarget(const TexturePtr& render_target, const TexturePtr& depth_stencil);
	//
	void setVertexBuffer(const VertexBufferPtr& vertex_buffer);
	void setIndexBuffer(const IndexBufferPtr& index_buffer);


	void drawTriangleList(UINT vertex_count, UINT start_vertex_index);
	void drawIndexedTriangleList(UINT index_count, UINT start_vertex_index, UINT start_index_location);
	void drawTriangleStrip(UINT vertex_count, UINT start_vertex_index);

	void setViewportSize(UINT width, UINT height);

	void setVertexShader(const VertexShaderPtr& vertex_shader);
	void setPixelShader(const PixelShaderPtr& pixel_shader);

	//void setTexture(const VertexShaderPtr& vertex_shader, const TexturePtr* texture, unsigned int num_textures);
	void setTexture(const Texture2DPtr* texture, unsigned int num_textures);

	void setConstantBuffer(const ConstantBufferPtr& buffer);
private:
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_device_context;
	RenderSystem * m_system = nullptr;
private:
	friend class ConstantBuffer;
};

