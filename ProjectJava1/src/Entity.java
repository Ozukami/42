
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Entity extends Rectangle {

	private int x;
	private int y;

	public Entity(Color color, double size) {
		this.setFill(color);
		this.setWidth(size);
		this.setHeight(size);
	}

}
