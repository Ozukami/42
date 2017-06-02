
import javafx.event.EventHandler;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;

public class KeyHandler implements EventHandler<KeyEvent> {

	private Game game;

	public KeyHandler(Game game) {
		this.game = game;
	}

	@Override
	public void handle(KeyEvent event) {
		// TODO Auto-generated method stub
		if (event.getCode().isArrowKey() && game.getState() == 1) {
			game.getMap().getPlayer().move(event.getCode());
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