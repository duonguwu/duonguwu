// Group: Duong Duy Nhu
// Code by duong vjp

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum SquareState
{
    NO_VAL = ' ',
    X_VAL = 'X',
    O_VAL = 'O',
    TIE_VAL
};

struct Game
{
    const int width;
    const int height;
    int GameBoard[9];
};

void Input(vector<int> &GameBoard){
    for(int i = 0; i < 9; i++){
        GameBoard.push_back(NO_VAL);    // Thêm các phần tử trống vào bàn cờ
    }
}

void setX(vector<int> &GameBoard, int value)    // Thêm điểm X
{
	GameBoard[value] = X_VAL;
} 

void setO(vector<int> &GameBoard, int value)    // Thêm điểm O 
{
	GameBoard[value] = O_VAL;
} 

bool isTaken(vector<int> GameBoard, int value)  // Hàm kiểm tra ô trống
{
	return GameBoard[value] == NO_VAL;  // Trả về true nếu ô value trống
}

bool isFull(vector<int> GameBoard)  // Kiểm tra bàn cờ đã đầy chưa
{
	for (int i = 0; i < GameBoard.size(); i++)
	{
		if (GameBoard[i] == NO_VAL) // Kiểm tra xem bàn cờ còn ô trống hay ko
			return false;
	}
	return true;
}

// Hàm kiểm tra điều kiện chiến thăngs


SquareState checkVictory(vector<int> &GameBoard)
{
        // 0 1 2
        // 3 4 5
        // 6 7 8

    // Trường hợp thằng hàng nằm ngang

	if (GameBoard[0] == X_VAL && GameBoard[1] == X_VAL && GameBoard[2] == X_VAL)
		return X_VAL;
	if (GameBoard[0] == O_VAL && GameBoard[1] == O_VAL && GameBoard[2] == O_VAL)
		return O_VAL;
	if (GameBoard[3] == X_VAL && GameBoard[4] == X_VAL && GameBoard[5] == X_VAL)
		return X_VAL;
	if (GameBoard[3] == O_VAL && GameBoard[4] == O_VAL && GameBoard[5] == O_VAL)
		return O_VAL;
	if (GameBoard[6] == X_VAL && GameBoard[7] == X_VAL && GameBoard[8] == X_VAL)
		return X_VAL;
	if (GameBoard[6] == O_VAL && GameBoard[7] == O_VAL && GameBoard[8] == O_VAL)
		return O_VAL;


    // Trường hợp thẳng hàng nằm dọc

	if (GameBoard[0] == X_VAL && GameBoard[3] == X_VAL && GameBoard[6] == X_VAL)
		return X_VAL;
	if (GameBoard[0] == O_VAL && GameBoard[3] == O_VAL && GameBoard[6] == O_VAL)
		return O_VAL;
	if (GameBoard[1] == X_VAL && GameBoard[4] == X_VAL && GameBoard[7] == X_VAL)
		return X_VAL;
	if (GameBoard[1] == O_VAL && GameBoard[4] == O_VAL && GameBoard[7] == O_VAL)
		return O_VAL;
	if (GameBoard[2] == X_VAL && GameBoard[5] == X_VAL && GameBoard[8] == X_VAL)
		return X_VAL;
	if (GameBoard[2] == O_VAL && GameBoard[5] == O_VAL && GameBoard[8] == O_VAL)
		return O_VAL;

    // Trường hợp đường chéo

	if (GameBoard[0] == X_VAL && GameBoard[4] == X_VAL && GameBoard[8] == X_VAL)
		return X_VAL;
	if (GameBoard[0] == O_VAL && GameBoard[4] == O_VAL && GameBoard[8] == O_VAL)
		return O_VAL;
	if (GameBoard[2] == X_VAL && GameBoard[4] == X_VAL && GameBoard[6] == X_VAL)
		return X_VAL;
	if (GameBoard[2] == O_VAL && GameBoard[4] == O_VAL && GameBoard[6] == O_VAL)
		return O_VAL;

	for (int i = 0; i < 9; i++)
	{
		if(GameBoard[i] == NO_VAL)
			return NO_VAL;
	}
	return TIE_VAL;
}

void player(vector<int> &GameBoard, string player)
{
	int value;
	while(true)
	{
		if (1)
		{
			char key = getchar();

			if (key == 27)// ESC => exit
				exit(0);

			// Chỗ này là mình bấm các phím trên bàn phím để đánh lên bàn cờ
			// Với mỗi nút, sẽ có 1 cái value tương ứng. 

			if (player.compare("I") == 0) // player 1
			{
				if ((key == 'Q' || key == 'q') && isTaken(GameBoard, 0))
					{value = 0;  break; }
				else if ((key == 'W' || key == 'w') && isTaken(GameBoard, 1)) // Kiểm tra xem ô có trống hay kh
					{value = 1;  break; }
				else if ((key == 'E' || key == 'e') && isTaken(GameBoard, 2))
					{value = 2;  break; }
				else if ((key == 'A' || key == 'a') && isTaken(GameBoard, 3))
					{value = 3;  break; }
				else if ((key == 'S' || key == 's') && isTaken(GameBoard, 4))
					{value = 4;  break; }
				else if ((key == 'D' || key == 'd') && isTaken(GameBoard, 5))
					{value = 5;  break; }
				else if ((key == 'Z' || key == 'z') && isTaken(GameBoard, 6))
					{value = 6;  break; }
				else if ((key == 'X' || key == 'x') && isTaken(GameBoard, 7))
					{value = 7;  break; }
				else if ((key == 'C' || key == 'c') && isTaken(GameBoard, 8))
					{value = 8;  break; }
			}
		}
	}
	// Sau khi có cái value khi nhập từ bàn phím, mình sẽ đánh dấu X vào vị trí value trên bàn cờ

    if (player.compare("I") == 0){ // player 1 
		setX(GameBoard, value);
	}
	else if (player.compare("II") == 0){
		setO(GameBoard, value);
	}
}
