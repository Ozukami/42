
import javafx.application.Application;
import javafx.stage.Stage;

public class Gate extends Application {

	private Game game;

	public static void main(String[] args) {
		Application.launch(Gate.class, args);
	}

	@Override
	public void start(Stage primaryStage) {
		this.game = new Game();
	}

}