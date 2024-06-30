#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include <string>
#include <iostream>
#include <vector>

static std::string WhichColor(char piece){
    switch(piece){
        case 'r' : 
            return "black";
        case 'n' : 
            return "black";
        case 'b' : 
            return "black";
        case 'q' : 
            return "black";
        case 'k' : 
            return "black";
        case 'p' : 
            return "black";
        case 'R' : 
            return "white";
        case 'N' : 
            return "white";
        case 'B' : 
            return "white";
        case 'Q' : 
            return "white";
        case 'K' : 
            return "white";
        case 'P' : 
            return "white";
    }
    return "none";
}


class Board{
    public : 
    std::vector<std::string> piece_array = {};    //each element will be piece/color/coordinate
    void Initialize(); //set up the default board;
    void InitializeFEN(std::string FEN);
    void DisplayBoard();
};

void Board::Initialize(){
    piece_array.clear();
    std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    int current_rank = 8;
    int current_file = 0; //acting as the index for files;
    std::string files = "abcdefgh";

    for(int i = 0; i < FEN.length(); i++){
        if(FEN[i] == '/'){
            current_rank--;
            current_file = 0;
        }
        else if((int)FEN[i] < 58){
            current_file += int(FEN[i]) - '0';
        }
        else{
            std::string piece = "";
            piece.push_back(FEN[i]);
            piece.push_back('/');
            
            if(WhichColor(FEN[i]) == "white"){
                piece.push_back('w');
            }
            else{
                piece.push_back('b');
            }
            piece.push_back('/');
            piece.push_back(files[current_file]);
            piece.push_back((char)('0' + current_rank));
            piece_array.push_back(piece);
            current_file++;
        }
    }
}
void Board::InitializeFEN(std::string FEN){
    piece_array.clear();
    int current_rank = 8;
    int current_file = 0; //acting as the index for files;
    std::string files = "abcdefgh";

    for(int i = 0; i < FEN.length(); i++){
        if(FEN[i] == '/'){
            current_rank--;
            current_file = 0;
        }
        else if((int)FEN[i] < 58){
            current_file += int(FEN[i]) - '0';
        }
        else{
            std::string piece = "";
            piece.push_back(FEN[i]);
            piece.push_back('/');
            
            if(WhichColor(FEN[i]) == "white"){
                piece.push_back('w');
            }
            else{
                piece.push_back('b');
            }
            piece.push_back('/');
            piece.push_back(files[current_file]);
            piece.push_back((char)('0' + current_rank));
            piece_array.push_back(piece);
            current_file++;
        }
    }
}
void Board::DisplayBoard(){
    if(piece_array.empty()){
        return;
    }
    using namespace std;
    int current_file = 0;
    int current_rank = 0;
    vector<vector<char>> board_array = {};
    for(int i  = 0; i < 8; i++){
        board_array.push_back({'_','_','_','_','_','_','_','_'});
    }
    for(int i = 0; i < piece_array.size();i++){
        char rank = piece_array[i][5];
        char file = piece_array[i][4];
        int row = '8' - rank;
        int column = file - 'a';
        board_array[row][column] = piece_array[i][0];
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            std::cout<<board_array[i][j]<<" | ";
        }
        std::cout<<'\n';
    }
}


#endif