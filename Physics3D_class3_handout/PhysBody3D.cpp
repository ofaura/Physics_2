#include "PhysBody3D.h"
#include "glmath.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// TODO 4: Fill in PhysBody methods. Remember to use 
// get/setOpenGLMatrix methods

// ---------------------------------------------------------
PhysBody3D::PhysBody3D(btRigidBody* body)
{
	this->body = body;
}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	body->getWorldTransform().getOpenGLMatrix(matrix);
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	btTransform* transform = new btTransform();
	transform->setFromOpenGLMatrix(matrix);

	body->setWorldTransform(*transform);
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	body->translate({ x, y, z });
}
