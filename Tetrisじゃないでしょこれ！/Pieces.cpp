# include "Pieces.h"

# include "Map.h"
# include "Game.h"

Pieces::Pieces(){
	pieces.resize(3);
	next_pieces.resize(3);
	next_next_pieces.resize(3);
	hold1.resize(3);
	hold2.resize(3);
	for (int i = 0; i < 3; i++){
		pieces[i].resize(3);
		next_pieces[i].resize(3);
		next_next_pieces[i].resize(3);
		hold1[i].resize(3);
		hold2[i].resize(3);
		for (int j = 0; j < 3; j++){
			pieces[i][j].escape();
			next_pieces[i][j].escape();
			next_next_pieces[i][j].escape();
			hold1[i][j].escape();
			hold2[i][j].escape();
		}
	}
	fallCounter = 0;
}

void Pieces::update(Game* game){
	std::shared_ptr<Map> MAP = game->getMap();
	std::vector<std::vector<Piece> > map = MAP->getMap();

	if (Input::KeyX.clicked){
		swap1();
	}
	if (Input::KeyC.clicked){
		swap2();
	}

	if (Input::KeyLeft.clicked && checkLeft(map)){
		x--;
	}
	if (Input::KeyRight.clicked && checkRight(map)){
		x++;
	}
	if (Input::KeyUp.clicked){
		turn(map);
	}
	if (++fallCounter % 100 == 0 || Input::KeyDown.clicked ||
		(Input::KeyDown.pressed && fallCounter % 5 == 0)){
		if (!checkBottom(map)){
			MAP->overWrite(pieces, x, y);
			newPiece();
		}
		y++;
	}

	if (over(map)){
		game->setGameOver();
		return;
	}

}

void Pieces::draw(){
	static Font font(10);
	font(L"xキーで交換").draw(20, 40);
	Rect(20, 60, 60, 60).drawFrame(0, 1, { Palette::White, 50 });
	font(L"cキーで交換").draw(20, 140);
	Rect(20, 160, 60, 60).drawFrame(0, 1, { Palette::White, 50 });
	font(L"next").draw(340, 20);
	Rect(340, 40, 60, 60).drawFrame(0, 1, { Palette::White, 50 });
	font(L"next next").draw(340, 120);
	Rect(340, 140, 60, 60).drawFrame(0, 1, { Palette::White, 50 });
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			pieces[i][j].draw(110 + (x + j) * BSIZE, 20 + (y + i) * BSIZE);
			next_pieces[i][j].draw(340 + j * BSIZE, 40 + i * BSIZE);
			next_next_pieces[i][j].draw(340 + j * BSIZE, 140 + i * BSIZE);
			hold1[i][j].draw(20 + j * BSIZE, 60 + i * BSIZE);
			hold2[i][j].draw(20 + j * BSIZE, 160 + i * BSIZE);
		}
	}
}

void Pieces::turn(std::vector<std::vector<Piece> > map){
	std::vector<Piece> v(2);
	std::vector<std::vector<Piece> > m(3, std::vector<Piece>(3));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			m[i][j].set(pieces[i][j]);
		}
	}
	for (int i = 0; i < 2; i++){
		v[i].set(m[0][i]);
	}
	for (int i = 0; i < 2; i++){
		m[0][i].set(m[2 - i][0]);
	}
	for (int i = 0; i < 2; i++){
		m[2 - i][0].set(m[2][2 - i]);
	}
	for (int i = 0; i < 2; i++){
		m[2][2 - i].set(m[i][2]);
	}
	for (int i = 0; i < 2; i++){
		m[i][2].set(v[i]);
	}

	int flag = 0;
	if (x < 0){ x++; flag = 1; }
	if (x >= 8) { x--; flag = 2; }
	if (y >= 18) { y--; flag = 3; }

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (m[i][j].getColor() != Type::NUL &&
				map[i + y][j + x].getColor() != Type::NUL){
				if (flag == 1)	x--;
				if (flag == 2)	x++;
				if (flag == 3)	y++;
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			pieces[i][j].set(m[i][j]);
		}
	}
}

bool Pieces::over(std::vector<std::vector<Piece> > map){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if ((i + y) < 20 && (j + x) >= 0 && (j + x) < 10 &&
				map[i + y][j + x].getColor() != Type::NUL
				&& pieces[i][j].getColor() != Type::NUL){
				return true;
			}
		}
	}
	return false;
}

void Pieces::newPiece(){
	//場所と値の初期化
	y = 0; x = 4;
	int sum = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (next_pieces[i][j].getColor() != Type::NUL){ sum++; }
			pieces[i][j].escape();
			pieces[i][j].set(next_pieces[i][j]);
			next_pieces[i][j].escape();
			next_pieces[i][j].set(next_next_pieces[i][j]);
			next_next_pieces[i][j].escape();
		}
	}

	//set
	Type t;
	switch (Random(1, 4)){
	case 1:
		t = Type::BULE;
		break;
	case 2:
		t = Type::RED;
		break;
	case 3:
		t = Type::ORANGE;
		break;
	case 4:
		t = Type::GREEN;
		break;
	}
	if (Random(0, 9) == 0){
		for (int i = 0; i < 3; i++){
			next_next_pieces[i][1].setColor(t);
		}
	}
	else{
		for (int i = 0; i < 4;){
			int X = Random(0, 2);
			int Y = Random(0, 2);
			if (next_next_pieces[Y][X].getColor() == Type::NUL){
				next_next_pieces[Y][X].setColor(t);
				i++;
			}
			if (sum == 0){
				X = Random(0, 2);
				Y = Random(0, 2);
				pieces[Y][X].setColor(t);
				X = Random(0, 2);
				Y = Random(0, 2);
				next_pieces[Y][X].setColor(t);
			}
		}
	}
}

bool Pieces::checkLeft(std::vector<std::vector<Piece> > map){
	int dy, dx;
	for (int j = 0; j < 3; j++){
		for (int i = 0; i < 3; i++){
			dx = x + j - 1;
			dy = y + i;
			if (pieces[i][j].getColor() != Type::NUL &&
				(dx < 0 || map[dy][dx].getColor() != Type::NUL)){
				return false;
			}
		}
	}
	return true;
}

bool Pieces::checkRight(std::vector<std::vector<Piece> > map){
	int dy, dx;
	for (int j = 2; j >= 0; j--){
		for (int i = 0; i < 3; i++){
			dx = x + j + 1;
			dy = y + i;
			if (pieces[i][j].getColor() != Type::NUL &&
				(dx >= 10 || map[dy][dx].getColor() != Type::NUL)){
				return false;
			}
		}
	}
	return true;
}

bool Pieces::checkBottom(std::vector<std::vector<Piece> > map){
	int dy, dx;
	for (int i = 2; i >= 0; i--){
		for (int j = 0; j < 3; j++){
			dx = x + j;
			dy = y + i + 1;
			if (pieces[i][j].getColor() != Type::NUL &&
				(dy >= 20 || map[dy][dx].getColor() != Type::NUL)){
				return false;
			}
		}
	}
	return true;
}

void Pieces::swap1(){
	std::vector<std::vector<Piece> > p(3, std::vector<Piece>(3));
	int sum = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (hold1[i][j].getColor() != NUL){
				sum++;
			}
		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			p[i][j].set(pieces[i][j]);
			pieces[i][j].set(hold1[i][j]);
			hold1[i][j].set(p[i][j]);
		}
	}
	if (sum == 0){
		newPiece();
	}
}

void Pieces::swap2(){
	std::vector<std::vector<Piece> > p(3, std::vector<Piece>(3));
	int sum = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (hold2[i][j].getColor() != NUL){
				sum++;
			}
		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			p[i][j].set(pieces[i][j]);
			pieces[i][j].set(hold2[i][j]);
			hold2[i][j].set(p[i][j]);
		}
	}
	if (sum == 0){
		newPiece();
	}
}