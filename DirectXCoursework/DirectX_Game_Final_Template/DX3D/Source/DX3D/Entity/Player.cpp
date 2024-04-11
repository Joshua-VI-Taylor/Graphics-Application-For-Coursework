#include <DX3D/Entity/Player.h>


Player::Player()
{
}

Player::~Player()
{
}

void Player::onCreate()
{
	Entity::onCreate();
	auto cam = createComponent<CameraComponent>();
	cam->setFarPlane(2000.0f);
	getTransform()->setPosition(Vector3D(0, 0, -10.0f));
}



void Player::onUpdate(float deltaTime)
{
	Entity::onUpdate(deltaTime);

	auto transform = getTransform();

	m_forward = 0.0f;
	m_rightward = 0.0f;


	if (getInputSystem()->isKeyDown(Key::W))
	{
		m_forward = 1.0f;
	}
	if (getInputSystem()->isKeyDown(Key::S))
	{
		m_forward = -1.0f;
	}
	if (getInputSystem()->isKeyDown(Key::A))
	{
		m_rightward = -1.0f;
	}
	if (getInputSystem()->isKeyDown(Key::D))
	{
		m_rightward = 1.0f;
	}

	auto deltaPos = getInputSystem()->getDeltaMousePosition();
	auto rot = transform->getRotation();
	rot = rot + Vector3D(deltaPos.m_y * 0.001f, deltaPos.m_x * 0.001f, 0);

	Matrix4x4 world;
	transform->getWorldMatrix(world);

	auto pos = transform->getPosition();
	pos = pos + world.getZDirection() * m_forward * 8.0f * deltaTime;
	pos = pos + world.getXDirection() * m_rightward * 8.0f * deltaTime;

	transform->setPosition(pos);
	transform->setRotation(rot);
}
