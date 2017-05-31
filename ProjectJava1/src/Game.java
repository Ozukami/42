
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class Game extends Stage {

	// private Map map;
	// private Player p1;
	private Scene scene;
	private Group gameScreen;
	private StartScreen startScreen;
	private Group endScreen;
	private int currentScreen; // 1 = start ; 2 = end ; 0 = game

	public Game() {
		this.setWindow();
		this.currentScreen = 1;
		this.startScreen = new StartScreen(new Rectangle(500, 500, Color.BLUE));
		this.endScreen = new Group(new Rectangle(500, 500, Color.RED));
		this.gameScreen = new Group(new Rectangle(500, 500, Color.ORANGE));
		this.scene = new Scene(this.startScreen);

		this.setScene(scene);
		this.show();

		this.scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				// TODO Auto-generated method stub
				if (event.getCode().equals(KeyCode.SPACE)) {
					if (currentScreen == 1) {
						scene.setRoot(gameScreen);
						currentScreen = 0;
					} else if (currentScreen == 2) {
						scene.setRoot(startScreen);
						currentScreen = 1;
					} else if (currentScreen == 0) {
						scene.setRoot(endScreen);
						currentScreen = 2;
					}
				}
			}
		});
	}

	private void setWindow() {
		this.setWidth(1000);
		this.setHeight(720);
		this.setResizable(false);
	}

}