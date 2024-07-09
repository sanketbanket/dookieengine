#include "board.h"

void Board::Initialize(){
    piece_array.clear();
    std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    int current_rank = 8;
    int current_file = 0; 

    for(int i = 0; i < FEN.length(); i++){
        if(FEN[i] == '/'){    //moves down a rank if / is encountered
            current_rank--;
            current_file = 0;
        }
        else if((int)FEN[i] < 58){
            current_file += int(FEN[i]) - '0';
        }
        else{
            std::string Position = "";
            char Origin = char(current_file + 'a');
            Position.push_back(char(current_file + 'a'));
            Position.push_back(char('0' + current_rank));
            Piece* newPiece = new Piece(FEN[i], Position, Origin);
            piece_array.push_back(newPiece);
            current_file++;
        }
    }
}

void Board::InitializeFEN(std::string FEN){
    piece_array.clear();
    int current_rank = 8;
    int current_file = 0;


    for(int i = 0; i < FEN.length(); i++){
        if(FEN[i] == '/'){
            current_rank--;
            current_file = 0;
        }
        else if((int)FEN[i] < 58){
            current_file += int(FEN[i]) - '0';  
        }
        else{
            std::string Position = "";
            char Origin = char(current_file + 'a');
            Position.push_back(char(current_file + 'a'));
            Position.push_back(char('0' + current_rank));
            Piece* newPiece = new Piece(FEN[i], Position, Origin);
            piece_array.push_back(newPiece);
            current_file++;
        }
    }
}
void Board::DisplayBoard(){
    std::cout<<"|---+---+---+---+---+---+---+---+-\n";
    for(int i = 0; i < 8; i++){
        std::cout<<"| ";
        for(int j = 0; j < 8; j++){
            if(board_array[i][j] == 0){
                std::cout<<' '<<" | ";
                continue;
            }
            std::cout << char(board_array[i][j])<<" | ";
            
        }

        std::cout<<char('8' - i)<<'\n';
        std::cout<<"|---+---+---+---+---+---+---+---+-\n";

    }
    std::cout<<"  a   b   c   d   e   f   g   h\n";
}

void Board::UpdateBoard(){
    for(Piece* x : piece_array){
        char rank = x-> position[1];
        char file = x-> position[0];
        int row = '8' - rank;
        int column = file - 'a';
        board_array[row][column] = int(x-> name);
    };
}

vector<Piece*> Board::getKings(){
    vector<Piece*> kings = {};
    for(Piece* pie : piece_array){
        if(pie->name == 'K' || pie-> name == 'k'){
            kings.push_back(pie);
        }
    }
    return kings;
}

std::vector<std::string> getKingMoves(Piece piece, Board board){
    int row = piece.position[0] - 'a';
    int col = '8'- piece.position[1] ;
    vector<string> validSquares = {};
    
    for(int i  = -1 ; i < 2; i++){    // these loops are just to iterate around the king
        for(int j = -1 ; j < 2; j++){
            if(isValidSquare(row + i, col + i)){
                if(whichColor(piece.name) == 'w' && board.black_attack[row + i][col + i]==0&& board.board_array[row+i][col+i] == 0){
                    board.white_attack[row + i][col + i] = 1;
                    validSquares.push_back(getSquare(row + i, col + i));
                }
                if(whichColor(piece.name) == 'b' && board.white_attack[row + i][col + i]==0&& board.board_array[row+i][col+i] == 0){
                    board.black_attack[row + i][col + i] = 1;
                    validSquares.push_back(getSquare(row + i, col + i));
                }
            }
        }
    }
    return validSquares;
}