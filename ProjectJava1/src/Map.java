
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.TilePane;
import javafx.scene.paint.Color;

public class Map {

	private Floor mapLayer[][];
	private Entity eventLayer[][];
	private int mapSize; // entity * entity
	private int cellSize;
	private Player player;

	public Map(TilePane mapLayer, TilePane eventLayer, AnchorPane pLayer) {
		this.mapSize = 20;
		this.cellSize = 30;
		this.mapLayer = new Floor[this.mapSize][this.mapSize];
		this.eventLayer = new Entity[this.mapSize][this.mapSize];
		this.player = new Player(Color.DODGERBLUE, this.cellSize, mapSize / 2, mapSize / 2);
		this.newGameMap(mapLayer, eventLayer);
		pLayer.getChildren().add(player);
	}

	private void newGameMap(TilePane mapLayer, TilePane eventLayer) {
		for (int y = 0; y < this.mapSize; y++) {
			for (int x = 0; x < this.mapSize; x++) {
				this.mapLayer[x][y] = new Floor(Color.FORESTGREEN, this.cellSize, x, y);
				mapLayer.getChildren().add(this.mapLayer[x][y]);
			}
		}
		for (int y = 0; y < this.mapSize; y++) {
			for (int x = 0; x < this.mapSize; x++) {
				if (x == 0 || x == this.mapSize - 1 || y == 0 || y == this.mapSize - 1) {
					this.eventLayer[x][y] = new Entity(Color.DARKGRAY, this.cellSize, x, y);
					this.eventLayer[x][y].setCollision(1);
					eventLayer.getChildren().add(this.eventLayer[x][y]);
				} else {
					this.eventLayer[x][y] = new Entity(Color.BLACK, this.cellSize, x, y);
					this.eventLayer[x][y].setVisible(false);
					eventLayer.getChildren().add(this.eventLayer[x][y]);
				}
			}
		}
	}

	public Floor[][] getMapLayer() {
		return mapLayer;
	}

	public void setMapLayer(Floor[][] mapLayer) {
		this.mapLayer = mapLayer;
	}

	public Entity[][] getEventLayer() {
		return eventLayer;
	}

	public void setEventLayer(Entity[][] eventLayer) {
		this.eventLayer = eventLayer;
	}

	public int getMapSize() {
		return mapSize;
	}

	public void setMapSize(int mapSize) {
		this.mapSize = mapSize;
	}

	public int getCellSize() {
		return cellSize;
	}

	public void setCellSize(int cellSize) {
		this.cellSize = cellSize;
	}

	public Player getPlayer() {
		return player;
	}

	public void setPlayer(Player player) {
		this.player = player;
	}
}