const int WIDTH = 200;
const int HEIGHT = 200;

typedef int Texture;

enum TERRAIN
{
	GRASS_TEXTURE,
	HILL_TEXTURE,
	RIVER_TEXTURE
};

// FlyweightFactory = 객체 생성
// 비공유 변수 새로 지정
class Terrain
{
public:
	Terrain(int InMovementCost, bool InIsWater, Texture InTexture)
		: movmentCost(InMovementCost), isWater(InIsWater), texture(InTexture)
	{
		
	}

	int GetMovementCost() const { return movmentCost; }
	bool GetIsWater() const { return isWater; }
	const Texture& GetTexture() const { return texture; }

private:
	int movmentCost;
	bool isWater;
	Texture texture;
};

class World
{
public:
	World()
		: grassTerrain(1, false, GRASS_TEXTURE),
	hillTerrain(3, false, HILL_TEXTURE),
	riverTerrain(2, true, RIVER_TEXTURE)
	{
		
	}

private:
	Terrain* tiles[WIDTH][HEIGHT];

	Terrain grassTerrain;
	Terrain hillTerrain;
	Terrain riverTerrain;

public:
	void GenerateTerrain()
	{
		for(int i = 0; i < WIDTH; i++)
		{
			for(int j = 0; i < HEIGHT; j++)
			{
				if (random(10) == 0)
					tiles[i][j] = &hillTerrain;
				else
					tiles[i][j] = &grassTerrain;
			}
		}
	}

	const Terrain& World::GetTile(int x, int y) const
	{
		return *tiles[x][y];
	}
};