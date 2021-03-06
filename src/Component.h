#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
public:
   Entity* owner;
   virtual ~Component() {}
   virtual void Initalize() {}
   virtual void Update(float deltaTime) {}
   virtual void Render() {}
};

#endif
