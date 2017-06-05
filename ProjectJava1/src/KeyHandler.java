
import javafx.animation.TranslateTransition;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class KeyHandler implements EventHandler<KeyEvent> {

	private Game game;
	private Controller controller;
	private Rectangle fireBall;
	private boolean cast = false;

	public KeyHandler(Game game, Controller controller) {
		this.game = game;
		this.controller = controller;
	}

	public boolean testCollision(KeyEvent event, Entity e) {
		if (event.getCode() == KeyCode.UP)
			return ((game.getMap().getEventLayer())[e.getXMap()][e.getYMap() - 1].getCollision() == 0);
		if (event.getCode() == KeyCode.DOWN)
			return ((game.getMap().getEventLayer())[e.getXMap()][e.getYMap() + 1].getCollision() == 0);
		if (event.getCode() == KeyCode.LEFT)
			return ((game.getMap().getEventLayer())[e.getXMap() - 1][e.getYMap()].getCollision() == 0);
		return ((game.getMap().getEventLayer())[e.getXMap() + 1][e.getYMap()].getCollision() == 0);
	}

	public boolean testPassifDmg(KeyEvent event, Entity e) {
		if (event.getCode() == KeyCode.UP)
			return ((game.getMap().getEventLayer())[e.getXMap()][e.getYMap() - 1].getPassifDmg() == 1);
		if (event.getCode() == KeyCode.DOWN)
			return ((game.getMap().getEventLayer())[e.getXMap()][e.getYMap() + 1].getPassifDmg() == 1);
		if (event.getCode() == KeyCode.LEFT)
			return ((game.getMap().getEventLayer())[e.getXMap() - 1][e.getYMap()].getPassifDmg() == 1);
		return ((game.getMap().getEventLayer())[e.getXMap() + 1][e.getYMap()].getPassifDmg() == 1);
	}

	public void applyDmg(int dmg) {
		game.getMap().getPlayer().setHealthPoints(game.getMap().getPlayer().getHealthPoints() - dmg);
		if (game.getMap().getPlayer().getHealthPoints() <= 0)
			controller.getHpBar().setStartX(-200); // + EXIT
		else
			controller.getHpBar().setStartX((-(200 - (game.getMap().getPlayer().getHealthPoints() * 200)
					/ game.getMap().getPlayer().getHealthPointsMax())));
		if (dmg > 0)
			controller.getHpBar().setVisible(true);
	}

	public void applyManaCost(int spellCost) {
		game.getMap().getPlayer().setManaPoints(game.getMap().getPlayer().getManaPoints() - spellCost);
		if (game.getMap().getPlayer().getManaPoints() == 0)
			controller.getManaBar().setStartX(-200);
		else
			controller.getManaBar().setStartX((-(200 - (game.getMap().getPlayer().getManaPoints() * 200)
					/ game.getMap().getPlayer().getManaPointsMax())));
		if (spellCost > 0)
			controller.getManaBar().setVisible(true);
	}

	public boolean testMana(int spellCost) {
		return (game.getMap().getPlayer().getManaPoints() >= spellCost);
	}

	@Override
	public void handle(KeyEvent event) {
		// TODO Auto-generated method stub
		if (cast) {

		} else if (event.getCode().isArrowKey() && game.getState() == 1) {
			if (testCollision(event, game.getMap().getPlayer())) {
				if (testPassifDmg(event, game.getMap().getPlayer()))
					applyDmg(20);
				game.getMap().getPlayer().move(event.getCode());
			}
		} else if (event.getCode() == KeyCode.SPACE) {
			if (testMana(0)) {
				applyManaCost(0);
				cast = true;
				fireBall = new Rectangle(10, 10, Color.ORANGERED);
				fireBall.setX(game.getMap().getPlayer().getX() + 10);
				fireBall.setY(game.getMap().getPlayer().getY() + 10);
				TranslateTransition move = game.getMap().getPlayer().getMove();
				move.setNode(fireBall);
				if (game.getMap().getPlayer().getOrientation() == 1) {
					fireBall.setY(game.getMap().getPlayer().getY() - 10);
					move.setByX(0);
					move.setByY(-500);
				} else if (game.getMap().getPlayer().getOrientation() == 2) {
					fireBall.setY(game.getMap().getPlayer().getY() + 30);
					move.setByX(0);
					move.setByY(500);
				} else if (game.getMap().getPlayer().getOrientation() == 3) {
					fireBall.setX(game.getMap().getPlayer().getX() - 10);
					move.setByX(-500);
					move.setByY(0);
				} else {
					fireBall.setX(game.getMap().getPlayer().getX() + 30);
					move.setByX(500);
					move.setByY(0);
				}
				controller.getpLayer().getChildren().add(fireBall);
				move.setOnFinished(new EventHandler<ActionEvent>() {

					@Override
					public void handle(ActionEvent event) {
						// TODO Auto-generated method stub
						fireBall.setVisible(false);
						cast = false;
					}
				});
				move.play();
			}
		} else if (event.getCode().isFunctionKey()) {
			if (event.getCode().equals(KeyCode.F1)) {
				game.getScene().setRoot(game.getStartScreen());
				game.setCurrentScreen(1);
			} else if (event.getCode().equals(KeyCode.F2)) {
				game.getScene().setRoot(game.getGameScreen());
				game.setCurrentScreen(2);
			} else if (event.getCode().equals(KeyCode.F3)) {
				game.getScene().setRoot(game.getEndScreen());
				game.setCurrentScreen(3);
			}
		} else if (event.getCode().equals(KeyCode.ESCAPE)) {
			game.getController().ExitGame();
		}
	}

}