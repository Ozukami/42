
import javafx.scene.layout.TilePane;
import javafx.scene.paint.Color;

public class Map {

	private Entity gameMap[][];
	private int mapSize; // entity * entity
	private int cellSize;
	private int xPlayer;
	private int yPlayer;

	public Map(TilePane mapContainer) {
		this.xPlayer = 50;
		this.yPlayer = 50;
		this.mapSize = 20;
		this.cellSize = 30;
		this.gameMap = new Entity[this.mapSize][this.mapSize];
		this.newGameMap(mapContainer);
	}

	private void newGameMap(TilePane mapContainer) {
		for (int y = 0; y < this.mapSize; y++) {
			for (int x = 0; x < this.mapSize; x++) {
				if (x == 0 || x == this.mapSize - 1 || y == 0 || y == this.mapSize - 1) {
					this.gameMap[x][y] = new Entity(Color.DARKGRAY, this.cellSize);
				} else {
					this.gameMap[x][y] = new Entity(Color.ORANGE, this.cellSize);
				}
				this.gameMap[x][y].setVisible(true);
				mapContainer.getChildren().add(this.gameMap[x][y]);
			}
		}
	}

	public Entity[][] getGameMap() {
		return gameMap;
	}

	public void setGameMap(Entity[][] gameMap) {
		this.gameMap = gameMap;
	}

	public int getxPlayer() {
		return xPlayer;
	}

	public void setxPlayer(int xPlayer) {
		this.xPlayer = xPlayer;
	}

	public int getyPlayer() {
		return yPlayer;
	}

	public void setyPlayer(int yPlayer) {
		this.yPlayer = yPlayer;
	}

	public Player getPlayer() {
		return ((Player) this.gameMap[this.xPlayer][this.yPlayer]);
	}
}
