
#include "Entity.h"
#include "EntityManager.h"
#include "Component.h"

Entity::Entity(EntityManager& manager): manager(manager) {
}

Entity::Entity(EntityManager& manager, std::string name): manager(manager), name(name) {
}

void Entity::Update(float deltaTime) {
   for (auto& component: components) {
      component->Update(deltaTime);
   }
}

void Entity::Render() {
   for (auto& component: components) {
      component->Render();
   }
}

void Entity::Destroy() {
   isActive = false;
}
