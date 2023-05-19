# include <time.h>
# include <SFML/Graphics.hpp>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace sf;

#define FONT "DeJaVuSans.ttf"

#define sprintf_s(buffer, buffer_size, stringbuffer, ...) (sprintf(buffer, stringbuffer, __VA_ARGS__))

#define MIN(a, b) a < b ? a : b // if a < b - return a, else - return b

#define SCREEN_W 1024
#define SCREEN_H 768
#define PADDING 64
#define MAP_W 36
#define MAP_H 30
#define COLORS 17

const Color colors[] = {
	Color(0xDC143Cff), // Crimson
	Color(0xFF1493ff), // Deep Pink
	Color(0xFF4500ff), // Orange-Red
	Color(0x800080ff), // Purple
	Color(0x4B0082ff), // Indigo
	Color(0x008000ff), // Green
	Color(0x808000ff), // Olive
	Color(0x008B8Bff), // Dark Cyan
	Color(0x008080ff), // Teal
	Color(0x4169E1ff), // Royal Blue
	Color(0x696969ff), // Dim Grey
	Color(0x7B68EEff), // Medium Slate Blue
	Color(0xFF6347ff), // Tomato
	Color(0xFF69B4ff), // Hot Pink
	Color(0x9ACD32ff), // Yellow Green
	Color(0x8FBC8Fff), // Dark Sea Green
	Color(0x483D8Bff) // Dark Slate Blue
};


// objects and textures
RenderWindow* window;

Texture* gridTex, * fieldTex, * rotateIconTex, * skipTurnTex, * paintIconTex;

RectangleShape* gridRect, * fieldRect, * rect, * rotateIconRect, * skipTurnRect, * paintIconRect;

Font* fnt;

Text* text;

Color p1color = Color(0xDC143Cff);
Color p2color = Color(0x32CD32ff);

int cellSize = 0;

int** map; // two-dimensional array

// new variables
int skip1 = 0, skip2 = 0;
char buf[128]; // buffer
int turn = -1;
int rw, rh;
int p1s = 0, p2s = 0;

bool gameOver = false;
int cx = -1;
int cy = -1;
int placeX = -1;
int placeY = -1;
int lastX = -1;
int lastY = -1;

std::vector<IntRect> p1Rects;
std::vector<IntRect> p2Rects;

// ������� ���������� �����
void prerenderGrid() {

	sf::RenderTexture* rTex = new sf::RenderTexture();
	rTex->create(MAP_W * cellSize, MAP_H * cellSize);

	sf::RectangleShape* gridShape = new sf::RectangleShape();
	gridShape->setSize(sf::Vector2f(cellSize - 2, cellSize - 2));
	gridShape->setOutlineColor(sf::Color(66, 66, 66, 255));
	gridShape->setOutlineThickness(1.0f);
	gridShape->setFillColor(sf::Color::Transparent);

	rTex->clear(sf::Color::Transparent);

	for (int i = 0; i < MAP_W; i++) {
		for (int j = 0; j < MAP_H; j++) {
			gridShape->setPosition(sf::Vector2f(cellSize * i + 1, cellSize * j + 1));
			rTex->draw(*gridShape);
		}
	}

	rTex->display();

	gridTex = new sf::Texture(rTex->getTexture());

	delete gridShape;
	delete rTex;
}


void updateFieldTex() {
	RenderTexture* rTex = new RenderTexture();
	rTex->create(MAP_W * cellSize, MAP_H * cellSize);

	float gridw = MAP_W * cellSize;
	float gridh = MAP_H * cellSize;

	rTex->clear(Color::Transparent);
	rTex->draw(*gridRect);
	
	// P1
	Color col = p1color;
	rect->setOutlineColor(col);
	col.a = 164;
	rect->setFillColor(col);
	
	text->setOutlineThickness(0.5f);
	text->setCharacterSize(16);
	text->setOutlineColor(Color::White);
	text->setFillColor(Color::White);

	for (auto it = p1Rects.begin(); it != p1Rects.end(); ++it) {
		IntRect r = *it;
		
		rect->setSize(Vector2f(r.width * cellSize - 4, r.height * cellSize - 4));
		rect->setPosition(Vector2f(cellSize * r.left + 2, cellSize * r.top + 2));
		
		rTex->draw(*rect);

		// Text
		sprintf_s(buf, 128, "%d", r.width * r.height);
		text->setString(String(buf));
		FloatRect bounds = text->getLocalBounds();

		float tx = (cellSize * r.left) + ((r.width * cellSize) - bounds.width) / 2;
		float ty = (cellSize * r.top) + ((r.height * cellSize) - bounds.height) / 2 - 4;
		
		text->setPosition(tx, ty);
		rTex->draw(*text);
	}



	// P2
	Color col2 = p2color;
	rect->setOutlineColor(col2);
	col2.a = 164;
	rect->setFillColor(col2);

	text->setOutlineThickness(0.5f);
	text->setCharacterSize(16);
	text->setOutlineColor(Color::White);
	text->setFillColor(Color::White);

	for (auto it2 = p2Rects.begin(); it2 != p2Rects.end(); ++it2) {
		IntRect r = *it2;

		rect->setSize(Vector2f(r.width * cellSize - 4, r.height * cellSize - 4));
		rect->setPosition(Vector2f(cellSize * r.left + 2, cellSize * r.top + 2));

		rTex->draw(*rect);

		// Text
		sprintf_s(buf, 128, "%d", r.width * r.height);
		text->setString(String(buf));
		FloatRect bounds = text->getLocalBounds();

		float tx = (cellSize * r.left) + ((r.width * cellSize) - bounds.width) / 2;
		float ty = (cellSize * r.top) + ((r.height * cellSize) - bounds.height) / 2 - 4;

		text->setPosition(tx, ty);
		rTex->draw(*text);
	}
}

void NextTurn() {
	turn++;
	rw = 1 + rand() % 6;
	rh = 1 + rand() % 6;
}

// ������� ������ ����� (����� �� ������������ ��� ����� ��� ��������� ������)
bool canPlace(int x, int y) {
	if (x < 0 || y < 0 || x > MAP_W - rw || y > MAP_H - rh) {
		return false;
	}

	// ���������� � ����� ��� ������ ����
	int player = turn % 2;
	if (player == 0 && p1Rects.size() == 0 && x == 0 && y == 0) {
		return true;
	}
	if (player == 1 && p2Rects.size() == 0 && x == MAP_W - rw && y == MAP_H - rh) {
		return true;
	}

	//Can't overlap other rects
	for (int i = x; i < x + rw; i++) {
		for (int j = y; j < y + rh; j++) {
			if (map[i][j] == 0 || map[i][j] == 1) {
				return false;
			}
		}
	}

	//Check neighbors
	for (int i = x; i < x + rw; i++) {
		if (y - 1 >= 0 && map[i][y - 1] == player) {
			return true;
		}
		if (y + rh < MAP_H && map[i][y + rh] == player) {
			return true;
		}
	}

	for (int i = y; i < y + rh; i++) {
		if (x - 1 >= 0 && map[x - 1][i] == player) {
			return true;
		}
		if (x + rw < MAP_W && map[x + rw][i] == player) {
			return true;
		}
	}

	return false;
}

// ������� �����
void place(int x, int y) {
	if (x < 0 || y < 0 || x > MAP_W - rw || y > MAP_H - rh) {
		return;
	}

	int player = turn % 2;
	for (int i = x; i < x + rw; i++) {
		for (int j = y; j < y + rh; j++) {
			map[i][j] = player;
		}
	}

	if (player == 0) {
		p1Rects.push_back(sf::IntRect(x, y, rw, rh));
		p1s += rw * rh;
		skip1 = 0;
	}
	else {
		p2Rects.push_back(sf::IntRect(x, y, rw, rh));
		p2s += rw * rh;
		skip2 = 0;
	}

	updateFieldTex();
	fieldRect->setTexture(fieldTex, true);
	NextTurn();
}


int main() {

	srand((unsigned)time(0));

	cellSize = MIN((SCREEN_W - PADDING * 2) / MAP_W, (SCREEN_H - PADDING * 2) / MAP_H);
	map = new int* [MAP_W];
	for (int i = 0; i < MAP_W; i++)
		map[i] = new int[MAP_H];

	for (int i = 0; i < MAP_W; i++) {
		for (int j = 0; j < MAP_H; j++) {
			map[i][j] = -1;
		}
	}

	fnt = new Font();
	fnt->loadFromFile("DejaVuSans.ttf");
	text = new Text();
	text->setFont(*fnt);

	rotateIconTex = new sf::Texture();
	rotateIconTex->loadFromFile("rotate.png");

	skipTurnTex = new sf::Texture();
	skipTurnTex->loadFromFile("skip.png");

	paintIconTex = new sf::Texture();
	paintIconTex->loadFromFile("fill.png");

	float gridx = (SCREEN_W - MAP_W * cellSize) / 2;
	float gridy = (SCREEN_H - MAP_H * cellSize) / 2;
	float gridw = MAP_W * cellSize;
	float gridh = MAP_H * cellSize;

	window = new sf::RenderWindow(sf::VideoMode(SCREEN_W, SCREEN_H), "Cubes");
	window->setFramerateLimit(60);

	gridRect = new sf::RectangleShape();
	gridRect->setSize(sf::Vector2f(gridw, gridh));
	gridRect->setTexture(gridTex, true);
	gridRect->setPosition(sf::Vector2f(0, 0));

	fieldRect = new sf::RectangleShape();
	fieldRect->setSize(sf::Vector2f(gridw, gridh));
	fieldRect->setTexture(fieldTex, true);
	fieldRect->setPosition(sf::Vector2f(gridx, gridy));

	rotateIconRect = new sf::RectangleShape();
	rotateIconRect->setTexture(rotateIconTex);
	rotateIconRect->setSize(sf::Vector2f(32, 32));
	rotateIconRect->setPosition(10, 64);

	skipTurnRect = new sf::RectangleShape();
	skipTurnRect->setTexture(skipTurnTex);
	skipTurnRect->setSize(sf::Vector2f(32, 32));
	skipTurnRect->setPosition(10, 106);

	paintIconRect = new sf::RectangleShape();
	paintIconRect->setTexture(paintIconTex);
	paintIconRect->setSize(sf::Vector2f(32, 32));
	paintIconRect->setPosition(10, 148);

	prerenderGrid();
	updateFieldTex();
	NextTurn();

	while (window->isOpen()) {
		sf::Event evt;
		while (window->pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) {
				window->close();
			}
		}

		window->clear(Color::Black);
		window->draw(*fieldRect);

		//UI
		window->draw(*rotateIconRect);
		window->draw(*skipTurnRect);
		window->draw(*paintIconRect);

		// print text
		text->setFillColor(Color(0x696969ff));
		text->setCharacterSize(15);
		text->setOutlineThickness(0);

		text->setFillColor(turn % 2 == 0 ? p1color : p2color);

		sprintf_s(buf, 128, "Turn: %d, Player: %d", turn +1, turn % 2 + 1);
		text->setString(String(buf));
		text->setPosition(Vector2f(10, 10));
		window->draw(*text);

		sprintf_s(buf, 128, "%d x %d", rw, rh);
		text->setString(String(buf));
		text->setPosition(Vector2f(10, 25));
		window->draw(*text);

		sprintf_s(buf, 128, "Player1 total squares: %d, skips: %d", p1s, skip1);
		text->setString(String(buf));
		text->setPosition(Vector2f(10, 720));
		window->draw(*text);

		sprintf_s(buf, 128, "Player2 total squares: % d, skips: % d", p2s, skip2);
		text->setString(String(buf));
		text->setPosition(Vector2f(10, 740));
		window->draw(*text);

		window->display();
	}

	for (int i = 0; i < MAP_W; i++)
		delete[] map[i];
	delete[] map;

	delete text;
	delete fnt;
	delete rotateIconRect;
	delete rotateIconTex;
	delete rect;
	delete gridRect;
	delete fieldRect;
	delete gridTex;
	delete fieldTex;
	delete window;

	return 0;
}