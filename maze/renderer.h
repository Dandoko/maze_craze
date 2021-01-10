#ifndef RENDERER_H
#define RENDERER_H

class Manager;

class Renderer {
private:
	Manager* m_Manager;
public:
	Renderer(Manager* manager);
	Renderer(const Renderer&) = delete;
	virtual ~Renderer();

	void render();
};

#endif