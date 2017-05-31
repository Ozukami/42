
import java.io.IOException;
import java.net.URL;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class Gate extends Application {

	private Game game;

	public static void main(String[] args) {
		Application.launch(Gate.class, args);
	}

	@Override
	public void start(Stage primaryStage) {
		// this.game = new Game();
		try {
			final URL url = getClass().getResource("start_screen.fxml");
			final FXMLLoader fxmlLoader = new FXMLLoader(url);
			final AnchorPane root = (AnchorPane) fxmlLoader.load();
			final Scene scene = new Scene(root, 300, 250);
			primaryStage.setScene(scene);
		} catch (IOException ex) {
			System.err.println("Erreur au chargement: " + ex);
		}
		primaryStage.setTitle("Test FXML");
		primaryStage.show();
	}

}