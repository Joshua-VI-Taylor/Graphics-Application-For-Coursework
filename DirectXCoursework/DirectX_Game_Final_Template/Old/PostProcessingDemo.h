/*MIT License

C++ 3D Game Tutorial Series (https://github.com/PardCode/CPP-3D-Game-Tutorial-Series)

Copyright (c) 2019-2022, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/


#pragma once
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/VertexBuffer.h>
#include <DX3D/Graphics/IndexBuffer.h>
#include <DX3D/Graphics/ConstantBuffer.h>
#include <DX3D/Graphics/VertexShader.h>
#include <DX3D/Graphics/PixelShader.h>
#include "InputListener.h"
#include "Matrix4x4.h"


class PostProcessingDemo : public Window, public InputListener
{
public:
	PostProcessingDemo();
	~PostProcessingDemo();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
	virtual void onFocus() override;
	virtual void onKillFocus() override;
	virtual void onSize() override;


	// Inherited via InputListener
	virtual void onKeyDown(int key) override;
	virtual void onKeyUp(int key) override;
	virtual void onMouseMove(const Point& mouse_pos) override;

	virtual void onLeftMouseDown(const Point& mouse_pos) override;
	virtual void onLeftMouseUp(const Point& mouse_pos) override;
	virtual void onRightMouseDown(const Point& mouse_pos) override;
	virtual void onRightMouseUp(const Point& mouse_pos) override;
public:
	void render();
	void update();
	void updateModel(Vector3D position, Vector3D rotation, Vector3D scale, const std::vector<MaterialPtr>& list_materials);
	void updateCamera();
	void updateThirdPersonCamera();
	void updateSkyBox();
	void updateLight();
	void updateSpaceship();
	void drawMesh(const MeshPtr& mesh, const std::vector<MaterialPtr>& list_materials/* MaterialPtr* list_materials, unsigned int size_list_materials*/);
	void updateViewportProjection();
private:
	SwapChainPtr m_swap_chain;

	TexturePtr m_spaceship_tex;
	MeshPtr m_spaceship_mesh;
	MaterialPtr m_spaceship_mat;

	TexturePtr m_asteroid_tex;
	MeshPtr m_asteroid_mesh;
	MaterialPtr m_asteroid_mat;

	TexturePtr m_sky_tex;
	MeshPtr m_sky_mesh;
	MaterialPtr m_sky_mat;


	MaterialPtr m_base_mat;

	TexturePtr m_render_target;
	TexturePtr m_depth_stencil;

	MeshPtr m_quad_mesh;
	MaterialPtr m_post_process_mat;

private:
	long m_old_delta;
	long m_new_delta;
	float m_delta_time;

	float m_current_cam_distance;
	float m_cam_distance = 14.0f;
	Vector3D m_current_cam_rot;
	Vector3D m_cam_rot;
	Vector3D m_cam_pos;

	float m_spaceship_speed = 125.0f;

	Vector3D m_current_spaceship_pos;
	Vector3D m_spaceship_pos;

	Vector3D m_current_spaceship_rot;
	Vector3D m_spaceship_rot;

	float m_delta_mouse_x = 0.0f, m_delta_mouse_y = 0.0f;

	Vector3D m_asteroids_pos[200];
	Vector3D m_asteroids_rot[200];
	Vector3D m_asteroids_scale[200];

	float m_forward = 0.0f;
	float m_rightward = 0.0f;

	bool m_turbo_mode = false;
	bool cull = true;
	Matrix4x4 m_world_cam;
	Matrix4x4 m_view_cam;
	Matrix4x4 m_proj_cam;

	float m_time = 0.0f;
	bool m_anim = false;

	Matrix4x4 m_light_rot_matrix;
	bool m_play_state = false;
	bool m_fullscreen_state = false;
	std::vector<MaterialPtr> m_list_materials;
	Vector4D m_light_position;


	float m_distortion_level = 1.0f;
};

