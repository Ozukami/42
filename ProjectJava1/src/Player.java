
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Player extends LivingEntity implements Motion {

	private Rectangle avatar;

	public Player(Color color, double size) {
		super(color, size);
	}

	@Override
	public void move(KeyCode k) {
		// TODO Auto-generated method stub

	}

}