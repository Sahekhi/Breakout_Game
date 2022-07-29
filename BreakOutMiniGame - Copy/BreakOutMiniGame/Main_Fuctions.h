#pragma once
#include <vector>
#include  "Ball.h"
enum CollisionType {
	VerticalCollision,
	HorizontalCollision,
	CornerCollision,
	ColCount
};


const float scalingFactor = 3.0f;


sf::Vector2f Get2DPositionWithIndex(int index);
bool FillTileArrayWithData(Tile* tiles[], int tileArrayLength);
bool CheckForInput(Ball& ball, sf::RectangleShape tileShapes[], Tile* gameTiles[], sf::RenderWindow& window);
float clip(float n, float lower, float upper);
bool CheckForCollisionWithPlayer(Ball& ball, sf::Vector2f playerTilePos, sf::Vector2f* bounceDirection, sf::Vector2f* nextBallPosition);
bool CheckForBallTileCollisionAndMovementChanges(Ball& ball, sf::RectangleShape* tileShapes, Tile** gametiles, sf::Vector2f* bounceDirection);
float lerp(float a, float b, float f);
bool VerticalCollisionCheck(sf::Vector2f circleDistance, Ball& ball);
bool HorizontalCollisionCheck(sf::Vector2f circleDistance, Ball& ball);
bool CornerCollisionCheck(sf::Vector2f circleDistance, Ball& ball);
bool RenderGameData(sf::RenderWindow& window, sf::RectangleShape tileShapes[], Tile* gametiles[]);
bool SetUpInputCountingSystem();
bool DoGameLoopCalculations(Ball& ball, sf::RectangleShape tileShapes[], Tile* gametiles[]);
bool MoveBallThroughInput(Ball& ball);
sf::Vector2f CalculateBounceVector(sf::Vector2f futureBallPosition, CollisionType type, Ball& ball);
bool DropTileEffect(Tile& tile, sf::RectangleShape* drawnTile);
bool DrawTileEffects(sf::RenderWindow& window);
TileType CheckEffectWithPlayerCollision(bool* collisionBool);
bool CheckForEffectUsage();
bool SpawnBall();
void UpdateCollisionDebugDrawings(sf::Vector2f leftRimNormal, sf::Vector2f rightRimNormal, sf::Vector2f ballToPlayerVector, sf::Vector2f newBallDirVector);