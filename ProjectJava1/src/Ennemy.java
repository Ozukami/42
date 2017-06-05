
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;

public class Ennemy extends LivingEntity implements Motion {

	private int range;

	public Ennemy(Color color, double size, int x, int y) {
		super(color, size, x, y);

		this.setHealthPoints(100);
		this.setHealthPointsMax(100);
		this.setManaPoints(100);
		this.setManaPointsMax(100);
	}

	@Override
	public void move(KeyCode k) {
		// TODO Auto-generated method stub
	}

	public void testDeplacement() {

		System.out.println("move ennemy");
	}

}