
import javafx.animation.TranslateTransition;
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

public class Player extends LivingEntity implements Motion {

	private Rectangle avatar;
	private TranslateTransition move;

	public Player(Color color, double size, int x, int y) {
		super(color, size, x, y);

		this.setHealthPoints(100);
		this.setHealthPointsMax(100);
		this.setManaPoints(100);
		this.setManaPointsMax(100);

		this.move = new TranslateTransition(new Duration(250));
		this.move.setNode(this);
	}

	@Override
	public void move(KeyCode k) {
		// TODO Auto-generated method stub
		if (k == KeyCode.UP) {
			this.setOrientation(1);
			this.setYMap(this.getYMap() - 1);
			this.setY(this.getY() - 30);
			// this.move.setByX(0);
			// this.move.setByY(-30);
			// this.toFront();
			// this.move.play();
		} else if (k == KeyCode.DOWN) {
			this.setOrientation(2);
			this.setYMap(this.getYMap() + 1);
			this.setY(this.getY() + 30);
			// this.move.setByX(0);
			// this.move.setByY(30);
			// this.toFront();
			// this.move.play();
		} else if (k == KeyCode.LEFT) {
			this.setOrientation(3);
			this.setXMap(this.getXMap() - 1);
			this.setX(this.getX() - 30);
			// this.move.setByX(-30);
			// this.move.setByY(0);
			// this.toFront();
			// this.move.play();
		} else if (k == KeyCode.RIGHT) {
			this.setOrientation(4);
			this.setXMap(this.getXMap() + 1);
			this.setX(this.getX() + 30);
			// this.move.setByX(30);
			// this.move.setByY(0);
			// this.toFront();
			// this.move.play();
		}
	}

	public Rectangle getAvatar() {
		return avatar;
	}

	public void setAvatar(Rectangle avatar) {
		this.avatar = avatar;
	}

	public TranslateTransition getMove() {
		return move;
	}

	public void setMove(TranslateTransition move) {
		this.move = move;
	}

}