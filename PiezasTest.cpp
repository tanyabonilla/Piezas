/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

const int rows = 3;
const int cols = 4; 

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, initialBoard)
{
  bool blankBoard = true;
  Piezas game = Piezas();
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(game.pieceAt(i,j) != Blank){
        blankBoard = false;
      }
    }
  }
   ASSERT_TRUE(blankBoard);
}

TEST(PiezasTest, resetBoard)
{
  Piezas game = Piezas();
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(1);
  game.gameState();
  game.reset();

  bool blankBoard = true;
  for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(game.pieceAt(i,j) != Blank){
        blankBoard = false;
      }
    }
  }
   ASSERT_TRUE(blankBoard);
}

TEST(PiezasTest, pieceAtFirstCheck)
{
  Piezas game;
  game.dropPiece(0);
  Piece curr = game.pieceAt(0,0);
  ASSERT_EQ(curr, X);
}

TEST(PiezasTest, gameNotOver)
{
  Piezas game = Piezas();
  Piece curr = game.gameState();
  ASSERT_EQ(curr, Invalid);
}

TEST(PiezasTest, xIsPlaced)
{
  Piezas piezas = Piezas();
  Piece cur = piezas.dropPiece(0);
  ASSERT_EQ(cur, X);
}

TEST(PiezasTest, oIsPlaced)
{
  Piezas game = Piezas();
  game.dropPiece(0);
  Piece cur = game.dropPiece(0);
  ASSERT_EQ(cur, O);
}

TEST(PiezasTest, outofBounds)
{
  Piezas game;
  Piece p = game.pieceAt(10, 0);
  ASSERT_EQ(p, Invalid);
}

TEST(PiezasTest, pieceAtX)
{
	Piezas game;
	game.dropPiece(0);
	Piece piece = game.pieceAt(0, 0);
    ASSERT_EQ(X, piece);
}

TEST(PiezasTest, drop2)
{
    Piezas game;
    game.dropPiece(0);
	game.dropPiece(0);
	for(int i = 0; i < 2; i++) {
		ASSERT_TRUE(game.pieceAt(i,0) != Blank);
	}
}

TEST(PiezasTest, drop3)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	for(int i = 0; i < 3; i++) {
		ASSERT_TRUE(game.pieceAt(i,0) != Blank);
	}
}

TEST(PiezasTest, lowerBounds)
{
	Piezas obj;
	Piece curr = obj.dropPiece(-1);
	ASSERT_TRUE(curr == Invalid);
}

/*
O X X O
O O X O
X O X X
*/
TEST(PiezasTest, xWins)
{
  Piezas game = Piezas();
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(2);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(3);
  Piece cur = game.gameState();
  ASSERT_EQ(cur, X);
}

/*
X O X O
O X O X
X O X O 
*/
TEST(PiezasTest, isTie)
{
  Piezas game = Piezas();
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(3);
  game.dropPiece(3);
  Piece curr = game.gameState();
  ASSERT_EQ(curr, Blank);
}

/*
O X X X
O O O O
O X X X
*/
TEST(PiezasTest, oWinsRow)
{
  Piezas game = Piezas();
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(0);
  game.dropPiece(2);
  game.dropPiece(0);
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(3);
  game.dropPiece(0);
  Piece curr = game.gameState();
  ASSERT_EQ(curr, O);
}
