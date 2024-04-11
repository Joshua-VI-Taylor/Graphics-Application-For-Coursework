#pragma once
#include <DX3D/Prerequisites.h>
#include <DX3D/Entity/Component/Component.h>
#include <DX3D/Math/Rect.h>
#include <DX3D/Math/Matrix4x4.h>
class CameraComponent:public Component
{
public:
	CameraComponent();
	virtual~CameraComponent();

	void getViewMatrix(Matrix4x4& view);
	void getProjectionMatrix(Matrix4x4& proj);


	void setFarPlane(float farPlane);
	float getFarPlane();

	void setNearPlane(float nearPlane);
	float getNearPlane();

	void setFieldOfView(float fieldOfView);
	float getFieldOfView();

	void setType(const CameraType& type);
	CameraType getType();

	void setScreenArea(const Rect& area);
	Rect getScreenArea();

private:
	void computeProjectionMatrix();
protected:
	virtual void onCreateInternal();
private:
	Matrix4x4 m_projection;

	f32 m_nearPlane = 0.01f;
	f32 m_farPlane = 10000.0f;
	f32 m_fieldOfView = 1.3f;
	CameraType m_type = CameraType::Perspective;
	Rect m_screenArea;
};
