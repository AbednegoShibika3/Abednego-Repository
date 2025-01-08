#include <vector>
#include <cstdlib>
#include <ctime>

const int WIDTH = 10;
const int HEIGHT = 20;
const int BLOCK_SIZE = 25;

const int tetromino [7] [4] [4] = {
{{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} },
{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}},
{{0, 1, 1}, {1, 1, 0}, {0, 0, 0}},
{{1,1}, {1,1},},
{{1, 1, 1}, {1, 0, 0}, {0, 0, 0}},
{{1, 1, 1}, {0, 0, 1}, {0, 0, 0}}
};

class Tetris {
	public:
		Tetris() {
			grid.resize(HEIGHT);
			for (int i = 0; i < HEIGHT; i++)
			grid[i].resize(WIDTH);
			spawnTetronimo();
		}
		
		void spawnTetronimo() {
			currentPiece = rand() % 7;
			PieceX = WIDTH / 2 - 2;
			pieceY = -2;
		}
		
		bool checkCollision(int offsetX, int offsetY) {
			for (int y = 0; y < getPieceHeight(); y++) {
			for (int x = 0; x < getPieceWidth(); x++)
			{
				if (tetromino[currentPiece] 
				[getRotation()][y] [x]) {
					if (PieceX + x + offsetX < 0 || 
					PieceX + x + offsetX >= WIDTH ||
					pieceY + y + offsetY >= HEIGHT ||
					grid[pieceY + + y + offsetY] [PieceX + x + offsetX]) {
						return true;
					}
				}
	    	}
		}
		return false;		
	}
	
	void lockPiece(){
		for (int y = 0; y < getPieceHeight(); y++) {
			for (int x = 0; x < getPieceWidth(); x++)
		{
			if (tetromino[currentPiece]
			[getRotation()][y] [x]) {
				grid[pieceY + y] [PieceX + x] = true;
			}
		}
		}
		spawnTetronimo();
	}
	
	void rotate() {
		rotation++;
		if (rotation >= getRotation()) rotation = 0;
		if (!checkCollision(0, 0)) rotation--;
	}
	
	void move(int dx) {
		if (!checkCollision(0, 1)) {
			pieceY++;
		} else {
			lockPiece();
		}
	}
	
	int getRotation() const { return rotation;	}
	
	private:
		std::vector<std::vector<bool>> grid;
		int currentPiece;
		int PieceX;
		int pieceY;
		int rotation;
		
		int getPieceHeight() const { return
		sizeof(tetromino[currentPiece]) /
		sizeof(tetromino[currentPiece][0]);}
		
		int getPieceWidth() const { return
		sizeof(tetromino[currentPiece]) /
		sizeof(tetromino[currentPiece][0]);}
		
		int getRotationCount() const { return
		sizeof(tetromino[currentPiece]) /
		sizeof(tetromino[currentPiece][0]);}
};

int main() {
	srand(static_cast<unsigned>(time(0)));
	
	sf::RenderWindow window(sf::VideoMode(WIDTH * BLOCK_SIZE, HEIGHT * BLOCK_SIZE), "Tetris");
	
	Tetris tetris;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::keyboard::Left) tetris.move(-1);
				if (event.key.code == sf::keyboard::Right) tetris.move(1);
				if (event.key.code == sf::keyboard::Down) tetris.drop();
				if (event.key.code == sf::keyboard::Up)  tetris.rotate();			}
		}
	}
	
	tetris.drop();
	
	window.clear();
	
	window.display();
	
	sf::sleep(sf::milliseconds(500));
}

return EXIT_SUCCESS;
}