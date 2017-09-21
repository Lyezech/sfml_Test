#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My shitty thing", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Green);
	float momentumx = 0.0;
	float momentumy = 0.0;
	float friction = 0.0001;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		//player movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			momentumy -= 0.00001;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			if(momentumx > 0.0)
				momentumx *= -.6;
			else
			momentumx -= 0.00001;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			momentumy += 0.00001;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			if (momentumx < 0.0)
				momentumx *= -.6;
			else
				momentumx += 0.00001;
		}

		momentumx += -momentumx*friction;
		momentumy += -momentumy*friction;
		player.move(momentumx, momentumy);


		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}