#include "stdafx.h"

class Object : public sf::Drawable
{
public:
	Object()
	{
		m_vertices = nullptr;
		m_texture = nullptr;
	}

	~Object()
	{
		delete[] m_vertices;
		delete m_texture;
	}

	void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(m_vertices, 4, sf::PrimitiveType::Quads, m_state);
	}

	void Update(float deltatime)
	{
		m_transform.rotate(deltatime * 180.0f / 3.141592f);
		m_state.transform = m_transform.getTransform();
	}

	void Initialize()
	{
		m_vertices = new sf::Vertex[4];
		m_vertices[0].position = sf::Vector2f(0.0f, 0.0f);
		m_vertices[1].position = sf::Vector2f(256.0f, 0.0f);
		m_vertices[2].position = sf::Vector2f(256.0f, 256.0f);
		m_vertices[3].position = sf::Vector2f(0.0f, 256.0f);

		m_vertices[0].color = sf::Color::Red;
		m_vertices[1].color = sf::Color::Green;
		m_vertices[2].color = sf::Color::Magenta;
		m_vertices[3].color = sf::Color::Cyan;

		m_vertices[0].texCoords = sf::Vector2f(0.0f, 0.0f);
		m_vertices[1].texCoords = sf::Vector2f(200.0f, 0.0f);
		m_vertices[2].texCoords = sf::Vector2f(200.0f, 200.0f);
		m_vertices[3].texCoords = sf::Vector2f(0.0f, 200.0f);

		m_texture = new sf::Texture;
		m_texture->loadFromFile("");
		m_texture->setSmooth(true);

		m_state = sf::RenderStates(m_texture);
		m_state.blendMode = sf::BlendAlpha; //Should be by default

		m_transform.setOrigin(128.0f, 128.0f);
		m_transform.setPosition(128.0f, 128.0f);
	}

private:
	sf::Vertex* m_vertices;
	sf::Texture* m_texture;
	sf::RenderStates m_state;
	sf::Transformable m_transform;
};

/*
Object obj;
obj.Initialize();

obj.Update(0.01f);3
window.draw(obj);
*/