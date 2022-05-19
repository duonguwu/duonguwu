#include "TicTacToe.cpp"

struct AIMove
{
    AIMove(){};
    AIMove(int Score) : score(Score){};
    int index;
    int score;
};

AIMove getBestMove(vector<int> &GameBoard, int player)
{
    SquareState rv = checkVictory(GameBoard);
    if (rv == O_VAL)
        return AIMove(10);
    else if (rv == X_VAL)
        return AIMove(-10);
    else if (rv == TIE_VAL)
        return AIMove(0);

    vector<AIMove> moves; // Khai báo mảng moves

    for (int i = 0; i < 9; i++)
    {
        if (GameBoard[i] == NO_VAL) 
        {
            AIMove items;
            items.index = i;
            GameBoard[i] = player;

            if (player == X_VAL)
                items.score = getBestMove(GameBoard, O_VAL).score;
            else if (player == O_VAL)
                items.score = getBestMove(GameBoard, X_VAL).score;

            moves.push_back(items); // Thêm giá trị vào mảng moves để tính đường đi
            GameBoard[i] = NO_VAL;  // Trả về ô trống cho vị trí vừa xét
        }
    }
    // Đoạn này là tính toán đưa ra đường đi tốt nhất.
    int bestMove = 0;
    if (player == O_VAL)  
    {
        int bestScore = INT_MIN;
        int size = moves.size();
        for (int i = 0; i < size; i++)
        {
            if (moves[i].score > bestScore)
            {   
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    else if (player == X_VAL)
    {
        int bestScore = INT_MAX;
        int size = moves.size();
        for (int i = 0; i < size; i++)
        {
            if (moves[i].score < bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    return moves[bestMove];
}

// Nếu mình đánh vào 1 trong 4 góc, index sẽ trả về 4 và đánh ô chính giữa
// => không thể chiến thắng được ;')))
// Còn nếu mình đánh vào giữa trước thì index trả về 0, đánh vào vị trí góc đầu tiên. 
// Sau đó sẽ dựa vào điều kiện để đánh chặn mình dẫn đến hòa

void performMove(vector<int> &gameBoard)
{
    AIMove bestMove = getBestMove(gameBoard, O_VAL);
    gameBoard[bestMove.index] = O_VAL;
}

void playWithAI()
{
    system("cls");
    vector<int> gb;
    Input(gb);
    char x;
    do
    {   
            system("cls");
            cout << "---|----|----\n";
            cout << " " << (char)gb[0] << " | " << (char)gb[1] << "  | " << (char)gb[2]  << "   \n";
            cout << "___|____|____\n";
            cout << "   |    |   \n";
            cout << " " << (char)gb[3] << " | " << (char)gb[4] << "  | " <<  (char)gb[5] << "   \n";
            cout << "___|____|____\n";
            cout << "   |    |   \n";
            cout << " " << (char)gb[6] << " | " <<  (char)gb[7] <<"  | " <<   (char)gb[8] << "  \n";
            cout << "___|____|____\n";
            cout << "   |    |   \n"; 
            
        player(gb, "I");

        if (checkVictory(gb) == X_VAL)  // Này cho có thôi chứ win kiểu gì đc =))))))
        {   
            cout << "You win !!!";
            return;
        }
        if (isFull(gb))     // Hết chỗ rồi mà chưa win thì hòa
        {   
            cout << "Ties !!!";
            break;
        }

        performMove(gb);
        //badMove(gb);
        if (checkVictory(gb) == O_VAL)
        {   
            cout << "You lose!!! ";
            break;
        }
    } while (checkVictory(gb) == NO_VAL);
}

void HuongDan(){
    cout << "Ta co ban co voi 9 vi tri: ";
    cout << "\n\t1 2 3 \n\t4 5 6 \n\t7 8 9" << endl; 
    cout << "Su dung cac nut Q W E A S D Z X C tuong ung voi cac chi so."<< endl;

}

void Menu(int &x){
    //system("cls");
    cout << "\n============ Menu ============" << endl;
    cout << "\n\t1. Play";
    cout << "\n\t2. How to play?";
    cout << "\n\t0. Exit" << endl;
    cout << "\n==============================" << endl;
    cout << "Moi nhap lua chon: ";
    cin >> x;
}

int main(){

    int x;
    int k;
    do
    {   
        Menu(x); 
        switch (x)
        {
        case 1:
            playWithAI();
            break;
        case 2:
            system("cls");
            HuongDan();
            break;
        default:
            break;
        }

    } while (x != 0);

    

}
