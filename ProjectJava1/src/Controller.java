
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.TilePane;

public class Controller {

	private Game game;

	@FXML
	private Button newGameButton;
	@FXML
	private Button continueButton;
	@FXML
	private Button exitButton;
	@FXML
	private TilePane mapContainer;

	public void StartNewGame() {
		game.getScene().setRoot(game.getGameScreen());
		game.setCurrentScreen(2);
	}

	public void ContinueGame() {

	}

	public void ExitGame() {
		System.exit(1);
	}

	public Game getGame() {
		return game;
	}

	public void setGame(Game game) {
		this.game = game;
	}

	public TilePane getMapContainer() {
		return mapContainer;
	}

	public void setMapContainer(TilePane mapContainer) {
		this.mapContainer = mapContainer;
	}
}
