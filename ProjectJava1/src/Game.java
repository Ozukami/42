
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
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
	private int currentScreen; // 1 = start ; 2 = end ; 0 = game
	private Scene scene;
	private Group gameScreen;
	private Group startScreen;
	private Group endScreen;
	private Controller controller;
	private FXMLLoader fxmlLoader;

	public Game() {
		this.setWindow();
		fxmlLoader = new FXMLLoader();
		this.currentScreen = 1;
		this.endScreen = new Group(new Rectangle(500, 500, Color.RED));
		this.gameScreen = new Group(new Rectangle(500, 500, Color.ORANGE));

		try {
			fxmlLoader.load(getClass().getResourceAsStream("/start_screen.fxml"));
			this.startScreen = fxmlLoader.<Group>getRoot();
			// fxmlLoader.load(getClass().getResourceAsStream("/game_screen.fxml"));
			// this.gameScreen = fxmlLoader.<Group>getRoot();
			// fxmlLoader.load(getClass().getResourceAsStream("/end_screen.fxml"));
			// this.endScreen = fxmlLoader.<Group>getRoot();
		} catch (Exception ex) {
			System.err.println("Erreur au chargement: " + ex);
		}

		controller = fxmlLoader.getController();

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
				} else if (event.getCode().equals(KeyCode.ESCAPE)) {
					controller.ExitGame();
				}
			}
		});
	}

	private void setWindow() {
		// this.setWidth(1080);
		// this.setHeight(740);
		this.setResizable(false);
	}

}