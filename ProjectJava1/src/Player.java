
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
		this.move = new TranslateTransition(new Duration(250));
		this.move.setNode(this);
	}

	@Override
	public void move(KeyCode k) {
		// TODO Auto-generated method stub
		if (k == KeyCode.UP && this.getYMap() > 1) {
			System.out.printf("UP : [%d,%d]", this.getXMap(), this.getYMap());
			this.setYMap(this.getYMap() - 1);
			this.setTranslateY(this.getTranslateY() - 30);
			// this.move.setByX(0);
			// this.move.setByY(-30);
			// this.toFront();
			// this.move.play();
			System.out.printf(" --> [%d,%d]\n", this.getXMap(), this.getYMap());
		} else if (k == KeyCode.DOWN && this.getYMap() < 18) {
			System.out.printf("DOWN : [%d,%d]", this.getXMap(), this.getYMap());
			this.setYMap(this.getYMap() + 1);
			this.setTranslateY(this.getTranslateY() + 30);
			// this.move.setByX(0);
			// this.move.setByY(30);
			// this.toFront();
			// this.move.play();
			System.out.printf(" --> [%d,%d]\n", this.getXMap(), this.getYMap());
		} else if (k == KeyCode.LEFT && this.getXMap() > 1) {
			System.out.printf("LEFT : [%d,%d]", this.getXMap(), this.getYMap());
			this.setXMap(this.getXMap() - 1);
			this.setTranslateX(this.getTranslateX() - 30);
			// this.move.setByX(-30);
			// this.move.setByY(0);
			// this.toFront();
			// this.move.play();
			System.out.printf(" --> [%d,%d]\n", this.getXMap(), this.getYMap());
		} else if (k == KeyCode.RIGHT && this.getXMap() < 18) {
			System.out.printf("RIGHT : [%d,%d]", this.getXMap(), this.getYMap());
			this.setXMap(this.getXMap() + 1);
			this.setTranslateX(this.getTranslateX() + 30);
			// this.move.setByX(30);
			// this.move.setByY(0);
			// this.toFront();
			// this.move.play();
			System.out.printf(" --> [%d,%d]\n", this.getXMap(), this.getYMap());
		}
	}

}