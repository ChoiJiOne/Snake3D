#include "GameObject/IGameObject.h"

#include "Manager/ObjectManager.h"

void IGameObject::SetUpdateOrder(int32_t updateOrder)
{
	updateOrder_ = updateOrder;
	ObjectManager::Get().SetNeedsToBeSortedUpdate(true);
}

void IGameObject::SetRenderOrder(int32_t renderOrder)
{
	renderOrder_ = renderOrder;
	ObjectManager::Get().SetNeedsToBeSortedRender(true);
}