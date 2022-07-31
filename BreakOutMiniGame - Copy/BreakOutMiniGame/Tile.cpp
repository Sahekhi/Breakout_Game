#include "Tile.h"

const float Tile::OUTLINE_THICKNESS = 0.5f;

Tile::Tile(sf::Vector2f pos, TileType type, sf::Color col, int id) {

	tileVisualID = id;
	isAlive = true;
	position = pos;
	hitCount = 0;
	baseColor = col;
	tileType = type;
	if (type == TileType::AddedBall) {
		hitCount = 3;

	}
	if (type == TileType::QuickerPlayer) {
		hitCount = 4;
	}
	if (type == TileType::NoEvent) {
		hitCount = 2;
	}
	allowedHits = hitCount;
}

bool Tile::UpdateTileColorBasedOnHits(RenderManager& renderManager) {

	if (!isAlive) {
		renderManager.DeleteShape(tileVisualID);
		return true;
	}
	/*float currentHitPercentage = 1.0f - (float)hitCount / allowedHits;
	sf::Uint8 redPercentage = lerp(baseColor.r, maxHitColor.r, currentHitPercentage);
	sf::Uint8 greenPercentage = lerp(baseColor.g, maxHitColor.g, currentHitPercentage);
	sf::Uint8 bluePercentage = lerp(baseColor.b, maxHitColor.b, currentHitPercentage);
	sf::Uint8 alphaPercentage = 255;

	sf::Color color = sf::Color(redPercentage, greenPercentage, bluePercentage, alphaPercentage);
	sf::RectangleShape* currentTile = (sf::RectangleShape*) renderManager.GetShape(tileVisualID);
	currentTile->setFillColor(color);*/
	return true;
}