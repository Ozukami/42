import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class Controller {

	@FXML
	private Button newGameButton;
	@FXML
	private Button continueButton;
	@FXML
	private Button exitButton;

	public void StartNewGame() {

	}

	public void ContinueGame() {

	}

	public void ExitGame() {
		System.exit(1);
	}
}
