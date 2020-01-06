
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <string>

class Entity;

class EntityManager {
public:
   void ClearData();
   void Update(float deltaTime);
   void Render();
   bool HasNoEntities();
   Entity& AddEntity(std::string entityName);
   std::vector<Entity*> GetEntities() const;
   std::size_t GetEntityCount();

private:
   std::vector<Entity*> entities;

};


#endif
