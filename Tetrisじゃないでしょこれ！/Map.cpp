# include <Siv3D.hpp>

# include "Map.h"
# include "Effect.h"

Map::Map(){
	shiftAllCounter = 3;
	score = 0;
	lineFlag = 0;
	block_counter = 0;
	back_counter = 0;

	map.resize(20);
	for (int i = 0; i < 20; i++){
		map[i].resize(10);
		for (int j = 0; j < 10; j++){
			map[i][j].setColor(Type::NUL);
		}
	}
	for (int i = 0; i < 9; i++){
		map[19][i].setColor(Type::BULE);
	}
}

void Map::update(std::shared_ptr<Effect> effect){

	//”wŒi
	back_counter++;
	if (back_counter %= 10){
		Vec2 pos(Random(640.0), Random(480.0));
		effect->add<Snow>(pos, 1);
	}

	if (Input::KeyZ.clicked && shiftAllCounter){
		shiftAllCounter--;
		shiftAll();
	}

	if (!lineFlag){
		exitLine(effect);
	}
	else if (lineFlag && System::FrameCount() - flagCounter > 10){
		for (int i = 0; i < 10; i++){
			Vec2 pos(Random(50, WIDTH*BSIZE), 30 + lineFlag*BSIZE);
			effect->add<Snow>(pos, 10);
		}
		shiftDown(lineFlag);
		lineFlag = 0;
	}
}

void Map::draw(){
	//draw line
	Line(39, 20, 39, 20 + BSIZE*HEIGHT).draw();
	Line(40 + BSIZE*WIDTH, 20, 40 + BSIZE*WIDTH, 20 + BSIZE*HEIGHT).draw();
	Line(39, 20 + BSIZE*HEIGHT, 40 + BSIZE*WIDTH, 20 + BSIZE*HEIGHT).draw();

	//draw block
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			Rect(40 + BSIZE*x, 20 + BSIZE*y, 19, 19).draw({ Palette::Gray, 50 });
			map[y][x].draw(40 + BSIZE*x, 20 + BSIZE*y);
		}
	}

	static Font font(25);
	font(L"Score").draw(300, 100);
	font(score).draw(320, 150);
	font(L"ZƒL[‚Å‚ð•ö‚·").draw(300, 200);
	font(L"Žc‚è", shiftAllCounter, L"‰ñ").draw(320, 240);
}

void Map::overWrite(std::vector<std::vector<Piece> > pieces, int x, int y){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (pieces[i][j].getColor() != Type::NUL){
				map[i + y][j + x].set(pieces[i][j]);
			}
		}
	}
}

void Map::clear(){
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++){
			map[i][j].setColor(Type::NUL);
		}
	}
	score = 0;
	shiftAllCounter = 3;
}

void Map::shiftDown(int y){
	for (int i = y; i >= 0; i--){
		for (int j = 0; j < WIDTH; j++){
			if (i == 0){
				map[i][j].setColor(Type::NUL);
			}
			else{
				map[i][j].set(map[i - 1][j]);
			}
		}
	}
}

void Map::shiftAll(){
	int cnt = 1;
	while (cnt){
		cnt = 0;
		for (int i = HEIGHT - 1; i >= 0; i--){
			for (int j = 0; j < WIDTH; j++){
				if (i == 0){
					map[i][j].setColor(Type::NUL);
				}
				else if (map[i][j].getColor() == Type::NUL &&
					map[i - 1][j].getColor() != Type::NUL){
					map[i][j].set(map[i - 1][j]);
					map[i - 1][j].setColor(Type::NUL);
					cnt++;
				}
			}
		}
	}
}

void Map::exitLine(std::shared_ptr<Effect> effect){
	int sco = 0;
	for (int y = 0; y < HEIGHT; y++){
		int x;
		for (x = 0; x < WIDTH; x++){
			if (map[y][x].getColor() == Type::NUL){
				break;
			}
		}
		if (x == WIDTH){
			sco = 100;
			if (System::FrameCount() - flagCounter < 10)	sco += 100;
			lineFlag = y;
			flagCounter = System::FrameCount();
		}
	}
	score += sco;
}