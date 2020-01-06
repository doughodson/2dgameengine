#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

class EntityManager;
class Component;

class Entity {
public:
   std::string name;
   Entity(EntityManager& manager);
   Entity(EntityManager& manager, std::string name);
   void Update(float deltaTime);
   void Render();
   void Destroy();
   bool IsActive() const { return isActive; }

private:
   EntityManager& manager;
   bool isActive{true};
   std::vector<Component*> components;
};



#endif

