
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
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
	private TilePane mapLayer;
	@FXML
	private TilePane eventLayer;
	@FXML
	private AnchorPane pLayer;

	public void StartNewGame() {
		game.getScene().setRoot(game.getGameScreen());
		game.setCurrentScreen(2);
		game.setState(1);
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

	public TilePane getMapLayer() {
		return mapLayer;
	}

	public void setMapLayer(TilePane mapLayer) {
		this.mapLayer = mapLayer;
	}

	public TilePane getEventLayer() {
		return eventLayer;
	}

	public void setEventLayer(TilePane eventLayer) {
		this.eventLayer = eventLayer;
	}

	public AnchorPane getpLayer() {
		return pLayer;
	}

	public void setpLayer(AnchorPane pLayer) {
		this.pLayer = pLayer;
	}
}