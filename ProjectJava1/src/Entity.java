
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Entity extends Rectangle {

	private int x;
	private int y;
	private int collision = 0;
	private int passifDmg = 0;

	public Entity(Color color, double size, int x, int y) {
		this.setFill(color);
		this.setWidth(size);
		this.setHeight(size);
		this.x = x;
		this.y = y;
		this.setX(x * 30);
		this.setY(y * 30);
	}

	public int getXMap() {
		return x;
	}

	public void setXMap(int x) {
		this.x = x;
	}

	public int getYMap() {
		return y;
	}

	public void setYMap(int y) {
		this.y = y;
	}

	public int getCollision() {
		return collision;
	}

	public void setCollision(int collision) {
		this.collision = collision;
	}

	public int getPassifDmg() {
		return passifDmg;
	}

	public void setPassifDmg(int passifDmg) {
		this.passifDmg = passifDmg;
	}

}