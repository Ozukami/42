
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.SplitPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class Game extends Stage {

	private Map map;
	private int currentScreen; // 1 = start ; 2 = end ; 0 = game
	private SplitPane gameScreen;
	private Group startScreen;
	private Group endScreen;
	private Controller controller;
	private FXMLLoader fxmlLoader;
	private KeyHandler keyHandler;
	private int state; // 1 = running

	public Game() {
		this.setWindow();
		fxmlLoader = new FXMLLoader();
		this.currentScreen = 1;
		this.endScreen = new Group(new Rectangle(500, 500, Color.RED));
		// this.gameScreen = new Group(new Rectangle(500, 500, Color.ORANGE));

		try {
			fxmlLoader.load(getClass().getResourceAsStream("/start_screen.fxml"));
			this.startScreen = fxmlLoader.<Group>getRoot();
			this.controller = fxmlLoader.getController();
			this.controller.setGame(this);
			fxmlLoader = new FXMLLoader();
			fxmlLoader.load(getClass().getResourceAsStream("/game_screen.fxml"));
			this.controller = fxmlLoader.getController();
			this.controller.setGame(this);
			this.gameScreen = fxmlLoader.<SplitPane>getRoot();
			// fxmlLoader = new FXMLLoader();
			// fxmlLoader.load(getClass().getResourceAsStream("/end_screen.fxml"));
			// this.controller = fxmlLoader.getController();
			// this.controller.setGame(this);
			// this.endScreen = fxmlLoader.<Group>getRoot();
		} catch (Exception ex) {
			System.err.println("Erreur au chargement 1: " + ex);
		}

		this.state = 0;
		this.setScene(new Scene(this.startScreen));
		this.show();

		this.controller.getMapLayer().setLayoutX(34);
		this.controller.getMapLayer().setLayoutY(84);
		this.controller.getMapLayer().setPrefWidth(600);
		this.controller.getMapLayer().setPrefHeight(600);
		this.controller.getEventLayer().setLayoutX(34);
		this.controller.getEventLayer().setLayoutY(84);
		this.controller.getEventLayer().setPrefWidth(600);
		this.controller.getEventLayer().setPrefHeight(600);

		this.controller.getHpBar().setVisible(false);
		this.controller.getManaBar().setVisible(false);

		this.map = new Map(this.controller.getMapLayer(), this.controller.getEventLayer(), this.controller.getpLayer());

		this.keyHandler = new KeyHandler(this, controller);
		this.getScene().setOnKeyPressed(this.keyHandler);
	}

	private void setWindow() {
		// this.setWidth(1080);
		// this.setHeight(740);
		this.setResizable(false);
	}

	public Map getMap() {
		return map;
	}

	public void setMap(Map map) {
		this.map = map;
	}

	public int getCurrentScreen() {
		return currentScreen;
	}

	public void setCurrentScreen(int currentScreen) {
		this.currentScreen = currentScreen;
	}

	public SplitPane getGameScreen() {
		return gameScreen;
	}

	public void setGameScreen(SplitPane gameScreen) {
		this.gameScreen = gameScreen;
	}

	public Group getStartScreen() {
		return startScreen;
	}

	public void setStartScreen(Group startScreen) {
		this.startScreen = startScreen;
	}

	public Group getEndScreen() {
		return endScreen;
	}

	public void setEndScreen(Group endScreen) {
		this.endScreen = endScreen;
	}

	public Controller getController() {
		return controller;
	}

	public void setController(Controller controller) {
		this.controller = controller;
	}

	public FXMLLoader getFxmlLoader() {
		return fxmlLoader;
	}

	public void setFxmlLoader(FXMLLoader fxmlLoader) {
		this.fxmlLoader = fxmlLoader;
	}

	public KeyHandler getKeyHandler() {
		return keyHandler;
	}

	public void setKeyHandler(KeyHandler keyHandler) {
		this.keyHandler = keyHandler;
	}

	public int getState() {
		return state;
	}

	public void setState(int state) {
		this.state = state;
	}

}